#include <stdio.h>
#include "string.h"

#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "hardware/sync.h"

//.................................PICO_LOG DECLARATIONS................................
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */

int *pico_flash_read(long int FLASH_TARGET_OFFSET, size_t len) 
{
    const uint32_t *flash_target_contents = (const uint32_t *) (XIP_BASE + FLASH_TARGET_OFFSET);
    uint32_t *stored_value = (uint32_t*)calloc(len, sizeof(uint32_t));

    for (size_t i = 0; i < len; ++i)
    {
        printf(CYAN "\n STORED VALUE : %d\n" RESET, flash_target_contents[i]);
        stored_value[i] = flash_target_contents[i];
    }

    return stored_value;                                                                                //++ Returns the pointer pointing to the array
}


int pico_flash_write(long int FLASH_TARGET_OFFSET, uint32_t flash_data[], size_t num)
{
    const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);
    uint32_t *stored_value = (uint32_t*)malloc(num + 1);

    uint32_t interrupts = save_and_disable_interrupts();
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);

    printf(YELLOW "\n PROGRAMMING FLASH MEMORY......\n" RESET);

    flash_range_program(FLASH_TARGET_OFFSET, flash_data, FLASH_PAGE_SIZE);
    restore_interrupts(interrupts);
    
    stored_value = pico_flash_read(FLASH_TARGET_OFFSET, num);

    if (strcmp(stored_value,flash_data)==0)                                                             //++ Compares the stored and written data 
        {
            printf(GREEN "\n COMMIT SUCCESSFULL \n" RESET);
            return "OK";
        }
    else
        {
            printf(RED "\n COMMIT UNSUCCESSFULL \n" RESET);
            return "ERR";
        }
}


void pico_flash_erase(long int FLASH_TARGET_OFFSET)
{
    int8_t stored_value = 0;
    uint32_t interrupts = save_and_disable_interrupts();
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);

    printf(YELLOW "\n ERASING FLASH MEMORY......\n" RESET);

    flash_range_program(FLASH_TARGET_OFFSET, stored_value, FLASH_PAGE_SIZE);
    restore_interrupts(interrupts);   
}

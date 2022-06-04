#include <stdio.h>
#include "string.h"
#include "pico/stdlib.h"
#include "pico_flash.h"

#include "hardware/flash.h"
#include "hardware/sync.h"

#define FLASH_TARGET_OFFSET (1792*1024)
const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

void flash_task(void *pvParameters)
{
    uint32_t counter0 = 0;
    uint32_t counter1 = 100;
    uint32_t counter2 = 1000;

    uint32_t flash_data[FLASH_PAGE_SIZE];

    while(true)
    {
        counter0++;
        counter1++;
        counter2++;
        flash_data[0] = counter0;
        flash_data[1] = counter1;
        flash_data[2] = counter2;

        pico_flash_read(FLASH_TARGET_OFFSET, 3);
    
        pico_flash_erase(FLASH_TARGET_OFFSET);
        
        pico_flash_read(FLASH_TARGET_OFFSET, 3);

        pico_flash_write(FLASH_TARGET_OFFSET, flash_data, 3);

        printf("\n -------------------------------------------------------------------------- \n");

        vTaskDelay( 1000 / portTICK_PERIOD_MS);
    }
}

int main()
{
    stdio_init_all();

    sleep_ms(10000);
    printf(CYAN "\n System Starting..............\n" RESET);
    printf(CYAN "\n Target Location is %ld\n" RESET, flash_target_contents);

    flash_task();

    return 0;

}
#include <stdio.h>
#include "string.h"
#include "pico/stdlib.h"
#include "pico_flash.h"

#include "hardware/flash.h"
#include "hardware/sync.h"

#define FLASH_TARGET_OFFSET (1792*1024)                                                         //++ Starting Flash Storage location after 1.8MB ( of the 2MB )
const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);      //++ Pointer pointing at the Flash Address Location

void flash_task(void *pvParameters)                                                             //++ Example Function to perform Flash Operations
{
    uint32_t counter0 = 0;                                                                      //++ Declaration of Variables to be stored
    uint32_t counter1 = 100;
    uint32_t counter2 = 1000;

    uint32_t flash_data[FLASH_PAGE_SIZE];                                                       //++ Declaring an array of size 256 to store the variables

    counter0++;
    counter1++;
    counter2++;
    flash_data[0] = counter0;                                                                   //++ Storing variables on respective array indexes
    flash_data[1] = counter1;
    flash_data[2] = counter2;

    pico_flash_read(FLASH_TARGET_OFFSET, 3);                                                    //++ Flash operation to read 3 Flash Addresses before erasing and storing new data

    pico_flash_erase(FLASH_TARGET_OFFSET);                                                      //++ Flash operation to erase entire flash page ( 256 locations together )

    pico_flash_read(FLASH_TARGET_OFFSET, 3);                                                    //++ Flash operation to read 3 Flash Addresses after erasing entire page

    pico_flash_write(FLASH_TARGET_OFFSET, flash_data, 3);                                       //++ Flash operation to write the 3 Flash Address with the array containg the variables

    printf("\n -------------------------------------------------------------------------- \n");

}

int main()
{
    stdio_init_all();                                                                           //++ Initialize rp2040

    sleep_ms(15000);                                                                            //++ Wait for 15 secs
    printf(CYAN "\n System Starting..............\n" RESET);
    printf(CYAN "\n Target Location is %ld\n" RESET, flash_target_contents);

    flash_task();                                                                               //++ Call the Flash Operations Function

    return 0;

}

//.................................PICO_LOG DECLARATIONS................................
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */

#ifndef PICOFLASH_H
#define PICOFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reads number of blocks from Pico Flash
 *
 * @param FLASH_TARGET_OFFSET Flash Offset Location used for read/write
 * @param len Length of number of locations to read from Flash
 * @return
 */
int *pico_flash_read(long int FLASH_TARGET_OFFSET, size_t len);

/**
 * @brief Writes data to specified Pico Flash Address
 *
 * @param FLASH_TARGET_OFFSET Flash Offset Location used for read/write
 * @param flash_data The array of data that will be stored in Flash 
 * @param num Number of data points to be stored
 * @return
 */
int pico_flash_write(long int FLASH_TARGET_OFFSET, uint32_t flash_data[], size_t num);

/**
 * @brief Erases the entire specified Flash Page
 *
 * @param FLASH_TARGET_OFFSET Flash Offset Location used for read/write
 * @return
 */
void pico_flash_erase(long int FLASH_TARGET_OFFSET);

#ifdef __cplusplus
}
#endif

#endif // PICOFLASH_H

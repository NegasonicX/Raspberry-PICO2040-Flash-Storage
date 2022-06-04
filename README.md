# Raspberry PICO2040 Flash Storage
The Following C Coded Library is used to perform Flash Write, Read and Erase functions on Raspberry Pico 2040.

# Raspberry PICO 2040 Flash:
* The official board of rp2040 uses W25Q16JVUXIQ 16Mbit (2MB) flash chip.
* Runs on 133MHz on single SPI clock and 266/532MHz equivalent Dual/Quad SPI.
* Minimum 100K Program-Erase cycles per sector along with 20-years of data rentention.
![RP2050_FLASH](https://user-images.githubusercontent.com/99990377/172008713-60fa314a-2fe1-4c75-9b4d-b0721388a63c.PNG)

# Understading the Flow:
* This code is developed for rp2040 on Embedded C Language.
* rp2040 doesn't much resources over the internet to use flash in a simple way and the only option available was a library on Arduino IDE.
* The following library is completed made on C Language and very simple to use.
* A Simple example is available in the main.c with necessary comments on each line of code for better understanding.
* There are 3 functions to perform Read, Write and Erase of pico Flash :
  * pico_flash_read()  ---> Performs Flash Read
  * pico_flash_write() ---> Performs Flash Write
  * pico_flash_erase() ---> Performs Flash Erase
* Please note, currently pico_flash_erase() will erase the whole page ( size = 256 ) and not just one memory location.

# Conclusion:
* Currently, only 32-bit integers can be stored in the pico flash.
* You do have to declare all the varaiables to be stored in flash as shown in the main.c
* I hope you all like it :-D

# Reference Material:
* https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf
* http://wiki.amperka.ru/_media/products:raspberry-pi-pico:w25q16jvuxiq-datasheet.pdf

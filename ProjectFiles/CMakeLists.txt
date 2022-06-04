add_executable(flash
    main.c
    pico_flash.c
    pico_flash.h
)

target_link_libraries(flash pico_stdlib hardware_flash hardware_sync)
pico_add_extra_outputs(flash)

pico_enable_stdio_uart(flash 0)
pico_enable_stdio_usb(flash 1)

pico_add_extra_outputs(flash)
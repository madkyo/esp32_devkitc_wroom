# esp32_devkitc_wroom

Note:
> This folder only contains ESP modified sample Firmware source files.
> For ESP32 Firmware code - users should get it directly this to build quickly


1. source ~/zephyrproject/.venv/bin/activate

2. west build -p always -b esp32_devkitc_wroom/esp32/procpu

3. west flash

4. minicom -D /dev/ttyUSB0
(.venv$: west espressif monitor -p /dev/ttyUSB0)

=========================================================================
## search fail message command

find build/ -type f | xargs grep -E dts_ord_41

## search key word infor find .c .h files

grep -nre "check power" --include="*.[ch]"

## Kconfig search

https://docs.zephyrproject.org/latest/kconfig.html

=========================================================================

HW : NodeMCU-32

Reference:

1. [esp-32s: button interrupt sample log:](https://drive.google.com/file/d/1ZcRvYyaoXPmLGt05yoVfGqjqnXD71D_m/view?usp=drive_link)

2. [board Specification NodeMCU-32 Ai-Thinker linker](https://uamper.com/products/datasheet/NodeMCU32-S_specification_V1.3.pdf?srsltid=AfmBOoo-2bG2DRyNEk61-R3R9b4ghIr9yflIHDpdr4ETYT5WFWgLW5HZ)

3. [zephyr 3.7.0 esp32_devkitc_wroom](https://docs.zephyrproject.org/3.7.0/boards/espressif/esp32_devkitc_wroom/doc/index.html)

note Step1. [Find device tree Bindings Generic or vendor-independent](https://docs.zephyrproject.org/3.7.0/build/dts/api/bindings.html)

note Step2. ./zephyrproject/zephyr/dts/bindings/ ymal files

note Step3. [Docs / 3.7.0 » Hardware Support](https://docs.zephyrproject.org/3.7.0/hardware/index.html)

[Peripherals](https://docs.zephyrproject.org/3.7.0/hardware/peripherals/index.html) exsample ADC. PWM. LED

youtube:

4. [ESP32 on Zephyr OS: GPIO Interrupt (ISR) [Part 3]](https://www.youtube.com/watch?v=NlRM2IfODTs)


5. [ADUINO SAMPLES WEB](https://www.lanmootech.com/courses/ultimate/lesson/%e9%96%8b%e9%97%9c%e6%8e%a7%e5%88%b6-led-%e7%87%88-%e5%96%ae%e5%85%83/)


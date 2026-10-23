# Description
This project focuses on the different types of ESP32 Wired Communications, such as UART, I2C, and SPI. The UART & SPI are tested through a loopback (Single ESP32) while I2C uses an actual I2C capable device, such as SSD1306 OLED Display.

More details are written in each sketch folder.

# General Pin/s Configuration Table

<div align="center">

| Signal    | UART TX | UART RX | I2C SDA | I2C SCL | SPI SCK | SPI MOSI | SPI MISO | SPI CS |
| :-------: | :------ | :------ | :------ | :------ | :------ | :------- | :------- | :----- |
| GPIO Used | 33      | 32      | 18      | 19      | 19      | 22       | 21       | 23     |

</div>

# Questions
1. Why does UART need both sides to use the same baud rate, while SPI uses a clock line?
    - UART is an asynchronous communication, which means the clock phase for the two devices are independent of each other, while an SPI is a synchronous communication method that shares the clock rate for the connected devices. The baud rate of UART is directly proportional to the Clock rate, and the clock is involved in managing the transmission timing to prevent issues such as malformed data during transmission. For SPI, the clock is shared together so that the communication between the connected devices is properly set-up.

2. Why can two devices with the same address does not share one I2C bus?
    - I2C data transmission requires address acknowledgement because I2C can communicate in one-to-one or one-to-many structure. Having 2 Devices connected to a single Controller with the same I2C bus and same addresses conflicts with the address acknowledgement. It sends ACK twice to the Controller, and the data transmitted back to the peripheral device may collide, or simply sends both to Device 1 & 2.

3. Why is CS set HIGH between SPI transfers?
    - For an active-low CS/SS, High means to ignore a specific slave/peripheral device, while low makes the device listen to the controller/master.

# Note
- Committer 'server5056' was caused by using a public computer, overriding the git local and global configuration during 'git push'.
- UART was possible with two ESP32 boards but restricted/limited due to insufficient owned ESP32 boards.
- I2C used SSD1306 OLED Display for the sake of conveniency.
- SPI sketch implementation reasoning is identical to UART.

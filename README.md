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

2. Why can two devices with the same address does not share one I2C bus?

3. Why is CS set HIGH between SPI transfers?

# Note
- Committer 'server5056' was caused by using a public computer, overriding the git local and global configuration during 'git push'.
- UART was possible with two ESP32 boards but restricted/limited due to insufficient owned ESP32 boards.
- I2C used SSD1306 OLED Display for the sake of conveniency.
- SPI sketch implementation reasoning is identical to UART.

# Description
This project focuses on the different types of ESP32 Wire Communications, such as, UART, I2C, and SPI.

# Pin/s Configuration & Observation Table

#### Pin/s Configuration Table

<div align="center">

| Signal    | UART TX | UART RX | I2C SDA | I2C SCL | SPI SCK | SPI MOSI | SPI MISO | SPI CS |
| :-------: | :------ | :------ | :------ | :------ | :------ | :------- | :------- | :----- |
| GPIO Used | 33      | 32      |         |         | 19      | 22       | 21       | 23     |

</div>

#### Observation Table

<div align="center">
  
| Test                              | Expected behavior                                  | Actual behavior |
| :-------------------------------- | :------------------------------------------------- | :-------------- |
| UART with jumper                  | RX receives data from TX                           |                 |
| UART without jumper               | RX is floating and cannot receive data from TX     |                 |
| I2C with module                   |                                                    |                 |
| I2C without module                |                                                    |                 |
| SPI with Jumper                   | MISO receives data from MOSI                       |                 |
| SPI without Jumper                | MISO is floating and cannot receive data from MOSI |                 |
| Sketch at 9600, monitor at 115200 |                                                    |                 |
| Sketch at 9600, monitor at 9600   |                                                    |                 |

</div>

# Note
Committer 'server5056' was caused by using a public computer, overriding the git local and global configuration during 'git push'.

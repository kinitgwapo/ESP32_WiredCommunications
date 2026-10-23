# Description
This project focuses on the different types of ESP32 Wire Communications, such as, UART, I2C, and SPI.

# Pin/s Configuration & Observation Table

#### Pin/s Configuration Table

<div align="center">

| Signal    | UART TX | UART RX | I2C SDA | I2C SCL | SPI SCK | SPI MOSI | SPI MISO | SPI CS |
| :-------: | :------ | :------ | :------ | :------ | :------ | :------- | :------- | :----- |
| GPIO Used | 33      | 32      | 18      | 19      | 19      | 22       | 21       | 23     |

</div>

#### Observation Table

<div align="center">
  
| Test                              | Expected behavior                                  | Actual behavior |
| :-------------------------------- | :------------------------------------------------- | :-------------- |
| UART with jumper                  | RX receives data from TX                           | Receives and prints the data transmitted                |
| UART without jumper               | RX is floating and cannot receive data from TX     | Can send, but Receiver gets nothing                |
| I2C with module                   | Scans for any peripheral devices that acknowledges an address sent by the Controller through SDA, then returns status code (0 = Acknowledged)                                                   | Returns ACK status code, outputs the address from for loop that was acknowledged by the peripheral device                |
| I2C without module                | Returns status code (2 = Not Acknowledged) due to no physical connection to any I2C device at all                                                   | Returns Status Code 2                |
| SPI with Jumper                   | MISO receives data from MOSI                       | Prints out the data sent in loopback                |
| SPI without Jumper                | MISO is floating and cannot receive data from MOSI | Does not print out sent data due to no physical loopback connection                |
| Sketch at 9600, monitor at 115200 | Garbled or Unreadable output                       | Printed random symbols, missed some bytes                |
| Sketch at 9600, monitor at 9600   | Correct, readable output                           | Printed the correct characters, identical to the transmitted data                |

</div>

# Note
Committer 'server5056' was caused by using a public computer, overriding the git local and global configuration during 'git push'.

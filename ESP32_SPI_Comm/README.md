# Serial Monitor & Observation Table

#### Serial Monitor

<div align="center">

| Output                              |
| :---------------------------------- |
| 11:58:55.543 -> Current CS State: 0 |
| 12:00:02.059 -> Current CS State: 1 |
| 12:00:02.059 -> Sent: a5            |
| 12:00:02.059 -> Received: a5        |

</div>

#### Test

<div align="center">

| Test               | Expected Behavior                                  | Actual Behavior                                                     |
| :----------------- | :------------------------------------------------- | :------------------------------------------------------------------ |
| SPI with Jumper    | MISO receives data from MOSI                       | Prints out the data sent in loopback                                |
| SPI without Jumper | MISO is floating and cannot receive data from MOSI | Does not print out sent data due to no physical loopback connection |

</div>

# Circuit Diagram
For now, the SCK is left floating because it has no other SPI capable device to communicate with and synchronize a transmission clock phase, while the CS/SS pin can either be connected to an LED to indicate transmission status, or just left floating.

<p align="center">
<img width="889" height="614" alt="SPI" src="https://github.com/user-attachments/assets/6cb92964-a0eb-4cc4-babe-69f24e92a4e0" />
</p>

# References
- https://docs.arduino.cc/learn/communication/spi/
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/gpio.html
- https://github.com/espressif/arduino-esp32/tree/master/libraries/SPI/src

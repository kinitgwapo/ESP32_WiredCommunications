# Output (Serial Monitor)

<div align="center">
  
|                                                               |
| :------------------------------------------------------------ |
| 01:08:02.448 -> Command sent (Serial Monitor Command): Hi!    |
| 01:08:03.068 -> Command received (Serial2):                   |
| 01:08:03.068 -> H                                             |
| 01:08:03.068 -> i                                             |
| 01:08:03.068 -> !                                             |
| 01:08:04.977 -> Command sent (Serial Monitor Command): Hello! |
| 01:08:05.097 -> Command received (Serial2):                   |
| 01:08:05.097 -> H                                             |
| 01:08:05.097 -> e                                             |
| 01:08:05.097 -> l                                             |
| 01:08:05.097 -> l                                             |
| 01:08:05.097 -> o                                             |
| 01:08:05.097 -> !                                             |
| 01:08:08.536 -> Command sent (Serial Monitor Command): PING   |
| 01:08:09.052 -> Command received (Serial2):                   |
| 01:08:09.052 -> P                                             |
| 01:08:09.099 -> I                                             |
| 01:08:09.099 -> N                                             |
| 01:08:09.099 -> G                                             |

</div>

### Test

<div align="center">
  
| Test                | Expected Behavior                     | Actual Behavior                          |
| :------------------ | :------------------------------------ | :--------------------------------------- |
| UART with jumper    | Serial2 receives the transmitted data | receives and prints the data transmitted |
| UART without jumper | Serial2 receives nothing              | Can send, but Receiver gets nothing      |

</div>

# Circuit Diagram
The RX Pin was set to be input_pullup internally to filter noise. The data can be transmitted to another device.

<p align="center">
  <img width="606" height="587" alt="UART" src="https://github.com/user-attachments/assets/78b87b76-d176-4cb3-8134-4aff3f1bcc09">
</p>

# References
- https://docs.arduino.cc/language-reference/en/functions/communication/serial/
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/gpio.html

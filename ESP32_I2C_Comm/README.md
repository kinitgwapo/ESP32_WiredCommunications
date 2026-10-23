# Output (Serial Monitor)

#### Test

<div align="center">


| Test               | Expected Behavior                                                                                                                             | Actual Behavior                                                                                           |
| :----------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------- |
| I2C with module    | Scans for any peripheral devices that acknowledges an address sent by the Controller through SDA, then returns status code (0 = Acknowledged) | Returns ACK status code, outputs the address from for loop that was acknowledged by the peripheral device |
| I2C without module | Returns status code (2 = Not Acknowledged) due to no physical connection to any I2C device at all                                             | Returns Status Code 2                                                                                     |

</div>

# Circuit Diagram

<p align="center">
<img width="934" height="424" alt="I2C" src="https://github.com/user-attachments/assets/6da22618-da8e-4fc3-bf7a-83ba5b74a7eb" />
</p>

# References
- https://docs.arduino.cc/learn/communication/wire/
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/gpio.html

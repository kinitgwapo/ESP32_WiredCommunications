# Serial Monitor & Observation Table

#### Test

<div align="center">


| Test               | Expected Behavior                                                                                                                             | Actual Behavior                                                                                           |
| :----------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------- |
| I2C with module    | Scans for any peripheral devices that acknowledges an address sent by the Controller through SDA, then returns status code (0 = Acknowledged) | Returns ACK status code, outputs the address from for loop that was acknowledged by the peripheral device |
| I2C without module | Returns status code (2 = Not Acknowledged) due to no physical connection to any I2C device at all                                             | Returns Status Code 2                                                                                     |

</div>

# Circuit Diagram
Both the SDA & SCL are connected to an external pull-up resistor to avoid using the internal ESP32 pull-up resistor which conflicts with the communication due to more ampere reduction from high-resistance, forcing the decision to use an external pull-up resistor with a much controlled resistance level to gain above 500uA+ during logic switching.


<p align="center">
<img width="934" height="424" alt="I2C" src="https://github.com/user-attachments/assets/dd81214d-17b8-49e0-a116-76546d614c96" />
</p>

# References
- https://docs.arduino.cc/learn/communication/wire/
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/gpio.html
- https://github.com/espressif/arduino-esp32/tree/master/libraries/Wire

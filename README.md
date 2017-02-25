# Coruja
### Home Security
This is an Arduino© (or compatible microcontroller) project that claims to get information (data) from sensors installed in a house and silently notify the owners. It was designed to work with infred motion sensors along with cameras and mics, providing the owners detailed info about what is goins on the house.

The project uses [PlatformIO](http://platformio.org/) for library management.

### Main components
#### [SIM800L](http://www.meshine-tech.com/SIM800L.html)
Used for communication in places that don't have WiFi available or other easy internet access. This module only requires a micro SIM card and can act as a modem, providing internet access. It can also send SMS and make calls, wich can be useful for transmition of real time audio.
#### [PIR HC-SR501](https://wikipedia.org/wiki/Passive_infrared_sensor)
Passive Infrared sensor, used for detecting motion of humans and other animals or anything warmer than the environment.

### **Hight Performance branch**
This branch will not use any library and focus on performance, but keeping all the features of the master branch. It will be interesting to see and compare the real diferences in performance in a real application.

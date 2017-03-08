# Coruja
### Home Security
This is an Arduino© (or compatible microcontroller) project that claims to get information (data) from sensors installed in a house and silently notify the owners. It was designed to work with infred motion sensors along with cameras and mics, providing the owners detailed info about what is goins on the house.

The project uses [PlatformIO](http://platformio.org/) for library management and for compiling/running the project.

### Main components

#### [PIR HC-SR501](https://wikipedia.org/wiki/Passive_infrared_sensor)
Passive Infrared sensor, used for detecting motion of humans and other animals or anything warmer than the environment.

#### [LASER](https://en.wikipedia.org/wiki/Laser_pointer)
The Pointer Laser, with a [Photoresistor](https://en.wikipedia.org/wiki/Photoresistor), can be used to built a moving sensor. The Laser will be pointed all the time to the Photoresistor. The Arduino can tell when the beam is interrupted, meaning that something got in it's way (a thief, maybe). It can be used in front of doors or windows.

#### [SIM800L](http://www.meshine-tech.com/SIM800L.html)
Used for communication in places that don't have WiFi available or other easy internet access. This module only requires a micro SIM card and can act as a modem, providing internet access. It can also send SMS and make calls, wich can be useful for transmition of real time audio.

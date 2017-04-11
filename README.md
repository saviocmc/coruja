# Coruja
### Home Security
This is an [Arduino©](https://www.arduino.cc/) (or compatible microcontroller) project that claims to get information (data) from multiple sensors installed in a house and silently notify the owners. It was designed to work with infra-red motion sensors along with cameras and mics, providing the owners detailed information about what is going on in the house.

The project uses [PlatformIO](http://platformio.org/) for library management and for compiling/running the project.

### Main components

#### [PIR HC-SR501](https://wikipedia.org/wiki/Passive_infrared_sensor)
Passive Infrared sensor, used for detecting motion of humans and other animals (or anything warmer than the environment).

#### [LASER](https://wikipedia.org/wiki/Laser_pointer)
A Laser Pointer, along with a [Photoresistor](https://wikipedia.org/wiki/Photoresistor), was used to built a "intruder" sensor. The Laser is pointed all the time to the Photoresistor. The Arduino can tell when the beam is interrupted, meaning that something got in it's way (a thief, maybe). It can be used in front of doors or windows.

#### [SIM800L](http://www.meshine-tech.com/SIM800L.html)
Used for communication in places that don't have WiFi available or other easy internet access. This module only requires a SIM card and can act as a modem, providing internet access. It can also send SMS and make calls, wich can be useful for transmition of real time audio.

### Compiling
* First install [PlatformIO Core](http://docs.platformio.org/en/latest/installation.html#installation-methods) or [PlatformIO IDE (Atom Editor)](http://docs.platformio.org/en/latest/ide/atom.html).
* Connect the arduino or compatible microcontroller to the computer.
* In a terminal/shell, go to the project directory and type ``pio run -t upload``

More information and options about compiling a PlatformIO project [here](http://docs.platformio.org/en/stable/userguide/cmd_run.html).

#SERIAL COMMUNICATION 
 *This tests a serial communication between arduino nano / or attiny digispark device with Raspberry card*

<div style="text-align: center">
<img src="" alt="front image" width="500"/>
</div>

## Table of Contents
1. [Usage](#usage)
2. [Hardware Description](#hardware-description)
3. [Short Tutorial](#short-tutorial)

## Installation and Usage

The i2c serial communication between a Raspberry master device and an arduino nano /or attiny digispark.
Note that for attiny device you need to include TinyWire from [tinyWire directory](/tinyWire).

* For digispark users : From the [tinyWire directory](/tinyWire)
* Use Arduino IDE to import TinyWire Library 


## Hardware Description
 
        Raspberry                                   
         ______                               Arduino nano / Attiny
        |      |                                    _________
        |      |                                   |         |
        |      - .............>  SDA  ...........> -         |
        |      - .............>  SCL  ...........> -         |
        |      |                                   |         |
        |      |                                   |         |
        |      - .............>  GND ............> -         |
        |______|                                   |_________|



## Short Tutorial 

To use this i2c communication, you need to install a C++ editor (Visual Code is recommended) 

* Open the serial_rasp_master.cpp file with the C++ editor
* Using a terminal (Visual Code), connect to your Raspberry IP 
* Use the command :

		scp serial_rasp_master.cpp pi@192.168.x.x: 

* Compile the File in the Raspberry terminal :

		g++ serial_rasp_master.cpp -o i2c 

* run the exe file in the Raspberry terminal : 

		./i2c 

You can test the communication in the arduino IDE using the serial monitor, you need to set the same baudrate in order to be synchronous 
		

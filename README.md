#PYDOME
 *Python Lib for Domes features control, this package allows users to build, evaluate and make tasks based on Raspberry OS*

<div style="text-align: center">
<img src="" alt="front image" width="500"/>
</div>

## Table of Contents
1. [Installation and Usage](#installation-and-usage)
2. [Data Format](#data-format)
3. [Hardware Description](#hardware-description)
4. [Short Tutorial](#short-tutorial)

## Installation and Usage

### Install 
The Pydome is a package which must be installed in Raspberry OS.
It requires **Python 3.7** or any later version.
For now, user can install **pydome** package through wheel files:

* From the [dist directory](/dist) download the .whl file
* Use pip command 
	python3 -m pip install pydome-1.0-py3-none-any.whl
* or 
	sudo apt-get install pydome

### Usage 
The **pydome** package is composed of modules:
- *gpio_checker* to check connexions between Raspberry master and output system
- *data_creator* to build data
- *dome_leds_on* to turn leds on or off
- *dome_features* to build and manage features needed to make relevant data

## Data Format
 
This allows to take look to data format after data acquisitions from embedded camera

## Hardware Description 

This make a brief description about materials and connextions


## Short Tutorial
Here is a quick tutorial to learn how to use data and how to obtain it

### Introduction

The goal of this Tutorial is to discover features of the pydome library. 

'''python
import pydome
import os
'''
# microdome

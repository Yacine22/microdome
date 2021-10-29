# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
from tkinter import * 
import os 
import subprocess
import sys 
import serial


def win():
    """
    Main Window
    -------
    None.
    """
    window = Tk()
    window.geometry('480x480')
    window.title("Micro Dome")
    
    btn1 = Button(window, text='make folder', command=make_folder())
    btn1.pack()



def make_folder():
    """
    Make folder
    -------
    None.

    """
    try:
        os.mkdir('./data')
    except:
        pass


window = win()
mainloop()
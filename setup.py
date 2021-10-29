# -*- coding: utf-8 -*-
"""
Created on Fri Oct 29 11:27:07 2021

@author: yme
"""

import setuptools

with open("README.md", "r") as rm:

    long_description = rm.read()

setuptools.setup(

     name='pydome',  

     version='1.0',
     

     author="Yacine Merabet",

     author_email="yacine.merabet@mercurioimaging.com",

     description="A GUI for dome control",

     long_description=long_description,

     long_description_content_type="text/markdown",

     url="https://github.com/Yacine22/mercurioimaging",

     packages=setuptools.find_packages(),

     
     install_requires=[
          'pycamera',
          'tkinter',
          'Pillow',
          'pyserial',
          'RPi.GPIO',
          
     ],

     classifiers=[

         "Programming Language :: Python :: 3.8",

         "License :: OSI Approved :: Mercurio License",

         "Operating System :: All",

     ],

 )
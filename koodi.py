#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import curses
import time
import random
import subprocess
import serial

os.system('sudo apt-get install streamripper vorbis-tools mumble lame vlc')

arduino = serial.Serial('/dev/ttyACM0', 9600)

try:
    print 'Trying...';
    time.sleep(1)
    arduino.flush()
except:
    print 'Failed to connect';
    
while True :
    loytyi = bool(False)
    while loytyi==False :
        Arvo = os.popen('pgrep mumble')
        c = curses.initscr().getch()
        if Arvo.readline() > 1 :
            arduino.write('H,' + str(Arvo))
            print 'Mumble on paalla'
        else :
            print 'Mumble ei paalla'
    if c == '4' :
        break;

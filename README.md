# STM8S003F3 Firmware for a "brain transplanted" HJ digital servo tester

I got a "fried" a digital servo tester from my friends with take it or throw it motto.

I cracked it up (it has 4 screws in the corners haha), and then i thought I saw a familiar part (STM8S0003F3) but it turned out it was a Nuvouton.

Since I have a quite few STM8s I replaced the MCU soldered the SWIM connector and the VCAP 100nF cap (marked with 104 on the silkscreen)

After a few hours and some STM8 development related rediscoveries I managed to get it rolling:
![The setup](docs/the_ultimate_hj_hacking_rig.jpg?raw=true "Setup")

I have included an STM8 CubeMX project as a reference for the pinout:
![Pinout](docs/cubemx.png?raw=true "Pinout")

## Features
At the moment two modes supported_
 - 700 - 2300 us standard servo
 - "DJI" mode: 1000us - 2000us with 2500 us interval

## Toolchain info

STM8 Standard peripherial lib from ST

STVP + Cosmic (planning to port SDCC and use openOCD and GDB for debugging)

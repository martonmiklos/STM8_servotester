# STM8S003F3 Firmware for a "brain transplanted" HJ digital servo tester

I got a "fried" a digital servo tester from my friends with "take it or throw it" motto.

I cracked it up (it has 4 screws in the corners under the front vinyl), and then I thought I saw a familiar part (STM8S0003F3) but it turned out it is powered by a Nuvouton MCU which is pin compatible with the STM8.

Since I have a quite few STM8s I have replaced the MCU, soldered the SWIM connector and populated the VCAP 100nF cap (marked with 104 on the silkscreen)

After a few hours and some STM8 development related rediscoveries I managed to get it rolling:
![The setup](docs/the_ultimate_hj_hacking_rig.jpg?raw=true "Setup")

I have included an STM8 CubeMX project as a reference for the pinout:
![Pinout](docs/cubemx.png?raw=true "Pinout")

## Features
At the moment two modes supported, you can switch between them by pressing the Select button:
 - 700 us - 2300 us with 10 ms interval "standard servo mode"
 - 1000us - 2000us with 2500 us interval "DJI mode"

### Adjusting limits:
* With Blank (0xFF filled) EEPROM the limits should be 1000us - 2000us respectively for the standard servo mode

* You can set separate limits for separate modes:

** To adjust the limits press the Pulse width button (type on the silkscreen) until the 'bot' text appear.

** Then push the PW button again and adjust the lower limit (500 us - 1500 us allowed).

** Once done with adjusting the minimum pulsewidth press the PW again and the 'toP' text will appear.

** Then push the PW button again and adjust the upper limit (1500 us - 3500 us allowed).

** Push the PW once again and your settings will be saved which is indicated with a blinking done text. 
 
## Toolchain info

STM8 Standard peripherial lib from ST

STVP + Cosmic (planning to port SDCC and use openOCD and GDB for debugging)

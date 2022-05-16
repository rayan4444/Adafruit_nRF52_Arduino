# Arduino Core for SIP Lab nRF52 Boards

This repository contains the Arduino board support pacakage for NRF52 based boards made at SIP Lab:

- [TapID Mainboard v3.0 (NRF52832)](https://github.com/eth-siplab-pcbs/TapID-mainboard-v3/tags)
- [TapID Mainboard v3.1 (NRF52840)]()

Support for the NRF52 official developement boards is also included:

- [Nordic nRF52840DK PCA10056](https://www.nordicsemi.com/Software-and-Tools/Development-Kits/nRF52840-DK)
- [Nordic nRF52832DK PCA10040](https://www.nordicsemi.com/Products/Development-hardware/nRF52-DK)

## BSP Installation

There are two methods that you can use to install this board support package.

### Recommended: Adafruit nRF52 BSP via the Arduino Board Manager

 1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (At least v1.6.12)
 2. Start the Arduino IDE
 3. Go into Preferences
 4. Add https://adafruit.github.io/arduino-board-index/package_adafruit_index.json as an 'Additional Board Manager URL'
 5. Restart the Arduino IDE
 6. Open the Boards Manager from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit'
 7. Once the BSP is installed, select 'Adafruit Feather nRF52840 Express' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the nRF52.

### Optional : if you want to add support for a new baord:

 1. Install BSP via Board Manager as above to install compiler & tools.
 2. Delete the core folder `nrf52` installed by Board Manager in Adruino15, depending on your OS. It could be
  * macOS  : `~/Library/Arduino15/packages/siplab/hardware/nrf52`
  * Linux  : `~/.arduino15/packages/siplab/hardware/nrf52`
  * Windows: `%APPDATA%\Local\Arduino15\packages\siplab\hardware\nrf52`
 3. `cd <SKETCHBOOK>`, where `<SKETCHBOOK>` is your Arduino Sketch folder:
  * macOS  : `~/Documents/Arduino`
  * Linux  : `~/Arduino`
  * Windows: `~/Documents/Arduino`
 4. Create a folder named `hardware/siplab`, if it does not exist, and change directories to it
 5. Clone this repo & its submodules:

   ```
   git clone https://github.com/adafruit/Adafruit_nRF52_Arduino.git
   cd Adafruit_nRF52_Arduino
   git submodule update --init
   ```
   
 6. Restart the Arduino IDE
 7. Once the BSP is installed, select 'Adafruit Feather nRF52840 Express' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the nRF52.

 8. Updating the package's archive and .json file
 * archive: ``` sudo tar -cvjSf packages_tapid_index.tar.bz2 * ```
 * SHA 256 checksum : ```shasum -a 256 package_tapid_index.tar.bz2```

### Flashing a board 

To flash the board you need to put the device in bootloader mode by pressing the reset button and flashing the program while the indication LED is slowly pulsating. Getting the timing right might need some practice :)

### Adafruit's nrfutil tools

This repository is based on the [Adafruit NRF52 Arduino](https://github.com/adafruit/Adafruit_nRF52_Arduino) one and uses the same core and tools. One such is [adafruit-nrfutil](https://github.com/adafruit/Adafruit_nRF52_nrfutil) (derived from Nordic [pc-nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil)): it is needed to upload sketch via serial port.

- For Windows and macOS, pre-built executable binaries are included at `tools/adafruit-nrfutil/`. It should work out of the box.
- Linux user need to run follow command to install it from PyPi

```
pip3 install adafruit-nrfutil --user
```

### Drivers

- [SiLabs CP2104 driver](http://www.silabs.com/products/mcu/pages/usbtouartbridgevcpdrivers.aspx) is required for USB to Serial when using with TapId Mainboard v3.0

## Bootloader

On a board that has never been programmed with Arduino before, you might need to install the bootloader. You can do so by connecting a programmer (using the debugging adapter) and choose the option "burn bootloader" in the Arduino IDE. 

The Arduino bootloader for the boards in this package is based on the (Adafruit NRF52 Arduino)[] bootloader. Support for the SIP lab boards was added in [this fork](https://github.com/rayan4444/Adafruit_nRF52_Bootloader) of the main repository. 

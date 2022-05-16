/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] = {
  // D0 - D7
  0,  // xtal 1
  1,  // xtal 2
  2,  // a0
  3,  // a1
  4,  // a2
  5,  // vbat
  6,  // RTS/I2C_SDA
  7,  // RXD

  // D8 - D13
  8,  // CTS/I2C_SCL

  9,  // GPIO9
  10, // GPIO10

  11, // GPIO11

  12, // GPIO12
  13, // SCK
  14, // MOSI

  15, // MISO
  16, // GPIO16

  // function set pins
  17, // GPIO17 
  18, // LED1
  19, // GPIO19
  20, // LED0
  21, // Reset
  22, // I2S_SCK
  23, // I2S_LRCK
  24, // I2S_SDOUT

  25, // LED4
  26, // GPIO26
  27, // LED2
  28, // BUTTON
  29, // GPIO29
  30, // GPIO30
  31, // GPIO31
};

void initVariant()
{
  // init LEDs
  pinMode(PIN_LED0, OUTPUT);
  ledOff(PIN_LED0);

  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);

  pinMode(PIN_LED3, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED4, OUTPUT);
  ledOff(PIN_LED2);

}


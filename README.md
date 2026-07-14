# 1.69" LCD Image Guide

Show any image on a 1.69" LCD display with Arduino.

## Display Specs

* Size: 1.69 inch
* Resolution: 240 × 280 px
* Interface: SPI
* Format: RGB565

## Steps

### 1. Resize the image

Go to:

https://www.iloveimg.com/resize-image

Resize your image to:

```text
240 × 280 px
```

Download the resized image.

### 2. Convert to RGB565

Go to:

http://www.rinkydinkelectronics.com/t_imageconverter565.php

Upload the resized image and convert it to RGB565 Arduino code.

### 3. Rename the file

Rename the downloaded file to:

```text
pic.c
```

Put `pic.c` in the same folder as your Arduino sketch.

### 4. Flash the Arduino

Open the Arduino code, connect your board, and upload the sketch.

Your image should now appear on the LCD.

# shuttercount_20d

Quick dirty C program written in a few minutes in nano on Linux to give you the shutter count from a Canon 20D RAW (CR2) image file of a Canon 20D EOS Camera.

The program opens, seeks to 0x95D, reads 2 bytes into an unsigned short, converts big-endian to little-endian and prints out the value which will be the shutter count.  Program does not check for valid 20D magic numbers or anything else....just quick and dirty.




#ifndef PREWITT_H
#define PREWITT_H

#include "../include/pixel.h"
#include "../include/bmpinfoheader.h"

#include <fstream>

PixelArray grayscale(std::ifstream& in, int height, int width);

PixelArray xMask(PixelArray pxArray, BmpInfoHeader infoHeader);
PixelArray yMask(PixelArray pxArray, BmpInfoHeader infoHeader);
PixelArray total(PixelArray GX, PixelArray GY, BmpInfoHeader infoHeader);

#endif

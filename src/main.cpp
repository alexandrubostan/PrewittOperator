#include "../include/pixel.h"
#include "../include/bmpfileheader.h"
#include "../include/bmpinfoheader.h"
#include "../include/prewitt.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

void writeFile(BmpFileHeader fileHeader, BmpInfoHeader infoHeader, PixelArray pxArray, std::string s) {
    std::ofstream out(s, std::ios::binary);
    if (!out) {
        std::cerr << "Cannot create file. Make sure the output folder is created.\n";
        return;
    }

    writeFileHeader(fileHeader, out);
    writeInfoHeader(infoHeader, out);

    uint8_t padding = (4 - (infoHeader.biWidth*3) % 4) % 4;

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            out << pxArray[i][j].B;
            out << pxArray[i][j].G;
            out << pxArray[i][j].R;
        }
        for (int y = 0; y < padding; y++) {
            out << 0;
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Give the file name as an argument. The file needs to be in the input folder.\n";
        return 1;
    } else if (argc != 2) {
        std::cerr << "Only 1 file name.\n";
        return 1;
    }

    std::string s = "./input/";
    s += argv[1];

    std::ifstream in(s, std::ios::binary);
    if (!in) {
        std::cerr << "Cannot open file. Make sure it's in the input folder.\n";
        return 1;
    }

    BmpFileHeader fileHeader = readFileHeader(in);
    BmpInfoHeader infoHeader = readInfoHeader(in);

    PixelArray pxArray = grayscale(in, infoHeader.biHeight, infoHeader.biWidth);

    //writeFile(fileHeader, infoHeader, pxArray, "./output/Grayscale.bmp");

    infoHeader.biHeight -= 2;
    infoHeader.biWidth -= 2;

    int newSize = floor(((24.0 * infoHeader.biWidth + 31) / 32) * 4);
    newSize *= infoHeader.biHeight;

    fileHeader.bfSize = newSize + fileHeader.bfOffBits;
    infoHeader.biSizeImage = newSize;

    PixelArray GX = xMask(pxArray, infoHeader);
    PixelArray GY = yMask(pxArray, infoHeader);
    PixelArray G = total(GX, GY, infoHeader);

    writeFile(fileHeader, infoHeader, GX, "./output/GX.bmp");
    writeFile(fileHeader, infoHeader, GY, "./output/GY.bmp");
    writeFile(fileHeader, infoHeader, G, "./output/G.bmp");
    return 0;
}
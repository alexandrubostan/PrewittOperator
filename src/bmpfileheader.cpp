#include "../include/bmpfileheader.h"

#include <fstream>
#include <iostream>

BmpFileHeader readFileHeader(std::ifstream& in) {
    BmpFileHeader fileHeader{};

    uint8_t buffer1 = 0;
    uint32_t buffer3 = 0;

    in.read((char*)&buffer1, sizeof(buffer1));
    fileHeader.bfType1 = buffer1;
    in.read((char*)&buffer1, sizeof(buffer1));
    fileHeader.bfType2 = buffer1;

    if (fileHeader.bfType1 != 0x42 && fileHeader.bfType2 != 0x4D) {
        std::cerr << "Invalid file format. File must be BMP\n";
        exit(1);
    }

    in.read((char*)&buffer3, sizeof(buffer3));
    fileHeader.bfSize = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    fileHeader.bfReserved = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    fileHeader.bfOffBits = buffer3;

    return fileHeader;
}

void writeFileHeader(BmpFileHeader fileHeader, std::ofstream& out) {
    out.write((char*)&fileHeader.bfType1, sizeof(fileHeader.bfType1));
    out.write((char*)&fileHeader.bfType2, sizeof(fileHeader.bfType2));
    out.write((char*)&fileHeader.bfSize, sizeof(fileHeader.bfSize));
    out.write((char*)&fileHeader.bfReserved, sizeof(fileHeader.bfReserved));
    out.write((char*)&fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));
}

#ifndef BMPFILEHEADER_H
#define BMPFILEHEADER_H

#include <cinttypes>
#include <fstream>

typedef struct BmpFileHeader{
    uint8_t bfType1;
    uint8_t bfType2;
    uint32_t bfSize;
    uint32_t bfReserved;
    uint32_t bfOffBits;
} BmpFileHeader;

BmpFileHeader readFileHeader(std::ifstream& in);
void writeFileHeader(BmpFileHeader header, std::ofstream& out);

#endif

#ifndef BMPINFOHEADER_H
#define BMPINFOHEADER_H

#include <cinttypes>
#include <fstream>

typedef struct BmpInfoHeader{
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BmpInfoHeader;

BmpInfoHeader readInfoHeader(std::ifstream& in);
void writeInfoHeader(BmpInfoHeader header, std::ofstream& out);

#endif

#include "../include/bmpinfoheader.h"

#include <fstream>

BmpInfoHeader readInfoHeader(std::ifstream& in) {
    BmpInfoHeader infoHeader;

    uint16_t buffer2;
    uint32_t buffer3;

    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biSize = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biWidth = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biHeight = buffer3;
    in.read((char*)&buffer2, sizeof(buffer2));
    infoHeader.biPlanes = buffer2;
    in.read((char*)&buffer2, sizeof(buffer2));
    infoHeader.biBitCount = buffer2;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biCompression = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biSizeImage = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biXPelsPerMeter = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biYPelsPerMeter = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biClrUsed = buffer3;
    in.read((char*)&buffer3, sizeof(buffer3));
    infoHeader.biClrImportant = buffer3;

    return infoHeader;
}

void writeInfoHeader(BmpInfoHeader infoHeader, std::ofstream& out) {
    out.write((char*)&infoHeader.biSize, sizeof(infoHeader.biSize));
    out.write((char*)&infoHeader.biWidth, sizeof(infoHeader.biWidth));
    out.write((char*)&infoHeader.biHeight, sizeof(infoHeader.biHeight));
    out.write((char*)&infoHeader.biPlanes, sizeof(infoHeader.biPlanes));
    out.write((char*)&infoHeader.biBitCount, sizeof(infoHeader.biBitCount));
    out.write((char*)&infoHeader.biCompression, sizeof(infoHeader.biCompression));
    out.write((char*)&infoHeader.biSizeImage, sizeof(infoHeader.biSizeImage));
    out.write((char*)&infoHeader.biXPelsPerMeter, sizeof(infoHeader.biXPelsPerMeter));
    out.write((char*)&infoHeader.biYPelsPerMeter, sizeof(infoHeader.biYPelsPerMeter));
    out.write((char*)&infoHeader.biClrUsed, sizeof(infoHeader.biClrUsed));
    out.write((char*)&infoHeader.biClrImportant, sizeof(infoHeader.biClrImportant));
}

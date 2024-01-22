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

void writeInfoHeader(BmpInfoHeader header, std::ofstream& out) {
    out.write((char*)&header.biSize, 4);
    out.write((char*)&header.biWidth, 4);
    out.write((char*)&header.biHeight, 4);
    out.write((char*)&header.biPlanes, 2);
    out.write((char*)&header.biBitCount, 2);
    out.write((char*)&header.biCompression, 4);
    out.write((char*)&header.biSizeImage, 4);
    out.write((char*)&header.biXPelsPerMeter, 4);
    out.write((char*)&header.biYPelsPerMeter, 4);
    out.write((char*)&header.biClrUsed, 4);
    out.write((char*)&header.biClrImportant, 4);
}

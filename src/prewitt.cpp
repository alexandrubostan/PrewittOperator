#include "../include/bmpfileheader.h"
#include "../include/bmpinfoheader.h"
#include "../include/pixel.h"

#include <cmath>

PixelArray grayscale(std::ifstream& in, int height, int width) {
    PixelArray pxArray(height, std::vector<Pixel>(width));

    uint8_t padding = (4 - (width * 3) % 4) % 4;
    uint8_t buffer = 0;
    double gray;

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            in.read((char*)&buffer, sizeof(buffer));
            gray = 0.07 * buffer;

            in.read((char*)&buffer, sizeof(buffer));
            gray += 0.72 * buffer;

            in.read((char*)&buffer, sizeof(buffer));
            gray += 0.21 * buffer;

            pxArray[i][j].B = round(gray);
            pxArray[i][j].G = pxArray[i][j].B;
            pxArray[i][j].R = pxArray[i][j].B;
        }
        in.ignore(padding);
    }
    return pxArray;
}

PixelArray xMask(PixelArray pxArray, BmpInfoHeader infoHeader) {
    const double gX[3][3] = {{1.0, 0, -1.0}, {1.0, 0, -1.0}, {1.0, 0, -1.0}};

    PixelArray GX(infoHeader.biHeight, std::vector<Pixel>(infoHeader.biWidth));

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            double sum = 0;

            for (int m = 2; m >= 0; m--) {
                for (int n = 0; n < 3; n++) {
                    sum += pxArray[i + m][j + n].R * gX[m][n];
                }
            }

            if (sum > 255)
                sum = 255;
            else if (sum < 0)
                sum = 0;

            GX[i][j].R = round(sum);
            GX[i][j].G = GX[i][j].R;
            GX[i][j].B = GX[i][j].R;
        }
    }
    return GX;
}

PixelArray yMask(PixelArray pxArray, BmpInfoHeader infoHeader) {
    const double gY[3][3] = {{1.0, 1.0, 1.0}, {0, 0, 0}, {-1.0, -1.0, -1.0}};

    PixelArray GY(infoHeader.biHeight, std::vector<Pixel>(infoHeader.biWidth));

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            double sum = 0;

            for (int m = 2; m >= 0; m--) {
                for (int n = 0; n < 3; n++) {
                    sum += pxArray[i + m][j + n].R * gY[m][n];
                }
            }

            if (sum > 255)
                sum = 255;
            else if (sum < 0)
                sum = 0;

            GY[i][j].R = round(sum);
            GY[i][j].G = GY[i][j].R;
            GY[i][j].B = GY[i][j].R;
        }
    }
    return GY;
}

PixelArray total(PixelArray GX, PixelArray GY, BmpInfoHeader infoHeader) {
    PixelArray G(infoHeader.biHeight, std::vector<Pixel>(infoHeader.biWidth));

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            double value = GX[i][j].R * GX[i][j].R;
            value += GY[i][j].R * GY[i][j].R;
            value = sqrt(value);

            G[i][j].R = round(value);
            G[i][j].G = G[i][j].R;
            G[i][j].B = G[i][j].R;
        }
    }
    return G;
}

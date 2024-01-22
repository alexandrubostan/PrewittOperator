#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>
#include <vector>

typedef struct Pixel{
    uint8_t R;
    uint8_t G;
    uint8_t B;
} Pixel;

using PixelArray = std::vector<std::vector<Pixel>>;

#endif

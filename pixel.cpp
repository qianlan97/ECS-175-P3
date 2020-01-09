//
//  pixel.cpp
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#include "polygon.h"
#include <iostream>

using namespace std;

void setPixel(float* PixelBuffer, Coordinate point, Coordinate viewport, float intensity) {
    int index = (point.y * viewport.x + point.x) * 3;
    PixelBuffer[index] = PixelBuffer[index+1] = PixelBuffer[index+2] = intensity;
}

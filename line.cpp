//
//  line.cpp
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#include "line.h"
#include "pixel.h"
#include <math.h>
#include "polygon.h"
#include <algorithm>
#include "pixel.h"
#include <iostream>

using namespace std;

void dda(float* PixelBuffer, Coordinate start, Coordinate end, Coordinate viewport) {

    int dx = end.x - start.x,
        dy = end.y - start.y,
        steps,
        k;
    float xIncrement, yIncrement, x = start.x, y = start.y;

    if (fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }

    xIncrement = float(dx) / float(steps);
    yIncrement = float(dy) / float(steps);

    Coordinate roundedStart(round(start.x), round(start.y), 0);
    setPixel(PixelBuffer, roundedStart, viewport, start.intensity);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        Coordinate point(round(x), round(y), 0);
        double intensity = 0;
        if (start.y != end.y) {
            // set intensities as lines are drawn
            intensity = ((end.y-point.y)/(end.y-start.y))*(start.intensity) + ((point.y-start.y)/(end.y-start.y))*(end.intensity);
        }
        setPixel(PixelBuffer, point, viewport, intensity);
    }

    Coordinate roundedEnd(round(end.x), round(end.y), 0);
    setPixel(PixelBuffer, roundedEnd, viewport, end.intensity);

}

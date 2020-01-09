//
//  rasterize.h
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifndef RASTERIZE_H
#define RASTERIZE_H

#include <vector>
#include "polygon.h"

using namespace std;

void rasterize(float* PixelBuffer, vector<Polygon> polygons, Coordinate viewport, int dimension, bool halftone);

#endif

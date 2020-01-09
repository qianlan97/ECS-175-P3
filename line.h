//
//  line.h
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifndef LINE_H
#define LINE_H

#include "polygon.h"

// DDA line drawing algorithm, pretty much copy-pasted from textbook page 134
void dda(float* PixelBuffer, Coordinate start, Coordinate end, Coordinate viewport);

#endif

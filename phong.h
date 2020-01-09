//
//  phong.h
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifndef PHONG_H
#define PHONG_H

#include <vector>
#include "polygon.h"

using namespace std;

Coordinate findCentroid(Polygon polygon);

double averageDistanceFromLightSource(vector<Polygon> polygon, Coordinate lightSource);

vector<double> phongIntensity(Polygon& polygon, int phongConstant, double ambient, double diffuse, double specular, double ambientIntensity, double sourceIntensity, Coordinate lightSource, Coordinate from, double averageDistance);

#endif

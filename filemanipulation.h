//
//  filemanipulation.h
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <vector>
#include "polygon.h"

using namespace std;

void readPolygons(char* fileName, vector<Polygon>& polygons);
void readEnvironment(char* fileName, int& phongConstant, double& ambient, double& diffuse, double& specular, double& ambientIntensity, double& sourceIntensity, float& lightSourceX, float& lightSourceY, float& lightSourceZ, float& fromX, float& fromY, float& fromZ);


#endif

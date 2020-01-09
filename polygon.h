//
//  polygon.h
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifndef POLYGON_H
#define  POLYGON_H

#include <vector>

using namespace std;

class Coordinate {
public:

    float x;
    float y;
    float z;
    double intensity;

    Coordinate();
    Coordinate(float x1, float y1, float z1);

};

class Triangle {
public:

    int v1;
    int v2;
    int v3;

    Triangle(int a, int b, int c);

};

class Polygon {
public:

    int numVertices;
    vector<Coordinate> vertices;
    int numTriangleFaces;
    vector<Triangle> triangleFaces;

    Polygon(int numVerts, vector<Coordinate> verts, int numTris, vector<Triangle> triFaces);

};

#endif

//
//  polygon.cpp
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#include "polygon.h"

#include <vector>

using namespace std;

Coordinate::Coordinate() {
    x = y = z = 0;
}

Coordinate::Coordinate(float x1, float y1, float z1) {
    x = x1;
    y = y1;
    z = z1;
}

Triangle::Triangle(int a, int b, int c) {
    v1 = a;
    v2 = b;
    v3 = c;
}

Polygon::Polygon(int numVerts, vector<Coordinate> verts, int numTris, vector<Triangle> triFaces) {
    numVertices = numVerts;
    vertices = verts;
    numTriangleFaces = numTris;
    triangleFaces = triFaces;
}

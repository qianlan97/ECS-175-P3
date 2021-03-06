//
//  filemanipulation.cpp
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#include "filemanipulation.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "polygon.h"
#include <string>

using namespace std;

void readPolygons(char* fileName, vector<Polygon>& polygons) {

    ifstream inputFile(fileName);
    string line;
    int numPolygons;

    // Get the number of polygons from the first line, then skip to description
    // of polygons
    inputFile >> numPolygons;
    getline(inputFile, line);
    getline(inputFile, line);

    // construct a Polygon object, one by one
    for (int i = 0; i < numPolygons; i++) {

        // Get current polygon's number of vertices
        int numVertices;
        inputFile >> numVertices;
        getline(inputFile, line);

        // Get coordinates of the current polygon's vertices
        vector<Coordinate> coordinates;
        for (int j = 0; j < numVertices; j++) {

            float float_x, float_y, float_z;
            string string_x, string_y, string_z;
            getline(inputFile, line);
            istringstream coordinate(line);
            getline(coordinate, string_x, ' ');
            getline(coordinate, string_y, ' ');
            getline(coordinate, string_z);
            float_x = stof(string_x);
            float_y = stof(string_y);
            float_z = stof(string_z);

            // Store current polygon's vertices info in a vector
            Coordinate point(float_x, float_y, float_z);
            coordinates.push_back(point);

        }

        // Get edges of current polygon
        int numTriangleFaces;
        inputFile >> numTriangleFaces;
        getline(inputFile, line);

        vector<Triangle> triangleFaces;
        for (int j = 0; j < numTriangleFaces; j++) {
            int int_v1, int_v2, int_v3;
            string string_v1, string_v2, string_v3;
            getline(inputFile, line);
            istringstream face(line);
            getline(face, string_v1, ' ');
            getline(face, string_v2, ' ');
            getline(face, string_v3);
            cout << string_v1 << string_v2 << "1" << string_v3 << endl;
            int_v1 = stoi(string_v1);
            int_v2 = stoi(string_v2);
            int_v3 = stoi(string_v3);

            // Store current polygon's vertices info in a vector
            Triangle triangle(int_v1, int_v2, int_v3);
            triangleFaces.push_back(triangle);

        }

        // Store current polygon's info in a vector
        Polygon polygon(numVertices, coordinates, numTriangleFaces, triangleFaces);
        polygons.push_back(polygon);

        // go to next Polygon
        getline(inputFile, line);
    }

}

void readEnvironment(char* fileName, int& phongConstant, double& ambient, double& diffuse, double& specular, double& ambientIntensity, double& sourceIntensity, float& lightSourceX, float& lightSourceY, float& lightSourceZ, float& fromX, float& fromY, float& fromZ) {

    ifstream inputFile(fileName);
    string line;

    getline(inputFile, line);
    phongConstant = stoi(line);

    getline(inputFile, line);
    istringstream coefficients(line);
    string string_ambient, string_diffuse, string_specular;
    getline(coefficients, string_ambient, ' ');
    getline(coefficients, string_diffuse, ' ');
    getline(coefficients, string_specular);
    ambient = stod(string_ambient);
    diffuse = stod(string_diffuse);
    specular = stod(string_specular);

    getline(inputFile, line);
    istringstream intensities(line);
    string string_source, string_ambientI;
    getline(intensities, string_source, ' ');
    getline(intensities, string_ambientI);
    sourceIntensity = stod(string_source);
    ambientIntensity = stod(string_ambientI);

    getline(inputFile, line);
    istringstream lightSource(line);
    string sourceX, sourceY, sourceZ;
    getline(lightSource, sourceX, ' ');
    getline(lightSource, sourceY, ' ');
    getline(lightSource, sourceZ);
    lightSourceX = stof(sourceX);
    lightSourceY = stof(sourceY);
    lightSourceZ = stof(sourceZ);

    getline(inputFile, line);
    istringstream from(line);
    string string_fromX, string_fromY, string_fromZ;
    getline(from, string_fromX, ' ');
    getline(from, string_fromY, ' ');
    getline(from, string_fromZ);
    fromX = stof(string_fromX);
    fromY = stof(string_fromY);
    fromZ = stof(string_fromZ);

}

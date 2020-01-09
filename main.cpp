//
//  main.cpp
//  ECS 175 P3
//
//  Created by Nan Chen on 11/11/19.
//  Copyright © 2019 Nan Chen. All rights reserved.
//

#ifdef WIN32
#include <windows.h>
#endif

#if defined (__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#else //linux
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <iostream>
#include "polygon.h"
#include "filemanipulation.h"
#include "pixel.h"
#include "line.h"
#include "rasterize.h"
#include "phong.h"
#include "rasterize.h"

float *PixelBuffer;
int width, height;
vector<Polygon> polygons;
void display();

int main(int argc, char *argv[])
{
    // viewport
    cout << "Enter the width of the display window: ";
    cin >> width;
    cout << "Enter the height of the display window: ";
    cin >> height;
	PixelBuffer = new float[width * height * 3];

    // read in polygon data from user input file
	readPolygons(argv[1], polygons);

    int phongConstant;
    double ambient, diffuse, specular, ambientIntensity, sourceIntensity;
    float lightSourceX, lightSourceY, lightSourceZ, fromX, fromY, fromZ;

    // read in environment data from user input file
    readEnvironment(argv[2], phongConstant, ambient, diffuse, specular, ambientIntensity, sourceIntensity, lightSourceX, lightSourceY, lightSourceZ, fromX, fromY, fromZ);

    Coordinate lightSource(lightSourceX, lightSourceY, lightSourceZ);
    Coordinate viewPoint(fromX, fromY, fromZ);
    double k = averageDistanceFromLightSource(polygons, lightSource);

    // calculate intensities at polygon vertices
    for (vector<Polygon>::iterator itr = polygons.begin(); itr != polygons.end(); itr++) {
        vector<double> intensities = phongIntensity(*itr, 4, 0.5, 0.25, 0.75, 5, 9,
                                lightSource, viewPoint, k);
    }

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(width/2, height/2);

	//create and set main window title
	glutCreateWindow("ECS175 Project 3");
	glClearColor(0, 0, 0, 0); //clears the buffer of OpenGL
	glutDisplayFunc(display);

	glutMainLoop();//main display loop, will display until terminate

	return 0;
}

//main display loop, this function will be called again and again by OpenGL
void display()
{
	//Misc.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

    bool halftone;
    cout << "Would you like to enable half tone? Enter 0 for no / 1 for yes: ";
    cin >> halftone;

    int projection;
    cout << "Which plane would you like to project to? Enter 0 for xy plane / 1 for yz plane / 2 for xz plane: ";
    cin >> projection;

    Coordinate viewport(width, height, 0);
    rasterize(PixelBuffer, polygons, viewport, projection, halftone);

	glDrawPixels(width, height, GL_RGB, GL_FLOAT, PixelBuffer);

    // clear
    for (int y = 0; y < viewport.y; y++) {
        for (int x = 0; x < viewport.x; x++) {
            int index = (y * viewport.x + x) * 3;
            PixelBuffer[index] = PixelBuffer[index+1] = PixelBuffer[index+2] = 0;
        }
    }

	glFlush();
    glutPostRedisplay();
}

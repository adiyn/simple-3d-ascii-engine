#ifndef SHAPES_H
#define SHAPES_H

#include "math_utils.h"

typedef struct Surface {
    Point3D** points;
} Surface;

typedef struct Cube {
    Point3D center;
    Surface *surfaces;
    int size;
} Cube;

typedef struct Triangle {
    Point3D center;
    Surface *surface;
    int height;
} Triangle;

Surface initSurface();
Cube initCube(double x, double y, double z);
void rotateCube(Cube* cube, double angleRad);
void freeCube(Cube cube);

#endif

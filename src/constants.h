#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>

#define SIDES 6.0
#define WIDTH_FIX 2.0
#define SCREEN_WIDTH 40.0
#define SCREEN_HEIGHT 20.0
#define FACE_SIZE 20.0
#define FOV_ANGLE 90.0
#define FOCAL_LENGTH ((SCREEN_WIDTH / 2) / tan((FOV_ANGLE / 2) * (M_PI / 180.0)))

#define EMPTY_POINT3D {-1,-1,-1}, -1.0
#define EMPTY_POINT2D {-1, -1}, -1.0
#define EMPTY_VECT3D -1, -1, -1
#define EMPTY_VECT2D -1, -1

#endif

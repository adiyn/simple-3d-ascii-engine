#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>

#define SIDES 6.0
#define WIDTH_FIX 2.0
#define SCREEN_WIDTH 120.0
#define SCREEN_HEIGHT 60.0
#define FACE_SIZE 40.0
#define FOV_ANGLE 120.0
#define FOCAL_LENGTH ((SCREEN_WIDTH / 2) / tan((FOV_ANGLE / 2) * (M_PI / 180.0)))

#define EMPTY_POINT3D {-1,-1,-1}, -1.0
#define EMPTY_POINT2D {-1, -1}, -1.0
#define EMPTY_VECT3D -1, -1, -1
#define EMPTY_VECT2D -1, -1

#ifdef __linux__
    #include <unistd.h>
#endif
#ifdef __WIN32
    #include <windows.h>
#endif
#endif


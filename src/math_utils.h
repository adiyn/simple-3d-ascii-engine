#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "constants.h"

typedef struct Vector2D {
    double x; double y;
} Vector2D;

typedef struct Vector3D {
    double x; double y; double z;
} Vector3D;

typedef struct Point3D {
    Vector3D vectPnt;
    double light_intensity;
} Point3D;

typedef struct Point2D {
    Vector2D vectPnt;
    double light_intensity;
} Point2D;

typedef struct Camera {
    Vector3D vectCam;
} Camera;

typedef struct LightSource {
    Vector3D vectLgt;
} LightSource;

Vector2D setVector2D(double x, double y);
Vector3D setVector3D(double x, double y, double z);
Point3D setPoint3D(double x, double y, double z);
Point2D setPoint2D(double x, double y);
double getRadius(double x, double y, double x1, double y1);
double distanceFromCamera(Point3D point, Camera camera);

Vector2D getVector2DFromVector3D(Vector3D vect, Camera camera);
Point2D getPoint2DFromPoint3D(Point3D p3D, Camera camera);
void setLightIntensity(Point3D *p3D, LightSource light);

#endif

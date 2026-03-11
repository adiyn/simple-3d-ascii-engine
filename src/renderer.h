#ifndef RENDERER_H
#define RENDERER_H

#include "shapes.h"

typedef struct Ray {
    Point3D origin;
    Vector3D vectDir;
    Point3D *points;
} Ray;

typedef struct RaycastResult {
    bool hit;
    Point3D hitCoordinate;
    Surface hitSurface;
} RaycastResult;

typedef struct Canvas {
    int size;
    char** grid;
    Point2D** points;
    double** zbuffer;
} Canvas;

Canvas initCanvas();
bool isRenderable(Surface surface, double x, double y);
bool doesRayIntersectSurface(Ray ray, Surface surface);
RaycastResult raycast(Ray ray, Surface surface, Cube cube, Camera camera);
void RenderWithLighting(Canvas canvas, Cube cube, Camera camera, LightSource light);
void RenderNaked(Canvas canvas, Cube cube, Camera camera);
void freeCanvas(Canvas canvas);
void freeAll(Canvas canvas, Cube cube);

#endif

#include "shapes.h"
#include <stdlib.h>
#include <math.h>

Surface initSurface()
{
    Surface surface;
    surface.points = (Point3D**)malloc(FACE_SIZE * sizeof(Point3D*));
    for (int i = 0; i < FACE_SIZE; i++) {
        surface.points[i] = (Point3D*)malloc(FACE_SIZE * WIDTH_FIX * sizeof(Point3D));
        for (int j = 0; j < FACE_SIZE * WIDTH_FIX; j++) {
            Point3D p = {EMPTY_POINT3D};
            surface.points[i][j] = p;
        }
    }
    return surface;
}

Cube initCube(double centerX, double centerY, double centerZ)
{
    Cube cube;
    cube.size = FACE_SIZE;
    cube.center = setPoint3D(centerX, centerY, centerZ);
    cube.surfaces = (Surface*)malloc(SIDES * sizeof(Surface));

    double stepU = (double)FACE_SIZE / ((double)FACE_SIZE * WIDTH_FIX - 1.0); // space between points adjusted for width
    double stepV = (double)FACE_SIZE / ((double)FACE_SIZE - 1.0);

    for (int s = 0; s < SIDES; s++) {
        cube.surfaces[s] = initSurface();
        for (int i = 0; i < FACE_SIZE; i++) {
            for (int j = 0; j < FACE_SIZE * WIDTH_FIX; j++) {
                
                double half = FACE_SIZE / 2.0;
                double u = -half + j * stepU;
                double v = -half + i * stepV;
                
                double x = 0, y = 0, z = 0;
                
                switch (s) {
                    case 0: 
                        x = centerX + u;
                        y = centerY + v; 
                        z = centerZ - half; 
                        break; // front
                    case 1:
                        x = centerX + u;
                        y = centerY + v;
                        z = centerZ + half;
                        break; // back
                    case 2:
                        x = centerX - half;
                        y = centerY + v;
                        z = centerZ + u;
                        break; // left
                    case 3:
                        x = centerX + half;
                        y = centerY + v;
                        z = centerZ + u;
                        break; // right
                    case 4:
                        x = centerX + u;
                        y = centerY - half;
                        z = centerZ + v;
                        break; // bottom
                    case 5:
                        x = centerX + u;
                        y = centerY + half; z = centerZ + v; break; // top
                }
                
                Point3D p3D = setPoint3D(x, y, z);
                cube.surfaces[s].points[i][j] = p3D;
            }
        }
    }
    return cube;
}

void initTriangle(double centerX, double centerY, double centerZ)
{

}

void rotateCube(Cube* cube, double angleRad) // magic
{
    for (int s = 0; s < SIDES; s++) {
        for (int i = 0; i < FACE_SIZE; i++) {
            for (int j = 0; j < FACE_SIZE * WIDTH_FIX; j++) {
                Point3D p = cube->surfaces[s].points[i][j];
                double x = p.vectPnt.x - cube->center.vectPnt.x;
                double z = p.vectPnt.z - cube->center.vectPnt.z;

                double rotatedX = x * sin(angleRad) - z * cos(angleRad);
                double rotatedZ = x * cos(angleRad) + z * sin(angleRad);

                cube->surfaces[s].points[i][j].vectPnt.x = rotatedX + cube->center.vectPnt.x;
                cube->surfaces[s].points[i][j].vectPnt.z = rotatedZ + cube->center.vectPnt.z;
            }
        }
    }
}

void freeCube(Cube cube)
{
    for (int s = 0; s < SIDES; s++) {
        for (int i = 0; i < FACE_SIZE; i++) {
            free(cube.surfaces[s].points[i]);
        }
        free(cube.surfaces[s].points);
    }
    free(cube.surfaces);
}

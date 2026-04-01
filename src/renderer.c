#include "renderer.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

Canvas initCanvas()
{
    Canvas canvas;
    canvas.size = (int)SCREEN_WIDTH * (int)SCREEN_HEIGHT;
    canvas.grid = (char**)malloc(SCREEN_HEIGHT * sizeof(char*));
    canvas.points = (Point2D**)malloc(SCREEN_HEIGHT * sizeof(Point2D*));
    canvas.zbuffer = (double**)malloc(SCREEN_HEIGHT * sizeof(double*)); // z-buffer to keep depth info
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        canvas.grid[i] = (char*)malloc(SCREEN_WIDTH * sizeof(char));
        canvas.points[i] = (Point2D*)malloc(SCREEN_WIDTH * sizeof(Point2D));
        canvas.zbuffer[i] = (double*)malloc(SCREEN_WIDTH * sizeof(double));
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            canvas.grid[i][j] = ' ';
            canvas.points[i][j] = (Point2D) {EMPTY_POINT2D};
            canvas.zbuffer[i][j] = 1e9;
        }
    }
    return canvas;
}

bool isRenderable(Surface surface, double x, double y)
{
    Point3D p = surface.points[(int)x][(int)y];
    return !(p.vectPnt.x == -1 && p.vectPnt.y == -1 && p.vectPnt.z == -1);
}

bool doesRayIntersectSurface(Ray ray, Surface surface)
{
    return false; // TODO
}

RaycastResult raycast(Ray ray, Surface surface, Cube cube, Camera camera)
{
    RaycastResult result = {false, {{0, 0, 0}, 0.0}, surface};
    return result; // TODO
}

void RenderWithLighting(Canvas canvas, Cube cube, Camera camera, LightSource light)
{
    // TODO
}

void emptyCanvas(Canvas canvas)
{
    for (int i=0; i<SCREEN_HEIGHT; i++) {
        for (int j=0; j<SCREEN_WIDTH; j++) {
            canvas.grid[i][j] = ' ';
            canvas.zbuffer[i][j] = 1e9; // send it to the mariana trench 
        }
    }
}

void clearScreen() {
    fputs("\x1b[2J\x1b[H", stdout);
}

void RenderNaked(Canvas canvas, Cube cube, Camera camera)
{
    int frame = 0;
    while (1) {
        emptyCanvas(canvas);
        
        for (int s = 0; s < SIDES; s++) {
            for (int i = 0; i < FACE_SIZE; i++) {
                for (int j = 0; j < FACE_SIZE * WIDTH_FIX; j++) {
                    Point3D p3D = cube.surfaces[s].points[i][j];
                    Point2D p2D = getPoint2DFromPoint3D(p3D, camera);
                    
                    if (!isRenderable(cube.surfaces[s], i, j)) continue; // don't draw stuff u can't see duh

                    int screenX = (int)(p2D.vectPnt.x + (SCREEN_WIDTH / 2.0));
                    int screenY = (int)(p2D.vectPnt.y + (SCREEN_HEIGHT / 2.0));

                    if (screenX >= 0 && screenX < SCREEN_WIDTH && screenY >= 0 && screenY < SCREEN_HEIGHT) { // inbounds
                        if (p3D.vectPnt.z < canvas.zbuffer[screenY][screenX]) { // if the new point is in front of the old one then :
                            if (i==0 || i==FACE_SIZE-1 || j==0 || j==(int)(FACE_SIZE * WIDTH_FIX)-1) {
                                canvas.grid[screenY][screenX] = '#'; // vertices
                            } else {
                                canvas.grid[screenY][screenX] = '*'; // surfaces
                            }
                            canvas.zbuffer[screenY][screenX] = p3D.vectPnt.z; // update the zbuffer with the new point's z value
                        }
                    }
                }
            }
        }

        printf("frame number : %d\n", frame++); // frame counter

        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                putchar(canvas.grid[y][x]);
            }
            putchar('\n');
        }

        #ifdef _WIN32
        clearScreen();
        #endif
        #ifdef __linux__
        printf("\033[2J\033[H");
        #endif

        rotateCube(&cube, 0.01);
    }
}

void freeCanvas(Canvas canvas)
{
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        free(canvas.grid[i]);
        free(canvas.points[i]);
        free(canvas.zbuffer[i]);
    }
    free(canvas.grid);
    free(canvas.points);
    free(canvas.zbuffer);
}

void freeAll(Canvas canvas, Cube cube) { // thanos snap
    freeCanvas(canvas);
    freeCube(cube);
}
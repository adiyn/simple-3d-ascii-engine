#include "src/constants.h"
#include "src/shapes.h"
#include "src/renderer.h"
#include "src/math_utils.h"

int main()
{
    Canvas canvas = initCanvas();
    Cube cube = initCube(0, 0, 0);
    Camera camera = {{0, -5, -60}};

    while (1) {
        RenderNaked(canvas, cube, camera);
    }

    freeAll(canvas, cube);
    return 0;
}
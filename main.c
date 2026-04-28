#include "src/constants.h"
#include "src/shapes.h"
#include "src/renderer.h"
#include "src/math_utils.h"

int main()
{
    pid_t child_pid = fork();
    char userinput[1024];
    
    /*for (;;) {
        fgets(userinput, sizeof(userinput), stdin);
        if (strcmp(userinput, "stop\n") == 0) {
            kill(child_pid, SIGSTOP);
            break;
        }
    }*/

    Canvas canvas = initCanvas();
    Cube cube = initCube(0, 0, 0);
    Camera camera = {{0, -5, -60}};

    while (1) {
        RenderNaked(canvas, cube, camera);
    }

    freeAll(canvas, cube);
    return 0;
}
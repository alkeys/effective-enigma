
#include <GL/freeglut_std.h>
#include "bandera.h"
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500,200);
    glutInitWindowSize(600,600);
    //glClearColor(0.8, 0, 0, 1);

    inicializar_escudo();
    glutDisplayFunc(dibujar_bandera);
    glutMouseFunc(mouseEvent);
    glutMainLoop();
    return (EXIT_SUCCESS);

}

//
// Created by alex on 11/05/23.
//

#include <GL/gl.h>
#include "GL/glut.h"
#include "bandera.h"
#include "math.h"
#include <stdio.h>

void franjas();

void dda(float x1, float y1, float x2, float y2, int puntosize, float R, float G, float B);

void punto(int x, int y, int ir, int iy, float R, float G, float B);

void crearCirculo(float x, float y, int r, int points, float R, float G, float B);

void parabola(int x, int y, float sizevert, float pos, int size, int caso, float R, float G, float B);

void puntosolo(int x, int y, int puntosize, float R, float G, float B);

void mediocirculo(int x, int y, int sizepoint, int size, int seg);

void letraD(int, int, int, float, float R, float G, float B);

void letraI(int, int, int, float R, float G, float B);

void letraS(int, int, int, float R, float G, float B);

void letraO(int, int, int, float R, float G, float B);

void letraU(int, int, int, float R, float G, float B);

void letraN(int, int, int, float R, float G, float B);

void tilde(int, int, int, float R, float G, float B);

void inicializar_escudo() {
    glutCreateWindow("AM18007");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

void dibujar_bandera() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 0.76, 0.4, 1);
    franjas();
    /*letraD(100,100);*/
    letraD(37, 290, 4, 1, 1, 0.63, 0);
    letraI(80, 290, 2, 1, 0.63, 0);
    letraO(122, 303, 18, 1, 0.63, 0);
    letraS(160, 310, 10, 1, 0.63, 0);
    letraU(200, 295, 3, 1, 0.63, 0);
    letraN(230, 295, 4, 1, 0.63, 0);
    letraI(260, 290, 2, 1, 0.63, 0);
    letraO(300, 303, 18, 1, 0.63, 0);
    glFlush();
}


void letraD(int x, int y, int puntosize, float tam, float R, float G, float B) {

    //punto
/*    puntosolo(x + (10 * tam), y + (13 * tam), puntosize + (21 * tam), R, G, B);*/
    //Dibuja la parte vertical de la letra D
    dda(x, y, x, y + (25 * tam), puntosize, R, G, B);
    //parte orizontal
    dda(x, y + (25 * tam), x + (20 * tam), y + (25 * tam), puntosize, R, G, B);
    dda(x, y, x + (20 * tam), y, puntosize, R, G, B);
    //parte de el circulo xd
    parabola(x + (25 * tam), y + (12 * tam), puntosize, -0.5, (12 * tam), 1, R, G, B);

}

void letraI(int x, int y, int puntosize, float R, float G, float B) {
    //letra I
    ///////parte de abajo
    //parte abajo
    dda(x, y - 1, x + 20, y - 1, puntosize, R, G, B);
    //pate abajo color
    dda(x, y + 1, x + 20, y + 1, puntosize, R, G, B);
    //parte de arriba
    dda(x, y + 2, x + 20, y + 2, puntosize, R, G, B);
    //lados
    dda(x, y - 1, x, y + 2, puntosize, R, G, B);
    dda(x + 19, y - 1, x + 19, y + 2, puntosize, R, G, B);
    //////////////////
    /////parte de enmedio la recta
    dda(x + 9, y + 2, x + 9, y + 25, puntosize, R, G, B);//color
    dda(x + 8, y + 2, x + 8, y + 25, puntosize - 1, R, G, B);
    dda(x + 10, y + 2, x + 10, y + 25, puntosize - 1, R, G, B);
    /////parte de arriba
    dda(x, y + 24, x + 20, y + 24, puntosize, R, G, B);
    //pate abajo color
    dda(x, y + 25, x + 20, y + 25, puntosize, R, G, B);
    //parte de arriba
    dda(x, y + 26, x + 20, y + 26, puntosize, R, G, B);
    //lados
    dda(x, y + 24, x, y + 26, puntosize, R, G, B);
    dda(x + 19, y + 24, x + 19, y + 26, puntosize, R, G, B);
}

void letraO(int x, int y, int size, float R, float G, float B) {
    crearCirculo(x, y, size, 2, R, G, B);
    crearCirculo(x, y, size - 2, 2, R, G, B);
}

void letraS(int x, int y, int puntosize, float R, float G, float B) {
    glPointSize(3);
    crearCirculo(x, y, puntosize, 3, R, G, B);
    crearCirculo(x, y - 15, puntosize, 3, R, G, B);
//punto y corte de arriba
    puntosolo(x + 15, y + 4, puntosize + 5, 1, 1, 1);
    puntosolo(x + 8, y - 5, puntosize - 4, 1, 1, 1);
    dda(x + 6, y + 8, x + 6, y + 12, puntosize / 5, R, G, B);
    //parte de abajo
    puntosolo(x - 14, y - 20, puntosize + 6, 1, 1, 1);
    puntosolo(x - 6, y - 11, puntosize - 4, 1, 1, 1);
    dda(x - 6, y - 15, x - 6, y - 25, puntosize / 5, R, G, B);
}

void letraU(int x, int y, int puntosize, float R, float G, float B) {
    dda(x - 5, y + 5, x - 5, y + 20, puntosize, R, G, B);
    dda(x + 14, y + 5, x + 14, y + 20, puntosize, R, G, B);
    parabola(x + 5, y - 5, puntosize, 1, 10, 0, R, G, B);
    dda(x - 7, y + 20, x - 2, y + 20, puntosize, R, G, B);
    dda(x + 11, y + 20, x + 17, y + 20, puntosize, R, G, B);
}

void letraN(int x, int y, int puntosize, float R, float G, float B) {
    dda(x, y - 5, x, y + 20, puntosize, R, G, B);
    dda(x + 20, y - 5, x + 20, y + 20, puntosize, R, G, B);
    dda(x, y + 20, x + 20, y - 5, puntosize, R, G, B);
    /////parte de arriba
    dda(x - 2, y + 20, x, y + 20, puntosize, R, G, B);
    dda(x + 15, y + 20, x + 25, y + 20, puntosize, R, G, B);
    ////parte de abajo
    dda(x - 5, y - 5, x + 5, y - 5, puntosize, R, G, B);
}


void franjas() {
    for (int i = 600; i > 400; --i) {
        dda(0, i, 600, i, 12, 0, 0, 1);
    }
    for (int i = 400; i > 200; --i) {
        dda(0, i, 600, i, 12, 1, 1, 1);
    }
    for (int i = 200; i > 0; --i) {
        dda(0, i, 600, i, 12, 0, 0, 1);
    }
}

/**
 *
 * @param x1 cordenada 1
 * @param y1 cordenada 1
 * @param x2 cordenada 2
 * @param y2 cordenada 2
 * @param puntosize tamano de punto
 * @param R color
 * @param G color
 * @param B color
 */
void dda(float x1, float y1, float x2, float y2, int puntosize, float R, float G, float B) {
    /**
     * algoritmo dda echo en c para lineas
     */
    float dx = x2 - x1;
    float dy = y2 - y1;
    float pasos, xIncrementos, yIncrementos, x = x1, y = y1;
    pasos = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    xIncrementos = dx / pasos;
    yIncrementos = dy / pasos;
    glPointSize(puntosize);
    glBegin(GL_POINTS);
    glColor3f(R, G, B);
    for (float i = 0; i < pasos; i++) {
        glVertex2f(x, y);
        x += xIncrementos;
        y += yIncrementos;
    }
    glEnd();
}


/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param puntosize tamano de punto
 * @param R color
 * @param G color
 * @param B color
 */
void puntosolo(int x, int y, int puntosize, float R, float G, float B) {
    glColor3f(R, G, B);
    glPointSize(puntosize);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void mouseEvent(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        printf("x= %i  y= %i ", x, (600 - y));
        glFlush();
    }

}


/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param sizevert tamano de picel
 * @param pos pocicion de habertura tanto < 0 = habertura a la izquierda
 *          >0 habertura acia derecha
 * @param size tamano
 * @param caso dos posibles casos 0 y 1 0=habertura vertical 1=havertura horizontal
 * @param R color
 * @param G color
 * @param B color
 */
void parabola(int x, int y, float sizevert, float pos, int size, int caso, float R, float G, float B) {
    glPointSize(sizevert);
    glBegin(GL_POINTS);
    glColor3f(R, G, B);
    switch (caso) {
        case 0:
            for (float x1 = -size; x1 <= size; x1 += 0.01) {
                float y1 = pos * x1 * x1 / size;
                glVertex2f(x + x1, y + y1);
            }
            break;
        case 1:
            for (float x1 = -size; x1 <= size; x1 += 0.1) {
                float y1 = pos * x1 * x1 / size;
                glVertex2f(x + y1, y + x1);
            }

            break;
    }
    glEnd();
}


void crearCirculo(float x, float y, int r, int pointsize, float R, float G, float B) {
//formula x2+y2=r2
//y=sqrt(r2-x2)
    r -= 2;

    double margenRadio, x2, y2;
    float abancePixel = 0.001;
    glColor3f(R, G, B);
    glPointSize(pointsize);
    glBegin(GL_POINTS);
    for (float i = -1; i < r; i += abancePixel) {
        margenRadio = (sqrt(pow(r, 2) - pow(i, 2)));

        //para el cuadrante 1 y 3
        glVertex2f(x + i, y + margenRadio);
        glVertex2f(x - i, y - margenRadio);
        //////////////
        //cuaqdrante 2 y 4
        glVertex2f(x - i, y + margenRadio);
        glVertex2f(x + i, y - margenRadio);
    }
    glEnd();
}

/**
 *
 * @param x cordenada origen
 * @param y cordenada origen
 * @param pos posicion de verticar si > 0 y si es < 0 orizontal
 * @param cantCur cantidad de curvas
 * @param R color
 * @param G color
 * @param B color
 */
void grafisin(int x, int y, int pos, float cantCur, float R, float G, float B) {
    int xAux = x;
    double curva;
    double curva2;
    glBegin(GL_POINTS);
    glColor3f(R, G, B);
    for (float x1 = -1.0f; x1 < cantCur * 6; x1 += 0.9) {
        curva = y + sin(2 * M_PI * x + x1) * 4;
        curva2 = x + x1 * 6;
        if (pos < 0) {
            glVertex2f(curva, curva2);
            //crearCirculo(curva, curva2, 5, R, G, B);
        } else {
            glVertex2f(curva2, curva);
            // crearCirculo(curva2, curva, 4, R, G, B);
        }
    }
    glEnd();
}


/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param size tamaño
 * @param seg segmentos de divicion
 */
void mediocirculo(int x, int y, int sizepoint, int size, int seg) {
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(0.11, 0.67, 0.24);
    float radio = size; // Radio del círculo
    int num_segmentos = 365; // Número de segmentos para aproximar el círculo
    for (int i = 0; i <= num_segmentos; i++) {
        float angulo = i * (M_PI / (num_segmentos * seg)); // Ángulo del segmento actual
        float fx = radio * cos(angulo); // Coordenada x del vértice actual
        float fy = radio * sin(angulo); // Coordenada y del vértice actual
        glVertex2f(x + fx, y + fy);
        glVertex2f(x - fx, y + fy);
        glVertex2f(x + fx, y - fy);
        glVertex2f(x - fx, y - fy);
        glVertex2f(x + fy, y - fx);
        glVertex2f(x - fy, y - fx);
    }
    glEnd();
}


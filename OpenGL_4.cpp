#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

void display()
{
    int x1 = 100, y1 = 100, z1 = 100;
    int x2 = -100, y2 = -100, z2 = -100;
    int x = 0, y = 0, z = 0;    //основные координаты
    int sumx = 0, sumy = 0, sumz = 0, r = 0, m = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(25, 1, 1, 0);

    //Рисуем куб
    glBegin(GL_LINE_STRIP);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(x2, y2, z1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glEnd();
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();

    //Цикл проверяет где находится точка и выходит, если точка приблизилась к крани
    while(sumx < x1 - 5 && sumx > x2 + 5 && sumy < y1 - 5 && sumy > y2 + 5 && sumz < z1 - 5 && sumz > z2 + 5){
        glBegin(GL_POINTS);
        r = rand()%8;       //выбираем случайно возможный путь
        if(x1 - x < y1 - y && x1 - x < z1 - z && x1 - x < (abs(x2-x)) && x1 - x < (abs(y2 - y)) && x1 - x < (abs(z1 - z))){        //1 минимальное расстояние до грани х
            m = x1 - x + 1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
            if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
        else if(y1 - y < x1 - x && y1 - y < z1 - z && y1 - y < (abs(x2-x)) && y1 - y < (abs(y2 - y)) && y1 - y < (abs(z1 - z))){        //2 минимальное расстояние до грани y
            m = y1 - y + 1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
            if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
        else if(z1 - z < y1 - y && z1 - z < x1 - x && z1 - z < (abs(x2-x)) && z1 - z < (abs(y2 - y)) && z1 - z < (abs(z1 - z))){        //3 минимальное расстояние до грани z
            m = z1 - z +1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
            if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
        else if((abs(x2-x)) < x1 - x && (abs(x2-x)) < y1 - y && (abs(x2-x)) < z1 - z && (abs(x2-x)) < (abs(y2 - y)) && (abs(x2-x)) < (abs(z1 - z))){        //4 минимальное расстояние до грани -х
            m = (abs(x2-x)) + 1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
            if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
        else if((abs(y2-y)) < x1 - x && (abs(y2-y)) < y1 - y && (abs(y2-y)) < z1 - z && (abs(y2-y)) < (abs(x2 - x)) && (abs(y2-y)) < (abs(z2 - z))){        //5 минимальное расстояние до грани -y
            m = (abs(y2-y)) + 1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
            if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
 //       else if((abs(z2-z)) < x1 - x && (abs(z2-z)) < y1 - y && (abs(z2-z)) < z1 - z && (abs(z2-z)) < (abs(y2 - y)) && (abs(z2-z)) < (abs(x2 - x))){        //6 минимальное расстояние до грани -z
            else{
            m = (abs(x2-x))+1;
            x = x + rand()%m; y = y + rand()%m; z = z + rand()%m;
             if(r == 0){
                glVertex3f(x,y,z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 1){
                glVertex3f(x,y,-z);
                sumx = sumx+x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 2){
                glVertex3f(x,-y,z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 3){
                glVertex3f(x,-y,-z);
                sumx = sumx+x; sumy=sumy-y; sumz=sumz-z;
            }
            else if(r == 4){
                glVertex3f(-x,y,z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz+z;
            }
            else if(r == 5){
                glVertex3f(-x,y,-z);
                sumx = sumx-x; sumy=sumy+y; sumz=sumz-z;
            }
            else if(r == 6){
                glVertex3f(-x,-y,z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz+z;
            }
            else if(r == 7){
                glVertex3f(-x,-y,-z);
                sumx = sumx-x; sumy=sumy-y; sumz=sumz-z;
            }
        }
        glEnd();
    }
    glutSwapBuffers();  //glFlush для одного буфера glutSapBuffers для 2-х
}

//void timer(int)
//{
//    glBegin(GL_POINTS);
//    glVertex3f(x, y, z);
//    glEnd();
//    glutTimerFunc(500, timer, 0);
//}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //два буфера 1 для рисования, 1 для вычислений
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(20, 810);
    glutCreateWindow("Cube");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -200, 200);
    glutDisplayFunc(display);
    //glutTimerFunc(500, timer, 0);
    glutMainLoop();
}

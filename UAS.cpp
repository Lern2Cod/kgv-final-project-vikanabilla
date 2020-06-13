#include<Windows.h>
#include<gl/glut.h>

int w = 1000, h = 1000 , z = -200;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;

void piramida() {
    glPushMatrix();
    glColor3ub(176, 117, 54);  //alas bawah
    glTranslatef(-10, -10, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(5, 5, 0.5);
    glutSolidCube(25);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(179, 116, 53);  //alas 2
    glTranslatef(-10, -1, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(4.8, 4.8, 0.5);
    glutSolidCube(23);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(182, 119, 53);  //alas 3
    glTranslatef(-10, 8, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(4.6, 4.6, 0.5);
    glutSolidCube(21);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(182, 119, 53);  //alas 4
    glTranslatef(-10, 17, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(4.4, 4.4, 0.5);
    glutSolidCube(19);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(185, 122, 53);  //alas 5
    glTranslatef(-10, 27, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(4.2, 4.2, 0.5);
    glutSolidCube(17);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(185, 122, 53);  //alas 6
    glTranslatef(-10, 35, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(4, 4, 0.5);
    glutSolidCube(15);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(189, 126, 53);  //alas 7
    glTranslatef(-10, 42, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(3.8, 3.8, 0.5);
    glutSolidCube(13);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(189, 126, 53);  //alas 8
    glTranslatef(-10, 48, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(3.6, 3.6, 0.5);
    glutSolidCube(11);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(193, 130, 53);  //alas 9
    glTranslatef(-10, 53, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(3.4, 3.4, 0.5);
    glutSolidCube(9);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(193, 130, 53);  //alas 10
    glTranslatef(-10, 57, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(3.2, 3.2, 0.5);
    glutSolidCube(7);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(197, 134, 53);  //alas 11
    glTranslatef(-10, 60, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(3, 3, 0.5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(197, 134, 53);  //alas 12
    glTranslatef(-10, 62, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(2.8, 2.8, 0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(199, 136, 53);  //alas 13
    glTranslatef(-10, 63, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(2.6, 2.6, 0.5);
    glutSolidCube(2);
    glPopMatrix();
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(10, 0, z);
    glRotatef(sudut, x1, y1, z1);
    piramida();
    glutSwapBuffers();
}

void resize(int w1, int h1) {
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeyboard(unsigned char key, int x, int y) {
    if (key == '=')
        z += 5;
    else if (key == '-')
        z -= 5;
    else if (key == 'y') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += 10;
    }
    else if (key == 't') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += -10;
    }
    else if (key == 'x') {
        x1 = 0;
        y1 = 1;
        z1 = 0;
        sudut += -10;
    }
    else if (key == 'c') {
        x1 = 0;
        y1 = 1;
        z1 = 0;
        sudut += 10;
    }
    else if (key == 'z') {
        x1 = 0;
        y1 = 0;
        z1 = 1;
        sudut += -10;
    }
}

void init() {
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Piramida");
    gluOrtho2D(-w, w, -h, h);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboard);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
}
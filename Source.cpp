#include <Windows.h>;
#include <glut.h>;
#include <math.h>;

void init() {
    glClearColor(0.68, 0.85, 0.9, 1.0); // Set clear color to white
}

void reshape(int w, int h) {
    glViewport(0.0, 0.0, w, h);
    if (h == 0) {
        h = 1;
    }
    float aspect_ratio = (float)w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w >= h) {
        gluOrtho2D(-10.0*aspect_ratio, 10.0* aspect_ratio, -10.0, 10.0); // Define your coordinate system
        //left right top bottom
    }
    else {
        gluOrtho2D(-10.0, 10.0, -10.0/aspect_ratio, 10.0/aspect_ratio);
    }
    glClear(GL_COLOR_BUFFER_BIT);

}

void drawWheelPoke(float radius,int n) {
    glLineWidth(5);
    glBegin(GL_LINES);
    for (int i = 0; i <= n; ++i) {
        float angle = 2 * 3.14 * i / n;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
        glVertex2f(0, 0);
    }
    glEnd();
}
 
void drawCircle(float radius, int n) {

    // Draw n-sided regular polygon (circle approximation) here
    glBegin(GL_POLYGON);
    for (int i = 0; i<=n; ++i) {
        float angle = 2 * 3.14 * i / n;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void displayWheel() {
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(6.5, 32);
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(5.0, 32);
    glColor3f(0.0, 0.0, 0.0);
    drawWheelPoke(5.0, 8);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(1.25, 32);
    glFlush();
}

void main(int argsc, char** argsv) {
    glutInit(&argsc, argsv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(720, 480);
    glutCreateWindow("OpenGL Wheel");
    init();
    //create graphic
    glutDisplayFunc(displayWheel);
    glutReshapeFunc(reshape);
    glutMainLoop();

}
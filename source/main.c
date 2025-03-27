#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <windows.h>

#include "headers/graphics.h"
#include "headers/gameMath.h"

#include "headers/simulation/simulation.h"

//Key input setup
#define KEY_COUNT 256 

bool keys[KEY_COUNT];

//Game values (non customizable)
float CENTER_X = (WINDOW_W / 2);
float CENTER_Y = (WINDOW_H / 2);

void init()
{
  glClearColor(0, 0, 0, 0);

  RandomInitialization();

  Start();

  gluOrtho2D(0, WINDOW_W, WINDOW_H, 0);
}

void display() 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



  glutSwapBuffers();
}

void keyDown(unsigned char key, int x, int y) 
{
  keys[key] = true; 
}

void keyUp(unsigned char key, int x, int y) 
{
  keys[key] = false; 
}

double lastTime = 0;
double deltaTime = 0;

void update()
{
  
  // Frame rate timer, which computes delta time and passes it to the simulation for further processing

  // needs to be improved heavily for more stability, but is a good foundation

  double currentTime = glutGet(GLUT_ELAPSED_TIME); 
  deltaTime = (currentTime - lastTime) / 1000.0; 

  if (deltaTime < FRAME_TIME / 1000.0) 
  {

    double sleepTime = (FRAME_TIME / 1000.0) - deltaTime;

    if (sleepTime > 0) 
    {

      int sleepMs = (int)(sleepTime * 1000);
      
      #ifdef _WIN32

        Sleep(sleepMs); // Windows version

      #else

        usleep(sleepMs * 1000); // Linux/macOS version

      #endif

    }
    
  }

  lastTime = glutGet(GLUT_ELAPSED_TIME);

  Update(deltaTime);
  glutPostRedisplay(); 

}

void windowResize(int width, int height)
{
  glutReshapeWindow(WINDOW_W, WINDOW_H);
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);    

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);        
  glutInitWindowSize(WINDOW_W, WINDOW_H);        
    
  glutCreateWindow("Simulation");  

  init();

  for (int i = 0; i < KEY_COUNT; i++) 
  {
    keys[i] = false;
  }

  glutDisplayFunc(display); 
  glutIdleFunc(update);      

  glutKeyboardFunc(keyDown);  
  glutKeyboardUpFunc(keyUp);  

  glutReshapeFunc(windowResize);

  glutMainLoop();      
  return 0;   
}
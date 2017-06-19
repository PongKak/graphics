#pragma once

#include <windows.h>
#include <math.h>
#include <gl/glut.h>
#include "gltools.h"
#include <vector>

#define GL_PI 3.141592f

struct box
{
	GLfloat xPos;
	GLfloat yPos;
	GLfloat Size;
	GLfloat xStep;
	GLfloat yStep;
	GLfloat colorR;
	GLfloat colorG;
	GLfloat colorB;
}Box;



void SetupRC();
void RenderScene();

void ContorolKey(int key, int x, int y);

void ChangeSize(int w, int h);

void TimerFunc(int value);
void LoadTexture(std::string textureName);

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zDistance = 0.0f;		///ADD


GLfloat windowWidth;
GLfloat windowHeight;

int numOfBox = 0;

void CreateBox();
void CheckColide(box*);
void MoveBox();
bool CheckCreatable(box*);

std::vector<box*> boxVector;

GLuint texID;
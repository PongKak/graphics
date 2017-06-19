#include "test.h"
#include "lodepng.h"
void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);


	glEnable(GL_LIGHTING);

	GLfloat ambienLight[] = { 0.5f,0.5f,0.5f,1.0f };
	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
	glLightfv(GL_LIGHT0,GL_AMBIENT, ambienLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}


// Called to draw scene
void RenderScene(void)
{

	static GLfloat fElect1 = 0.0f;
	static GLfloat fElect2 = 0.0f;
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	xRot = 0.0f;
	yRot = 0.0f;


	glMatrixMode(GL_MODELVIEW);
	
	//태양
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -100.0f);
	glColor3f(1.0f, 0.0f, 0.0f);

	GLUquadric* sun = gluNewQuadric();
	gluQuadricDrawStyle(sun, GLU_FILL);
	gluQuadricTexture(sun, GL_TRUE);
	gluQuadricNormals(sun, GLU_SMOOTH);
	gluSphere(sun, 30, 15, 15);
	LoadTexture("planet3.png");

	glBindTexture(GL_TEXTURE_2D, texID);

	//지구
	glPushMatrix();
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(200.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	GLUquadric* earth = gluNewQuadric();
	gluQuadricDrawStyle(earth, GLU_FILL);
	gluQuadricTexture(earth, GL_TRUE);
	gluQuadricNormals(earth, GLU_SMOOTH);
	gluSphere(earth, 20, 15, 15);

	LoadTexture("planet5.png");
	//달
	glRotatef(fElect2, 0.0f, 1.0f, 0.0f);
	glTranslatef(50.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	GLUquadric* moon = gluNewQuadric();
	gluQuadricDrawStyle(moon, GLU_FILL);
	gluQuadricTexture(moon, GL_TRUE);
	gluQuadricNormals(moon, GLU_SMOOTH);
	gluSphere(moon, 10, 15, 15);
	glPopMatrix();

	LoadTexture("planet10.png");

	fElect1 += 2.0f;
	fElect2 += 3.0f;
	
	if (fElect1 > 360.0f)
	{
		fElect1 = 0.0f;
	}

	if (fElect2 > 360.0f)
	{
		fElect2 = 0.0f;
	}

	// 박스 팅기기
	/*
	for (auto i : boxVector)
	{
		glColor3f(i->colorR, i->colorG, i->colorB);
		glRectf(i->xPos - i->Size/2, i->yPos - i->Size/2, i->xPos + i->Size/2, i->yPos + i->Size/2);
	}
	*/


	// color cube

	/*
	glBegin(GL_TRIANGLE_STRIP);



	GLfloat size = 200.0f;
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, size, size);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(size, size, size);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(size, 0.0f, size);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, size, size);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(size, size, size);


	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(size, size, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	*/
	
	




	glutSwapBuffers();
}


/////////////////////////////////////////////////////
// Handle arrow keys
void ContorolKey(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;

	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key == GLUT_KEY_HOME) //add
		zDistance += 5.0f;

	if (key == GLUT_KEY_END) //add
		zDistance -= 5.0f;

	if (key == GLUT_KEY_F10)
		CreateBox();

	glutPostRedisplay();
}



void ChangeSize(int w, int h)
{
	
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat lightPos[] = { 0.0f,0.0f,0.0f,1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	if (w < h)
	{
		windowWidth = 200.0f;
		windowHeight = 200.0f *h / w;
		glOrtho(-windowWidth, windowWidth, -windowHeight, windowHeight, 400.0f, -400.0f);
	}
	else
	{
		windowWidth = 200.0f *w / h;
		windowHeight = 200.0f;
		glOrtho(-windowWidth, windowWidth, -windowHeight, windowHeight, 400.0f, -400.0f);
	}


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



}

void TimerFunc(int value)
{


	//MoveBox();
	glutPostRedisplay();

	glutTimerFunc(33, TimerFunc, 1);
}

void LoadTexture(std::string fileName)
{
	std::vector<unsigned char>image;

	unsigned int width, height, error;

	error = lodepng::decode(image, width, height, fileName);

	if (error != 0)
	{
		printf("texture load failed");
		return;
	}

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data());
}

void CreateBox()
{
	box* newBox = new box();
	newBox->Size = (rand() % 100) + 20;
	int xRange = windowWidth*2 - (newBox->Size);
	int yRange = windowHeight*2 - (newBox->Size);
	newBox->xPos = (GLfloat)(rand() % xRange + newBox->Size / 2 - windowWidth);
	newBox->yPos = (GLfloat)(rand() % yRange + newBox->Size / 2 - windowHeight);

	int speed = 2;
	newBox->xStep = (GLfloat)speed;
	newBox->yStep = (GLfloat)speed;


	newBox->colorR = rand() % 256 / (GLfloat)255;
	newBox->colorG = rand() % 256 / (GLfloat)255;
	newBox->colorB = rand() % 256 / (GLfloat)255;

	auto creatable = CheckCreatable(newBox);

	if (creatable)
	{
		boxVector.push_back(newBox);
	}
}

void CheckColide(box* now)
{
	for (auto i : boxVector)
	{
		if (i == now)
		{
			continue;
		}


		if (abs(now->xPos - i->xPos) < now->Size / 2 + i->Size / 2 &&
			abs(now->yPos - i->yPos) < now->Size / 2 + i->Size / 2)
		{
			auto xRange = abs(now->xPos - i->xPos);
			auto yRange = abs(now->yPos - i->yPos);

			if (xRange > yRange)
			{
				now->xStep = -now->xStep;
				i->xStep = -i->xStep;
			}
			else
			{
				now->yStep = -now->yStep;
				i->yStep = -i->yStep;
			}
		}

	}

}

void MoveBox()
{

	for (auto i : boxVector)
	{
		if (i->xPos > windowWidth - i->Size / 2 || i->xPos < -windowWidth + i->Size / 2)
		{
			i->xStep = -(i->xStep);
		}

		if (i->yPos > windowHeight - i->Size / 2 || i->yPos < -windowHeight + i->Size / 2)
		{
			i->yStep = -(i->yStep);
		}

		if (i->xPos > windowWidth - i->Size / 2)
		{
			i->xPos = windowWidth - i->Size / 2 - 1;
		}
		if (i->yPos > windowHeight - i->Size / 2)
		{
			i->yPos = windowHeight - i->Size / 2 - 1;
		}

		CheckColide(i);

		i->xPos += i->xStep;
		i->yPos += i->yStep;

	}
}

bool CheckCreatable(box * newBox)
{
	for (auto i : boxVector)
	{
		if (abs(newBox->xPos - i->xPos) < newBox->Size / 2 + i->Size / 2 &&
			abs(newBox->yPos - i->yPos) < newBox->Size / 2 + i->Size / 2)
		{
			return false;
		}
	}

	return true;
}


void main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Jet");



	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(ContorolKey);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(33, TimerFunc, 1);
	SetupRC();
	//LoadTexture("planet3.png");
	//LoadTexture("planet5.png");
	//LoadTexture("planet10.png");


	glutMainLoop();
}
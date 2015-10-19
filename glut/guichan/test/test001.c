#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>	
#include <GL/glut.h>
#include "TextureLoader.h"
#include "SDLMOD_events.h"
#include "SDLMOD_video.h"
#include "TextureLoader.h"
#include "SDLMOD_ext_pixel.h"

#define FILENAME "image1.bmp"
#define TITLE "OpenGL & GLUT sample program"

unsigned char * texture_data = NULL;
int textureContainsData = 0;

UINT g_TextureArray[1];
int g_ID = 0;
unsigned int g_TextureWidth = 100;
unsigned int g_TextureHeight = 100;

int g_video_width, g_video_height;
char g_video_resized;
SDLMOD_Surface *screen;
SDLMOD_Surface *screen2;

unsigned char * texture_data2 = NULL;
unsigned int g_TextureWidth2 = 100;
unsigned int g_TextureHeight2 = 100;

#define Rmask 0x000000FF
#define Gmask 0x0000FF00
#define Bmask 0x00FF0000
//#define Amask 0xFF000000
#define Amask 0x00000000
#define SDL_VIDEO_MODE_BPP 24


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, 0.0f);

	if (textureContainsData) {
		glDeleteTextures(1, &g_TextureArray[g_ID]);
	}
	
	glGenTextures(1, &g_TextureArray[g_ID]);
	glBindTexture(GL_TEXTURE_2D, g_TextureArray[g_ID]);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
	//glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, frame->w, frame->h, 0,
	//			  texture_format, GL_UNSIGNED_BYTE, frame->pixels);
		
	SDLMOD_LockSurface(screen);
	//dumpBMPRaw("image1_out.bmp", screen->pixels, screen->w, screen->h);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
		screen->w, screen->h, 0, GL_RGB, GL_UNSIGNED_BYTE, 
		screen->pixels);
	SDLMOD_UnlockSurface(screen);

	glScalef(1.0f, -1.0f, 1.0f);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//FIXME:
	//gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 50.0f);

	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int mx, int my)
{
}

void motion(int mx, int my)
{
}

void idle(void)
{
}

int initEnvironment(void)
{	
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);

	texture_data = loadBMPRaw(FILENAME, &g_TextureWidth, &g_TextureHeight, 0, 1);	
	if (texture_data)
	{
		glGenTextures(1, &g_TextureArray[g_ID]);
		glBindTexture(GL_TEXTURE_2D, g_TextureArray[g_ID]);
		//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, g_TextureWidth, g_TextureHeight, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, g_TextureWidth, g_TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		textureContainsData = 1;
		//free(data);
		return 1;
	}
	else
	{
		return(0);
	}
}

static int win;
static int menyid;
static int animeringsmeny;
static int springmeny;
static int val = 0;

void menu(int value){
	printf("menu %d\n", value);
	if (value == 0) 
	{
		glutDestroyWindow(win);
		exit(0);
	} 
	else 
	{
		val = value;
	}
	glutPostRedisplay();
}

void createMenu(void){
	animeringsmeny = glutCreateMenu(menu);
	glutAddMenuEntry("menu 1", 1);
	glutAddMenuEntry("menu 2", 2);
	
	springmeny = glutCreateMenu(menu);
	glutAddMenuEntry("menu 3", 3);
	glutAddMenuEntry("menu 4", 4);
	
	menyid = glutCreateMenu(menu);
	glutAddSubMenu("menu 5", animeringsmeny);
	glutAddSubMenu("menu 6", springmeny);
	glutAddMenuEntry("exit", 0);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char ** argv)
{
	unsigned int i, j;

	g_video_width = 640;
	g_video_height = 480;
	g_video_resized = 0;

	screen = SDLMOD_CreateRGBSurface(0,
		g_video_width, g_video_height, SDL_VIDEO_MODE_BPP,
		Rmask, Gmask, Bmask, Amask
		);
	if(!screen) {
		fprintf(stderr, "SDL: could not set video mode - exiting\n");
		exit(1);
	}

	SDLMOD_ext_fillRectangle(screen, 
		0xff, 0x00, 0x00, 0xff,
		10, 20, 300, 300);
	SDLMOD_ext_drawRectangle(screen, 
		0x00, 0xff, 0x00, 0xff,
		10, 20, 300, 300);
	SDLMOD_ext_drawHLine(screen, 
		0x00, 0x00, 0xff, 0xff,
		20, 300, 300);
	SDLMOD_ext_drawVLine(screen, 
		0x00, 0x00, 0xff, 0xff,
		20, 20, 300);
	SDLMOD_ext_drawLine(screen, 
		0x00, 0x00, 0xff, 0xff,
		20, 20, 300, 300);

	screen2 = SDLMOD_CreateRGBSurface(0,
		100, 100, SDL_VIDEO_MODE_BPP,
		Rmask, Gmask, Bmask, Amask
		);
	texture_data2 = loadBMPRaw(FILENAME, &g_TextureWidth2, &g_TextureHeight2, 0, 1);	
	if (texture_data2)
	{
		//SDLMOD_LockSurface(screen2);
		for (j = 0; j < g_TextureHeight2; ++j)
		{
			for (i = 0; i < g_TextureWidth2; ++i)
			{
				unsigned char r, g, b;
				b = texture_data2[3 * j * 100 + 3 * i];
				g = texture_data2[3 * j * 100 + 3 * i + 1];
				r = texture_data2[3 * j * 100 + 3 * i + 2];
				SDLMOD_ext_putPixelAlpha(screen2, i, j, r, g, b, 0xff);
			}
		}
		//SDLMOD_UnlockSurface(screen2);
		free(texture_data2);
	}
	//dumpBMPRaw("image1_out.bmp", screen2->pixels, screen2->w, screen2->h);
	SDLMOD_ext_drawImage(screen,
		screen2,
		0, 0, 0, 0, 100, 100);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(g_video_width, g_video_height);
	if (0) 
	{
		glutInitWindowPosition(0, 0);
	}
	else
	{
		int cx, cy;
		cx = glutGet(GLUT_SCREEN_WIDTH);
		cy = glutGet(GLUT_SCREEN_HEIGHT);
		glutInitWindowPosition(
			(cx - g_video_width) / 2, 
			(cy - g_video_height) / 2);
	}

	win = glutCreateWindow(TITLE);
	createMenu();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);

	if (initEnvironment())
	{
		glutMainLoop();
	}

	return 0;
}

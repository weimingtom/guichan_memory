#include "guichan/guichan.hpp"
#include "glutinput.hpp"
#include "glutgraphics.hpp"
#include "glutimageloader.hpp"
#include "guichan/platform.hpp"


#define TIMER_MILLIS ((int)(1000 / 60))

#define Rmask 0x000000FF
#define Gmask 0x0000FF00
#define Bmask 0x00FF0000
#define Amask 0xFF000000


#define FILENAME "image1.bmp"
#define TITLE "OpenGL & GLUT sample program"
uint32_t g_TextureArray[1];
int g_ID = 0;

static int win;
static int menyid;
static int animeringsmeny;
static int springmeny;
static int val = 0;

unsigned char * texture_data = NULL;
int textureContainsData = 0;

/*=============================*/

SDLMOD_Surface* screen;

/*=============================*/


/*
 ** see also:
 **   http://blog.csdn.net/wuyong2k/article/details/7839973
 **   http://www.cnblogs.com/jiaohuang/archive/2011/07/25/2116263.html
 **   http://blog.sina.com.cn/s/blog_67612f950100svu5.html
 **   http://blog.csdn.net/hitxiaya/article/details/5974811
 **   http://www.programmer-club.com.tw/ShowSameTitleN/opengl/2628.html
 */
namespace glut
{
    bool running = true;

    gcn::GLUTGraphics* graphics;
    gcn::GLUTInput* input;
    gcn::GLUTImageLoader* imageLoader;





void display(void)
{
    globals::gui->logic();
    globals::gui->draw();

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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 
		screen->w, screen->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
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

	//NOTE: avoid memory leak
	glDeleteTextures(1, &g_TextureArray[g_ID]);

	glutSwapBuffers();
	
#ifdef _DEBUG
	//fprintf(stderr, "[display]%s\n", "glutSwapBuffers");
#endif
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
	int cw, ch, sw, sh;
	cw = glutGet(GLUT_WINDOW_WIDTH);
	ch = glutGet(GLUT_WINDOW_HEIGHT);
	sw = screen->w;
	sh = screen->h;
	
	int sx = (cw != 0) ? (int)((double)sw / (double)cw * (double)mx) : mx;
	int sy = (ch != 0) ? (int)((double)sh / (double)ch * (double)my) : my;

	glut::input->pushMouseInput(button, state, sx, sy);
}

void motion(int mx, int my)
{
	int cw, ch, sw, sh;
	cw = glutGet(GLUT_WINDOW_WIDTH);
	ch = glutGet(GLUT_WINDOW_HEIGHT);
	sw = screen->w;
	sh = screen->h;
	
	int sx = (cw != 0) ? (int)((double)sw / (double)cw * (double)mx) : mx;
	int sy = (ch != 0) ? (int)((double)sh / (double)ch * (double)my) : my;

	glut::input->pushMotionInput(sx, sy);
}

void passiveMotion(int mx, int my)
{
	glut::input->pushPassiveMotionInput(mx, my);
}

void keyboard(unsigned char key, int x, int y) 
{ 
	if (key == 27)
	{
		// ESC key
		glutDestroyWindow(win);
		exit(0);
	} 
	else 
	{
		glut::input->pushKeyDownInput(key);
	}
}
 
void keyboardUp(unsigned char key, int x, int y) 
{ 
	glut::input->pushKeyUpInput(key);
}
 
void special(int key, int x, int y) 
{
	glut::input->pushSpecialDownInput(key);
}

void specialUp(int key, int x, int y) 
{
	glut::input->pushSpecialUpInput(key);
}

void timer(int value)
{
   glutPostRedisplay();
   glutTimerFunc(TIMER_MILLIS, timer, 1);
}

//FIXME: I don't know why cpu is 100% if I use idle() :( 
void idle(void)
{
	//NOTE: 
	//please use timer() instead of idle() if 
	//not for memory leak detect
	//glutPostRedisplay();
}

void menu(int value)
{
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

void createMenu(void)
{
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

int initEnvironment(void)
{	
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);

	return 1;
}


    void init()
    {
        //SDL_Init(SDL_INIT_VIDEO);
        screen = SDLMOD_CreateRGBSurface(0,
			640, 480, 32,
			Rmask, Gmask, Bmask, Amask
			);
        //SDL_EnableUNICODE(1);
        //SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

        imageLoader = new gcn::GLUTImageLoader();
        gcn::Image::setImageLoader(imageLoader);
        graphics = new gcn::GLUTGraphics();
        graphics->setTarget(screen);
        input = new gcn::GLUTInput();

        globals::gui = new gcn::Gui();
        globals::gui->setGraphics(graphics);
        globals::gui->setInput(input);
    }

    void halt()
    {
        delete globals::gui;

        delete imageLoader;
        delete input;
        delete graphics;

        //SDL_Quit();
    }

    void run(int argc, char **argv)
    {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
		glutInitWindowSize(640, 480);
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
				(cx - 640) / 2, 
				(cy - 480) / 2);
		}

		win = glutCreateWindow(TITLE);
		createMenu();

		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutMouseFunc(mouse);
		glutMotionFunc(motion);
		glutPassiveMotionFunc(passiveMotion);
		glutKeyboardFunc(keyboard);
		glutKeyboardUpFunc(keyboardUp);
		glutSpecialFunc(special);
		glutSpecialUpFunc(specialUp);
		glutTimerFunc(TIMER_MILLIS, timer, 1);

		//FIXME: I don't know why cpu is 100% if I use idle() :( 
		//glutIdleFunc(idle);

		if (initEnvironment())
		{
			glutMainLoop();
		}
    }
}

// Mehmet Ceylan
// 040080213	
// Proje 1
//
//  
//  
//

#include <iostream>
#include <glut.h>
#include <SOIL.h>

GLdouble angle = 0;
GLint sun_2d,earth_2d,moon_2d,moon2_2d,mars_2d;
void setupLight(){
    glEnable(GL_LIGHTING);
	
	GLfloat light_position[] = { 0.f, 0.f, -15.f, 1.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    GLfloat global_ambient[] = { 0.2,  0.2, 0.2, 1.0 };
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glShadeModel(GL_SMOOTH);
}


GLint LoadGLTexture(const char *filename)
{
    GLuint _texture;
   _texture = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture 
	(
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 
     );
    if(_texture == 0)
    {
	 printf( "SOIL loading error:");
    }
	return _texture;
}

static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
	gluLookAt(0,10,10,0.f,0.f,-15.f,0,1,0);
    setupLight();
	
    GLUquadric* sun = gluNewQuadric();
    gluQuadricNormals(sun, GLU_SMOOTH);
    gluQuadricTexture(sun, GL_TRUE);
	glTranslatef(0.f, 0.f, -15.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,sun_2d);
	glPushMatrix();
    glRotated(90, 1, 0, 0);
	GLfloat emission[] = {0.9, 0.9, 0.9, 1};
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	gluSphere( sun , 1 , 50 , 25 );
	glPopMatrix();
    glDisable(GL_TEXTURE_2D);
	
	GLfloat r_emission[4] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, r_emission);
	
	glPushMatrix();
	
	GLUquadric* earth = gluNewQuadric();
    gluQuadricNormals(earth, GLU_SMOOTH);
    gluQuadricTexture(earth, GL_TRUE);
	glRotated(angle,0,1,0);
	glTranslatef(6.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,earth_2d);
	glRotated(angle,0,1,0);
	glPushMatrix();
	glRotated(90, -1, 0, 0);
	gluSphere( earth , 1 , 50 , 25 );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();

	GLUquadric* moon = gluNewQuadric();
    gluQuadricNormals(moon, GLU_SMOOTH);
    gluQuadricTexture(moon, GL_TRUE);
	glRotated(2*angle,0,-1,0);
	glTranslatef(2.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,moon_2d);
	glRotated(2*angle,0,-1,0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	gluSphere( moon , 0.5 , 50 , 25 );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
	glPushMatrix();

	GLUquadric* moon2 = gluNewQuadric();
    gluQuadricNormals(moon2, GLU_SMOOTH);
    gluQuadricTexture(moon2, GL_TRUE);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,moon2_2d);
    glTranslatef(4.f, 0.f, 0.f);
	glRotated(angle,0,1,0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	gluSphere( moon2 , 0.5 , 50 , 25 );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPopMatrix();

	GLUquadric* jupiter = gluNewQuadric();
    gluQuadricNormals(jupiter, GLU_SMOOTH);
    gluQuadricTexture(jupiter, GL_TRUE);
	glRotated(angle,0,-1,0);
	glTranslatef(14.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,mars_2d);
	glRotated(2*angle,0,1,0);
	glPushMatrix();
	glRotated(90, -1, 0, 0);
	gluSphere( jupiter , 1 , 50 , 25 );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();

	GLUquadric* moon3 = gluNewQuadric();
    gluQuadricNormals(moon3, GLU_SMOOTH);
    gluQuadricTexture(moon3, GL_TRUE);
	glRotated(3*angle,0,-1,0);
	glTranslatef(2.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,moon2_2d);
	glRotated(3*angle,0,-1,0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	gluSphere( moon , 0.5 , 50 , 25 );
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
    
	
	glPopMatrix();
	
    glutSwapBuffers();
    
}

static void timerCallback (int value)
{
 
    angle = angle + 0.5;
    
    glutTimerFunc(10, timerCallback, 0);
    glutPostRedisplay();
}

int main (int argc, char ** argv)
{

    GLenum type;
    
	glutInit(&argc, argv);
	glutInitWindowSize(1024,768);
	type = GLUT_RGB;
	type |= GLUT_DOUBLE;
	type |= GLUT_DEPTH;
    type |= GLUT_MULTISAMPLE;
	glutInitDisplayMode(type);
	glutCreateWindow("Project1");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
	sun_2d=LoadGLTexture("sun.jpg");
    earth_2d=LoadGLTexture("earth_sphere.jpg");
	moon_2d=LoadGLTexture("moon.jpg"); 
	moon2_2d=LoadGLTexture("texture.jpg");
	mars_2d=LoadGLTexture("jupiter.jpg");
	glMatrixMode(GL_PROJECTION);
    gluPerspective(70, 1024/768, 0.1, 100);
    
    glMatrixMode(GL_MODELVIEW);
   
    timerCallback(0);
    glutDisplayFunc(Draw);
	
    glutMainLoop();
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


#include <iostream>
#include <glut.h>
#include <stdlib.h>



static GLfloat stop = 1.0,k=0; //for stopping moving objects at some point
GLfloat z = 0, x = 0, n = 0;
GLfloat d = 1, e = 1, f = 1, g = 1, h = 1 ,spin11=0.0,spin12=0.0,spinx11=0.0,spiny11=0.0;

static GLint i = 0.0, spin1 = 0.0;
static GLfloat spin4 = 0.0;
static GLfloat spinx = 0.0, spiny = 0.0, spinp = 0.0;
void animate(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

static GLfloat spin = 0.0, spin2 = 0.0, spin5 = 0.0, spin6 = 0.0, spin7 = 0.0, spin8 = 0.0, spin9 = 0.0;;
static GLfloat rcolor = 0.0, gcolor = 0.0, bcolor = 0.0;
void rect(GLfloat, GLfloat);
void select(GLfloat, GLfloat, std::string);
void spinDisplay();

GLfloat a = -20, b = -25, c = 5; // values of coordinates

GLfloat vertices1[][3] = { { -40,a - 5,-c },{ -35,a - 5,-c },{ -35,b - 5,-c },{ -40,b - 5,-c },{ -40,a - 5,-.1 },{ -35,a - 5 ,-.1 },{ -35,b - 5,-.1 },{ -40,b - 5,-.1 } };
//GLfloat vertices1[][3]={{-20,a+40,-c},{-5,a+40,-c},{-5,b+40,-c},{-20,b+40,-c},{-20,a+40,-1},{-5,a+40,-.1},{-5,b+40,-.1},{-20,b+40,-.1}};

GLfloat normals1[][3] = { { -20,a,-c },{ 20,a,-c },{ 20,b,-c },{ -20,b,-c },{ -20,a,-1 },{ 20,a,-.1 },{ 20,b,-.1 },{ -20,b,-.1 } };

//color array
GLfloat colors[][3] = { { 0,0,0 },{ 1,0,0 },{ 1,1,0 },{ 0,1,0 },{ 0,0,1 },{ 1,0,1 },{ 1,1,1 },{ 0,1,1 } };

static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;
static GLdouble viewer[] = { 0.0, 0.0, 5.0 }; /* initial viewer location */


void rot()
{
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
}


void polygon1(int a, int b, int c, int d)
{

	glBegin(GL_QUADS);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor3fv(colors[a]);
	glNormal3fv(normals1[a]);
	glVertex3fv(vertices1[a]);
	glColor3fv(colors[b]);
	glNormal3fv(normals1[b]);
	glVertex3fv(vertices1[b]);
	glColor3fv(colors[c]);
	glNormal3fv(normals1[c]);
	glVertex3fv(vertices1[c]);
	glColor3fv(colors[d]);
	glNormal3fv(normals1[d]);
	glVertex3fv(vertices1[d]);

	glEnd();


}

void colorcube1()
{

	polygon1(0, 3, 2, 1);
	polygon1(2, 3, 7, 6);
	polygon1(0, 4, 7, 3);
	polygon1(1, 2, 6, 5);
	polygon1(4, 5, 6, 7);
	polygon1(0, 1, 5, 4);

}



void rect(GLfloat x, GLfloat y, GLfloat z)
{
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + z, y);
	glVertex2f(x + z, y + z);
	glVertex2f(x, y + z);
	glEnd();
}


void all_txt()
{
	glPushMatrix();
	// d---Encoder

	glColor3f(0.0, 0.0, 1.0);
	select(-83.0, 17.0, "0");
	
	
	(-83.0, 21.0, "a3");

	glColor3f(0.0, 0.0, 1.0);
	select(-78.0, 17.0, "1");
	select(-78.0, 21.0, "a2");

	glColor3f(0.0, 0.0, 1.0);
	select(-73.0, 17.0, "1");
	select(-73.0, 21.0, "a1");

	glColor3f(0.0, 0.0, 1.0);
	select(-68.0, 17.0, "1");
	select(-68.0, 21.0, "a0");

	//c---Encoder
	glColor3f(0.0, 0.0, 1.0);
	select(-83.0, -28.0, "0");
	select(-83.0, -32.0, "a3");


	glColor3f(0.0, 0.0, 1.0);
	select(-78.0, -28.0, "1");
	select(-78.0, -32.0, "a2");

	glColor3f(0.0, 0.0, 1.0);
	select(-73.0, -28.0, "1");
	select(-73.0, -32.0, "a1");

	glColor3f(0.0, 0.0, 1.0);
	select(-68.0, -28.0, "1");
	select(-68.0, -32.0, "a0");

	glColor3f(0.0, 0.0, 1.0);
	select(-63.0, -28.0, "0");
	select(-63.0, -32.0, "r2");

	glColor3f(0.0, 0.0, 1.0);
	select(-58.0, -28.0, "0");
	select(-58.0, -32.0, "r1");

	glColor3f(0.0, 0.0, 1.0);
	select(-53.0, -28.0, "1");
	select(-53.0, -32.0, "r0");

	//d----Decoder

	glColor3f(0.0, 0.0, 1.0);
	select(57.0, 17.0, "0");
	select(57.0, 21.0, "a3");

	glColor3f(0.0, 0.0, 1.0);
	select(52.0, 17.0, "1");
	select(52.0, 21.0, "a2");

	glColor3f(0.0, 0.0, 1.0);
	select(47.0, 17.0, "1");
	select(47.0, 21.0, "a1");

	glColor3f(0.0, 0.0, 1.0);
	select(42.0, 17.0, "1");
	select(42.0, 21.0, "a0");


	//c---Decoder
	glColor3f(0.0, 0.0, 1.0);
	select(74.0, -28.0, "0");
	select(74.0, -32.0, "q0");

	glColor3f(0.0, 0.0, 1.0);
	select(68.0, -28.0, "0");
	select(68.0, -32.0, "q1");

	glColor3f(0.0, 0.0, 1.0);
	select(63.0, -28.0, "1");
	select(63.0, -32.0, "q2");

	glColor3f(0.0, 0.0, 1.0);
	select(58.0, -28.0, "1");
	select(58.0, -32.0, "b0");

	glColor3f(0.0, 0.0, 1.0);
	select(52.0, -28.0, "0");
	select(52.0, -32.0, "b1");

	glColor3f(0.0, 0.0, 1.0);
	select(47.0, -28.0, "0");
	select(47.0, -32.0, "b2");

	glColor3f(0.0, 0.0, 1.0);
	select(42.0, -28.0, "1");
	select(42.0, -32.0, "b3");


	//----- Syndrome bits------//

	glColor3f(0.0, 0.0, 1.0);
	select(8.0, -2.0, "0");
	select(8.0, 2.0, "s3");

	glColor3f(0.0, 0.0, 1.0);
	select(13.0, -2.0, "0");
	select(13.0, 2.0, "s2");

	glColor3f(0.0, 0.0, 1.0);
	select(18.0, -2.0, "1");
	select(18.0, 2.0, "s1");

	glColor3f(0.0, 0.8, 0.0);
	select(-62.0, -3.0, "Generator");

	glColor3f(0.0, 0.8, 0.0);
	select(9.0, -11.0, "Checker");

	glColor3f(0.0, 0.8, 0.0);
	select(40.0, 4.0, "Correction logic");


	glColor3f(0.0, 0.8, 0.0);
	select(-50.0, 30.0, "ENCODER");

	glColor3f(0.0, 0.8, 0.0);
	select(30.0, 30.0, "DECODER");

	glColor3f(0.0, 0.8, 0.0);
	select(-80.0, 25.0, "Dataword");

	glColor3f(0.0, 0.8, 0.0);
	select(-64.0, -35.0, "Codeword");

	glColor3f(0.0, 0.8, 0.0);
	select(50.0, 25.0, "Dataword");

	glColor3f(0.0, 0.8, 0.0);
	select(25.0, -31.0, "Codeword");

	glColor3f(0.0, 0.9, 0.0);
	select(-20.0, 45.0, "HAMMING CODES!!");

	glColor3f(0.0, 0.9, 0.0);
	select(45.0, 42.0, "RECIEVER");

	glColor3f(0.0, 0.9, 0.0);
	select(-65.0, 42.0, " SENDER");

	//----ro r1 r2 description

	glColor3f(0.0, 0.8, 0.0);
	select(-43.0, -6.0, "r0=a2+a1+a0");
	select(-43.0, -9.0, "r1=a3+a2+a1");
	select(-43.0, -12.0, "r2=a1+a0+a3");

	//-----s0 s1 s2 description

	glColor3f(0.0, 0.8, 0.0);

	select(-15.0, -3.0, "syndrome");
	select(-15.0, -6.0, "s0=b2+b1+b0+q0");
	select(-15.0, -9.0, "s1=b3+b2+b1+q1");
	select(-15.0, -12.0, "s2=b3+b1+b0+q2");


	glColor3f(0.0, 0.8, 0.0);
	select(-12.0, -31.0, "Unreliable");
	glColor3f(0.0, 0.8, 0.0);
	select(-12.0, -33.0, "transmission");

	select(-17.0, 30.0, "d : DW to CW");
	select(-17.0, 26.0, "e : generator to CW");
	select(-17.0, 22.0, "h : unreliable");
	select(-17.0, 18.0, "f : CW to logic");
	select(-17.0, 14.0, "g : logic to DW");





	glPopMatrix();
	//glFlush();

}


void packet1()
{
	//packet moving from E --DW genereator to CW

	glPushMatrix();
	glTranslatef(0.0, -spin5, 1.0);
	glColor3f(rcolor, gcolor, 0.5);

	glRectf(-80, 2.0, -82.0, 7.0);
	glRectf(-74, 2.0, -76.0, 7.0);
	glRectf(-69, 2.0, -71.0, 7.0);
	glRectf(-64, 2.0, -66.0, 7.0);

	glPopMatrix();
	glEnable(GL_TEXTURE_2D);


	//packet moving from E --DW genereator to CW

	glPushMatrix();
	glTranslatef(0.0, -spin6, 0.0);
	glColor3f(rcolor, gcolor, 0.5);

	glRectf(-60, -8.0, -58.0, -6.0);
	glRectf(-56, -8.0, -54.0, -6.0);
	glRectf(-50, -8.0, -48.0, -6.0);

	glPopMatrix();
	//glEnable(GL_TEXTURE_2D);


}

void lines()
{
	glPushMatrix();
	//arrows
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	//===============arrow poiting t0 errror=======//
	glVertex2f(48.0, -33.0);
	glVertex2f(48.0, -37.0);

	glVertex2f(48.0, -33.0);
	glVertex2f(49.0, -34.0);
	glVertex2f(48.0, -33.0);
	glVertex2f(47.0, -34.0);

	//vertical lines

	glVertex2f(-82.0, 15.0);
	glVertex2f(-82.0, -25.0);

	//arr
	glVertex2f(-82.0, -25.0);
	glVertex2f(-81.0, -24.0);
	glVertex2f(-82.0, -25.0);
	glVertex2f(-83.0, -24.0);

	// arr

	glVertex2f(-77.0, 15.0);
	glVertex2f(-77.0, -25.0);
	glVertex2f(-77.0, -25.0);
	glVertex2f(-76.0, -24.0);
	glVertex2f(-77.0, -25.0);
	glVertex2f(-78.0, -24.0);

	glVertex2f(-72.0, 15.0);
	glVertex2f(-72.0, -25.0);
	glVertex2f(-72.0, -25.0);
	glVertex2f(-71.0, -24.0);
	glVertex2f(-72.0, -25.0);
	glVertex2f(-73.0, -24.0);

	glVertex2f(-67.0, 15.0);
	glVertex2f(-67.0, -25.0);
	glVertex2f(-67.0, -25.0);
	glVertex2f(-66.0, -24.0);
	glVertex2f(-67.0, -25.0);
	glVertex2f(-68.0, -24.0);

	//horizontal lines

	glVertex2f(-82.0, 12.0);
	glVertex2f(-50.0, 12.0);

	glVertex2f(-77.0, 9.0);
	glVertex2f(-52.0, 9.0);

	glVertex2f(-72.0, 6.0);
	glVertex2f(-55.0, 6.0);

	glVertex2f(-67.0, 3.0);
	glVertex2f(-58.0, 3.0);

	//Vertical from generator

	glVertex2f(-52.0, -5.0);
	glVertex2f(-52.0, -25.0);
	glVertex2f(-52.0, -25.0);
	glVertex2f(-51.0, -24.0);
	glVertex2f(-52.0, -25.0);
	glVertex2f(-53.0, -24.0);

	glVertex2f(-56.0, -5.0);
	glVertex2f(-56.0, -25.0);
	glVertex2f(-56.0, -25.0);
	glVertex2f(-55.0, -24.0);
	glVertex2f(-56.0, -25.0);
	glVertex2f(-57.0, -24.0);

	glVertex2f(-61.0, -5.0);
	glVertex2f(-61.0, -25.0);
	glVertex2f(-61.0, -25.0);
	glVertex2f(-60.0, -24.0);
	glVertex2f(-61.0, -25.0);
	glVertex2f(-62.0, -24.0);

	//Vertical lines for generator

	glVertex2f(-50.0, 12.0);
	glVertex2f(-50.0, 0.0);
	glVertex2f(-50.0, 0.0);
	glVertex2f(-49.0, 1.0);
	glVertex2f(-50.0, 0.0);
	glVertex2f(-51.0, 1.0);
	glVertex2f(-52.0, 9.0);
	glVertex2f(-52.0, 0.0);
	glVertex2f(-52.0, 0.0);
	glVertex2f(-51.0, 1.0);
	glVertex2f(-52.0, 0.0);
	glVertex2f(-53.0, 1.0);

	glVertex2f(-55.0, 6.0);
	glVertex2f(-55.0, 0.0);
	glVertex2f(-55.0, 0.0);
	glVertex2f(-54.0, 1.0);
	glVertex2f(-55.0, 0.0);
	glVertex2f(-56.0, 1.0);

	glVertex2f(-58.0, 3.0);
	glVertex2f(-58.0, 0.0);
	glVertex2f(-58.0, 0.0);
	glVertex2f(-57.0, 1.0);
	glVertex2f(-58.0, 0.0);
	glVertex2f(-59.0, 1.0);

	//checker to syndrome

	glVertex2f(14.0, -4.0);
	glVertex2f(14.0, -8.0);
	glVertex2f(14.0, -4.0);
	glVertex2f(13.0, -5.0);
	glVertex2f(14.0, -4.0);
	glVertex2f(15.0, -5.0);

	//checker to logic
	//vertical
	glVertex2f(14.0, 6.0);
	glVertex2f(14.0, 1.0);


	//horizontal
	glVertex2f(14.0, 6.0);
	glVertex2f(38.0, 6.0);

	//logic to dataword

	glVertex2f(59.0, 8.0);
	glVertex2f(59.0, 15.0);
	glVertex2f(59.0, 15.0);
	glVertex2f(58.0, 14.0);
	glVertex2f(59.0, 15.0);
	glVertex2f(60.0, 14.0);

	glVertex2f(54.0, 8.0);
	glVertex2f(54.0, 15.0);
	glVertex2f(54.0, 15.0);
	glVertex2f(53.0, 14.0);
	glVertex2f(54.0, 15.0);
	glVertex2f(55.0, 14.0);

	glVertex2f(49.0, 8.0);
	glVertex2f(49.0, 15.0);
	glVertex2f(49.0, 15.0);
	glVertex2f(48.0, 14.0);
	glVertex2f(49.0, 15.0);
	glVertex2f(50.0, 14.0);

	glVertex2f(44.0, 8.0);
	glVertex2f(44.0, 15.0);
	glVertex2f(44.0, 15.0);
	glVertex2f(43.0, 14.0);
	glVertex2f(44.0, 15.0);
	glVertex2f(45.0, 14.0);

	//logic to codeword

	glVertex2f(59.0, 3.0);
	glVertex2f(59.0, -25.0);
	glVertex2f(59.0, 3.0);
	glVertex2f(58.0, 2.0);
	glVertex2f(59.0, 3.0);
	glVertex2f(60.0, 2.0);

	glVertex2f(54.0, 3.0);
	glVertex2f(54.0, -25.0);
	glVertex2f(54.0, 3.0);
	glVertex2f(53.0, 2.0);
	glVertex2f(54.0, 3.0);
	glVertex2f(55.0, 2.0);


	glVertex2f(49.0, 3.0);
	glVertex2f(49.0, -25.0);
	glVertex2f(49.0, 3.0);
	glVertex2f(48.0, 2.0);
	glVertex2f(49.0, 3.0);
	glVertex2f(50.0, 2.0);
	glVertex2f(44.0, 3.0);
	glVertex2f(44.0, -25.0);
	glVertex2f(44.0, 3.0);
	glVertex2f(43.0, 2.0);
	glVertex2f(44.0, 3.0);
	glVertex2f(45.0, 2.0);

	//codeword to checker

	//for q0,q1,q2

	//vertical
	glVertex2f(64.0, -12.0);
	glVertex2f(64.0, -25.0);

	glVertex2f(70.0, -10.0);
	glVertex2f(70.0, -25.0);

	glVertex2f(75.0, -8.0);
	glVertex2f(75.0, -25.0);

	//horizontal
	glVertex2f(25.0, -12.0);
	glVertex2f(64.0, -12.0);
	glVertex2f(25.0, -12.0);
	glVertex2f(26.0, -11.0);
	glVertex2f(25.0, -12.0);
	glVertex2f(26.0, -13.0);
	glVertex2f(25.0, -10.0);
	glVertex2f(70.0, -10.0);
	glVertex2f(25.0, -10.0);
	glVertex2f(26.0, -11.0);
	glVertex2f(25.0, -10.0);
	glVertex2f(26.0, -9.0);

	glVertex2f(25.0, -8.0);
	glVertex2f(75.0, -8.0);
	glVertex2f(25.0, -8.0);
	glVertex2f(26.0, -9.0);
	glVertex2f(25.0, -8.0);
	glVertex2f(26.0, -7.0);

	//for b0,b1,b2,b3

	//vertical from dataword
	glVertex2f(24.0, -13.0);
	glVertex2f(24.0, -15.0);
	glVertex2f(24.0, -13.0);
	glVertex2f(25.0, -14.0);
	glVertex2f(24.0, -13.0);
	glVertex2f(23.0, -14.0);

	glVertex2f(19.0, -13.0);
	glVertex2f(19.0, -18.0);
	glVertex2f(19.0, -13.0);
	glVertex2f(18.0, -14.0);
	glVertex2f(19.0, -13.0);
	glVertex2f(20.0, -14.0);

	glVertex2f(14.0, -13.0);
	glVertex2f(14.0, -21.0);
	glVertex2f(14.0, -13.0);
	glVertex2f(13.0, -14.0);
	glVertex2f(15.0, -14.0);
	glVertex2f(14.0, -13.0);
	glVertex2f(9.0, -13.0);
	glVertex2f(9.0, -24.0);
	glVertex2f(9.0, -13.0);
	glVertex2f(8.0, -14.0);
	glVertex2f(9.0, -13.0);
	glVertex2f(10.0, -14.0);

	//horizontal from dataword
	glVertex2f(24.0, -15.0);
	glVertex2f(59.0, -15.0);

	glVertex2f(19.0, -18.0);
	glVertex2f(54.0, -18.0);

	glVertex2f(14.0, -21.0);
	glVertex2f(49.0, -21.0);

	glVertex2f(9.0, -24.0);
	glVertex2f(44.0, -24.0);

	glEnd();

	glPopMatrix();
	//glFlush();
}

void packet2()
{


	//------PACKET FLOWS-----//

	glPushMatrix();
	glTranslatef(0.0, spin7, 1.0);
	glRectf(57, -24.0, 59.0, -20.0);
	glRectf(52, -24.0, 54.0, -20.0);
	glRectf(47, -24.0, 49.0, -20.0);
	glRectf(42, -24.0, 44.0, -20.0);  // bo,b1
	glPopMatrix();

	/*	glPushMatrix();
	glTranslatef(0.0, spin8, 1.0);
	glRectf(73, -24.0, 75.0, -20.0);
	glRectf(68, -24.0, 70.0, -20.0);
	glRectf(62, -24.0, 64.0, -20.0);  //   q0,q1,q2
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);   */

	glPushMatrix();
	glTranslatef(0.0, spin9, 1.0);
	glRectf(57, 8.0, 59.0, 10.0);
	glRectf(52, 8.0, 54.0, 10.0);
	glRectf(47, 8.0, 49.0, 10.0);
	glRectf(42, 8.0, 44.0, 10.0);
	glPopMatrix();
	//glEnable(GL_TEXTURE_2D);
}

void encoder()
{
	//---------------------------ENCODER----------------------------------//
	//DATAWORD!!!!!

	glPushMatrix();

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(-90.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(-90.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(-90.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(-90.0, 15.0, 5);

	glPopMatrix();
	glFlush();

	glPushMatrix();
	if (spin > 5.0)
	{
		glutIdleFunc(0);
	}
	glPopMatrix();
	glFlush();

	//CODEWORD!!!!
	glPushMatrix();

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);


	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(-90.0, -30.0, 5);

	glPopMatrix();

	glPushMatrix();
	if (spin2 > 10.0)
	{
		glutIdleFunc(0);
	}
	glPopMatrix();

	//glFlush();

}

void decoder()
{
	//--------------------------------------DECODER----------------------------------//
	//DATAWORD

	glPushMatrix();

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(36.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(36.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(36.0, 15.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(1.0, 0.5, 0.0);
	rect(36.0, 15.0, 5);

	glPopMatrix();

	glPushMatrix();
	if (spin > 5.0)
	{
		glutIdleFunc(0);
	}
	glPopMatrix();
	glFlush();
	//CODEWORD

	glPushMatrix();

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.8);//pink
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glTranslatef(spin2, 0.0, 0.0);
	glColor3f(0.0, 0.5, 0.0);
	rect(36.0, -30.0, 5);

	glPopMatrix();

	glPushMatrix();
	if (spin2 > 10.0)
	{
		glutIdleFunc(0);
	}
	glPopMatrix();
	glFlush();
}

void syndrome()
{
	//------------------------3 syndrome bits----------------//

	glPushMatrix();

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(0.5, 0.0, 0.5);
	rect
		(2.0, -4.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(0.5, 0.0, 0.6);
	rect
		(2.0, -4.0, 5);

	glTranslatef(spin, 0.0, 0.0);
	glColor3f(0.5, 0.0, 0.7);
	rect(2.0, -4.0, 5);

	glPopMatrix();

	glPushMatrix();
	if (spin > 5.0)
	{
		glutIdleFunc(0);
	}
	glPopMatrix();
}

void generator()
{
	//-----------Generator-----//

	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);
	glRectf(-63.0, -5.0, -48.0, 0.0);
	glPopMatrix();
}

void checker()
{

	//-----------checker-----//

	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);
	glRectf(8.0, -8.0, 25.0, -13.0);
	glPopMatrix();

}

void logic()
{

	// logic//

	glPushMatrix();
	glColor3f(0.5, 0.0, 0.0);
	glRectf(38.0, 3.0, 70.0, 8.0);
	glPopMatrix();
	glEnable(GL_TEXTURE);

	//unreliable transmission

	glBegin(GL_LINES);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(41.0, -28.0);   //right
	glVertex2f(-48.0, -28.0);   //left
	glEnd();
}

void boxes()
{
	//------- OUTERBOX for E

	glBegin(GL_LINES);

	glVertex2f(-88.0, 38.0); // vertical
	glVertex2f(-88.0, -38.0);

	glVertex2f(-25.0, 38.0); // vertical
	glVertex2f(-25.0, -38.0);

	glVertex2f(-88.0, 38.0); // horizontal
	glVertex2f(-25.0, 38.0);

	glVertex2f(-88.0, -38.0); // horizontal
	glVertex2f(-25.0, -38.0);

	glEnd();

	//------ OUTERBOX for D

	glBegin(GL_LINES);

	glVertex2f(6.0, 38.0);
	glVertex2f(6.0, -38.0);

	glVertex2f(89.0, 38.0);
	glVertex2f(89.0, -38.0);

	glVertex2f(6.0, 38.0);
	glVertex2f(89.0, 38.0);

	glVertex2f(6.0, -38.0);
	glVertex2f(89.0, -38.0);
	glEnd();

}

void print1()
{
	glPushMatrix();
   

    glColor3f(0.0,0.0,1.0);
	glTranslatef(0,spin11+spin12,0);
	select(-30,-23,"Department of CSE,Atria Institute Of Technology");
	 
    
	 glColor3f(1.0,0.0,1.0);
	glTranslatef(0,spin11+spin12,0);
    select(-18,-23,"* Anushree Ankola - 1AT13CS017 *");

    
    glColor3f(1.0,0.0,1.0);
	 glTranslatef(0,spin11+spin12,0);
    select(-18,-23,"* Anu P.M- 1AT13CS016 *");

	glColor3f(1.0,0.0,1.0);
	 glTranslatef(0,spin11+spin12,0);
    select(-18,-23,"* Akansha Rana - 1AT13CS008 *");

	
	 if(spinx11>2.8)
	 {
		 glutIdleFunc(0);
	 }
	 glPopMatrix();
}
void print2()
{ 
	glPushMatrix();
	glColor3f(1,0.0,0.0);
	glTranslatef(0,-spin12,0);
    select(-26,40,"A MINI PROJECT ON SELECTIVE REPEAT ARQ");
	
	glColor3f(1.0,1.0,0.0);
	glTranslatef(0,-spin12,0);
    select(-26,40,"Project Guide: Dr Jasma Balasangameswara");
	
    glColor3f(0.0,1.0,0.0);
	glTranslatef(0,-spin12,0);
    select(-24,40,"Project Coordinator : Prof. Keerthi P");
	 
    glColor3f(0.0,0.0,0.0);

    if(spiny11>2.8)
	 {
		 glutIdleFunc(0);
	 }
	 glPopMatrix();
	 glColor3f(1.0,1.0,1.0);
    select(55,-48,"press 1");

}

void display(void)
	{   
	if(k==0)
    { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
		print1();
		print2();
		 glColor3f(1.8,1.8,1.8);
	
     select(-15,-32,"PRESS SPACE TO START");
    }
    else

{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	rot();

	//box(-5,-5);
	packet1();
	packet2();

	encoder();
	decoder();

	syndrome();
	generator();
	checker();
	logic();

	all_txt();
	lines();
	boxes();

	//============unreliable packet============//

	glTranslatef(spinp, 0, 0);
	colorcube1();
	//glFlush();

	glLoadIdentity();

	//glFlush();

	glPopMatrix();
	

}
	glutSwapBuffers();
}

void select(GLfloat x1, GLfloat y1, std::string s)
{

	//glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(x1, y1);
	//std::string s=" " ;
	void *font = GLUT_BITMAP_HELVETICA_18;
	for (std::string::iterator i = s.begin(); i != s.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
}
void spindisplay3()
 {
 spin11=spin11+4;
 spinx11=spinx11+2;
 glutPostRedisplay();
 }
  void spindisplay4()
 {
 spin12=spin12+4;
 spiny11=spiny11+2;
 glutPostRedisplay();
 }

void spinDisplay(void)
{


	spin4 = spin4 + 0.00000043;
	spin1 = spin1 + 0.0000006;

	// data word--encoder translatn, code word--decoder translatn,

	spin = spin + 0.2;
	spin2 = spin2 + 0.2;
	//spin5 = spin5 + 1.0;
	//spin6 = spin6 + 0.6;
	//spin7 = spin7 + 0.9;
	spin8 = spin8 + 0.9;
	//spin9 = spin9 + 0.18;


	//spinp = spinp + 2.8;
	// if (spin > 360.0)
	// spin = spin - 360.0;

	glutPostRedisplay();
}

void spinDisplay1(void)
{

	spin7 = spin7 + 6;
	glutPostRedisplay();
}

void spinDisplay2(void)
{

	spin5 = spin5 + 4.5;
	glutPostRedisplay();
}
void spinDisplay3(void)
{

	spin6 = spin6 + 4.2;
	glutPostRedisplay();
}
void spinDisplay4(void)
{

	spin9 = spin9 + 5;
	glutPostRedisplay();
}

void spinDisplay5(void)
{

	spinp = spinp + 8;
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 32: ++k;
             glutPostRedisplay();
             break;
	case 'd':    if (d <= 6)
		glutIdleFunc(spinDisplay2);
		d++;
		break;
	case 'e':if (e <= 4)
		glutIdleFunc(spinDisplay3);
		e++;
		break;
	case 'f':if (f <= 4)
		glutIdleFunc(spinDisplay1);
		f++;
		break;
	case 'g':if (g <= 1)
		glutIdleFunc(spinDisplay4);
		g++;
		break;
	case 'h':if (h <= 9)
		glutIdleFunc(spinDisplay5);
		h++;
		break;

		 case '1': glutIdleFunc(spindisplay4);
	 break;
	}
}


void mouse(int button, int state, int x, int y)
{
	if (stop <= 1)

		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);

			break;

		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
		}
	stop++;

	if (stop > 1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
		if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
		theta[axis] += 2.0;
		if (theta[axis] > 360.0) theta[axis] -= 360.0;
		display();

	}

}
void reshape(int w, int h)
{

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	if (w <= h)

		glOrtho(-50.0, 50.0, -50.0*(GLfloat)h / (GLfloat)w, 50.0*(GLfloat)h / (GLfloat)w, -50.0, 50.0);
	else
		glOrtho(-50.0*(GLfloat)w / (GLfloat)h, 50.0*(GLfloat)w / (GLfloat)h, -50.0, 50.0, -50.0, 50.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //note the addition to double.c
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);


	glutReshapeFunc(reshape);
	// glutIdleFunc(spinDisplay);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	//glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

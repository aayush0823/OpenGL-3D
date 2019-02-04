#include "ball.h"
#include "main.h"
#include <math.h>

glm::mat4 rotatez,rotatey,rotatex;
Ball::Ball(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotationx = 0;
    this->rotationy = 0;
    this->rotationz = 0;
    this->speed = 0.1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    double pi = 3.14159265359;
    GLfloat vertex_buffer_data[1000];
    int t=0;
    for(int i=0;i<18*50;i+=18)
    {
    	vertex_buffer_data[i]=0.1*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+1]=0.1*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+2]=0.0f;
        vertex_buffer_data[i+3]=0.1*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+4]=0.1*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+5]=0.0f;
        vertex_buffer_data[i+6]=0.1*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+7]=0.1*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+8]=0.5f;

        vertex_buffer_data[i+9]=0.1*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+10]=0.1*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+11]=0.5f;
        vertex_buffer_data[i+12]=0.1*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+13]=0.1*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+14]=0.5f;
        vertex_buffer_data[i+15]=0.1*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+16]=0.1*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+17]=0.0f;
        t++;
    }
    GLfloat vertex_buffer_data_end[500];
    t=0;
    for(int i=0;i<9*50;i+=9)
    {
    	vertex_buffer_data_end[i]=0.1*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data_end[i+1]=0.1*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data_end[i+2]=0.5f;
        vertex_buffer_data_end[i+3]=0.1*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data_end[i+4]=0.1*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data_end[i+5]=0.5f;
        vertex_buffer_data_end[i+6]=0.0;
        vertex_buffer_data_end[i+7]=0.0;
        vertex_buffer_data_end[i+8]=0.7f;
        t++;
    }

    GLfloat vertex_buffer_data2[] = {
        0.05f,0.06f,0.5f,
        0.05f,0.06f,0.3f,
        0.3f,0.0f,0.3f,

        0.05f,-0.06f,0.5f,
        0.05f,-0.06f,0.3f,
        0.3f,0.0f,0.3f,

        0.05f,-0.06f,0.3f,
        0.05f,0.06f,0.3f,
        0.3f,0.0f,0.3f,

        0.05f,-0.06f,0.5f,
        0.05f,0.06f,0.5f,
        0.3f,0.0f,0.3f,

        -0.05f,0.06f,0.5f,
        -0.05f,0.06f,0.3f,
        -0.3f,0.0f,0.3f,

        -0.05f,-0.06f,0.5f,
        -0.05f,-0.06f,0.3f,
        -0.3f,0.0f,0.3f,

        -0.05f,-0.06f,0.3f,
        -0.05f,0.06f,0.3f,
        -0.3f,0.0f,0.3f,

        -0.05f,-0.06f,0.5f,
        -0.05f,0.06f,0.5f,
        -0.3f,0.0f,0.3f,

    };

    GLfloat vertex_buffer_data3[500];
    t=0;
    for(int i=0;i<9*50;i+=9)
    {
    	vertex_buffer_data3[i]=0.1*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data3[i+1]=0.1*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data3[i+2]=0.0f;
        vertex_buffer_data3[i+3]=0.1*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data3[i+4]=0.1*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data3[i+5]=0.0f;
        vertex_buffer_data3[i+6]=0.0;
        vertex_buffer_data3[i+7]=0.0;
        vertex_buffer_data3[i+8]=0.1f;
        t++;
    }

    this->object = create3DObject(GL_TRIANGLES, 3*100, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data_end, COLOR_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3*8, vertex_buffer_data2, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data3, COLOR_BLACK, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    rotatez    = glm::rotate((float) (this->rotationz * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotatey    = glm::rotate((float) (this->rotationy * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate*rotatez*rotatey);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Ball::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Ball::tick(int move) {
	if(move == 1)
		this->rotationy -= 3*speed;
	if(move == 2)
		this->rotationy += 3*speed;
	if(move == 3)
	{
		this->position.z += speed*cos(this->rotationy * M_PI / 180.0f);
		this->position.x += speed*sin(this->rotationy * M_PI / 180.0f);
	}
	if(move == 4)
	{
		this->position.z -= speed*cos(this->rotationy * M_PI / 180.0f);
		this->position.x -= speed*sin(this->rotationy * M_PI / 180.0f);
	}
	if(move == 5)
		this->position.y += speed;
	if(move == 6)
		this->position.y -= speed;
}

void Ball::rotate(int move) {
	if(move == 1)
		this->rotationz -= 3*speed;
	if(move == 2)
		this->rotationz += 3*speed;
}
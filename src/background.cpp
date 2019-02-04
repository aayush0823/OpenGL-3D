#include "background.h"
#include "main.h"
#include <math.h>

Bg::Bg(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 1 triangles each, so this makes 6*1=12 triangles, and 12*3 vertices
    // static const GLfloat vertex_buffer_data[] = {
    //     -100.0f,-20.2f,100.0f,
    //     -100.0f,-100.0f,100.0f,
    //     100.0f,-20.2f,100.0f,

    //     100.0f, -100.0f,100.0f,
    //     -100.0f,-100.0f,100.0f,
    //     100.2f,-20.2f,100.0f,

    //     -100.0f,-1.2f,-100.0f,
    //     -100.0f,-100.0f,-100.0f,
    //     100.0f,-20.2f,-100.0f,

    //     100.0f, -100.0f,-100.0f,
    //     -100.0f,-100.0f,-100.0f,
    //     100.2f,-20.2f,-100.0f,
        
    //     -100.0f,-20.2f,-100.0f,
    //     -100.0f,-20.2f,100.0f,
    //     100.0f,-20.2f,-100.0f,

    //     100.0f,-20.2f,100.0f,
    //     -100.0f,-20.2f,100.0f,
    //     100.0f,-20.2f,-100.0f,

    //     -100.0f,-100.0f,-100.0f,
    //     -100.0f,-100.0f,100.0f,
    //     100.0f,-100.0f,-100.0f,

    //     100.0f,-100.0f,100.0f,
    //     -100.0f,-100.0f,100.0f,
    //     100.0f,-100.0f,-100.0f,

    //     100.0f,-20.2f,-100.0f,
    //     100.0f,-20.2f,-100.0f,
    //     100.0f,-100.0f,100.0f,

    //     100.0f,-100.0f,100.0f,
    //     100.0f,-100.0f,-100.0f,
    //     100.0f,-20.2f,-100.0f,

    //     -100.0f,-20.2f,-100.0f,
    //     -100.0f,-20.2f,-100.0f,
    //     -100.0f,-100.0f,100.0f,

    //     -100.0f,-100.0f,100.0f,
    //     -100.0f,-100.0f,-100.0f,
    //     -100.0f,-20.2f,-100.0f,

    // };
    double pi = 3.14159265359;
    GLfloat vertex_buffer_data[500];
    int t=0;
    for(int i=0;i<9*50;i+=9)
    {
    	vertex_buffer_data[i]=1000.2*cos(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+1]=0.0f;
        vertex_buffer_data[i+2]=1000.2*sin(2*pi/(float)50*(float)t);
        vertex_buffer_data[i+3]=1000.2*cos(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+4]=0.0f;
        vertex_buffer_data[i+5]=1000.2*sin(2*pi/(float)50*(float)(t+1));
        vertex_buffer_data[i+6]=0.0f;
        vertex_buffer_data[i+7]=0.0f;
        vertex_buffer_data[i+8]=0.0f;
        t++;
    }

    this->object = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
}

void Bg::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Bg::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}
#include "dashboard.h"
#include "main.h"
#include <math.h>

void Dashboard::draw(glm::mat4 VP,float x,float y,float z, float length,int type,color_t color) {
    this->position = glm::vec3(x, y, z);
    if(type==0)
    {
        GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        0.0f+length,0.0f,0.0f,
        0.0f+length,0.0f,0.3f,

        0.0f,0.0f,0.0f,
        0.0f,0.0f,0.3f,
        0.0f+length,0.0f,0.3f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data, color, GL_FILL);
    }
    else if(type==1)
    {
        GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        0.0f+length,0.0f,0.0f,
        0.0f+length,0.0f,0.4f,

        0.0f,0.0f,0.0f,
        0.0f,0.0f,0.4f,
        0.0f+length,0.0f,0.4f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data,color, GL_FILL);
    }
    else if(type==2)
    {
        GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f+length,0.1f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f+length,0.1f,0.0f,
        0.0f+length,0.0f,0.0f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data, color, GL_FILL);
    }
    else if(type==3)
    {
        GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f+length,0.1f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f+length,0.1f,0.0f,
        0.0f+length,0.0f,0.0f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data,color, GL_FILL);
    }
    else if(type==4)
    {
        double pi = 3.14159265359;
        int t=0;
        GLfloat vertex_buffer_data[]={
            0.05f,0.05f,0.0f,
            0.05f,0.04f,0.0f,
            -0.05f,0.05f,0.0f,

            0.05f,0.04f,0.0f,
            -0.05f,0.04f,0.0f,
            -0.05f,0.05f,0.0f,

            0.05f,-0.05f,0.0f,
            0.05f,-0.04f,0.0f,
            -0.05f,-0.05f,0.0f,

            0.05f,-0.04f,0.0f,
            -0.05f,-0.04f,0.0f,
            -0.05f,-0.05f,0.0f,

            0.05f,0.05f,0.0f,
            0.04f,0.05f,0.0f,
            0.05f,-0.05f,0.0f,

            0.04f,0.05f,0.0f,
            0.04f,-0.05f,0.0f,
            0.05f,-0.05f,0.0f,

            -0.05f,0.05f,0.0f,
            -0.04f,0.05f,0.0f,
            -0.05f,-0.05f,0.0f,

            -0.04f,0.05f,0.0f,
            -0.04f,-0.05f,0.0f,
            -0.05f,-0.05f,0.0f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*8, vertex_buffer_data, color, GL_FILL);
    }
    this->speed = 0.1;
    glm::mat4 rotatey;
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotatez    = glm::rotate((float) (this->rotationz * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 rotatex    = glm::rotate((float) (this->rotationx * M_PI / 180.0f), glm::vec3(1, 0, 0));
    if(type==1)
        rotatey = glm::rotate((float)(45* M_PI / 180.0f), glm::vec3(0, 1, 0));
    else
        rotatey = glm::rotate((float) (this->rotationy * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate*rotatey*rotatex*rotatez);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Dashboard::tick(int move) {
    if(move == 1)
        this->rotationy -= 3*speed;
    if(move == 2)
        this->rotationy += 3*speed;
    if(move == 3)
    {
        this->position.z += speed*cos(this->rotationy * M_PI / 180.0f)*cos(this->rotationx * M_PI / 180.0f);
        this->position.x += speed*sin(this->rotationy * M_PI / 180.0f)*cos(this->rotationx * M_PI / 180.0f);
        this->position.y -= speed*sin(this->rotationx * M_PI / 180.0f);
    }
    if(move == 4)
    {
        this->position.z -= speed*cos(this->rotationy * M_PI / 180.0f)*cos(this->rotationx * M_PI / 180.0f);
        this->position.x -= speed*sin(this->rotationy * M_PI / 180.0f)*cos(this->rotationx * M_PI / 180.0f);
        this->position.y += speed*sin(this->rotationx * M_PI / 180.0f);
    }
    if(move == 5)
        this->position.y += speed;
    if(move == 6)
        this->position.y -= speed;
}
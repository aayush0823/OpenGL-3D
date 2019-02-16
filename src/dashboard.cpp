#include "dashboard.h"
#include "main.h"
#include <math.h>
GLfloat vertex_buffer_board[] = {
        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f,0.1f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f,0.0f,0.0f,
        };
GLfloat vertex_buffer_arrow[]={
            -0.05f,0.0f,0.0f,
             0.5,0.5,0.0f,
             0.05f,0.0f,0.0f,
        };       
double pi = 3.14159265359;
Dashboard::Dashboard(float x, float y,float z, color_t color,int type) {
    this->position = glm::vec3(x, y, z);
    if(type==0)
    {
        GLfloat vertex_buffer_board[] = {
        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f,0.1f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f,0.0f,0.0f,
        };
    }
    else if(type==1)
    {
        int t=0;
        GLfloat vertex_buffer_speed[225];
        for(int i=0;i<9*25;i+=9)
        {
            vertex_buffer_speed[i]=0.6*cos(2*pi/(float)50*(float)t);
            vertex_buffer_speed[i+1]=0.6*sin(2*pi/(float)50*(float)t);
            vertex_buffer_speed[i+2]=0.0f;
            vertex_buffer_speed[i+3]=0.6*cos(2*pi/(float)50*(float)(t+1));
            vertex_buffer_speed[i+4]=0.6*sin(2*pi/(float)50*(float)(t+1));
            vertex_buffer_speed[i+5]=0.0f;
            vertex_buffer_speed[i+6]=0.0;
            vertex_buffer_speed[i+7]=0.0;
            vertex_buffer_speed[i+8]=0.0f;
            t++;
        }
        GLfloat vertex_buffer_arrow[]={
            -0.05f,0.0f,0.0f,
             0.5,0.5,0.0f,
             0.05f,0.0f,0.0f,
        };

        this->object = create3DObject(GL_TRIANGLES, 3*25, vertex_buffer_speed, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_arrow, COLOR_RED, GL_FILL);
    }
    else if(type==2)
    {
        double pi = 3.14159265359;
        GLfloat dashboard_data[360];
        int t=0;
        for(int i=0;i<9*40;i+=9)
        {
            dashboard_data[i]=1.0*cos(2*pi/(float)40*(float)t);
            dashboard_data[i+1]=1.0*sin(2*pi/(float)40*(float)t);
            dashboard_data[i+2]=0.0f;
            dashboard_data[i+3]=1.0*cos(2*pi/(float)40*(float)(t+1));
            dashboard_data[i+4]=1.0*sin(2*pi/(float)40*(float)(t+1));
            dashboard_data[i+5]=0.0f;
            dashboard_data[i+6]=0.0f;
            dashboard_data[i+7]=0.0f;
            dashboard_data[i+8]=0.0f;
            t++;
        }

        this->object = create3DObject(GL_TRIANGLES, 3*40, dashboard_data, color, GL_FILL);
    }
    else if(type==3)
    {
        GLfloat vertex_buffer_player[]={
            -0.1f,-0.1f,0.0f,
             0.1f,-0.1f,0.0f,
             0.0f, 0.1f,0.0f,

            -0.05f,-0.1f,0.0f,
             0.05f,-0.1f,0.0f,
             0.05f,-0.2f,0.0f,

             -0.05f,-0.2f,0.0f,
              0.05f,-0.2f,0.0f,
             -0.05f,-0.1f,0.0f,
        };
        this->object = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_player, color, GL_FILL);
    }
    else if(type == 4)
    {
        GLfloat vertex_buffer_data1[]={
            -0.02f,-0.02f,0.0f,
             0.02f,-0.02f,0.0f,
            -0.02f, 0.02f,0.0f,

             0.02f, 0.02f,0.0f,
             0.02f,-0.02f,0.0f,
            -0.02f, 0.02f,0.0f
        };
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data1, color, GL_FILL);
    }
}


GLfloat dashboard_data[230];
void Dashboard::draw(glm::mat4 VP,float x,float y,float z, float length,color_t color,int type) {
    if(type==0)
    {
        vertex_buffer_board[6]=length;
        vertex_buffer_board[12]=length;
        vertex_buffer_board[15]=length;
        this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_board, color, GL_FILL);
    }
    else if(type==1)
    {
        if(length>0.57)length = 0.57;
        vertex_buffer_arrow[3] = 0.5*cos(2*pi/(float)1.2*length);
        vertex_buffer_arrow[4] = 0.5*sin(2*pi/(float)1.2*length);
        this->object1 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_arrow, COLOR_RED, GL_FILL);
    }
    else if(type == 4)
    {
        this->position = glm::vec3(x, y, z);
    }
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotatey    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(0, 1, 0));
    if(type==3)
        rotatey = glm::rotate((float) (-length * M_PI / 180.0f), glm::vec3(0, 0, 1));
    else
        rotatey    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(0, 1, 0));

    Matrices.model *= (translate*rotatey);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    if(type==1)
        draw3DObject(this->object1);
}
#include "enemy.h"
#include "main.h"
#include <math.h>

float mod(float a)
{
	if(a>0)return a;
	return -a;
}

Enemy::Enemy(float x, float y,float z, color_t color, int type ) {
    this->position = glm::vec3(x, y, z);
    this->speed = 0.3;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    double pi = 3.14159265359;
    int t=0;
    if(type==1)//island
    {
        GLfloat vertex_buffer_data[500];
        for(int i=0;i<9*50;i+=9)
        {
    	   vertex_buffer_data[i]=1.2*cos(2*pi/(float)50*(float)t);
            vertex_buffer_data[i+2]=1.2*sin(2*pi/(float)50*(float)t);
            vertex_buffer_data[i+1]=0.0f;
            vertex_buffer_data[i+3]=1.2*cos(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data[i+5]=1.2*sin(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data[i+4]=0.0f;
            vertex_buffer_data[i+6]=0.0;
            vertex_buffer_data[i+7]=0.0;
            vertex_buffer_data[i+8]=0.0f;
            t++;
        }
        this->object = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
    }
    if(type==2)//fuel
    {
        GLfloat vertex_buffer_data[] = {
        -0.1f,-0.1f + 0.1f,-0.1f,
        -0.1f,-0.1f + 0.1f, 0.1f,
        -0.1f, 0.1f + 0.1f, 0.1f,

         0.1f,0.1f + 0.1f,-0.1f,
        -0.1f,-0.1f + 0.1f,-0.1f,
        -0.1f, 0.1f + 0.1f,-0.1f,
        
        0.1f,0.1f + 0.1f,-0.1f,
        0.1f,-0.1f + 0.1f,-0.1f,
        -0.1f,-0.1f + 0.1f,-0.1f,
        
        -0.1f,-0.1f + 0.1f,-0.1f,
        -0.1f,0.1f + 0.1f, 0.1f,
        -0.1f, 0.1f + 0.1f,-0.1f,
        
         0.1f,-0.1f + 0.1f, 0.1f,
        -0.1f,-0.1f + 0.1f, 0.1f,
        -0.1f,-0.1f + 0.1f,-0.1f,
        
        -0.1f, 0.1f + 0.1f, 0.1f,
        -0.1f,-0.1f + 0.1f, 0.1f,
         0.1f,-0.1f + 0.1f, 0.1f,
        
        0.1f, 0.1f + 0.1f, 0.1f,
        0.1f,-0.1f + 0.1f,-0.1f,
        0.1f, 0.1f + 0.1f,-0.1f,
        
        0.1f,-0.1f + 0.1f,-0.1f,
        0.1f, 0.1f + 0.1f, 0.1f,
        0.1f,-0.1f + 0.1f, 0.1f,
        
         0.1f, 0.1f + 0.1f, 0.1f,
         0.1f, 0.1f + 0.1f,-0.1f,
        -0.1f, 0.1f + 0.1f,-0.1f,
        
         0.1f, 0.1f + 0.1f, 0.1f,
        -0.1f, 0.1f + 0.1f,-0.1f,
        -0.1f, 0.1f + 0.1f, 0.1f,
        };

        this->object = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
    }
    if(type==3)//volcano
    {
        GLfloat vertex_buffer_data[500];
        for(int i=0;i<9*50;i+=9)
        {
            vertex_buffer_data[i]=0.6*cos(2*pi/(float)50*(float)t);
            vertex_buffer_data[i+1]=0.0f;
            vertex_buffer_data[i+2]=0.6*sin(2*pi/(float)50*(float)t);
            vertex_buffer_data[i+3]=0.6*cos(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data[i+4]=0.0f;
            vertex_buffer_data[i+5]=0.6*sin(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data[i+6]=0.0;
            vertex_buffer_data[i+7]=1.0;
            vertex_buffer_data[i+8]=0.0f;
            t++;
        }
        GLfloat vertex_buffer_data2[500];
        for(int i=0;i<9*50;i+=9)
        {
            vertex_buffer_data2[i]=0.2*cos(2*pi/(float)50*(float)t);
            vertex_buffer_data2[i+1]=0.7f;
            vertex_buffer_data2[i+2]=0.2*sin(2*pi/(float)50*(float)t);
            vertex_buffer_data2[i+3]=0.2*cos(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data2[i+4]=0.7f;
            vertex_buffer_data2[i+5]=0.2*sin(2*pi/(float)50*(float)(t+1));
            vertex_buffer_data2[i+6]=0.0;
            vertex_buffer_data2[i+7]=1.0;
            vertex_buffer_data2[i+8]=0.0f;
            t++;
        }
        this->object = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
    }
    if(type==4)//bomb
    {
    	this->inibombx = this->position.x;
    	this->inibomby = this->position.y;
    	this->inibombz = this->position.z;

        GLfloat vertex_buffer_data[1000];
        for(int i=0;i<9*10;i+=9)
        {
            vertex_buffer_data[i]=0.05*cos(2*pi/(float)10*(float)t);
            vertex_buffer_data[i+1]=0.0f;
            vertex_buffer_data[i+2]=0.05*sin(2*pi/(float)10*(float)t);
            vertex_buffer_data[i+3]=0.05*cos(2*pi/(float)10*(float)(t+1));
            vertex_buffer_data[i+4]=0.0f;
            vertex_buffer_data[i+5]=0.05*sin(2*pi/(float)10*(float)(t+1));
            vertex_buffer_data[i+6]=0.0;
            vertex_buffer_data[i+7]=0.0;
            vertex_buffer_data[i+8]=0.0f;
            t++;
        }
        for(int i=9*10;i<9*20;i+=9)
        {
            vertex_buffer_data[i]=0.05*cos(2*pi/(float)10*(float)t);
            vertex_buffer_data[i+1]=0.05*sin(2*pi/(float)10*(float)t);
            vertex_buffer_data[i+2]=0.0f;
            vertex_buffer_data[i+3]=0.05*cos(2*pi/(float)10*(float)(t+1));
            vertex_buffer_data[i+4]=0.05*sin(2*pi/(float)10*(float)(t+1));
            vertex_buffer_data[i+5]=0.0f;
            vertex_buffer_data[i+6]=0.0;
            vertex_buffer_data[i+7]=0.0;
            vertex_buffer_data[i+8]=0.0f;
            t++;
        }
        this->object = create3DObject(GL_TRIANGLES, 3*20, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_data, color, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_data, color, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_data, color, GL_FILL);
    }
    if(type == 5)//missile
    {
    	GLfloat vertex_buffer_data[500];
    	GLfloat vertex_buffer_data2[500];
    	int t=0;
    	for(int i=0;i<9*50;i+=9)
    	{
    		vertex_buffer_data[i]=0.05*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+1]=0.05*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+2]=0.0f;
       		vertex_buffer_data[i+3]=0.05*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data[i+4]=0.05*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data[i+5]=0.0f;
        	vertex_buffer_data[i+6]=0.05*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+7]=0.05*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+8]=0.2f;

        	vertex_buffer_data2[i]=0.05*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data2[i+1]=0.05*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data2[i+2]=0.2f;
        	vertex_buffer_data2[i+3]=0.05*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+4]=0.05*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+5]=0.2f;
        	vertex_buffer_data2[i+6]=0.05*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+7]=0.05*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+8]=0.0f;
        	t++;
    	}
    	this->object = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, COLOR_BLACK, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
    }
    if(type == 6)//boat
    {

    GLfloat base_vertex_buffer_data[] = {
        -.101f, -.101f, -0.201f,
        0.101f, -0.101f, -0.201f,
        -0.101f, -0.101f, 0.201f,

        -0.101f, -0.101f,0.201f,
        0.101f, -0.101f, 0.201f,
        0.101f, -0.101f, -0.201f
    };
    GLfloat side_vertex_buffer_data[] = {
        -0.101f, -0.101f, -0.201f,
        -0.101f, -0.101f, 0.201f,
        -0.201f, 0.101f, 0.301f,

        -0.101f, -0.101f, -0.201f,
        -0.201f, 0.101f, 0.301f,
        -0.201f, 0.101f, -0.301f,

        0.101f, -0.101f, -0.201f,
        0.101f, -0.101f, 0.201f,
        0.201f,  0.101f, 0.301f,

        0.101f, -0.101f, -0.201f,
        0.201f, 0.101f, 0.301f,
        0.201f, 0.101f, -0.301f,

    };
    GLfloat face_vertex_buffer_data[] = {
        -0.201f,   0.101f,-0.301f,
        -0.101f, -0.101f, -0.201f,
        0.001f, 0.201f,-0.401f,

        0.201f, 0.101f,-0.301f,
        0.101f,  -0.101f,-0.201f,
        0.001f, 0.201f,-0.401f,

        0.001f, 0.201f,-0.401f,
        -0.101f, -0.101f,-0.201f,
        0.101f, -0.101f,-0.201f,

        -0.201f, 0.101f, 0.301f,
        -0.101f,-0.101f, 0.201f,
        0.001f, 0.201f, 0.401f,

        0.201f, 0.101f,0.301f,
        0.101f,  -0.101f,0.201f,
        0.001f,  0.201f,0.401f,

        0.001f, 0.201f,0.401f,
        -0.101f,-0.101f, 0.201f,
        0.101f,-0.101f, 0.201f,

    };

    GLfloat pole_vertex_buffer_data[] = {
    	0.03f,0.0f,0.0f,
    	-0.03f,0.0f,0.0f,
    	0.03f,1.0f,0.0f,

    	-0.03f,0.0f,0.0f,
    	-0.03f,1.0f,0.0f,
    	0.03f,1.0f,0.0f,

    	0.0f,0.0f,0.03f,
    	0.0f,0.0f,-0.03f,
    	0.0f,1.0f,0.03f,

    	0.0f,0.0f,-0.03f,
    	0.0f,1.0f,-0.03f,
    	0.0f,1.0f,0.03f,

    };
    this->object = create3DObject(GL_TRIANGLES, 2 * 3, base_vertex_buffer_data, COLOR_BROWN);
    this->object1 = create3DObject(GL_TRIANGLES, 4 * 3, side_vertex_buffer_data,COLOR_RED);
    this->object2 = create3DObject(GL_TRIANGLES, 6 * 3, face_vertex_buffer_data,COLOR_ORANGE);
    this->object3 = create3DObject(GL_TRIANGLES, 4 * 3, pole_vertex_buffer_data,COLOR_WHITE);
    }

    if(type==7)//cannon
    {
        GLfloat vertex_buffer_data[] = {
        -0.2f,-0.2f , 0.2f,
        -0.2f, 0.2f , 0.2f,
         0.2f,-0.2f , 0.2f,

         0.2f,0.2f,0.2f,
        -0.2f, 0.2f,0.2f,
         0.2f,-0.2f,0.2f,

         -0.2f,-0.2f ,-0.2f,
        -0.2f, 0.2f ,-0.2f,
         0.2f,-0.2f ,-0.2f,

         0.2f,0.2f,-0.2f,
        -0.2f, 0.2f,-0.2f,
         0.2f,-0.2f,-0.2f,

         0.2f,-0.2f ,-0.2f,
         0.2f, 0.2f ,-0.2f,
         0.2f,-0.2f , 0.2f,

         0.2f,0.2f,0.2f,
         0.2f,0.2f,-0.2f,
         0.2f,-0.2f,0.2f,
        
        -0.2f,0.2f ,-0.2f,
        -0.2f,-0.2f,-0.2f,
        -0.2f,-0.2f, 0.2f,
        
        -0.2f, 0.2f, 0.2f,
        -0.2f,-0.2f, 0.2f,
        -0.2f, 0.2f,-0.2f,
        
         0.2f,-0.2f,-0.2f,
        -0.2f,-0.2f, 0.2f,
        -0.2f,-0.2f,-0.2f,
        
        -0.2f,-0.2f , 0.2f,
         0.2f,-0.2f ,-0.2f,
         0.2f,-0.2f , 0.2f,
        
        -0.2f, 0.2f, 0.2f,
        -0.2f,0.2f,-0.2f,
        0.2f, 0.2f,-0.2f,
        
        0.2f,0.2f ,-0.2f,
        -0.2f,0.2f , 0.2f,
        0.2f,0.2f , 0.2f,
        };

        this->object = create3DObject(GL_TRIANGLES, 3*12, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*12, vertex_buffer_data, color, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*12, vertex_buffer_data, color, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*12, vertex_buffer_data, color, GL_FILL);
    }
    if(type==8)//arrow
    {
        GLfloat vertex_buffer_data[] = {
        -0.2f,0.3f ,-0.2f,
        -0.2f,0.3f , 0.2f,
        -0.2f,1.0f ,-0.2f,

        -0.2f,1.0f , 0.2f,
        -0.2f,0.3f , 0.2f,
        -0.2f,1.0f ,-0.2f,

         0.2f,0.3f ,-0.2f,
         0.2f,0.3f , 0.2f,
         0.2f,1.0f ,-0.2f,

         0.2f,1.0f , 0.2f,
         0.2f,0.3f , 0.2f,
         0.2f,1.0f ,-0.2f,

        -0.2f,0.3f ,-0.2f,
         0.2f,0.3f ,-0.2f,
        -0.2f,1.0f ,-0.2f,

         0.2f,1.0f ,-0.2f,
         0.2f,0.3f ,-0.2f,
        -0.2f,1.0f ,-0.2f,

        -0.2f,0.3f , 0.2f,
         0.2f,0.3f , 0.2f,
        -0.2f,1.0f , 0.2f,

         0.2f,1.0f , 0.2f,
         0.2f,0.3f , 0.2f,
        -0.2f,1.0f , 0.2f,

        -0.2f,0.3f ,-0.2f,
         0.2f,0.3f ,-0.2f,
        -0.2f,0.3f , 0.2f,

         0.2f,0.3f ,-0.2f,
         0.2f,0.3f ,0.2f,
        -0.2f,0.3f ,0.2f,

        -0.2f,1.0f ,-0.2f,
         0.2f,1.0f ,-0.2f,
        -0.2f,1.0f , 0.2f,

         0.2f,1.0f ,-0.2f,
         0.2f,1.0f ,0.2f,
        -0.2f,1.0f ,0.2f,

        -0.3f,0.3f ,0.2f,
         0.3f,0.3f ,0.2f,
         0.0f,0.0f ,0.2f,

        -0.3f,0.3f ,-0.2f,
         0.3f,0.3f ,-0.2f,
         0.0f,0.0f ,-0.2f,

		};

        this->object = create3DObject(GL_TRIANGLES, 3*14, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*10, vertex_buffer_data, color, GL_FILL);
    }
    if(type == 9)
    {
    	GLfloat vertex_buffer_data[450];
    	GLfloat vertex_buffer_data2[450];
    	int t=0;
    	for(int i=0;i<9*50;i+=9)
    	{
    		vertex_buffer_data[i]=0.18*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+1]=0.18*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+2]=0.0f;
       		vertex_buffer_data[i+3]=0.18*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data[i+4]=0.18*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data[i+5]=0.0f;
        	vertex_buffer_data[i+6]=0.15*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+7]=0.15*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data[i+8]=0.0f;

        	vertex_buffer_data2[i]=0.15*cos(2*pi/(float)50*(float)t);
        	vertex_buffer_data2[i+1]=0.15*sin(2*pi/(float)50*(float)t);
        	vertex_buffer_data2[i+2]=0.0f;
       		vertex_buffer_data2[i+3]=0.15*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+4]=0.15*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+5]=0.0f;
        	vertex_buffer_data2[i+6]=0.18*cos(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+7]=0.18*sin(2*pi/(float)50*(float)(t+1));
        	vertex_buffer_data2[i+8]=0.0f;
        	t++;
    	}
    	this->object  = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data, COLOR_GREY, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_GREY, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_GREY, GL_FILL);
        this->object3 = create3DObject(GL_TRIANGLES, 3*50, vertex_buffer_data2, COLOR_GREY, GL_FILL);
    }
}

void Enemy::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Enemy::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Enemy::boom(float rotationx , float rotationy) { 
    this->position.x += speed*sin(rotationy * M_PI / 180.0f);
    this->position.y += -2*speed*sin(rotationx * M_PI / 180.0f);
    this->position.z += speed*cos(rotationx * M_PI / 180.0f)*cos(rotationy * M_PI / 180.0f);
}

void Enemy::missile() { 
    this->position.y -= speed/3;
}

void Enemy::enemybomb(){
	if(this->inibombx-this->playerx > 0)
		this->position.x -= speed*(mod(this->inibombx-this->playerx)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));
	else
		this->position.x += speed*(mod(this->inibombx-this->playerx)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));

	if(this->inibomby-this->playery > 0)
		this->position.y -= speed*(mod(this->inibomby-this->playery)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));
	else
		this->position.y += speed*(mod(this->inibomby-this->playery)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));
	
	if(this->inibombz-this->playerz > 0)
		this->position.z -= speed*(mod(this->inibombz-this->playerz)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));
	else
		this->position.z += speed*(mod(this->inibombz-this->playerz)/(mod(this->inibombx-this->playerx)+mod(this->inibomby-this->playery)+mod(this->inibombz-this->playerz)));
}
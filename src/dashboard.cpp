#include "dashboard.h"
#include "main.h"
#include <math.h>

void Dashboard::draw(glm::mat4 VP,float x,float y,float z, float length,color_t color) {
    this->position = glm::vec3(x, y, z);

        GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        0.0f,0.1f,0.0f,
        0.0f+length,0.1f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f+length,0.1f,0.0f,
        0.0f+length,0.0f,0.0f,
        };
    this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data, color, GL_FILL);
    Matrices.model = glm::mat4(0.2f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
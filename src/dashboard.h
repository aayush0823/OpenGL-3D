#include "main.h"

#ifndef DB_H
#define DB_H


class Dashboard {
public:
    Dashboard() {}
    glm::vec3 position;
    void draw(glm::mat4 VP,float x, float y,float z,float length,color_t color,int type);
private:
    VAO *object;
    VAO *object1;
};

#endif // DB_H

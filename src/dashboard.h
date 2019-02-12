#include "main.h"

#ifndef DB_H
#define DB_H


class Dashboard {
public:
    Dashboard() {}
    glm::vec3 position;
    float rotationx;
    float rotationy;
    float rotationz;
    void draw(glm::mat4 VP,float x, float y,float z,float length,int type,color_t color);
    void tick(int move);
    void rotate(int move);
    double speed;
private:
    VAO *object;
};

#endif // DB_H

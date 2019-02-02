#include "main.h"

#ifndef BALL_H
#define BALL_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    double speed;
private:
    VAO *object;
};

#endif // BALL_H

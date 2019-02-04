#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotationx;
    float rotationy;
    float rotationz;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick(int move);
    void rotate(int move);
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H

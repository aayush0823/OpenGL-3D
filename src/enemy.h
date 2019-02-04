#include "main.h"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float z, color_t color , int type);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void boom(float rotation);
    void missile();
    double speed;
private:
    VAO *object;
    VAO *object1;
};

#endif // BALL_H

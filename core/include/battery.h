//
// Created by adolin on 24. 01. 21.
//

#ifndef ARC_ENGINE_BATTERY_H
#define ARC_ENGINE_BATTERY_H
#include "engine_includes.h"
class Battery{
public:
    Battery();

    void set_level(int level){level_ = level;}

    void Render(arc::BatchRenderer& batch);
private:
    int level_;

    glm::vec3 pos_;
    glm::vec2 size_;
    glm::vec2 pixel_size_;
    arc::Texture battery_, bar_;
};
#endif //ARC_ENGINE_BATTERY_H

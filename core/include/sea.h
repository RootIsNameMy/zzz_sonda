//
// Created by adolin on 24. 01. 21.
//

#ifndef ARC_ENGINE_SEA_H
#define ARC_ENGINE_SEA_H
#include "engine_includes.h"
class Sea{
public:
    Sea();

    void Update(float delta);
    void Render(arc::BatchRenderer& batch);
private:
    int height_,width_;
    glm::vec2 size_;
    glm::vec3 pos_;
    uint8_t* data_;
    arc::Texture sea_;
};
#endif //ARC_ENGINE_SEA_H

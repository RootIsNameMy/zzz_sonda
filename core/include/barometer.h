//
// Created by adolin on 24. 01. 21.
//

#ifndef ARC_ENGINE_BAROMETER_H
#define ARC_ENGINE_BAROMETER_H
#include "engine_includes.h"
class Barometer{
public:
    Barometer();

    void set_pressure(float pressure){
        pressure_ = std::max(min_,std::min(max_,pressure));
        progress_ = (pressure - min_ )/(max_ - min_);
    }

    void Render(arc::BatchRenderer& batch);
private:
    float pressure_, max_, min_, progress_;

    glm::vec3 pos_;
    glm::vec2 size_;
    glm::vec2 pixel_size_;
    arc::Texture barometer_, pointer_;
};
#endif //ARC_ENGINE_BATTERY_H

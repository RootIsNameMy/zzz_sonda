//
// Created by adolin on 23. 01. 21.
//

#ifndef ARC_ENGINE_TEMPERATURE_METER_H
#define ARC_ENGINE_TEMPERATURE_METER_H
#include "engine_includes.h"
class TemperatureMeter{
public:
    TemperatureMeter(float min = -30, float max = 50);

    inline void set_temp(float temp){
        temp_ = temp;
        progress_ = (float)(temp_-min_)/span_;
    }
    void Update(float delta);
    void Render(arc::BatchRenderer& batch);

    const float& min()const {return min_;}
    float max()const {return min_ + span_;}
private:
    float min_,span_, width_, height_;
    float temp_;
    float progress_;
    glm::vec3 pos_;

    arc::Texture light_,container_,inner_core_, outer_core_, top_;

};
#endif //ARC_ENGINE_TEMPERATURE_METER_H

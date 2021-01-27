//
// Created by adolin on 25. 01. 21.
//

#ifndef ARC_ENGINE_SUN_AND_MOON_H
#define ARC_ENGINE_SUN_AND_MOON_H
#include "engine_includes.h"
class SunAndMoon{
public:
    SunAndMoon();

    void set_time(int time){
        time = std::abs(time);
        time +=18*60;
        time_ = time%(24*60);

        progress_ = (float)time_/(24.0f*60.0f);
    }
    void Render(arc::BatchRenderer& batch);
private:
    int time_;//0-24*60
    float progress_;
    glm::vec2 sun_size_, moon_size_;
    glm::vec3 pos_;
    arc::Texture sun_, rays_, moon_;

};
#endif //ARC_ENGINE_SUN_AND_MOON_H

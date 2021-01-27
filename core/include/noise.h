//
// Created by adolin on 25. 01. 21.
//

#ifndef ARC_ENGINE_NOISE_H
#define ARC_ENGINE_NOISE_H
#include "engine_includes.h"
class Noise{
public:
    static void Setup(uint64_t seed);


    static float Waves(glm::vec2 p);

private:
    static float Fade(float t);

    static float Grad(int p1, int p2);
};
#endif //ARC_ENGINE_NOISE_H

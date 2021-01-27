//
// Created by adolin on 25. 01. 21.
//

#include "noise.h"
#include <random>
struct NoiseData{
    int width;
    int8_t *values;


};
static NoiseData s_data;

float Noise::Fade(float t) {
    return t*t*t*(t*(t*6 - 15) + 10);
}
float Noise::Grad(int p1, int p2) {
    p1 %=s_data.width;
    p2 %=s_data.width;
    return (float)s_data.values[p1*s_data.width + p2];
}

float Noise::Waves(glm::vec2 p) {
    glm::vec2 p0 = glm::floor(p);
    glm::vec2 p1 = p0 + glm::vec2{1,0};
    glm::vec2 p2 = p0 + glm::vec2{0,1};
    glm::vec2 p3 = p0 + glm::vec2{1,1};



    float g0 = Grad((int) p0.x, (int) p0.y);
    float g1 = Grad((int) p1.x, (int) p1.y);
    float g2 = Grad((int) p2.x, (int) p2.y);
    float g3 = Grad((int) p3.x, (int) p3.y);


    float t0 = p.x - p0.x;
    float fade_t0 = Fade(t0);

    float t1 = p.y - p0.y;
    float fade_t1 = Fade(t1);

    float p0p1 = (1.0f - fade_t0) * glm::dot(glm::vec2(g0) ,(p - p0)) + fade_t0 * glm::dot(glm::vec2(g1), (p - p1)); /* between upper two lattice points */
    float p2p3 = (1.0f - fade_t0) * glm::dot(glm::vec2(g2), (p - p2)) + fade_t0 * glm::dot(glm::vec2(g3), (p - p3)); /* between lower two lattice points */


    return (1.0f - fade_t1) * p0p1 + fade_t1 * p2p3;
}

void Noise::Setup(uint64_t seed){
    int width = 100;
    s_data.width = width;
    s_data.values = new int8_t[width*width];

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int8_t> dis(0,1);

    for (int i = 0; i < width*width; ++i) {
        s_data.values[i] = dis(gen)*2 - 1;
    }
}

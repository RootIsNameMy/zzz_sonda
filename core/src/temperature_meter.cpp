//
// Created by adolin on 23. 01. 21.
//
#include "temperature_meter.h"

TemperatureMeter::TemperatureMeter(float min, float max):min_(min), span_(max-min),temp_(0) {

    container_.Create2D("temp_meter/container.png");
    inner_core_.Create2D( "temp_meter/inner_core.png");
    outer_core_.Create2D( "temp_meter/outer_core.png");
    light_.Create2D("temp_meter/light.png");
    top_.Create2D("temp_meter/top.png");

    height_ = (float)container_.height();
    width_ = (float)container_.width()/(float)height_;

    height_ = (float)arc::Engine::window().height()/3.5f;
    width_*=height_;
    pos_ = {(float)arc::Engine::window().width()/2.0f-width_/2.0f - 20,-(float)arc::Engine::window().height()/2.0f + height_/2 + 20,0};
}

void TemperatureMeter::Update(float delta) {

}

void TemperatureMeter::Render(arc::BatchRenderer& batch) {


    glm::vec4 light = arc::Color::InterpolateRGB(0x8eb6ff,0xfa8c8c,progress_);
    glm::vec4 medium = arc::Color::InterpolateRGB(0x639bff,0xff6363,progress_);
    glm::vec4 dark = arc::Color::InterpolateRGB(0x4d78c5,0xc44f4f,progress_);

    batch.DrawTexture(inner_core_, pos_, {width_, height_},  medium);
    batch.DrawTexture(outer_core_, pos_, {width_, height_},  dark);
    //pillers

    float h1 = height_/(const float)container_.height();

    float min = 14*h1;
    float half = height_/2.0f;

    float h  = (1 + progress_*22)*h1;
    float pos_y =  min + h / 2.0f - half;





    batch.DrawQuad(pos_ + glm::vec3(0,pos_y,0),{width_*6/(const float)container_.width(),h},dark);
    batch.DrawQuad(pos_ + glm::vec3(0,pos_y,0),{width_*4/(const float)container_.width(),h},medium);

    batch.DrawTexture(top_,pos_ + glm::vec3(0,h1*progress_*22,0), {width_, height_},light);
    batch.DrawTexture(container_,pos_, {width_, height_},medium);
    batch.DrawTexture(light_,pos_, {width_, height_},{1,1,1,0.75f});
}

//
// Created by adolin on 24. 01. 21.
//
#include "barometer.h"

Barometer::Barometer():max_(1060), min_(970) {

    barometer_.Create2D( "barometer/barometer.png");
    pointer_.Create2D( "barometer/pointer.png");

    size_.y = (float)barometer_.height();
    size_.x = (float)barometer_.width() / (float)size_.y;

    size_.y = (float)arc::Engine::window().height()/4.0f;
    size_.x*=size_.y;
    pos_ = {(float)arc::Engine::window().width()/2.0f-size_.x/2.0f - 20 - 200,-(float)arc::Engine::window().height()/2.0f + size_.y/2 + 20,0};

    pixel_size_ = size_ /glm::vec2(barometer_.width(), barometer_.height());

}

void Barometer::Render(arc::BatchRenderer &batch) {
    batch.DrawTexture(barometer_, pos_, size_);

    float flux = std::sin(arc::Engine::running_time()*15.0f);
    float angle = -progress_*230 + 115 + flux*3;


    batch.DrawTexture(pointer_, pos_ , size_,angle);



}

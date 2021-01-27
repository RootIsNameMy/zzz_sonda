//
// Created by adolin on 24. 01. 21.
//
#include "battery.h"

Battery::Battery() {

    battery_.Create2D( "battery/battery.png");
    bar_.Create2D( "battery/bar.png");

    size_.y = (float)battery_.height();
    size_.x = (float)battery_.width()/(float)size_.y;

    size_.y = (float)arc::Engine::window().height()/5.0f;
    size_.x*=size_.y;
    pos_ = {(float)arc::Engine::window().width()/2.0f-size_.x/2.0f - 20 - 100,-(float)arc::Engine::window().height()/2.0f + size_.y/2 + 20,0};

    pixel_size_ = size_ /glm::vec2(battery_.width(),battery_.height());

}

void Battery::Render(arc::BatchRenderer &batch) {
    batch.DrawTexture(battery_,pos_,size_);

    float progress = (float)level_/100.0f;
    float h = progress*pixel_size_.y*25;



    batch.DrawTexture(bar_,pos_+glm::vec3(0,h,0),size_);
    batch.DrawQuad(pos_ + glm::vec3(-pixel_size_.x*7,h/2 - size_.y/2.0f  + pixel_size_.y*2.5,0),{pixel_size_.x, std::max(h -  pixel_size_.y,0.0f)},
                   arc::Color::InterpolateArc(0xfc9090, 0xbfff92, progress));//; 0-1
    batch.DrawQuad(pos_ + glm::vec3(-pixel_size_.x*5.5f,h/2 - size_.y/2.0f + pixel_size_.y*1.5,0),{pixel_size_.x*2, std::max(h -  pixel_size_.y,0.0f)},
                   arc::Color::InterpolateArc(0xfc5353, 0x9bff54, progress));
    batch.DrawQuad(pos_ + glm::vec3(0,h/2 - size_.y/2.0f + pixel_size_.y*0.5,0),{pixel_size_.x*9, std::max(h -  pixel_size_.y,0.0f)},
                   arc::Color::InterpolateArc(0xf43e3e, 0x8bf540, progress));//
    batch.DrawQuad(pos_ + glm::vec3(+pixel_size_.x*5.5f,h/2 - size_.y/2.0f + pixel_size_.y*1.5,0),{pixel_size_.x*2, std::max(h -  pixel_size_.y,0.0f)},
                   arc::Color::InterpolateArc(0xcf3838, 0x77d136, progress));
    batch.DrawQuad(pos_ + glm::vec3(+pixel_size_.x*7,h/2 - size_.y/2.0f + pixel_size_.y*2.5,0),{pixel_size_.x, std::max(h -  pixel_size_.y,0.0f)},
                   arc::Color::InterpolateArc(0xb32e2e, 0x68b32e, progress));



}

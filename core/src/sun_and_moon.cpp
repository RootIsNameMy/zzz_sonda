//
// Created by adolin on 25. 01. 21.
//
#include "sun_and_moon.h"

SunAndMoon::SunAndMoon() {
    sun_.Create2D( "sun_and_moon/sun.png");
    rays_.Create2D( "sun_and_moon/rays.png");
    moon_.Create2D( "sun_and_moon/moon.png");

    sun_size_.y = (float)sun_.height();
    sun_size_.x = (float)sun_.width() / (float)sun_size_.y;

    sun_size_.y = (float)arc::Engine::window().height()/5.0f;
    sun_size_.x*=sun_size_.y;

    float sun_to_moon = (float)moon_.width()/(float)sun_.width();
    moon_size_ = sun_to_moon*sun_size_;



    pos_ = {(float)arc::Engine::window().width()/2.0f-sun_size_.x/2.0f - 20,+(float)arc::Engine::window().height()/2.0f - sun_size_.y/2 - 20,0};


}

void SunAndMoon::Render(arc::BatchRenderer &batch) {

    glm::vec3 d = {arc::Engine::window().width(),arc::Engine::window().height(),0} ;
    d/=2.0f;
    if(progress_<0.5){
        float angle = progress_*3.141592f*2.0f;
        glm::vec3 dir = {std::cos(angle),std::sin(angle),0};

        batch.DrawTexture(sun_, dir*d + dir*glm::vec3{sun_size_.x,-sun_size_.y,0}/2.0f,sun_size_);

        float change = std::sin(arc::Engine::running_time()*2)*5;
        batch.DrawTexture(rays_,dir*d+ dir*glm::vec3{sun_size_.x,-sun_size_.y,0}/2.0f,sun_size_+change);
    }
    else{
        float angle = (progress_-0.5f)*3.141592f*2.0f;
        glm::vec3 dir = {std::cos(angle),std::sin(angle),0};
        batch.DrawTexture(moon_, dir*d + dir*glm::vec3{sun_size_.x,-sun_size_.y,0}/2.0f,moon_size_);
    }









}

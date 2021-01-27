//
// Created by adolin on 24. 01. 21.
//
#include <random>
#include "sea.h"

#include "noise.h"

Sea::Sea() {

    height_ = 200;
    width_ = 500;
    data_ = new uint8_t[height_*width_*4];
    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {

            arc::Color::InterpolateArc(0x031b33, 0x0b6bcb, std::pow((float) i / (float) height_, 2),
                                       &data_[i * width_ * 4 + j * 4], 1, 0.35);
        }
    }



    sea_.Create2D("Sea", width_, height_, data_);

    size_.x = width_;
    size_.y = (float)height_/size_.x;

    size_.x = arc::Engine::window().width();
    size_.y*=size_.x;

    pos_ = {0,-size_.y/2+60,0};

}


void Sea::Update(float delta) {


    for (int j = 0; j < width_; ++j) {
        float t = (float)arc::Engine::running_time()/2.0f;
        float n = (0.5f+ Noise::Waves({j/113.7f+t/1.124583f, j/64.5437f+t/15.323214f}))* 12 + 4;
        //float n = (0.5f+ Noise::Waves({(float) j / 111.0f + t / 0.734f, (float) j / 97.0f + t / 4.2413f})) * 16 + 6;

        for (int i = height_ - 20; i < height_; ++i) {
            if (n > i - height_ + 20+1)
                arc::Color::InterpolateArc(0x031b33, 0x0b6bcb, std::pow((float) i / (float) height_, 2),
                                           &data_[i * width_ * 4 + j * 4], 1, 0.35);
            else if(n > i - height_ + 20)
                arc::Color::FromHex(0xade8ff, &data_[i * width_ * 4 + j * 4], 255 - i);
            else {
                arc::Color::FromHex(0x168bff, &data_[i * width_ * 4 + j * 4], 0);
            }


        }
    }

    sea_.set_data(data_, height_ * width_ * 4);
}

void Sea::Render(arc::BatchRenderer &batch) {
    batch.DrawTexture(sea_,pos_,size_);
}

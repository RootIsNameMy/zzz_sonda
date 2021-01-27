//
// Created by adolin on 22. 01. 21.
//

#include "sonda.h"
#include "input.h"
#include "noise.h"

Sonda::Sonda() {

    Noise::Setup(1337);
    sonda_.Create2D("sonda/sonda.png");
    shadows_[0].Create2D("sonda/top_shadow.png");
    shadows_[1].Create2D("sonda/top_left_shadow.png");
    shadows_[2].Create2D("sonda/left_shadow.png");
    shadows_[3].Create2D("sonda/bottom_left_shadow.png");
    shadows_[4].Create2D("sonda/bottom_shadow.png");
    shadows_[5].Create2D("sonda/bottom_right_shadow.png");
    shadows_[6].Create2D("sonda/right_shadow.png");
    shadows_[7].Create2D("sonda/top_right_shadow.png");

    lights_[0].Create2D("sonda/top_light.png");
    lights_[1].Create2D("sonda/top_left_light.png");
    lights_[2].Create2D("sonda/left_light.png");
    lights_[3].Create2D("sonda/bottom_left_light.png");
    lights_[4].Create2D("sonda/bottom_light.png");
    lights_[5].Create2D("sonda/bottom_right_light.png");
    lights_[6].Create2D("sonda/right_light.png");
    lights_[7].Create2D("sonda/top_right_light.png");



    width_ = (float)sonda_.width();
    height_ = (float)sonda_.height() / width_;
    width_ = (float)arc::Engine::window().width()/4.0f;
    height_*=width_;
}

void Sonda::Update(float delta) {
    if(read_sensors) ReadSensorData(delta);
    temperature_meter_.set_temp(sensor_data_.temperature);
    battery_.set_level(sensor_data_.battery);
    barometer_.set_pressure(sensor_data_.pressure);
    temperature_meter_.Update(delta);
    sea_.Update(delta);
    sun_and_moon_.set_time(sensor_data_.time);
}

void Sonda::Render(arc::BatchRenderer &batch) {

    float t = (float)(arc::Engine::running_time()-0.5f)/2.0f;
    float t1 = (float)(arc::Engine::running_time()+arc::Engine::delta_time() - 0.5f)/2.0f;

    float n = (0.5f+ Noise::Waves({250/113.7f+t/1.124583f, 250/64.5437f+t/15.323214f}))* 12 + 4;
    float n1 = (0.5f+ Noise::Waves({250/113.7f+t1/1.124583f, 250/64.5437f+t1/15.323214f}))* 12 + 4;

    float angle = glm::degrees(std::atan(((n1-n)/100.0f)/(float)arc::Engine::delta_time()));

    float time_process = (float)((sensor_data_.time+18*60)%(60*24)) *3.141592f*2/ ((float)60*24);
    float alpha = 1 - std::max(0.0,std::min(1.0,std::pow((0.5f-0.5f*std::sin(time_process)),2)));


    batch.DrawTexture(sonda_, {0, n, 0}, {width_, height_}, sensor_data_.tilt.z+angle,glm::vec4(glm::vec3(alpha*0.5+0.5),1));


    float tilt = sensor_data_.tilt.z + 22.5;
    if(tilt<0){
        tilt+=360;
    }

    for (int i = 0; i < 8; ++i) {
        if(tilt < 45.0f*(i+1.0f)){
            batch.DrawTexture(shadows_[i], {0, n, 0}, {width_, height_}, sensor_data_.tilt.z+angle, glm::vec4(glm::vec3(alpha*0.5+0.5),1));
            batch.DrawTexture(lights_[i], {0, n, 0}, {width_, height_}, sensor_data_.tilt.z+angle,arc::Color::FromHex(0xffffff,alpha*0.5f));
            break;
        }
    }






    sun_and_moon_.Render(batch);
    sea_.Render(batch);
    temperature_meter_.Render(batch);
    battery_.Render(batch);
    barometer_.Render(batch);



}

void Sonda::ReadSensorData(float delta) {
    static float elapsed_time = 0.0f;
    elapsed_time += delta;

    if(elapsed_time > 0.1){
        arc::AndroidInput::GetRotationData((float*)&sensor_data_.tilt); // TODO: does not work on normal phone + sensors start reading after they first change
        sensor_data_.tilt.x = sensor_data_.tilt.x * 180 / M_PI;
        sensor_data_.tilt.y = sensor_data_.tilt.y * 180 / M_PI;
        sensor_data_.tilt.z = sensor_data_.tilt.z * 180 / M_PI;
        arc::AndroidInput::GetTemperatureData(&sensor_data_.temperature);
        static float light = 0;
        arc::AndroidInput::GetLightSensorData(&light);
        sensor_data_.time = (int)((light/40000.0f)*24*60);
        arc::AndroidInput::GetPressureData(&sensor_data_.pressure);
        arc::AndroidInput::GetBatteryInfo(nullptr, &sensor_data_.battery);
        elapsed_time = 0.0f;
    }
}
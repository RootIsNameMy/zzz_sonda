//
// Created by sam on 12/25/20.
//

#ifndef ARC_ENGINE_CAMERA_CONTROLLER_H
#define ARC_ENGINE_CAMERA_CONTROLLER_H


#include "engine_includes.h"

class CameraController: public arc::OrthographicCamera, public arc::KeyboardListener, public arc::WindowListener, public arc::MouseListener, public arc::TouchListener{

public:
    void OnCreate(uint width, uint height, const glm::vec3& position = {0,0,10}){
        arc::EventHandler::SubscribeKeyboard(this);
        arc::EventHandler::SubscribeWindow(this);
        arc::EventHandler::SubscribeMouse(this);
        arc::EventHandler::SubscribeTouch(this);

        Setup((float)width/(float)height,(float)height,-100,100,position);
        position_ = {};
        width_ = width;
        height_ = height;
        zoom_ = (float)height;
        dir_ = {};
    }

    void OnUpdate(float delta_time){
        position_+=dir_*delta_time*zoom_;

        SetView(position_);
        dir_ = {};
    }


    bool OnWindowResize(int width, int height) override {
        width_ = width; height_ = height;
        SetProjection((float)width/(float)height, zoom_);
        return true;
    }

//    bool OnScroll(double x_offset, double y_offset) override {
//        zoom_-=y_offset*zoom_/10.0f;
//        SetProjection((float)width_/(float)height_, zoom_);
//    }

    bool OnTouchDown(int id, float x, float y) override {
        return true;
    }

    bool OnTouchUp(int id, float x, float y) override {
        return true;
    }

    bool OnTouchMove(int id, float dx, float dy) override {
        if(!ImGui::IsAnyItemActive()){
            dir_ = {};
            dir_.x -= dx*width_;
            dir_.y -= dy*height_;
        }
        return true;
    }

    bool OnMultiGesture(float x, float y, float dist, float theta) override {
        zoom_-=dist*zoom_;
        dir_ = {};
        SetProjection((float)width_/(float)height_, zoom_);
        return true;
    }

private:
    float zoom_;
    uint width_, height_;
    glm::vec3 position_{}, dir_{};
};
#endif //ARC_ENGINE_CAMERA_CONTROLLER_H

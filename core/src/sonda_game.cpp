//
// Created by adolin on 21. 12. 20.
//

#include "../include/sonda_game.h"



SondaGame::SondaGame(): sonda_() {
//"/data/data/com.example.test_android/files/test.png"
}

void SondaGame::Init() {

    renderer_.Init();

    camera_.OnCreate(arc::Engine::window().width(),arc::Engine::window().height());


    //setup camera
}

void SondaGame::Dispose() {
    renderer_.Destroy();
}




void SondaGame::Update() {

    camera_.OnUpdate(arc::Engine::delta_time());

    float time_process = (float)((sonda_.sensor_data().time+18*60)%(60*24)) *3.141592f*2/ ((float)60*24);
    arc::RenderCommand::SetClearColor(arc::Color::InterpolateArc(0x81e3fc,0x091b2b,std::max(0.0,std::min(1.0,std::pow((0.5f-0.5f*std::sin(time_process)),2)))));
    arc::RenderCommand::Clear();

    sonda_.Update(arc::Engine::delta_time());
    renderer_.Begin(camera_);
    {
        sonda_.Render(renderer_);
    }
    renderer_.End();

}




void SondaGame::ImGuiRender() {
    static bool on_left = true;
    if(on_left)
        ImGui::SetNextWindowPos({0,0});
    else
        ImGui::SetNextWindowPos({arc::Engine::window().width()*2.0f/3.0f,0});
    ImGui::SetNextWindowSize({(float)arc::Engine::window().width()/3.0f,(float)arc::Engine::window().height()});
    ImGui::Begin("Sensors");
    if(ImGui::Button(on_left?"move right":"move left")){
        on_left = !on_left;
    }
    ImGui::SetWindowFontScale(5.0f);//TODO: look into scaling
    ImGui::Checkbox("Read from sensors", &sonda_.read_sensors);
    if(!sonda_.read_sensors) {
        ImGui::DragFloat("Tilt", &sonda_.sensor_data().tilt.z, 1, -180, 180);
        ImGui::DragFloat("Pressure", &sonda_.sensor_data().pressure, 1, 970, 1060);
        ImGui::DragFloat("Temperature", &sonda_.sensor_data().temperature, 0.25, -30, 50);
        ImGui::DragInt("Battery", &sonda_.sensor_data().battery, 1, 0, 100);
        ImGui::DragInt("Time", &sonda_.sensor_data().time, 1, 0, 60*24);
    }
    ImGui::End();
}





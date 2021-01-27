//
// Created by adolin on 21. 12. 20.
//

#ifndef ARC_ENGINE_BATTLEMAPAPP_H
#define ARC_ENGINE_BATTLEMAPAPP_H



#include "camera_controller.h"
#include "sonda.h"


class SondaGame: public arc::Application {
public:


    SondaGame();
    void Init() override;
    void Dispose() override;
    void Update() override;
    void ImGuiRender() override;


private:
    CameraController camera_;
    arc::BatchRenderer renderer_;
    Sonda sonda_;




};


#endif //ARC_ENGINE_BATTLEMAPAPP_H

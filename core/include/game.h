//
// Created by adolin on 21. 12. 20.
//

#ifndef ARC_ENGINE_BATTLEMAPAPP_H
#define ARC_ENGINE_BATTLEMAPAPP_H



#include "engine_includes.h"


class Game: public arc::Application {
public:


    Game();
    void Init() override;
    void Dispose() override;
    void Update() override;
    void ImGuiRender() override;


private:
    arc::BatchRenderer renderer_;
    arc::OrthographicCamera camera_;




};


#endif //ARC_ENGINE_BATTLEMAPAPP_H

#include "../include/game.h"

Game::Game() {

}

void Game::Init() {

    renderer_.Init();
    camera_.SetProjection((float)arc::Engine::window().width()/(float)arc::Engine::window().height(),1);
    camera_.SetView({});
}

void Game::Dispose() {
    renderer_.Destroy();
}




void Game::Update() {


    arc::RenderCommand::SetClearColor({0.25,0.25,0.75,1});
    arc::RenderCommand::Clear();




    renderer_.Begin(camera_);
    {
        renderer_.DrawQuad({},{0.5,0.5},
                           {
            0.5 - 0.4*std::sin(arc::Engine::running_time()),
            0.5 - 0.4*std::cos(arc::Engine::running_time()*1.24357),
            0.5 - 0.4*std::sin(arc::Engine::running_time()*2.995723),
            1},arc::Engine::running_time()*30);
    }
    renderer_.End();

}




void Game::ImGuiRender() {
    ImGui::Begin("ImGui window");

    ImGui::End();
}





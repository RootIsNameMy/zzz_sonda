//
// Created by adolin on 21. 12. 20.
//
#include "sonda_game.h"
int main(){
    arc::Engine engine;
    arc::Engine::AppConfig config;
    //get the assets folder
    std::string file_path = __FILE__;
    file_path = file_path.substr(0,file_path.rfind('/'));
    file_path = file_path.substr(0,file_path.rfind('/'));
    config.asset_folder = file_path+"/core/assets/";

    config.title = "Game";

    engine.LaunchDesktopApp<SondaGame>(config);

    return 0;
}
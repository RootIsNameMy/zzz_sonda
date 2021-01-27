cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")

project(
        TestGame
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(core STATIC src/sonda.cpp include/temperature_meter.h src/temperature_meter.cpp src/barometer.cpp src/battery.cpp include/sea.h src/sea.cpp include/sun_and_moon.h src/sun_and_moon.cpp include/noise.h src/noise.cpp)
target_sources(core
        PRIVATE
        src/sonda_game.cpp
        )
target_include_directories(core PUBLIC include)
target_link_libraries(core PUBLIC arc_engine)

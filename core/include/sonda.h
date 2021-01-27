//
// Created by adolin on 22. 01. 21.
//

#ifndef ARC_ENGINE_SONDA_H
#define ARC_ENGINE_SONDA_H
#include "temperature_meter.h"
#include "battery.h"
#include "barometer.h"
#include "sea.h"
#include "sun_and_moon.h"

class Sonda{
public:
    struct SensorData{
        glm::vec3 tilt{0,0,0};// radians
        float temperature{0};//in celsius
        int battery{0};//0-100
        float pressure{970};//970 - 1060
        int time{0};//0 - 24*60 in minutes,0-midnight
    };
    bool read_sensors = false;

    Sonda();

    void Update(float delta);
    void Render(arc::BatchRenderer& batch);
    void ReadSensorData(float delta);

    SensorData& sensor_data()  {return sensor_data_;}


private:
    arc::Texture sonda_, lights_[8], shadows_[8];
    float width_, height_;
    SensorData sensor_data_;

    TemperatureMeter temperature_meter_;
    Battery battery_;
    Barometer barometer_;
    Sea sea_;
    SunAndMoon sun_and_moon_;
};
#endif //ARC_ENGINE_SONDA_H

#ifndef WHEELKINEMATICSHANDLER_H
#define WHEELKINEMATICSHANDLER_H

#include <QObject>

class WheelKinematicsHandler
{
public:
    WheelKinematicsHandler();
    float calculateWheelDirection(float y,float x);
    float calculateWheelMagnitude(float y, float x);
    float calculateFLWheelSpeed(float direction, float magnitude, float z);
    float calculateFRWheelSpeed(float direction, float magnitude, float z);
    float calculateBLWheelSpeed(float direction, float magnitude, float z);
    float calculateBRWheelSpeed(float direction, float magnitude, float z);

};

#endif // WHEELKINEMATICSHANDLER_H

#include "wheelkinematicshandler.h"
#include <math.h>
#include <algorithm>
#include "constants.h"
#define PI 3.14159265

WheelKinematicsHandler::WheelKinematicsHandler()
{

}

float WheelKinematicsHandler::calculateWheelDirection(float y, float x)
{
    float firstCalc = atan2(y,x);
    if(!(firstCalc == 0) && firstCalc/abs(firstCalc) == -1.0) {
        firstCalc = firstCalc + (2 * PI);
    }
    return firstCalc;
}

float WheelKinematicsHandler::calculateWheelMagnitude(float y, float x)
{

    return (std::clamp(((float)sqrt(pow(y, 2) + pow(x, 2))), MovementConstants::MinSpeed, MovementConstants::MaxSpeed));
}

float WheelKinematicsHandler::calculateFLWheelSpeed(float direction, float magnitude, float z)
{
    return ((((float) -sin(direction + (1.0/4.0 * PI))) * magnitude) + z);
}

float WheelKinematicsHandler::calculateFRWheelSpeed(float direction, float magnitude, float z)
{
    return ((((float) sin(direction - (1.0/4.0 * PI))) * magnitude) + z);
}

float WheelKinematicsHandler::calculateBLWheelSpeed(float direction, float magnitude, float z)
{
    return ((((float) -sin(direction - (1.0/4.0 * PI))) * magnitude) + z);
}

float WheelKinematicsHandler::calculateBRWheelSpeed(float direction, float magnitude, float z)
{
    return ((((float) sin(direction + (1.0/4.0 * PI))) * magnitude) + z);
}

#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "ecrobot_interface.h"

#include "Balancer.h"
#include "Calibration.h"
#include "TargetValue.h"
#include "PID_Tail.h"
#include "PID_Brightness.h"
#include "Display.h"
#include "Runner.h"
#include "./UI/PushButton.h"
#include "WheelMotor.h"

#include "DetectorPart/DistanceEncoder.h"
#include "DetectorPart/SpeedEncoder.h"
#include "DetectorPart/Timer.h"

Balancer balancer;
Calibration calibration;
TargetValue targetValue;
PID_TAIL pid_tail;
PID_BRIGHTNESS pid_brightness;
Display display;
Runner runner;

//UI package
PushButton pushButton;

WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;

//DetectorPart
Timer timer;
DistanceEncoder distanceEncoder;
SpeedEncoder speedEncoder;



extern void initialization();

#endif



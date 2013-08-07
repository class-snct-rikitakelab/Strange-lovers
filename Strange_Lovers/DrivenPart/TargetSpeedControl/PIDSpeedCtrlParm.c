#include "PIDSpeedCtrlParm.h"

void PSCP_init(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm){
//200mm/s Kp0.03�����傤�ǂ悢
	this_PIDSpeedCtrlParm->sKp = 0.0008;
	
	//this_PIDSpeedCtrlParm->sKp = 1.5;
	//this_PIDSpeedCtrlParm->sKi = 0.0002;
	//this_PIDSpeedCtrlParm->sKi = 0.0002;
	this_PIDSpeedCtrlParm->sKd = 0.0001;
}

float PSCP_getSKp(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm){
	return this_PIDSpeedCtrlParm->sKp;
}

void PSCP_setSKp(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm){
	this_PIDSpeedCtrlParm->sKp = parm;
}

float PSCP_getSKi(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm){
	return this_PIDSpeedCtrlParm->sKi;
}

void PSCP_setSKi(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm){
	this_PIDSpeedCtrlParm->sKi = parm;
}

float PSCP_getSKd(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm){
	return this_PIDSpeedCtrlParm->sKd;
}

void PSCP_setSKd(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm){
	this_PIDSpeedCtrlParm->sKd = parm;
}

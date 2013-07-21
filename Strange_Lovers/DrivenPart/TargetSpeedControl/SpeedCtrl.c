#include "SpeedCtrl.h"
#include "../../Factory.h"

//���������\�b�h
void SC_init(SpeedCtrl *this_SpeedCtrl,PIDSpeedCtrl PSC)
{
	S_init(&mSpeed);
	mPIDSpeedCtrl = PSC; //�I�u�W�F�N�g�̒��ւ������Ă�@�����o�Ŏ�������ׂ�
	PSC_init(&mPIDSpeedCtrl);

	this_SpeedCtrl->S_CtrlState = S_CTRL_OFF;
}

//�ڕW�p�x�ݒ胁�\�b�h
void SC_setTargSpeed(SpeedCtrl *this_SpeedCtrl, int parm)
{
	S_setTargSpeed(&mSpeed,parm);
}

int SC_getTargSpeed(SpeedCtrl *this_SpeedCtrl)
{
	return S_getTargSpeed(&mSpeed);
}

void SC_setCtrlParm(SpeedCtrl *this_SpeedCtrl,PIDSpeedCtrlParm parm)
{
	PSC_setPIDSpeedCtrlParm(&mPIDSpeedCtrl,parm);
}

PIDSpeedCtrlParm SC_getCtrlParm(SpeedCtrl *this_SpeedCtrl)
{
	return PSC_getPIDSpeedCtrlParm(&mPIDSpeedCtrl);
}

void SC_startCtrl(SpeedCtrl *this_SpeedCtrl)
{
	SC_changeMode(&(*this_SpeedCtrl),S_CTRL_ON);
}

void SC_stopCtrl(SpeedCtrl *this_SpeedCtrl)
{
	PSC_reset(&mPIDSpeedCtrl);
	SC_changeMode(&(*this_SpeedCtrl),S_CTRL_OFF);
}

void SC_run(SpeedCtrl *this_SpeedCtrl)
{
	switch(this_SpeedCtrl->S_CtrlState){
	case S_CTRL_ON:
		SC_doCtrl(&(*this_SpeedCtrl));
		break;
	case S_CTRL_OFF:
		break;
	default:
		break;
	}
}

//�p�x������s���\�b�h
void SC_doCtrl(SpeedCtrl *this_SpeedCtrl)
{
	int forward = PSC_calcSpeedCtrlVal(&mPIDSpeedCtrl,S_getTargSpeed(&mSpeed),S_getBfSpeed(&mSpeed),S_getSpeed(&mSpeed,systick_get_ms()),systick_get_ms()*0.001);
	//WheelMotor_drive_motor(&rightWheelMotor,forward);
	//WheelMotor_drive_motor(&leftWheelMotor,forward);
	Balancer_set_forward(&balancer ,(S8)forward);
}

void SC_changeMode(SpeedCtrl *this_SpeedCtrl,SpeedCtrlState state){
	this_SpeedCtrl->S_CtrlState = state;
}
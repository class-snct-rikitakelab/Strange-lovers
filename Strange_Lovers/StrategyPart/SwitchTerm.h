#ifndef STRATEGYPART_SWITCH_TERM_H
#define STRATEGYPART_SWITCH_TERM_H

/**
 * �؂�ւ�����l
 */
typedef struct {
	/**
	 * �ړ�����
	 */
	float distance;

	/**
	 * �X��
	 */
	int inclination;

	/**
	 * ����
	 */
	int time;

	/**
	 * �^�b�`�Z���T������
	 */
	int inPushed;
	
	/**
	 * ���x
	 */
	int speed;

	float curvature;

	int tail_angle;

	float direction;

}SwitchTerm;
#endif



#ifndef SERVO_H_
#define SERVO_H_


#include "DIO_Interface.h"
#include "Timers.h"

typedef enum{
	Clock_Wize,
	UntiClock_Wize
	}Direction_type;


void SERVO_Init(void);
void SERVO_SetAngle(u8 angle);
void DCMOTOR_Direction(Direction_type dir);



#endif /* SERVO_H_ */
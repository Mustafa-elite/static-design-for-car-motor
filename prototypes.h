#pragma once
#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include <stdio.h>
#include "STD_TYPES.h"
/*----------------------------Micro controller------------------------------*/
typedef enum {
	quarterMax,
	halfMax,
	threequartersMax,
	fullMax
}EN_frequency_t;
typedef enum {
	bit0,
	bit1,
	bit2,
	bit3,
	bit4,
	bit5,
	bit6,
	bit7
}EN_pins_t;
typedef enum {
	quarter,
	half,
	threequarters,
	full
}EN_duty_t;
//DIO
void DIO_init(void);//initializes digital I/O
void DIO_write(u8 port, EN_pins_t pin, u8 data);//takes the input data and the pins and  the port of the location to store this data
void DIO_read(u8 port, EN_pins_t pin, u8* data);//reaads a data from the given pins and port to store it in the location of a given adress
void DIO_toggle(u8 port, EN_pins_t pin);//toggles the binarary data in a given port and pin.
//PWM
void PWM_init(void);//initializes the PWM pins
void PWM_start(EN_frequency_t frequency, EN_duty_t dutycycle);//takes the given frequency and the duty cycle to give the order to the motor to do the given specification
void PWM_stop(void);//stops the PWM from working


//timer
void TIMER_init(void);//intializes the timer in the micro controller
void TIMER_start(u64 ticks);//takes an input of number of ticks to count a specific number o seconds
void TIMER_read(u8* value);//reads the time of the timer and returns it in a given data. 
void TIMER_set(u8 value);//setting the value of the timer to a given value.
void TIMER_checkStatus(u8* status);//checking the status of the timer and returning the status in agiven adress.

/*--------------------------------MOTOR-----------------------------------*/
typedef enum {
	SPEED0,
	FOWRWARD30,
	FOWRWARD60,
	FOWRWARD90,
	BACKWARD30
}EN_Speed_dir_t;
typedef struct {
	u8 port;
	EN_pins_t pin;
}ST_Motor_t;
EN_Speed_dir_t Detect_Speed_Dir(ST_Motor_t* ST_motor);//detecting the current speed and dir and return it as enum
void increaseForward30(ST_Motor_t* ST_motor);//increasing the speed in forwaard dir according to the current state
void increaseBackward30(ST_Motor_t* ST_motor);//if button 4 is set to speed b
void setSpeedToZero(ST_Motor_t* ST_motor);//if button 4 is set to speed zero,this is called to make speed 0
void turnLeft_Right(ST_Motor_t* ST_motor, EN_Button_t);//if button 2,3 is pressed,respond by moving left or right
void changeSpeed_dir(ST_Motor_t* ST_motor, EN_Speed_dir_t current_speed, EN_Button_t button);//calls all the above function to control the speed and dir.
/*--------------------------------BUTTONS----------------------------------*/
typedef enum {
	Button1,
	Button2,
	Button3,
	Button4
}EN_Button_t;
typedef enum {
	PRESSED,
	NOTPRESSED
}EN_ISPRESSED_t;
EN_Button_t getButton(EN_pins_t pins);//get the input button from user
EN_ISPRESSED_t isStillPressed(EN_Button_t button, EN_pins_t pins);//check if button is still pressed or no
/*----------------------------APPLICATION----------------------------------*/
EN_Button_t whichButtonPressed(EN_pins_t pins); //call getButton and isStillPressed.
void makeMove(void);

#endif // !MAIN_H

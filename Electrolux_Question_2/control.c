//******************************************************************************
//
//  Knowledge Assessment (Question 2)
//
//******************************************************************************
//  DATA: 26/06/2022
//  Guilherme Pereira de Resende
//
//	Control logic
//------------------------------------------------------------------------------

#include "control.h"

//******************************************************************************
//	Abstracted functions used to solve Question 2
//------------------------------------------------------------------------------

// Abstracted function to use a 1ms timer
void timerInit(void);

// Abstracted function to check the timer
// Returns the amount of time (in ms) counted from the timerInit()
uint16_t timerCheck(void);


//******************************************************************************
//	Process to control the states
//------------------------------------------------------------------------------
void controlProcess(void)
{
	static uint8_t controlState = STATE_OFF;

	// State Machine control
	switch(controlState)
	{
		// ---------------------------------------------------
		case STATE_OFF:
			// Code to be executed while in State Off
			break;

		// ---------------------------------------------------
		case STATE_ON:
			// Code to be executed while in State On
			break;

		// ---------------------------------------------------
		case PROTECTION:
			if(timerCheck() >= PROTECTION_TIMEOUT)
			{
				controlState = STATE_OFF;
			}
			break;

		// Protection state must be executed if this code is reached
		// ---------------------------------------------------
		default:
			timerInit();
			controlState = PROTECTION;
			break;
	}
}


//******************************************************************************
//	Function to change the state machine to STATE_ON
//------------------------------------------------------------------------------
void stateOn(void)
{
	if(controlState == STATE_OFF)
	{
		controlState = STATE_ON;
	}
}


//******************************************************************************
//	Function to change the state machine to STATE_OFF
//  passing through the PROTECTION STATE
//------------------------------------------------------------------------------
void StateOff(void)
{
	if(controlState == STATE_ON)
	{
		timerInit();	// Starts the protection time
		controlState = PROTECTION;
	}
}



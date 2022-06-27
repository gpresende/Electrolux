//******************************************************************************
//
//  Knowledge Assessment (Question 2)
//
//******************************************************************************
//  DATA: 26/06/2022
//  Guilherme Pereira de Resende
//
//	Button Control
//------------------------------------------------------------------------------

#include "button.h"
#include "control.h"

//******************************************************************************
//	Abstracted functions to Question 2
//------------------------------------------------------------------------------

// Abstracted functions to use 1ms timers
void timer0Start(void);
void timer1Start(void);

// Abstracted functions to check the timer
// Returns the amount of time (in ms) counted from the timer start
uint32_t timer0Check(void);
uint32_t timer1Check(void);

// Abstract function to initialize microcontroller button pin
void buttonInit(void);

// Abstracted function to read pin state
// Return 1 if pressed or 0 if not
uint8_t isButtonPressed(void);

// Variable to save the amount of time the button was kept pressed
uint32_t buttonPressedTime = 0;

//******************************************************************************
//	Process to control the button
//------------------------------------------------------------------------------
void buttonProcess(void)
{
	static uint8_t buttonState = INIT;

	// State Machine to control button states
	switch(buttonState)
	{
		// Init state is used to assure the button state during initialization
		// ---------------------------------------------------
		case INIT:
			if(isButtonPressed())
				buttonState = PRESSED;
			else
				buttonState = RELEASED;
			break;

		// State to represent the released button,
		// Used to identify when the button was pressed
		// ---------------------------------------------------
		case RELEASED:
			if(isButtonPressed())
			{
				timer0Start();	// Timeout to prevent debounce issues
				buttonState = PRESSING;
			}
			break;

		// Confirms if the button was really pressed or not (noise)
		// ---------------------------------------------------
		case PRESSING:
			if(timer0Check() >= DEBOUNCE_TIME)
			{
				if(isButtonPressed())
				{
					buttonPressedAction();
					buttonState = PRESSED;	// Confirms the button is pressed
				}
				else
				{
					buttonState = RELEASED;	// After debounce time, button is not pressed (abort)
				}
			}
			break;

		// State to represent the pressed button,
		// Used to identify when the button was released
		// ---------------------------------------------------
		case PRESSED:
			if(isButtonPressed() == 0)
			{
				timer0Start();	// Timeout to prevent debounce issues
				buttonState = RELEASING;
			}
			break;

		// Confirms if the button was really released
		// ---------------------------------------------------
		case RELEASING:
			if(timer0Check() >= DEBOUNCE_TIME)
			{
				if(isButtonPressed() == 0)		// Confirms if the button released action
				{
					buttonReleasedAction();
					buttonState = RELEASED;
				}
				else
				{
					buttonState = PRESSED;
				}
			}
			break;

		// ---------------------------------------------------
		default:
			buttonState = INIT;
			break;
	}
}


//******************************************************************************
//	Action to be executed when button is pressed
//------------------------------------------------------------------------------
void buttonPressedAction(void)
{
	timer1Start();	// Timer to count the time (in ms) the button is kept pressed
	stateOn();		// Changes the state control
}


//******************************************************************************
//	Action to be executed when button is released
//------------------------------------------------------------------------------
void buttonReleasedAction(void)
{
	stateOff();		// Changes the state control
	buttonPressedTime = timer1Check() + DEBOUNCE_TIME;	// Saves the time since the button was pressed
}

//******************************************************************************
//	Returns the amount of time (in ms) the button kept pressed
//------------------------------------------------------------------------------
uint32_t getButtonPressedTime(void)
{
	return buttonPressedTime;
}

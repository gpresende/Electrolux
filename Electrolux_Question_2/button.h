//******************************************************************************
//
//  Knowledge Assessment (Question 2)
//
//******************************************************************************
//  DATA: 26/06/2022
//  Guilherme Pereira de Resende
//
//	Button Control - Header file
//------------------------------------------------------------------------------


#ifndef BUTTON_H_
#define BUTTON_H_



#define DEBOUNCE_TIME	20

typedef enum button_states
{
	INIT,
	RELEASED,
	PRESSING,
	PRESSED,
	RELEASING,
};

void buttonInit(void);
void buttonProcess(void);
void buttonPressedAction(void);
void buttonReleasedAction(void);
uint32_t getButtonPressedTime(void);

#endif

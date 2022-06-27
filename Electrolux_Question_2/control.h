//******************************************************************************
//
//  Knowledge Assessment (Question 2)
//
//******************************************************************************
//  DATA: 26/06/2022
//  Guilherme Pereira de Resende
//
//	Control - Header File
//------------------------------------------------------------------------------

#ifndef CONTROL_H_
#define CONTROL_H_


#define PROTECTION_TIMEOUT	10000

typedef enum control_states
{
	STATE_OFF,
	STATE_ON,
	PROTECTION
};

void stateOn(void);
void stateOff(void);

#endif

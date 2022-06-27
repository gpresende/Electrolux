//******************************************************************************
//
//  Knowledge Assessment (Question 4)
//
//******************************************************************************
//  DATA: 27/06/2022
//  Guilherme Pereira de Resende
//
//	Protocol
//------------------------------------------------------------------------------

#include "protocol.h"

MESSAGE frame;

//******************************************************************************
//	Abstracted functions used to solve Question 4
//------------------------------------------------------------------------------

// Abstracted function to inicialize UART peripheral and used pins
void uart_init(void);


// Abstracted RX Interrupt function
__interrupt void UART_RX_ISR(void)
{
	protocolParser(UCA1RXBUF);	// Receive one byte
}


//******************************************************************************
//	Process to control the protocol states
//------------------------------------------------------------------------------
void protocolParser(uint8_t byte)
{
	static uint8_t protocolState = COMMAND;		// Controls the state machine
	static uint8_t payload_size = 0;			// Saves the payload size
	static uint8_t received_bytes = 0;			// Controls the payload received bytes

	// State Machine to control the parser
	switch(protocolState)
	{
		// State to receive the command byte
		// Waits until a valid command is received
		// ---------------------------------------------------
		case COMMAND:
			if(byte == COMMAND_1)
			{
				payload_size = COMMAND_1_SIZE;
				protocolState = PAYLOAD;
			}
			else if(byte == COMMAND_2)
			{
				payload_size = COMMAND_2_SIZE;
				protocolState = PAYLOAD;
			}
			frame.command = byte;
			received_bytes = 0;
			break;

		// State to receive all payload bytes from a specific command
		// ---------------------------------------------------
		case PAYLOAD:
			frame.payload[received_bytes++] = byte;

			if(payload_size == received_bytes)
			{
				process_message(&frame);
				protocolState = COMMAND;
			}
			break;

		// ---------------------------------------------------
		default:
			protocolState = COMMAND;
			break;
	}
}


//******************************************************************************
//	Process received message
//------------------------------------------------------------------------------
void process_message(MESSAGE * msg)
{
	// Process message here or in another layer
}

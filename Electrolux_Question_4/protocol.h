//******************************************************************************
//
//  Knowledge Assessment (Question 4)
//
//******************************************************************************
//  DATA: 27/06/2022
//  Guilherme Pereira de Resende
//
//	Protocol - Header File
//------------------------------------------------------------------------------

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define MAX_PAYLOAD	50

// Generic message struct
typedef struct
{
    uint8_t command;
    uint8_t payload[MAX_PAYLOAD];
} MESSAGE;


enum protocol_states
{
    COMMAND = 0,
    PAYLOAD
};

// Commands definition
#define COMMAND_1  0x10
#define COMMAND_2  0x20

// Commands size
#define COMMAND_1_SIZE	6
#define COMMAND_2_SIZE	8

void uart_init(void);
void protocolParser(uint8_t byte);
void process_message(MESSAGE * msg);

#endif

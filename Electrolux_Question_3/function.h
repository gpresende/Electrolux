//******************************************************************************
//
//  Knowledge Assessment (Question 3)
//
//******************************************************************************
//  DATA: 27/06/2022
//  Guilherme Pereira de Resende
//
//	Function - Header File
//------------------------------------------------------------------------------

#ifndef FUNCTION_H_
#define FUNCTION_H_

#define ARRAY_SIZE	10

// Struct to organize the input and output values 
typedef struct
{
	uint16_t input_array[ARRAY_SIZE];
	uint16_t even_array[ARRAY_SIZE];
	uint16_t even_array_size;
    uint16_t average;
    uint16_t max;
    uint16_t min;
} ARRAY_STR;

void calculator(ARRAY_STR *data);

#endif

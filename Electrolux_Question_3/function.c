//******************************************************************************
//
//  Knowledge Assessment (Question 3)
//
//******************************************************************************
//  DATA: 27/06/2022
//  Guilherme Pereira de Resende
//
//	Function
//------------------------------------------------------------------------------

#include "function.h"



//******************************************************************************
//	Calculator function
//------------------------------------------------------------------------------
void calculator(ARRAY_STR *data)
{
	uint32_t average;
	uint16_t max = 0;
	uint16_t min = 0xffff;
	uint16_t even_index;

	for(uint16_t n=0; n<ARRAY_SIZE; n++)
	{
		// Average accumulation
		average += data->input_array[n];

		// Max value identification
		if(data->input_array[n] > max)
			max = data->input_array[n];

		// Min value identification
		if(data->input_array[n] < min)
			min = data->input_array[n];

		// Even array contruction
		if(data->input_array[n] % 2)
		{
			data->even_array[even_index] = data->input_array[n];
		}
	}

	// Filling the struct with the remaining results
	data->average = (uint16_t)(average / ARRAY_SIZE);
	data->max = max;
	data->min = min;
	data->even_array_size = even_index;
}



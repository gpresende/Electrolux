//******************************************************************************
//
//  Knowledge Assessment (Question 3)
//
//******************************************************************************
//  DATA: 27/06/2022
//  Guilherme Pereira de Resende
//
//	Main Function
//------------------------------------------------------------------------------

#include "function.h"


//******************************************************************************
//	Main function
//------------------------------------------------------------------------------
int main(void)
{
	ARRAY_STR arrayStr;

	// Fill array input example
	for(uint16_t index=0; index<ARRAY_SIZE; index++)
	{
		arrayStr.input_array[index] = index;
	}

	// The remaining struct fields will be filled with the results at arrayStr
	calculator(&arrayStr);

	return 0;
}




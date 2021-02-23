#include "_data_structure.h"

int third_highest_int_in_array(int* array, unsigned int array_length) {
	// Returns the third highest inteager stored in an array without sorting the array.

	int first = 0;			// Container for the highest value in the array
	int second = 0;			// Container for the second highest value in the array
	int third = 0;			// Container for the third highest value in the array

	// Running a loop till the end of the length of an array
	for (unsigned int i = 0; i < array_length; i++, array++) {		
		if (*array > first) {			
			third = second;				// Shifting
			second = first;				// ..
			first = *array;				// Adding the new highest
		}
		else if (*array > second) {
			third = second;				// Shifting
			second = *array;			// Adding the new second highest
		}
		else if (*array > third) third = *array;	// Adding the new third highest
	}
	return third;	// Returning third highest
}
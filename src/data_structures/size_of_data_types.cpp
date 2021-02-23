#include<iostream>
#include<string>
#include "_data_structure.h"

void size_of_data_types() {
	// Prints the size (in bytes) of the basic data types present in base C++
	std::cout << "Fundamental datatypes" << std::endl;
	std::cout << "Size of an 'BOOL' data type is: " << sizeof(bool) << " bytes." << std::endl;
	std::cout << "Size of an 'INT' data type is: " << sizeof(int) << " bytes." << std::endl;
	std::cout << "Size of an 'CHAR' data type is: " << sizeof(char) << " bytes." << std::endl;
	std::cout << "Size of an 'SHORT' data type is: " << sizeof(short) << " bytes." << std::endl;
	std::cout << "Size of an 'LONG' data type is: " << sizeof(long) << " bytes." << std::endl;
	std::cout << "Size of an 'FLOAT' data type is: " << sizeof(float) << " bytes." << std::endl;
	std::cout << "Size of an 'DOUBLE' data type is: " << sizeof(double) << " bytes.\n" << std::endl;
	std::cout << "Combination of Fundamental datatypes" << std::endl;
	std::cout << "Size of an 'LONG INT' data type is: " << sizeof(long int) << " bytes." << std::endl;
	std::cout << "Size of an 'LONG LONG' data type is: " << sizeof(long long) << " bytes." << std::endl;
	std::cout << "Size of an 'LONG FLOAT' data type is: " << sizeof(long float) << " bytes." << std::endl;
	std::cout << "Size of an 'LONG DOUBLE' data type is: " << sizeof(long double) << " bytes.\n" << std::endl;
	std::cout << "Unsigned datatypes" << std::endl;
	std::cout << "Size of an 'UNSIGNED INT' data type is: " << sizeof(unsigned int) << " bytes." << std::endl;
	std::cout << "Size of an 'UNSIGNED SHORT' data type is: " << sizeof(unsigned short) << " bytes." << std::endl;
	std::cout << "Size of an 'UNSIGNED CHAR' data type is: " << sizeof(unsigned char) << " bytes.\n" << std::endl;
	std::cout << "Custom data types" << std::endl;
	std::cout << "Size of an 'STRING' data type is: " << sizeof(std::string) << " bytes.\n\n" << std::endl;
}
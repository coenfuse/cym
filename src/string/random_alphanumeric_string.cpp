#include "_string.h"
#include <iostream>
#include <ctime>	// This gives random value at every iteration this code.
#include <string>

void rndm_alphanum(unsigned int length) {
	srand((unsigned int)time(NULL) + rand() % 9999);
	std::string pool = "0123456789~!@#$%^&*_+=-QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>/?][{}";
	std::string random_string;
	while(length != 0) {
		random_string += pool[rand() % pool.length()];
		length--;
	}
	std::cout << random_string << std::endl;
}

std::string rndm_alphanum(size_t length) {
	srand((unsigned int)time(NULL) + rand() % 9999);
	std::string pool = "0123456789~!@#$%^&*_+=-QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>/?][{}";
	std::string random_string;
	while (length != 0) {
		random_string += pool[rand() % pool.length()];
		length--;
	}
	return random_string;
}
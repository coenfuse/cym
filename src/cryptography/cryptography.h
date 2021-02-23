#pragma once
#include<string>
#include<time.h>
#include<chrono>

// Basic Report Struct;
struct report {
	std::string key;
	unsigned int comparisions;
	bool solved;
};

report simple_brute(std::string to_crack, size_t code_length);
report improved_brute(std::string to_crack, size_t code_length);
report logical_brute(std::string to_crack);

#include"cryptography.h"

std::string recursive_bich(std::string to_crack, size_t code_length, size_t start_from);

report improved_brute(std::string to_crack, size_t code_length) {
	std::string alpha_pool = "0123456789~!@#$%^&*_+=-QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>/?][{}";
	std::string candidate;
	bool success = false;
	unsigned int comparisions = 0;
	unsigned int start_from = 0;

	while (!success) {
		for (size_t i = 0; i < alpha_pool.length(); i++) {
			if (alpha_pool[i] == to_crack[0]) {
				candidate = alpha_pool[i];
				while (!success) {
					candidate += recursive_bich(to_crack, code_length, start_from +1);
					comparisions++;
					if (candidate == to_crack) {
						comparisions++;
						success = true;
						return { candidate, comparisions, success };
					}
					comparisions++;
					start_from++;
					i++;
				}
			}
			comparisions++;
		}
	}
}

std::string recursive_bich(std::string to_crack, size_t code_length, size_t start_from) {
	if (start_from <= code_length) {
		std::string alpha_pool = "0123456789~!@#$%^&*_+=-QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>/?][{}";
		std::string chara;
		size_t i = 0;
		while (true) {
			if (alpha_pool[i] == to_crack[start_from]) {
				chara = alpha_pool[i];
				return chara;
			}
			i++;
		}
	}
	return "";
}
#include "cryptography.h"

report simple_brute(std::string to_crack, size_t code_length) {
	std::string alpha_pool = "abcdefghijklmnopqrstuvwxyz0123456789)!@#$%^&*(_+=ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand((unsigned int)time(NULL));
	unsigned int comparision = 0;
	bool success = false;
	std::string candidate;

	while (!success) {
		candidate.clear();
		for (size_t i = 0; i < code_length; i++) {
			candidate += alpha_pool[rand() % alpha_pool.length()];

			if (candidate == to_crack) {
				comparision++;
				success = true;
				return { candidate, comparision, success };
			}
			comparision++;
		}

	}

}
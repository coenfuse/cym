#include"cryptography.h"
#define BILLION 1000000000

report logical_brute(std::string to_crack) {
	std::string alpha_pool = "0123456789~!@#$%^&*_+=-QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>/?][{}";
	std::string candidate;
	size_t length = 1;
	unsigned int comparisions = 0;;
	bool success = false;
	
	while (true) {

		// 1 bit brute
		for (size_t i = 0; i < 84; i++) {
			candidate = alpha_pool[i];

			if (to_crack == candidate) {
				return { candidate, ++comparisions, true };
			}
			comparisions++;
		}

		// 2 bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				candidate = alpha_pool[i];
				candidate += alpha_pool[j];

				if (to_crack == candidate) {
					return { candidate, ++comparisions, true };
				}
				comparisions++;
			}
		}

		// This is going real messy really quickly
		// 3bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {

					if (comparisions > BILLION)
						return { candidate, ++comparisions, to_crack == candidate };

					candidate = alpha_pool[i];
					candidate += alpha_pool[j];
					candidate += alpha_pool[k];

					if (to_crack == candidate) {
						return { candidate, ++comparisions, true };
					}
					comparisions++;
				}
			}
		}

		// Real unfeasible code down here.
		// 4bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {
					for (size_t l = 0; l < 84; l++){

						if (comparisions > BILLION)
							return { candidate, ++comparisions, to_crack == candidate };

						candidate = alpha_pool[i];
						candidate += alpha_pool[j];
						candidate += alpha_pool[k];
						candidate += alpha_pool[l];

						if (to_crack == candidate) {
							return { candidate, ++comparisions, true };
						}
						comparisions++;
					}
				}
			}
		}

		// 5bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {
					for (size_t l = 0; l < 84; l++) {
						for (size_t m = 0; m < 84; m++){

							if (comparisions > BILLION)
								return { candidate, ++comparisions, to_crack == candidate };

							candidate = alpha_pool[i];
							candidate += alpha_pool[j];
							candidate += alpha_pool[k];
							candidate += alpha_pool[l];
							candidate += alpha_pool[m];

							if (to_crack == candidate) {
								return { candidate, ++comparisions, true };
							}
							comparisions++;
						}
					}
				}
			}
		}

		// 6bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {
					for (size_t l = 0; l < 84; l++) {
						for (size_t m = 0; m < 84; m++) {
							for (size_t n = 0; n < 84; n++){

								if (comparisions > BILLION)
									return { candidate, ++comparisions, to_crack == candidate };

								candidate = alpha_pool[i];
								candidate += alpha_pool[j];
								candidate += alpha_pool[k];
								candidate += alpha_pool[l];
								candidate += alpha_pool[m];
								candidate += alpha_pool[n];

								if (to_crack == candidate) {
									return { candidate, ++comparisions, true };
								}
								comparisions++;
							}
						}
					}
				}
			}
		}

		//7bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {
					for (size_t l = 0; l < 84; l++) {
						for (size_t m = 0; m < 84; m++) {
							for (size_t n = 0; n < 84; n++){
								for (size_t o = 0; o < 84; o++){

									if (comparisions > BILLION)
										return { candidate, ++comparisions, to_crack == candidate };

									candidate = alpha_pool[i];
									candidate += alpha_pool[j];
									candidate += alpha_pool[k];
									candidate += alpha_pool[l];
									candidate += alpha_pool[m];
									candidate += alpha_pool[n];
									candidate += alpha_pool[o];

									if (to_crack == candidate) {
										return { candidate, ++comparisions, false };
									}
									comparisions++;
								}
							}
						}
					}
				}
			}
		}

		// 8bit brute
		for (size_t i = 0; i < 84; i++) {
			for (size_t j = 0; j < 84; j++) {
				for (size_t k = 0; k < 84; k++) {
					for (size_t l = 0; l < 84; l++) {
						for (size_t m = 0; m < 84; m++) {
							for (size_t n = 0; n < 84; n++){
								for (size_t o = 0; o < 84; o++){
									for (size_t p = 0; p < 84; p++){

										if (comparisions > BILLION)
											return { candidate, ++comparisions, to_crack == candidate };

										candidate = alpha_pool[i];
										candidate += alpha_pool[j];
										candidate += alpha_pool[k];
										candidate += alpha_pool[l];
										candidate += alpha_pool[m];
										candidate += alpha_pool[n];
										candidate += alpha_pool[o];
										candidate += alpha_pool[p];

										if (to_crack == candidate) {
											return { candidate, ++comparisions, true };
										}
										comparisions++;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return {candidate, comparisions, success};
}
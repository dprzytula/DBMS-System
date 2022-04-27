#include "ROT13.h"

string Cipher::encrypt(string data) {
	int length = data.length(), character;
	char temp;

	for (int i = 0; i < length; i++) {
		temp = data[i] + 13;

		if (temp > 126) {
			character = temp - 126;
			character += 32;
			data[i] = character;
		}
		else {
			data[i] += 13;
		}
	}

	return data;
}

string Cipher::decrypt(string data) {
	int length = data.length(), character;
	char temp;

	for (int i = 0; i < length; i++) {
		temp = data[i] - 13;

		if (temp < 33) {
			character = 33 - temp;
			character = 127 - character;
			data[i] = character;
		}
		else {
			data[i] -= 13;
		}
	}

	return data;
}
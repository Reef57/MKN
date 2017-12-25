#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int* to_array(std::string str) {
	int len = str.length();
	int *array = new int[len];

	for(int i = 0; i < str.length(); i++) {
		array[i] = str[i] - '0';
	}

	return array;
}

void increase_cap(int* array) {
	int sz = sizeof(array)/sizeof(int);
	int* tmp_array = new int[(sz + 1)];
	
	tmp_array[0] = 1;

	for(int i = 0; i < sz; i++) {
		tmp_array[i + 1] = array[i];
	}

	delete[] array;
	array = tmp_array;
}

void addition(int* number1, int* number2, int* number3) {
	int sz1 = sizeof(number1) / sizeof(int);
	int sz2 = sizeof(number2) / sizeof(int);

	for(int i = sz2 - 1; i >= 0; i--) {
		if(number1[i] == 1 && number2[i] == 1) {

			number3[i] = 0;

			int j = i + 1;
			while(true) {

				if(number1[j] == 1) {
					number1[j] = 0;
				} else {
					number1[j] = 1;
					break;
				}

				j++;

				if(j == sz1) {
					increase_cap(number1);
					break;
				}
			}
		}
		else {
			number3[i] = number1[i] + number2[i];
		}
	}
}

void subtraction(int* number1, int* number2, int* number3) {

}

void multiplication(int* number1, int* number2, int* number3) {

}

//----big-endian----
int main() {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	std::string str1, str2;
	input >> str1;
	input >> str2;

	char op;
	input >> op;

	int* number1;
	int* number2;

	if(str1.length() > str2.length()) {
		number1 = to_array(str1);
		number2 = to_array(str2);
	} else {
		number1 = to_array(str2);
		number2 = to_array(str1);
	}

	int sz1 = sizeof(number1) / sizeof(int);
	int sz2 = sizeof(number2) / sizeof(int);

	std::cout << "size of number1 = " << sz1 << std::endl;
	std::cout << "number1: ";
	for(int i = 0; i < sz1; i++) {
		std::cout << number1[i];
	}
	std::cout << std::endl;

	std::cout << "size of number2 = " << sz2 << std::endl;
	std::cout << "number2: ";
	for(int i = 0; i < sz2; i++) {
		std::cout << number2[i];
	}
	std::cout << std::endl;

	int* number3;

	sizeof(number1) > sizeof(number2) ? number3 = new int[(sizeof(number1)/sizeof(int)) + 1]
									  : number3 = new int[(sizeof(number2)/sizeof(int)) + 1];

	switch(op) {
		case '+':
			addition(number1, number2, number3);
			break;
		case '-':
			subtraction(number1, number2, number3);
			break;
		case '*':
			multiplication(number1, number2, number3);
			break;
	}

	int sz3 = sizeof(number3) / sizeof(int);

	for(int i = 0; i < sz3; i++) {
		output << number3[i];
	}

	input.close();
	output.close();
	delete[] number1;
	delete[] number2;
	delete[] number3;
	return 0;
}
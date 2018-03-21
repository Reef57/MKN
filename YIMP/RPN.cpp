// RPN.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>

int priority(char op) {
	switch (op) {
	case '^':
		return 4;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '(':
		return 1;
		break;
	case ')':
		return 1;
		break;
	}
}

/*
^
*, /
+, -
()
*/
int main() {
	std::vector<char> ops;
	std::string output = "";

	std::string input = "(1 + 2) * 4 + 3";
	//std::getline(std::cin, input);


	for (int i = 0; i < input.length(); i++) {
		char c = input[i];

		if (isdigit(c)) {
			output += c;
			output += ' ';
		}
		else if (c != ' '){
			if (c == '(') {
				ops.push_back(c);
			}
			else if (c == ')') {
				char tmp = ops[ops.size() - 1];
				while (tmp != '(') {
					output += tmp;
					output += ' ';
					ops.pop_back();
					tmp = ops[ops.size() - 1];
				}
				ops.pop_back();
			}
			else {
				int r_prior = priority(c);
				if (ops.size() != 0) {
					int l_prior = priority(ops[ops.size() - 1]);
					if (l_prior >= r_prior) {
						output += ops[ops.size() - 1];
						output += ' ';
						ops.pop_back();
						ops.push_back(c);
					}
					else {
						ops.push_back(c);
					}
				}
				else {
					ops.push_back(c);
				}
			}
		}

		//----------------------------debug------------------------
		std::cout << "===" << i << "===" << std::endl;
		std::cout << "character: " << c << std::endl;
		std::cout << "output: " << output << std::endl;
		std::cout << "op stack: ";
		for (int i = 0; i < ops.size(); i++) {
			std::cout << ops[i] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;
	while (ops.size() != 0) {
		output += ops[ops.size() - 1];
		output += ' ';
		ops.pop_back();
	}

	std::cout << "output: " << output << std::endl;

	
	//calculating
	std::vector<int> numbers;
	int l, r;
	
	for (int i = 0; i < output.size(); i++) {
		char c = output[i];
		if (isdigit(c)) {
			numbers.push_back(atoi(&c));
		}
		else if (c != ' ') {
			int prior = priority(c);
			if (prior == 4) {
				r = numbers[numbers.size() - 1];
				numbers.pop_back();
				r *= r;
				numbers.push_back(r);
			}
			else {
				r = numbers[numbers.size() - 1];
				numbers.pop_back();
				l = numbers[numbers.size() - 1];
				numbers.pop_back();

				switch (c) {
				case '+':
					l += r;
					break;
				case '-':
					l -= r;
					break;
				case '*':
					l *= r;
					break;
				case '/':
					l /= r;
					break;
				}

				numbers.push_back(l);
			}
		}
	}

	std::cout << "numbers!" << std::endl;
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << std::endl;
	}

	system("pause");
	return 0;
}


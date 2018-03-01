// LR1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

class ComplexNum {
	double x, y;
	
public:
	ComplexNum(double real, double img)
		: x(real), y(img)
	{}

	friend ComplexNum operator+(const ComplexNum& a, const ComplexNum& b);
	friend ComplexNum operator-(const ComplexNum& a, const ComplexNum& b);
	friend ComplexNum operator*(const ComplexNum& a, const ComplexNum& b);
	friend ComplexNum operator/(const ComplexNum& a, const ComplexNum& b);
	friend std::ostream &operator<<(std::ostream &stream, ComplexNum num);
};

ComplexNum operator+(const ComplexNum& a, const ComplexNum& b) {
	return ComplexNum(a.x + b.x, a.y + b.y);
}

ComplexNum operator-(const ComplexNum& a, const ComplexNum& b) {
	return ComplexNum(a.x - b.x, a.y - b.y);
}

ComplexNum operator*(const ComplexNum& a, const ComplexNum& b) {
	return ComplexNum(((a.x * b.x) - (a.y * b.y)), ((a.y * b.x) + (a.x * b.y)));
}

ComplexNum operator/(const ComplexNum& a, const ComplexNum& b) {
	return ComplexNum((a.x * b.x + a.y * b.y)/(b.x * b.x + b.y * b.y),
						(a.y * b.x - a.x * b.y)/(b.x * b.x + b.y * b.y));
}

std::ostream &operator<<(std::ostream &stream, ComplexNum num) {
	stream << num.x;
	if (num.y > 0) {
		stream << " + " << num.y << "i";
	}
	else {
		stream << " - " << num.y * (-1) << "i";
	}
	return stream;
}
 
void printNumbers(std::vector<ComplexNum> list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << i << ". " << list[i] << std::endl;
	}
}

void printOptions() {
	std::cout << "1. New number" << std::endl;
	std::cout << "2. List numbers" << std::endl;
	std::cout << "3. +" << std::endl;
	std::cout << "4. -" << std::endl;
	std::cout << "5. *" << std::endl;
	std::cout << "6. /" << std::endl;
	std::cout << "7. exit" << std::endl;
}
void menu(std::vector<ComplexNum> list) {
	int choice;
	double a, b;
	
	std::cout << "Your numbers:" << std::endl;
	printNumbers(list);
	
	printOptions();
	std::cin >> choice;

	while (choice != 7) {
		switch (choice) {
		case 1:
			std::cout << "a + bi" << std::endl;
			std::cout << "Enter a" << std::endl;
			std::cin >> a;
			std::cout << "Enter b" << std::endl;
			std::cin >> b;
			ComplexNum tmp(a, b);
			list.push_back(tmp);
			std::cout << "Number created successfully" << std::endl;
			break;
		case 2:
			std::cout << "Your numbers: " << std::endl;
			printNumbers(list);
			break;
		case 3:
			std::cout << "Enter index of 1st elem" << std::endl;
			std::cin >> a;
			std::cout << "Enter index of 2nd elem" << std::endl;
		}
	}

}

int main() {
	ComplexNum num1(3, 4);
	ComplexNum num2(1, 2);

	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;

	std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
	std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
	std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
	std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
	std::cout << "-----------END OF TESTS-----------" << std::endl;

	std::vector<ComplexNum> list;
	list.push_back(num1);
	list.push_back(num2);

	menu(list);

	system("pause");
	return 0;
}
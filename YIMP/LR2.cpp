// MyString.cpp: определяет точку входа для консольного приложения.
// Павловская, стр. 255, Вариант 5

#include "stdafx.h"
#include <iostream>
#include <cstring>

class MyString {
	char* str;
	int size;
public:
	MyString();
	MyString(char c_str[]);
	MyString(char c);
	~MyString();

	int length();
	void erase();
};

MyString::MyString() {
	str = NULL;
	size = 0;
}

MyString::MyString(char c_str[]) {
	size = sizeof(c_str);
	str = new char[size];
	strcpy(str, c_str);
}

MyString::MyString(char c) {
	str = new char[1];
	str[0] = c;
	size = 1;
}

MyString::~MyString() {
	if (str) {
		delete[] str;
		size = 0;
	}
}

int MyString::length() {
	if (str) {
		return size;
	}
}

void MyString::erase() {
	delete[] str;
	str = NULL;  // unneeded?
	size = 0;
}

int main() {
	return 0;
}
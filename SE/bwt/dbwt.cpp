#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream input("output.txt");
	std::ofstream output("input.txt");

	std::string str;
	int K;

	input >> str >> K;

	std::vector<std::string> reshift(str.length(), "");

	for(int i = 0; i < str.length(); i++) {
		for(int j = 0; j < reshift.size(); j++) {
			reshift[j] = str[j] + reshift[j];
		}
		std::sort(reshift.begin(), reshift.end());
		for(int j = 0; j < reshift.size(); j++) {
			std::cout << reshift[j] << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}

	for(int i = 0; i < reshift.size(); i++) {
		std::cout << reshift[i] << std::endl;
	}

	output << reshift[K - 1];

	input.close();
	output.close();
	return 0;
}
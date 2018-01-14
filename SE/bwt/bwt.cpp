#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	std::string str;
	input >> str;

	unsigned int N = str.length();
	std::vector<std::string> shift(N, str);

	//таблица циклических сдвигов
	for(int i = 1; i < shift.size(); i++) {
		std::string tmp_str = shift[i - 1];
		for(int j = 0; j < shift[i - 1].length() - 1; j++) {
			tmp_str[j] = shift[i - 1][j + 1];
		}
		tmp_str[tmp_str.length() - 1] = shift[i - 1][0];
		shift[i] = tmp_str;
	}

	std::sort(shift.begin(), shift.end());

	//нахождение номера исходной строки в отсортированной таблице
	unsigned int indx = 0;
	for(int i = 0; i < shift.size(); i++) {
		if(!str.compare(shift[i])) {
			indx = i + 1;
			break;
		}
	}

	//запись результата в файл
	for(int i = 0; i < shift.size(); i++) {
		output << shift[i][shift[i].length() - 1];
	}
	output << " " << indx;

	input.close();
	output.close();
	return 0;
}
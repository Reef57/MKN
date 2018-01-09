#include <fstream>
#include <iostream>
#include <vector>

int main() {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	std::string text, to_find;

	std::getline(input, text);
	std::getline(input, to_find);

	int n = text.length();
	int m = to_find.length();

	std::vector<int> suffshift(m+1, m);
	std::vector<int> z(m, 0);

	for(int j = 1, maxZidx = 0, maxZ = 0; j< m; ++j) {
		if(j <= maxZ) z[j] = std::min(maxZ - j + 1, z[j - maxZidx]);
		while(j + z[j] < m && to_find[m - 1 - z[j]] == to_find[m - 1 - (j + z[j])]) z[j]++;
		if(j + z[j] - 1 > maxZ) {
			maxZidx = j;
			maxZ = j + z[j] - 1;
		}
	}

	for(int j = m - 1; j > 0; j--) {
		suffshift[m - z[j]] = j;
	}

	for(int j = 1, r = 0; j <= m - 1; j++)
		if(j + z[j] == m)
			for(; r<= j; r++)
				if(suffshift[r] == m) 
					suffshift[r] = j;

	int j, bound = 0;
	for(int i = 0; i<= n - m; i += suffshift[j + 1]) {
		for(j = m - 1; j >= bound && to_find[j] == text[i + j]; j--);
		if(j < bound) {
			output << i << " ";
			bound = m - suffshift[0];
			j = -1;
		}
		else {
			bound = 0;
		}
	}

	input.close();
	output.close();
	return 0;
}
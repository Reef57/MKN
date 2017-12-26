#include <iostream>
#include <vector>

std::vector<int> vec;
int N;

void swap(int a, int b) {
	int tmp = vec[a];
	vec[a] = vec[b];
	vec[b] = tmp;
}

void gen(int k) {
	if(k == N) {
		for(int i = 0; i < N; i++) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		for(int j = k; j < N; j++) {
			swap(k, j);
			gen(k + 1);
			swap(k, j);
		}
	}
}

int main() {
	std::cout << "Enter N: " << std::endl;
	std::cin >> N;

	for(int i = 1; i <= N; i++) {
		vec.push_back(i);
	}

	gen(0);

	return 0;	
}
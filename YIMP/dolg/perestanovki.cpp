#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<bool> used;
std::vector<string> inputStr, ans;
std::vector<std::vector<string>> result;
int N;

void fill(int c){
    if (c == N){
        result.push_back(ans);
        return;
    }
    for (int i = 0; i < N; i++){
        if (used[i] == false){
            ans.push_back(inputStr[i]);
            used[i] = true;
            reshuffle(c + 1);
            ans.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

    input >> N;

    for (int i = 0; i < N; i++){
        string a;
        input >> a;
		used.push_back(false);
        inputStr.push_back(a);
    }
    reshuffle(0);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            output << result[i][j] << " ";
        }
        output << endl;
    }
    return 0;
}


#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1], std::ios_base::in | std::ios_base::binary);
    std::ofstream LREfile("output.txt");

    char a, cot;
    int icot;

    while(file.peek() != EOF){
        file.get(cot);
        icot = static_cast<int>(cot);
        file.get(a);
        if(icot > 0){
            for(int i = 0; i < icot; i ++){
                LREfile << a;
            }
        }
        else{
            icot += 127;
            LREfile << a;
            for(int i = 1; i < icot; i++){
                file.get(a);
                LREfile << a;
            }
        }
    }

    file.close();
    LREfile.close();
    return 0;
}
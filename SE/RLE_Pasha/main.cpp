#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

int main(int argc, char* argv[]) {
	
    std::ifstream file(argv[1], std::ios_base::in | std::ios_base::binary);
    strcat(argv[1], ".lre");	
    std::ofstream LREfile(argv[1]);

    char a;
    char a1[128];
    a1[0] = '\0';
    int cot = 1;
    bool s = 1;
    a1[0] = file.peek();

    while(!file.eof()){
        file>>a;
		//LREfile.put(a);
		//cot++;
		
        if(cot == 126){
            if(s == 0) {
                
                LREfile << static_cast<char>(cot);
                for (int i = 0; i < 126; i++) {
                    LREfile << a1[i];
                }
                cot = 1;
            }
            else{
                LREfile << 125 <<a1[0];
                cot = 2;
            }
        }
		
        if(s == 1){if(a == file.peek()){cot++;}
        else{
            LREfile << static_cast<char>(cot) <<a1[0];
            s = 0;
            cot = 0;
        }}
        else{
            if(a != file.peek()){
                a1[cot] = a;
                cot++;
            }
            else{
                if(cot != 0) {
                    cot -= 127;
                    LREfile << static_cast<char>(cot);
                    for (int i = 0; i < cot + 127; i++) { LREfile << a1[i]; }
                }
                cot = 2;
                a1[0] = a;
                s = 1;
            }
        }

    }
	
	LREfile << cot;

    if(s == 0){if(cot != 0) {
            //cot -= 127;
            LREfile << static_cast<char>(cot);
            for (int i = 0; i < cot + 127; i++) { LREfile << a1[i]; }
	}}

    file.close();
    LREfile.close();
    return 0;
}
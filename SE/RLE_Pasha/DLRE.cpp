#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1], std::ios_base::in | std::ios_base::binary);
    std::ofstream LREfile("output", std::ios_base::binary);

    char a, cot;
    int icot, k;	
	long nFileLen = 0;
	k = 0;
	
	if (file)
	{
	   file.seekg(0, std::ios_base::end);
	   nFileLen = file.tellg();
	   file.seekg(0, std::ios_base::beg);
	}
	
	
	while(k < nFileLen){
        file.get(cot);
        icot = static_cast<int>(cot);
        file.get(a);
		k += 2;
        if(icot > 0){
            for(int i = 0; i < icot; i++){
                LREfile << a;
            }
        }
        else{
            icot += 127;
            LREfile << a;
            for(int i = 1; i < icot; i++){
                file.get(a);
                LREfile << a;
				k++;
            }
        }
    }

    file.close();
    LREfile.close();
    return 0;
}
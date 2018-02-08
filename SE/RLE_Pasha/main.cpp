#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1], std::ios_base::in | std::ios_base::binary);
    std::ofstream LREfile("compressed_file", std::ios_base::binary);

    char a;
    char a1[128];
    a1[0] = '\0';
    int cot = 1;
    bool s = 1;
    a1[0] = file.peek();

	long nFileLen = 0;
	if (file)
	{
	   file.seekg(0, std::ios_base::end);
	   nFileLen = file.tellg();
	   file.seekg(0, std::ios_base::beg);
	}
	
	
	for(int i = 0; i < nFileLen; i++){
        file.get(a);
        if(cot == 120){
            if(s == 0) {
                LREfile << static_cast<char>(cot-2-127);
                for (int i = 0; i < 118; i++) {
                    LREfile << a1[i];
                }
				a1[0] = a1[118];
				a1[1] = a1[119];
                cot = 2;
            }
            else{
                LREfile << static_cast<char>(118) <<a1[0];
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
					//LREfile << (cot);
                    cot -= 127;
                    LREfile << static_cast<char>(cot);
                    for (int i = 0; i < cot + 127; i++) {LREfile << a1[i];}
                }
                cot = 2;
                a1[0] = a;
                s = 1;
            }
        }

    }

    if(s == 0){if(cot != 0) {
            cot -= 127;
            LREfile << static_cast<char>(cot);
            for (int i = 0; i < cot + 127; i++) { LREfile << a1[i]; }
	}}

    file.close();
    LREfile.close();
    return 0;
}
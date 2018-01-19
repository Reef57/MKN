#include <string>
#include <fstream>
#include <iostream>
int main(){
  std::string line, fline;
  int  sl, ssl;
  line = "chlenchlen111noobnoob";
  fline = "noob";
  sl = line.length();
  ssl = fline.length();
	
  int  i, Pos;
  int  movet[256];
  for ( i = 0; i < 256; i ++ )
    movet[i] = ssl;

  for ( i = ssl-1; i >= 0; i-- )
    if ( movet[(short)(fline[i])] == ssl ) 
      movet[(short)(fline[i])] = ssl - i - 1;
  
  Pos = ssl - 1;
  while ( Pos < sl ) 
	if ( fline[ssl - 1] != line[Pos] )
      Pos += movet[(short)(line[Pos])];
    else 
      for ( i = ssl - 2; i >= 0; i-- ){
        if ( fline[i] != line[Pos - ssl + i + 1] ) {
          Pos += movet[(short)(line[Pos - ssl + i + 1])] - 1;
          break;
        }
        else
          if ( i == 0 ){
			std::cout << Pos - ssl + 1 << std::endl;
            Pos++;
		  }
      }

  return 0;
}

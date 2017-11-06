#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[]) {
	uint32_t uncompsize = 0;
	uint32_t compsize = 0;
	uint32_t bytes = 0;

	float compratio = 0;



	char filename[256];

	if(argc < 2) {
		printf("Invalid input\n");
		return 0;
	}

	//get filename from stdin
	strcpy(&filename[0], argv[1]);

	FILE* fd_in;
	if((fd_in = fopen(filename, "rb")) == NULL) {
		printf("Unable to open file\n");
		return 1;
	}

	strcat(filename, ".rle\0");

	FILE* fd_out;
	if((fd_out = fopen(filename, "wb")) == NULL) {
		printf("Unable to create file\n");
		return 1;
	}

	//-------------size--------------
	fseek(fd_in, 0, SEEK_END);
	uncompsize = ftell(fd_in);
	rewind(fd_in);
	//-------------------------------

	printf("%d bytes\n\n", uncompsize);

	uint32_t cur = 0;
	uint8_t prev = 0;
	uint8_t stop = 1;
	uint8_t i = 0;
	
	while(stop) {
		cur = fgetc(fd_in);

		if(cur == EOF) {
			stop = 0;
		}

		if(bytes == 0) {
			prev = cur;
		}

		if((prev != (uint8_t)cur) || (i == UINT8_MAX) || (stop == 0)) {
			fputc(i, fd_out);

			fputc(prev, fd_out);

			prev = cur;
			i = 1;

			compsize += 2;
		}

		else {
			i++;
		}

		if(stop != 0) {
			bytes++;
		}
	}

	compratio = (float)uncompsize / compsize;

	printf("Uncompressed size: %d bytes\n", uncompsize);
	printf("  Compressed size: %d bytes\n", compsize);
	printf("            Ratio: %.1f (%.0f%%)\n", compratio, (((float)1 / compratio) * 100));

}
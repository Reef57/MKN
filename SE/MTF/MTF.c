#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char input_char, char* list) {
	int i;
	for(i = 0; i < strlen(list); i++) {
		if(list[i] == input_char) {
			return i;
			break;
		}
	}
}


void moveToFront(int curr_index, char* list) {
	char* record = (char*)malloc(sizeof(char) * 26);
	strcpy(record, list);
	strncpy(list + 1, record, curr_index);

	list[0] = record[curr_index];
}

void MTF(char* input_text, int len_text, char* list) {
	int i;
	int* output_arr = (int*)malloc(sizeof(int) * len_text);

	for(i = 0; i < len_text; i++) {
		output_arr[i] = search(input_text[i], list);

		printf("%d ", output_arr[i]);

		moveToFront(output_arr[i], list);
	}
}

void dMTF(int* input, int len_text, char* list) {
	int i;
	char* output_arr = (char*)malloc(sizeof(char) * len_text);

	for(i = 0; i < len_text; i++) {
		output_arr[i] = list[input[i]];

		printf("%c", output_arr[i]);

		moveToFront(input[i], list);
	}
}

int main() {
	char* input_text = "bananaaa";
	int len_text = strlen(input_text);

	char* list = (char*)malloc(sizeof(char) * 26);
	strcpy(list, "abcdefghijklmnopqrstuvwxyz");

	printf("Input text: %s", input_text);
	printf("\nMTF: ");


	MTF(input_text, len_text, list);

	int dmtf_test[8] = {1, 1, 13, 1, 1, 1, 0, 0};
	int len = 8;

	strcpy(list, "abcdefghijklmnopqrstuvwxyz");
	dMTF(dmtf_test, len, list);

	return 0;
}
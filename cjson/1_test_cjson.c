#include <stdio.h>
#include "cJSON.h"

#define FILE_LENGTH 4096

// read json data from 1_test_data.txt file
int read_json_data_from_file(const char* filename, char* json_data) {
	FILE* fp;
	long filesize = 0;
	int ret = 0;

	fp = fopen(filename, "r");
	if(NULL == fp) {
		printf("open file error");
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	rewind(fp);

	ret = fread(json_data, 1, filesize, fp);
	if(NULL == ret) {
		printf("freed error\n");
		return -1;
	}
	return ret;
}

int main(void) {
	return 0;
}

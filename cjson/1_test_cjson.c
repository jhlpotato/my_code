#include <stdio.h>
#include "cJSON.h"

#define FILE_LENGTH 40960
#define FILE_NAME "1_test_data.txt"

// read json data from 1_test_data.txt file
int read_json_data_from_file(const char* filename, char* json_data) 
{
	FILE* fp;
	long filesize = 0;
	int ret = 0;

	fp = fopen(filename, "r");
	if(NULL == fp) {
		printf("open file error\n");
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	rewind(fp);

	ret = fread(json_data, 1, filesize, fp);
	if(0 == ret) {
		printf("freed error\n");
		return -1;
	}
	return ret;
}

// read data from json_data
// api1: cJSON_Parse()
// api2: cJSON_GetObjectItemCaseSensitive()
void test_json_1(char* json_data)
{
	// test 01
	cJSON* root = cJSON_Parse(json_data);
	cJSON* format = cJSON_GetObjectItemCaseSensitive(root, "format");
	cJSON* framerate_item = cJSON_GetObjectItemCaseSensitive(format, "frame rate");
	double framerate = 0;
	if(cJSON_IsNumber(framerate_item)) {
		framerate = framerate_item->valuedouble;
	}

	printf("######## Test 01 ########\n");
	printf("frame rate = %lf\n", framerate);

	// test 02
	cJSON_SetNumberValue(framerate_item, 25);
	char* rendered = cJSON_Print(root);
	
	printf("######## Test 02 ########\n");
	printf("json data = %s\n", rendered);
}

void test_json_2()
{
	cJSON *root;
	cJSON *fmt;
	root = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
	cJSON_AddItemToObject(root, "format", fmt = cJSON_CreateObject());
	cJSON_AddStringToObject(fmt, "type", "rect");
	cJSON_AddNumberToObject(fmt, "width", 1920);
	cJSON_AddNumberToObject(fmt, "height", 1080);
	cJSON_AddFalseToObject(fmt, "interlace");
	cJSON_AddNumberToObject(fmt, "frame rate", 24);

	char* result = cJSON_Print(root);
	printf("######## Test 03 ########\n");
	printf("json data = %s\n", result);
}

int main(void) 
{
	char json_data[FILE_LENGTH];
	int ret = 0;
	ret = read_json_data_from_file(FILE_NAME, json_data);
	if(-1 == ret) {
		printf("read_json_data_from_file error\n");
		return -1;
	}

	printf("ret = %d\n", ret);		
	printf("json_data = %s\n", json_data);

	// test
	test_json_1(json_data);	
	test_json_2();
	return 0;
}

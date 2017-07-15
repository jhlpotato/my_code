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
// api3: cJSON_IsNumber()
// api4: cJSON_SetNumberValue()
// api5: cJSON_Print()
void test_json_1(char* json_data)
{

	printf("######## Test 12 ########\n");
	cJSON_Minify(json_data);
	printf("json data = %s\n", json_data);

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

	printf("######## Test 07 ########\n");
	printf("root json size = %d\n", cJSON_GetArraySize(root));
	printf("format json size = %d\n", cJSON_GetArraySize(format));
	
	printf("######## Test 08 ########\n");
	cJSON *json_item1 = cJSON_GetArrayItem(root, 0);
	cJSON *json_item2 = cJSON_GetArrayItem(root, 1);
	printf("json_item1 data = %s\n", cJSON_Print(json_item1));
	printf("json_item2 data = %s\n", cJSON_Print(json_item2));

	printf("######## Test 09 ########\n");
	cJSON* format1 = cJSON_GetObjectItem(root, "format");
	cJSON* framerate_item1 = cJSON_GetObjectItem(format1, "frame rate");
	printf("json data = %s\n", cJSON_Print(format1));
	printf("json data = %s\n", cJSON_Print(framerate_item1));
	
	printf("######## Test 10 ########\n");
	cJSON_bool isHasItem1 = cJSON_HasObjectItem(root, "format");
	cJSON_bool isHasItem2 = cJSON_HasObjectItem(root, "formai");
	printf("has format item = %d\n", (int)isHasItem1);
	printf("has formai item = %d\n", (int)isHasItem2);

	printf("######## Test 06 ########\n");
	cJSON_Delete(format);
	printf("json data = %s\n", cJSON_Print(root));

	printf("######## Test 11 ########\n");
	cJSON* cjson_null = cJSON_CreateNull();
	printf("json data = %s\n", cJSON_Print(cjson_null));
	printf("json data is null or not = %d\n", (int)cJSON_IsNull(cjson_null));
	cJSON_Delete(cjson_null);

	cJSON* cjson_true = cJSON_CreateTrue();
	printf("json data = %s\n", cJSON_Print(cjson_true));
	printf("json data is true or not = %d\n", (int)cJSON_IsTrue(cjson_true));
	cJSON_Delete(cjson_true);

	cJSON* cjson_false = cJSON_CreateFalse();
	printf("json data = %s\n", cJSON_Print(cjson_false));
	printf("json data is false or not = %d\n", (int)cJSON_IsFalse(cjson_false));
	cJSON_Delete(cjson_false);


	cJSON_bool bool_type = (cJSON_bool)1;
	cJSON* cjson_bool = cJSON_CreateBool(bool_type);
	printf("json data = %s\n", cJSON_Print(cjson_bool));
	printf("json data is bool or not = %d\n", (int)cJSON_IsBool(cjson_bool));
	cJSON_Delete(cjson_bool);

	double number_type = 88;
	cJSON* cjson_number = cJSON_CreateNumber(number_type);
	printf("json data = %s\n", cJSON_Print(cjson_number));
	printf("json data is number or not = %d\n", (int)cJSON_IsNumber(cjson_number));
	cJSON_Delete(cjson_number);
		
	char* string_type = "jinhongliang";
	cJSON* cjson_string = cJSON_CreateString(string_type);
	printf("json data = %s\n", cJSON_Print(cjson_string));
	printf("json data is string or not = %d\n", (int)cJSON_IsString(cjson_string));
	cJSON_Delete(cjson_string);

	char* raw_type = "jinhongliang_raw";
	cJSON* cjson_raw = cJSON_CreateRaw(raw_type);
	printf("json data = %s\n", cJSON_Print(cjson_raw));
	printf("json data is raw or not = %d\n", (int)cJSON_IsRaw(cjson_raw));
	cJSON_Delete(cjson_raw);

	cJSON* cjson_array = cJSON_CreateArray();
	printf("json data = %s\n", cJSON_Print(cjson_array));
	printf("json data is array or not = %d\n", (int)cJSON_IsArray(cjson_array));
	cJSON_Delete(cjson_array);

	cJSON* cjson_object = cJSON_CreateObject();
	printf("json data = %s\n", cJSON_Print(cjson_object));
	printf("json data is object or not = %d\n", (int)cJSON_IsObject(cjson_object));
	cJSON_Delete(cjson_object);
	
}

// create json struct
// api6: cJSON_CreateObject();
// api7: cJSON_AddItemToObject()
// api8: cJSON_AddStringToObject()
// api9: cJSON_AddNumberToObject()
// api10: cJSON_AddFalseToObject()
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
	
	printf("######## Test 04 ########\n");
	printf("json version = %s\n", cJSON_Version());

	printf("######## Test 05 ########\n");
	printf("json data = %s\n", cJSON_PrintUnformatted(root));

	printf("######## Test 12 ########\n");
	cJSON_AddNullToObject(root, "null");
	cJSON_AddTrueToObject(root, "true");
	cJSON_AddFalseToObject(root, "false");
	cJSON_AddBoolToObject(root, "bool", 1);
	cJSON_AddNumberToObject(root, "number", 88);
	cJSON_AddStringToObject(root, "string", "jinhongliang");
	cJSON_AddRawToObject(root, "Raw", "jinhongliang_raw");
	printf("json data = %s\n", cJSON_Print(root));
	
	
	printf("######## Test 06 ########\n");
	cJSON_Delete(fmt);
	printf("json data = %s\n", cJSON_Print(root));
	
	
	printf("######## Test 11 ########\n");
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cJSON * int_array_root = cJSON_CreateIntArray(a, 10);
	printf("json data = %s\n", cJSON_Print(int_array_root));
	cJSON_AddItemToArray(int_array_root, cJSON_CreateNumber(11));
	printf("json data = %s\n", cJSON_Print(int_array_root));
	cJSON_Delete(int_array_root);
	
	//float b[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
	float b[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
	cJSON * float_array_root = cJSON_CreateFloatArray(b, 10);
	printf("json data = %s\n", cJSON_Print(float_array_root));
	cJSON_AddItemToArray(float_array_root, cJSON_CreateNumber(11.5));
	printf("json data = %s\n", cJSON_Print(float_array_root));
	cJSON_Delete(float_array_root);

	double c[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
	//double c[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
	cJSON * double_array_root = cJSON_CreateDoubleArray(c, 10);
	printf("json data = %s\n", cJSON_Print(double_array_root));
	cJSON_AddItemToArray(double_array_root, cJSON_CreateNumber(11.5));
	printf("json data = %s\n", cJSON_Print(double_array_root));
	cJSON_Delete(double_array_root);

	// note: must const char ** 
	const char* d[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	cJSON * string_array_root = cJSON_CreateStringArray(d, 10);
	printf("json data = %s\n", cJSON_Print(string_array_root));
	cJSON_AddItemToArray(string_array_root, cJSON_CreateString("eleven"));
	printf("json data = %s\n", cJSON_Print(string_array_root));
	cJSON_Delete(string_array_root);
	
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

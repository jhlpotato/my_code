cc=gcc
CFLAGS=-I.

1_test_cjson: 1_test_cjson.c 
	$(cc) -o 1_test_cjson 1_test_cjson.c cJSON.c $(CFLAGS)

test: test.c
	$(cc) -o test.c cJSON.c $(CFLAGS)

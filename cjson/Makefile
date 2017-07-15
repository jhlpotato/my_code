cc=gcc
CFLAGS=-I.

1_test_cjson: 1_test_cjson.c 
	$(cc) -o 1_test_cjson 1_test_cjson.c cJSON.c $(CFLAGS) -pthread

clean:
	rm -f 1_test_cjson

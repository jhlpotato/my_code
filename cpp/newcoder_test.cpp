#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(void) {
	for(int i = 0; i < 2; ++i) {
		fork();
		printf("-\n");
	}
	return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
	const int i = 0; 
	int *j = (int *) &i; 
	*j = 1; 
	printf("%d,%d", i, *j);
	return 0;
}
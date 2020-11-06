#include <stdio.h>
#include <string.h>

int F1(unsigned int n) {
	if (n == 0) return n;

	int i, j;

	for (i = 1; i < 2 * n - 1; i += 2) 
		for (j = 0; j < (n - 1) * (n - 1); j++);
	
	return j + i;
}

int main() {
    printf("%d\n", F1(10));
    return 0;
}
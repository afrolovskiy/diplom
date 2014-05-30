#include <stdio.h>
#include <stdlib.h>

int main(int arc, void *argv[]) {
	int x, y, z;

	if (arc < 3){
		return -1;
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	if (x > y) {
		x = x + 10;
		y = 2 * y;
	} else {
		x = x - 10;
		y = y / 2;
	}

	z = x + y;

	return 0;
}
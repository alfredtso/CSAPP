#include <stdio.h>
#include <sys/_types/_u_int8_t.h>

int uadd_ok(u_int8_t x, u_int8_t y) {
	// return 1 if can be added without overflow
	// since both unsigned, overflow detection comes from
	// x + y >= x or y
	
	u_int8_t addition = x + y;
	printf("x + y = %d\n", addition);
	return addition >= x;
}

int main() {
	u_int8_t x = 45;
	u_int8_t y = 24;
	int noOverflow = uadd_ok(x, y);

	u_int8_t x1 = 124;
	u_int8_t y1 = 200;
	int overflow = uadd_ok(x1, y1);

	printf("Results: %d, %d\n", noOverflow, overflow);
}


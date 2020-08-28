#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer x, size_t len)
{
	int i;

	for (i = 0; i < len; ++i)
		printf("%.2x", x[i]);
	printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer) &x,  sizeof(int));}
void show_float(float x) {show_bytes((byte_pointer) &x, sizeof(float));}
void show_pointer(void *x) {show_bytes((byte_pointer) &x, sizeof(void *));}

void swapping_value(int *x, int  *y){

	printf("Show x and y pointer before swapping\n");
	byte_pointer xpt = (byte_pointer) x;
	byte_pointer ypt = (byte_pointer) y;
	show_pointer(xpt);
	show_pointer(ypt);
	printf("Show x and y before swapping\n");
	printf("x: %d , y: %d\n", *x, *y);
	printf("\n");

	// Magic
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;

	printf("Show x and y pointer after swapping\n");
	show_pointer(xpt);
	show_pointer(ypt);
	printf("Show x and y after swapping\n");
	printf("x: %d , y: %d\n", *x, *y);
}

int main()
{
	int x = 12345;
	int *xpt = &x;
	byte_pointer xpter = (byte_pointer) &x;

	int y = 0x12345678;
	int *ypt = &y;
	byte_pointer pter = (byte_pointer) &y;
	const char *m = "mnopqr";

	short z = 12345;
	short mz = -x;

	printf("casting signed to unsigned\n");
	short int v = -12345;
	unsigned short uv = (unsigned short) v;
	printf("v = %d, uv = %u\n", v, uv);

	printf("Printing short x .... \n");
	show_bytes((byte_pointer) &z, sizeof(short));
	show_bytes((byte_pointer) &mz, sizeof(short));

	printf("Printing Int ...\n");
	show_int(y);
	printf("\n");

	printf("Printing Float ...\n");
	show_float(3510593.0);
	printf("\n");
	
	printf("Printing Pointer ...\n");
	show_pointer(xpt);
	printf("\n");

	printf("Printing Pointer with show_bytes...\n");
	show_bytes(xpter, 1);
	printf("\n");
	
	printf("Printing string mnopqr \n");
	show_bytes((byte_pointer) m, strlen(m));
	show_bytes((byte_pointer) m, 7);
	printf("\n");

	swapping_value(xpt,ypt);
	return 0;
}



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uintptr_t tag(uintptr_t ptr) {
	uintptr_t mask = (uintptr_t)(0xac) << 56;
	return ptr | mask;
}

int main() {
	int *ptr_to_int = (int*)malloc(sizeof(int));

	ptr_to_int = (int*)tag((uintptr_t)ptr_to_int);

	*ptr_to_int = 0x77;

	printf("ptr_to_int: %lx\n", (uintptr_t)ptr_to_int);

	return 0;
}

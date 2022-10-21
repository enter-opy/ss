#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, starting_block, file_length, possible, exit;

	printf("Enter the number of blocks: ");
	scanf("%d", &n);

	int blocks[n];
	for (int i = 0; i < n; i++) blocks[i] = 0;

	do {
		possible = 1;
		printf("Enter the starting block and length of the file: ");
		scanf("%d", &starting_block);
		scanf("%d", &file_length);

		for (int i = starting_block; i < starting_block + file_length; i++) {
			if (blocks[i] != 0) {
				possible = 0;
				break;
			}
		}
		
		if (possible != 0) {
			for (int i = starting_block; i < starting_block + file_length; i++) blocks[i] = 1;
			
			printf("Allocated\n");
		} else {
			printf("Not allocated\n");
		}

		printf("Do you want to continue (0-exit, 1-continue): ");
		scanf("%d", &exit);
	} while (exit != 0);

	return 0;
}

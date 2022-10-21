#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, head_position, total_head_movement;

	printf("Enter the number of requests: ");
	scanf("%d", &n);

	int requests[n];

	printf("Enter request sequence:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &requests[i]);
	}

	printf("Enter the initial head position: ");
	scanf("%d", &head_position);

	printf("Seek sequence:\n");
	for (int i = 0; i < n; i++) {
		total_head_movement += (abs(head_position - requests[i]));
		printf("%d\t", requests[i]);
		head_position = requests[i];
	}

	printf("\nTotal head movement: %d", total_head_movement);

	return 0;
}

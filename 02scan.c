#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, head_position, total_head_movement = 0, initial_direction, min, temp, flag;

	printf("Enter the number of requests: ");
	scanf("%d", &n);

	int requests[n];

	printf("Enter request sequence:\n");
	for (int i = 0; i < n; i++) scanf("%d", &requests[i]);

	printf("Enter the initial head position: ");
	scanf("%d", &head_position);

	printf("Enter the initial head movement direction (high-1, low-0): ");
	scanf("%d", &initial_direction);

	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) if (requests[j] > requests[min]) min = j;
		
		temp = requests[i];
		requests[i] = requests[min];
		requests[min] = temp;
	}
	
	printf("Seek sequence:\n");
	if (initial_direction) {
		for (int i = 0; i < n; i++) {
			if (head_position < requests[i]) {
				flag = i;
				continue;
			}
			
			total_head_movement += (abs(head_position - requests[i]));
			printf("%d\t", requests[i]);
			head_position = requests[i];		
		}

		for (int i = flag; i >= 0; i--) {
			total_head_movement += (abs(head_position - requests[i]));
			printf("%d\t", requests[i]);
			head_position = requests[i];		
		}
	} else {
		for (int i = n - 1; i >= 0; i--) {
			if (head_position > requests[i]) {
				flag = i;
				continue;
			}
			
			total_head_movement += (abs(head_position - requests[i]));
			printf("%d\t", requests[i]);
			head_position = requests[i];		
		}

		for (int i = flag; i < n; i++) {
			total_head_movement += (abs(head_position - requests[i]));
			printf("%d\t", requests[i]);
			head_position = requests[i];		
		}
	}

	printf("\nTotal head movement: %d", total_head_movement);

	return 0;
}

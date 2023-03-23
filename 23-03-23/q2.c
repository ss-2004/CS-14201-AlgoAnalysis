#include <stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
	int i, j;
	printf("Following activities can be performed : ");
	i = 0;
	printf("%d ", i);

	for (j = 1; j < n; j++) {
		if (s[j] >= f[i]) {
			printf("%d ", j);
			i = j;
		}
	}
}

int main()
{
	int n, i;
	printf("Enter number of activities : ");
	scanf("%d", &n);	
	int s[n];
	int f[n];

	printf("Enter start time : ");
	for(i=0; i<n; i++)
		scanf("%d", &s[i]);
	printf("Enter end time : ");
	for(i=0; i<n; i++)
		scanf("%d", &f[i]);

	printMaxActivities(s, f, n);
	printf("\n");
	return 0;
}


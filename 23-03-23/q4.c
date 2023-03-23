#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
	int i, W, N;
	printf("Enter number of items : ");
	scanf("%d", &N);
	printf("Enter bag capacity : ");
	scanf("%d", &W);
	
	int profit[N];
	int weight[N];
	int n = sizeof(profit) / sizeof(profit[0]);
	
	printf("Enter profits : ");
	for(i=0; i<n; i++)
		scanf("%d", &profit[i]);
	printf("Enter weigths : ");
	for(i=0; i<n; i++)
		scanf("%d", &weight[i]);

	printf("Total profit = %d\n", knapSack(W, weight, profit, n));
	return 0;
}


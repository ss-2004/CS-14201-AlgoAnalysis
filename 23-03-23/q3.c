#include <stdio.h>

int coinCount[5] = {0};
int coins[] = {1, 5, 10, 20, 50};

int count(int n, int sum)
{
	if (sum == 0)
		return 1;
	if (sum < 0)
		return 0;
	if (n <= 0)
		return 0;
		
	coinCount[n-1]=(sum/coins[n-1]);
	count(n-1, sum%coins[n-1]);
}

int main()
{
	int i, j, money;
	int n = sizeof(coins) / sizeof(coins[0]);
	printf("Enter money to be changed : "); 
	scanf("%d", &money);
	
	count(n, money);
	for(i=4; i>=0; i--)
		printf("Rs %d x %d\n", coins[i], coinCount[i]);
	return 0;
}


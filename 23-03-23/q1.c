#include <limits.h>
#include <stdio.h>

int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int K)
{
	if (K > 0 && K <= r - l + 1) {
		int pos = partition(arr, l, r);
		if (pos - l == K - 1)
			return arr[pos];
		if (pos - l > K - 1) 
			return kthSmallest(arr, l, pos - 1, K);
		return kthSmallest(arr, pos + 1, r,
						K - pos + l - 1);
	}
	return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l, j;
	for (j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

int main()
{
	int n, i, k;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter k : ");
	scanf("%d", &k);	
	
	int arr[n];
	printf("Enter array : ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("K'th smallest element is %d", kthSmallest(arr, 0, N - 1, K));
	return 0;
}


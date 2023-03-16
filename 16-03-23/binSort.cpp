// Analysis of BinSort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;

void swp(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int findMax(int arr[], int n)
{
	int i, mx = -1*pow(2, 32) + 2;
	for(i=0; i< n; i++)
	{
		if(arr[i] > mx)
			mx = arr[i];
	}
	return mx;
}

void binSort()
{
	int mx = findMax(arr, n);
	int i, j;
	node **bins;
	bins = new node *[max+1];
	
	for(i=0; i<mx+1; i++)
		bins[i] = NULL;
	for(i=0; i<n; i++)
		insert(bins[arr[i]], arr[i]);
		
	i=0; j=0;
	while(i < mx+1)
	{
		while(bins[i] != NULL)
			arr[j++] = dlt(bins[i]);
		i++;
	}
}

void writeTable(int size, double time, char *filename) {
    int i;
    FILE *fp = fopen(filename, "a+");

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n");
    else {
        fprintf(fp, "%d %lf", size, time);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void readData(int arr[], char *filename) {
    FILE *fp = fopen(filename, "r+");
    char x[16];
    int i, k = 0;

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n");
    else {
        while (fgets(x, 16, fp) != NULL) {
            int num = 0;
            fscanf(fp, "%d", &num);
            if (num == 0) break;
            arr[k++] = num;
        }
    }
    fclose(fp);
}

int main(int argc, char **argv) {
	int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
	int n=11, i;
//    int arr[100000];
// 	  int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};
//    int i = 0;
//    for (i = 0; i <= 11; i++) {
//        readData(arr, argv[1]);
//        begin = clock();
        binSort(arr, 0, n-1);
//        end = clock();
//        writeTable(size[i], (end - begin) / 2000, argv[2]);
//    }

	for(i=0; i<n; i++)
		printf("%d, ", arr[i]);
	printf("\n");
    return 0;
}

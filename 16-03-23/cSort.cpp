// Analysis of CountSort over 100K entries

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
	int i, mx = -16777216;
	for(i=0; i< n; i++)
	{
		if(arr[i] > mx)
			mx = arr[i];
	}
	return mx;
}

void cSort(int arr[], int n)
{
	int mx = findMax(arr, n);
	int i, j, *c;
	c = (int*) malloc(sizeof(int) * mx + 1);
	
	for(i=0; i<mx+1; i++)
		c[i]=0;
	for(i=0; i<n; i++)
		c[arr[i]]++;
			
	i=0; j=0;
	while(j < mx + 1)
	{
		if(c[j] > 0){
			arr[i++] = j;
			c[j]--;
		}
		else j++;
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
	int n=10, i;
//    int arr[100000];
// 	  int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};
//    int i = 0;
//    for (i = 0; i <= 11; i++) {
//        readData(arr, argv[1]);
//        begin = clock();
        cSort(arr, n);
//        end = clock();
//        writeTable(size[i], (end - begin) / 2000, argv[2]);
//    }

	for(i=0; i<n; i++)
		printf("%d, ", arr[i]);
	printf("\n");
    return 0;
}

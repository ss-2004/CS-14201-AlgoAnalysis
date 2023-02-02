// Analysis of Merge Sort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1], R[n2];
	for(i=0; i<n1; i++)
		L[i]=arr[l+i];
	for(j=0; j<n2; j++)
		R[j]=arr[m+1+j];
	
	i=0;j=0;k=l;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;		
		}
		k++;
	}

	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l+(r-1)/2;
		mSort(arr, l, m);
		mSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void writeTable(int size, double time) {
    int i;
    FILE *fp = fopen("mTable.txt", "a+");

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n");
    else {
        fprintf(fp, "%d %lf", size, time);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void readData(int arr[]) {
    FILE *fp = fopen("avg.txt", "r+");
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

int main() {
	int arr[100000];
	int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};
    int i;
	for (i = 0; i <= 11; i++) {
		readData(arr);
        begin = clock();
        mSort(arr, 0, size[i]-1);
        end = clock();
        writeTable(size[i], (end - begin) / 3500);
    }
    return 0;
}

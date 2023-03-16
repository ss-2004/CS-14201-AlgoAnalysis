// Analysis of QuickSort over 100K entries

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

int divArr(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swp(&arr[i], &arr[j]);
		}
	}
	swp(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void qSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = divArr(arr, low, high);
		qSort(arr, low, pi - 1);
		qSort(arr, pi + 1, high);
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
    int arr[100000];
    int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};
    int i = 0;
    for (i = 0; i <= 11; i++) {
        readData(arr, argv[1]);
        begin = clock();
        qSort(arr, 0, size[i]-1);
        end = clock();
        writeTable(size[i], (end - begin) / 2000, argv[2]);
    }
    return 0;
}

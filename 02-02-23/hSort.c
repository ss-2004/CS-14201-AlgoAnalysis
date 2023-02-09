// Analysis of Heap Sort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;

void insertMaxHeap(int arr[], int n) {
    int t, i = n;
    t = arr[n];

    while (i > 1 && t > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = t;
}

int removeMaxHeap(int arr[], int n) {
    int i, j, x, t, val;
    val = arr[1];
    x = arr[n];
    arr[1] = arr[n];
    arr[n] = val;
    i = 1;
    j = i * 2;

    while (j <= n - 1) {
        if (j < n - 1 && arr[j + 1] > arr[j])
            j++;
        if (arr[i] < arr[j]) {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i = j;
            j *= 2;
        } else break;
    }
    return val;
}

void createMaxHeap(int arr[], int n) {
    int i;
    for (i = 2; i < n; i++)
        insertMaxHeap(arr, i);
}

void hSort(int arr[], int n) {
    int i;
    for (i = 2; i < n; i++)
        insertMaxHeap(arr, i);
    for (i = n - 1; i > 1; i--)
        removeMaxHeap(arr, i);
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
    int i;
    for (i = 0; i <= 11; i++) {
        readData(arr, argv[1]);
        begin = clock();
        hSort(arr, size[i] - 1);
        end = clock();
        writeTable(size[i], (end - begin) / 100, argv[2]);
    }
    return 0;
}

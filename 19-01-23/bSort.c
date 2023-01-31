// Analysis of BubbleSort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;
int arr[100000];
int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};

void swp(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void bSort(int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j])
                swp(&arr[j], &arr[j + 1]);
        }
    }
}

void writeTable(int size, double time) {
    int i;
    FILE *fp = fopen("bTable.txt", "a+");

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n");
    else {
        fprintf(fp, "%d %lf", size, time);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void readData() {
    FILE *fp = fopen("data.txt", "r+");
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
    readData();
    for (int i = 0; i <= 11; i++) {
        begin = clock();
        bSort(size[i]);
        end = clock();
        writeTable(size[i], (end - begin) / 3500);
        readData();
    }
    return 0;
}

// Analysis of Selection Sort over 100K entries

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

void sSort(int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swp(&arr[min], &arr[i]);
    }
}

void writeTable(char* filename, int size, double time) {
    int i;
    FILE *fp = fopen(filename, "a+");

    if (fp == NULL) printf("FILE CANNOT BE OPENED\n");
    else {
        fprintf(fp, "%d %lf", size, time);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void readData(char* filename) {
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

int main(int argc, char** argv) {
    for (int i = 0; i <= 11; i++) {
		readData(argv[1]);
        begin = clock();
        sSort(size[i]);
        end = clock();
        writeTable(argv[2], size[i], (end - begin) / 2000.0);
    }
    return 0;
}

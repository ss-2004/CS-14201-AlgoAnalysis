// Analysis of BubbleSort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;
int arr[100000];
int size[] = {1000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 65000, 80000, 90000, 100000};

void writeRand()
{
    int i, toWrite=0;
	int size = 100000;
   	FILE *fp =  fopen("best.txt", "w+");
    if(fp == NULL) printf("FILE CANNOT BE OPENED\n");
   	else
	{
    	fprintf(fp, "%d", size);
        fprintf(fp, "\n");
        for(i=1; i<=100000; i++)
        {
            toWrite = arr[i];
            fprintf(fp, "%d", toWrite);
            fprintf(fp, "\n");
        }
    }
	fclose(fp);
}

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
        bSort(size[i]);
        end = clock();
        writeTable(argv[2], size[i], (end - begin) / 3500.0);
    }
    return 0;
}

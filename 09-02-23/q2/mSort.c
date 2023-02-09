// Analysis of Merge Sort over 100K entries

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
clock_t end;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int A[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=l;
    int B[100000];
    while(i<=mid && j<=r)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=r;j++)
        B[k++]=A[j];
    for(i=l;i<=r;i++)
        A[i]=B[i];
}

void mSort(int A[],int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        mSort(A,l,mid);
        mSort(A,mid+1,r);
        merge(A,l,mid,r);
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
        mSort(arr, 0, size[i]);
        end = clock();
        writeTable(size[i], (end - begin) / 2000, argv[2]);
    }
    return 0;
}

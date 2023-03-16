// Analysis of BinSort over 100K entries

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;

clock_t st;
clock_t en;

template<class T>
void Print(T &vec, int n, string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Max(int A[], int n) {
    int max = -32768;
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

class Node {
public:
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx) {
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr) {
        ptrBins[idx] = temp;
    } else {
        Node *p = ptrBins[idx];
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx) {
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void binSort(int A[], int n) {
    int max = Max(A, n);
    Node **bins = new Node *[max + 1];

    for (int i = 0; i < max + 1; i++) {
        bins[i] = nullptr;
    }

    for (int i = 0; i < n; i++) {
        Insert(bins, A[i]);
    }

    int i = 0;
    int j = 0;
    while (i < max + 1) {
        while (bins[i] != nullptr) {
            A[j++] = Delete(bins, i);
        }
        i++;
    }
    delete[] bins;
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
        st = clock();
        binSort(arr, size[i]);
        en = clock();
        writeTable(size[i], (en - st), argv[2]);
    }
    return 0;
}

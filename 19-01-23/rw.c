#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void writeRand(int size)
{
	int i, toWrite=0;
	
	FILE *fp =  fopen("test.txt", "w+");
	if(fp == NULL) printf("FILE CANNOT BE OPENED\n");
	else
	{
		fprintf(fp, "%d", size);
		fprintf(fp, "\n");
		for(i=1; i<=size; i++)
		{
			toWrite = rand() % size + 1;
			fprintf(fp, "%d", toWrite);
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}

void readRand()
{
	FILE *fp =  fopen("test.txt", "r+");
	char x[16];

	if(fp == NULL) printf("FILE CANNOT BE OPENED\n");
	else
	{
		while( fgets(x,16,fp) != NULL )
		{
			int num=0;
			fscanf(fp, "%d", &num);
			if(num == 0) break;
			printf("%d\n", num);
			//fscanf(fp, "\n");
		}
	}
	fclose(fp);
}

int main()
{
	writeRand(10);
	readRand();
	return 0;
}

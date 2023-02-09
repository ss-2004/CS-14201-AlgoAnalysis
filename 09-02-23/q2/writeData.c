//Generate and write random set of numbers to file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void writeRand(int size)
{
	int i, toWrite=0;
	
	FILE *fp =  fopen("data.txt", "w+");
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

int main()
{
	writeRand(100000);
	return 0;
}

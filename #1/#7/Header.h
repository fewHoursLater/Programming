#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <math.h>
#include <limits.h>

#pragma warning(disable:4996)

struct Student 
{
	char Name[256];
	int Group;
	float Rating;
	int IsElder;

};

float MedRank(struct Student*, int, int);
int FFF(char*,int);


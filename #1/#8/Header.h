#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>

#pragma warning(disable:4996)

typedef struct
{
	int x;
	int y;

}Vertex;

typedef struct Node
{
	Vertex firstVertex;
	Vertex secondVertex;
	Vertex thirdVertex;

	struct Node* next;

}List;

List* ListCreator(int, int, int, int, int, int);

List* Remover(List*);

int AddElement(List* head, int, int, int, int, int, int);

int isThisTriangle(int, int, int, int, int,int);

int IsIntersection(int, int, int, int, int, int, int, int);

int ZeroDeterminant(int, int, int, int, int, int, int, int);

int global(int, int, int, int, int, int, int, int, int, int, int, int);

int last_chanse_to_have_intersection(int, int, int, int, int, int, int, int, int, int, int, int);



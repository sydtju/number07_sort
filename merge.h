#ifndef MERGE_H
#define MERGE_H

#include"public.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int MergeSort(element *dat,int n);
int Merge(element *dat,element *temp,int low,int high,int size);
#endif

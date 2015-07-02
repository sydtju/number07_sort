#include"bubble.h"
#include"public.h"
#include<stdlib.h>
#include<stdio.h>

/*冒泡排序屌丝版*/
int bubble_sort(element *data,int length){
	int i;
	for(i=0;i<length;i++){
		int j;
		for(j=i+1;j<length;j++){
			if ((*(data+i)).number>(*(data+j)).number){
				swap((data+i),(data+j));
			}
		}		
	}
	return 0;
}
/*冒泡排序正版*/
int bubble_sort_upgrade(element *data,int length){
	int i;
	int flag=1;
	for(i=0;i<length&&flag;i++){
		int j;
		for(j=length-1;j>i;j--){
			flag=0;//如果没有发生移动说明 已经排序完全 不需要比较了
			if ((*(data+j)).number<(*(data+j-1)).number){
				swap((data+i),(data+j-1));
				flag=1;//当发生移动说明 还没有排序完全
			}
		}		
	}
	return 0;
}
/*冒泡排序*/
/*相邻元素两两比较*/

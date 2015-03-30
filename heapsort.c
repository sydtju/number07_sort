#include<stdlib.h>
#include<stdio.h>
#include"heapsort1.h"

void swap2(int dat[],int a,int b){
	int temp=dat[a];
	dat[a]=dat[b];
	dat[b]=temp;
}
void adjustheap1(int *dat,int root_temp,int length){
	int i=0;
	for(i=2*root_temp;i<=length;i*=2){//这里必须循环 保证子树都满足大根堆的性质
			int max=0;
		if(i<length){//这里是保证i+1是有效的
			//找出左右孩子中的最大值
			if(dat[i]>dat[i+1]){
				max=i;
			}
			else
				max=i+1;
			//将最大值与父节点进行比较
			if(dat[i/2]<dat[max]){
				swap2(dat,i/2,max);
				i=max;
			}
			else{
				break;//如果本节点是不需要调整的 那么久可以退出  因为前面的也是符合大根堆的
			}
		}
		else{
			break;
		}
	}
}
void heapsort1(int *dat,int length){
	int i=0,j=0;
	for(i=length/2;i>0;i--){//初始化大根堆
		adjustheap1(dat,i,length);
	}
	for(i=length;i>1;i--){
		swap2(dat,1,i);
		adjustheap1(dat,1,i-1);
	}
}

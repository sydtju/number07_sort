#include"SelectSort.h"
/**/
int SelectSort(element *data,int n){
	int i,j;
//	element temp;
	int tempCn;
	if (n<0){
		fprintf(stdout,"the number n is error!\n");
		return 1;
	}
	for(i=0;i<n-1;i++){
		tempCn=i;
		for(j=i+1;j<n;j++){//每次选出最小的 而只进行一次移动  冒泡是进行多次移动
			if((*(data+j)).number<(*(data+tempCn)).number){
				tempCn=j;
			}
		}
		swap((data+i),(data+tempCn));//移动操作只进行一次
	}
	return 0;
}
/*选择排序*/
/*这种排序方式相对于冒泡排序具有更小的移动次数，所以比冒泡排序有更好的时间复杂度*/

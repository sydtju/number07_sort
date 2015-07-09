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

//20150709  第二种写法为经典写法
	void selectSort(vector<int> &dat){
		int length=dat.size();
		int max=INT_MIN,position=0;
		if (0==length||1==length)	return;
		for (int i=length-1;i>=0;i--)
		{
			for (int j=0;j<i+1;j++)
			{
				if (dat[j]>max){max=dat[j];position=j;}
			}
			swap(dat[position],dat[i]);
			max=INT_MIN;
			position=0;
		}
	}
	void SelectSort_update(vector<int>&dat){
		unsigned int length=dat.size();
		unsigned int pos=0;
		for(unsigned int i=0;i<length;++i){
			pos=i;
			for (unsigned int j=i;j<length;++j)
			{
				if(dat[j]<dat[pos])pos=j;
			}
			if(i!=pos) swap(dat[i],dat[pos]);
		}
	}

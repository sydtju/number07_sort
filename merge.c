#include"merge.h"
int Merge(element *dat,element *temp,int low,int high,int size){
	//int //
		int mid=low+size;
		int t=mid;
		int k=low;
		int s=low;
		if(low>=0&&size>=0&&low+size<=high){
			while(low<t&&mid<high){
				if (dat[low].number>dat[mid].number){
					temp[k]=dat[mid];
					mid++;
					k++;
				}
				else{
					temp[k]=dat[low];
					low++;
					k++;
				}
			}
			while(low==t&&mid<high){
				temp[k]=dat[mid];
				mid++;
				k++;
			}
			while(mid==high&&low<t){
				temp[k]=dat[low];
				low++;
				k++;
			}
			for(;s<k;s++){
				dat[s]=temp[s];
			}
		}
		else{
			//exit(EXIT_FAILURE);
			fprintf(stdout,"parameter is error!\n");  
			return 1;
		}
		return 0;
}
int MergeSort(element *dat,int n){
	int i,j,k;
	element *datp=(element *)malloc(n*sizeof(element));
	if(datp==NULL){
		exit(EXIT_FAILURE);
	}
	for(i=1;i<n;i*=2){
		for(j=0;j<n-2*i;j=j+2*i){
			 Merge(dat,datp,j,j+2*i,i);
		}
		if (j+i-1<n){
			Merge(dat,datp,j,n,i);
		}
	}
	return 0;
}
//20150721 改进版  可以继续改进  从低到高的顺序
void merge(vector<int> &dat,int start1,int end1,int start2,int end2){
	vector<int> temp;
	//int length=(int)dat.size()>end?end:(int)dat.size();
	end1=end1>(int)dat.size()?dat.size():end1;
	end2=end2>(int)dat.size()?dat.size():end2;
	int start=start1>start2?start2:start1;
	while (start1<end1&&start2<end2)
	{
		if (dat[start1]>dat[start2])
			temp.push_back(dat[start2++]);
		else
			temp.push_back(dat[start1++]);
	}
	if (start1==end1) 
		while(start2<end2) 
			temp.push_back(dat[start2++]);
	if (start2==end2) 
		while(start1<end1) 
			temp.push_back(dat[start1++]);
	int length=temp.size();
	for (int i=0;i<length;++i) 
		dat[i+start]=temp[i];
}
void mergesort(vector<int> &dat){
	int length=1;
	int maxlength=(int)dat.size();
	while (length<maxlength)
	{
		for (int i=0;i<maxlength;i=i+2*length)
		{
			merge(dat,i,i+length,i+length,i+2*length);
		}
		length=2*length;
	}
} 

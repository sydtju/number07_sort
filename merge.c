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

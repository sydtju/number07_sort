int shellSort(int dat[],int length){
	int i=0;
	int j=0;
	int gap=0;
	if(NULL==dat||0==length) return 0;//边界判断
	for(gap=length/2;gap>0;gap=gap/2){
		for(i=gap;i<length;i++){
			//插排操作
			int temp=dat[i];
			for(j=i;j>=gap;j=j-gap){
				if (temp<dat[j-gap]){
					dat[j]=dat[j-gap];
				}
				else{
					break;
				}
			}
			dat[j]=temp;
			//
		}
	}
	return 0;
}
//20150721
void shellsort(vector<int> &dat){
	int length=(int)dat.size();
	if(length==0||length==1) return ;
	for(int gap=length/2;gap>0;gap=gap/2)
		for (int i=gap;i<length;++i)
		{//这里用的是插入排序  插入的方式  是循环链的那种 
			int temp=dat[i];
			while (i>=gap&&temp<dat[i-gap])
			{
				dat[i]=dat[i-gap];
				i=i-gap;
			}
			dat[i]=temp;
		}
}
void shellsort1(vector<int> &dat){
	int length=(int)dat.size();
	if(length==0||length==1) return ;
	for(int gap=length/2;gap>0;gap=gap/2)
		for (int i=gap;i<length;++i)
			for(int j=i;j>=gap&&dat[j]<dat[j-gap];j=j-gap)
				swap(dat[j],dat[j-gap]);////这里用的是插入排序  插入的方式  是冒泡的那种 其实复杂程度比上面高 但是代码简单 
}

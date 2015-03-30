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

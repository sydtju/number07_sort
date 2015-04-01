void insertsort(int dat[],int length){
	int i=0;
	int j=0;
	int temp=0;
	for(i=1;i<length;i++){
		temp=dat[i];
		for(j=i;j>0;j--){
			if(dat[j-1]>temp) dat[j]=dat[j-1];
			else{
				break;
			}
		}	
		dat[j]=temp;
	}
}

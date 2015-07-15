//快速排序算法  
int partition_sort(vector<int> &dat,int start,int end){//
	int std=dat[start];
	int left=start;
	int right=end;
	while (start<end)
	{
		while (start<end&&dat[end]>std)--end;//这里应该是>号
		dat[start]=dat[end];
		while (start<end&&dat[start]<=std)++start;
		dat[end]=dat[start];
	}
	dat[start]=std;//注意：标准就赋值给 上一个赋值给其它位置的元素  因为这个元素没有丢失 
	return start;
}
void qSort(vector<int> &dat,int start,int end){
	int p;
	if (start<end)
	{
		p=partition_sort(dat,start,end);
		qSort(dat,start,p-1);
		qSort(dat,p+1,end);
	}
	else return ;
}

//#include <cstdilb>
#include <iostream>
#include <vector>
using namespace std;
//排序以0为开始 
void Adjust_heap(vector<int> &dat,int node,int length){
	int child=0;
	//条件2*i+1的目的是确保该节点拥有子节点  2i+1是它的左子节点（因为偏移了一个单位）  这里的length是数组的长度  
	for(int i=node;2*i+1<length;i=child){     //被交换的子节点 还要进行调整 因为被调换了 所以不确定他是否满足大根堆的条件         
		child=2*i+1;
	//前面已经判断了 该节点拥有子节点  这里前面条件判断是 这个节点是否拥有右子节点  如果有那就找出 两个子节点中最大的 如果没有 那左子节点就是最大的
		if (child+1<length&&dat[child+1]>dat[child]) ++child;  
		if(dat[i]<dat[child]) swap(dat[i],dat[child]);
		else 
			break;
	}
}
void heapsort(vector<int> &dat){
	int length=dat.size();
	//制作大根堆 小根堆   确保任何一个有子节点的节点都满足条件 length/2-1是最后一个非叶子节点
	for(int i=length/2-1;i>=0;--i){
		Adjust_heap(dat,i,length);
	}
	//将最大的数与后面的数交换
	for (int i=length-1;i>=0;--i)
	{
		swap(dat[0],dat[i]);
		Adjust_heap(dat,0,i);
	}
}
void show(vector<int> dat){
	for(int i=0;i<dat.size();++i){
		cout<<" "<<dat[i];
	}
	cout<<endl;
}
int main(){
	int dat[]={2,2,3,6,7,8,9,1,0};
	vector<int> data(dat,dat+sizeof(dat)/sizeof(int));
	heapsort(data);
	show(data);
	system("pause");
	return 0;
}

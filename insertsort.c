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
//2015 0703 重新编写测试通过
#include <iostream>
#include <vector>
using namespace std;
class sort{
private:
	static int counter;
public:
	//经典插入排序代码  插入排序是稳定排序  时间复杂度平均是n^2 最差是n^2 最好是O(n) 空间复杂度是O(1) 
	void insert_sort(vector<int> &data){
		int length=data.size();
		int j=0,temp=0;
		for (int i=1;i<length;++i){
			j=i;
			temp=data[i];
			while (j>0&&data[j-1]>temp){	//j>0在前
				data[j]=data[j-1];
				j--;
			}
			data[j]=temp;
		}
	}
	void show_vector(vector<int>&data){
		vector<int>::iterator it=data.begin();
		cout<<"第"<<counter++<<"次打印结果如下："<<endl;
		for (;it!=data.end();++it)
		{
			cout<<*it<<"  ";
		}
		cout<<endl;
	}
};
int sort::counter=0;
int main(int argc,char *argv[]){
	int dat[10]={0,2,3,6,4,5,9,8,7,1};
	vector<int> data(dat,dat+sizeof(dat)/sizeof(int));
	sort s;
	s.show_vector(data);
	s.insert_sort(data);
	s.show_vector(data);
	system("pause");
	return 0;
}

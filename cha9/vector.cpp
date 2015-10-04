#include <iostream>
#include <vector>
using namespace std;


void printcontainer(vector<int> v)
{
	for(auto it=v.begin();it!=v.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	vector<int> v;
	vector<int> s{-1,-2,-3};
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(v.begin()+3,0);//在迭代器指向元素前插入
	printcontainer(v);
	v.insert(v.begin()+4,2,-99);//插入2个-99
	printcontainer(v);
	v.insert(v.begin(),s.begin(),s.end());//把迭代器s范围内元素插入到v迭代器之前
	printcontainer(v);
	v.insert(v.begin(),{99,98});//可以直接把列表插入
	printcontainer(v);

	v.emplace(v.begin(),1);//emplace,emplace_front,emplace_back直接调用v元素类型的构造函数

	printcontainer(v);
	v.pop_back();
	v.erase(v.begin());
	v.erase(v.begin(),v.end()-1);
	printcontainer(v);
	// cout<<v.front()<<endl;
	// cout<<v.back()<<endl;
	

	// cout<<v.at(2)<<endl;

	return 0;
}
#include <iostream>
#include <forward_list>
using namespace std;


void printcontainer(forward_list<int> l)
{
	for(auto it=l.begin();it!=l.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	forward_list<int> l;

	l.insert_after(l.before_begin(),{1,2,3,4,5,6});
	printcontainer(l);
	l.erase_after(l.before_begin(),l.end());
	printcontainer(l);
	return 0;
}
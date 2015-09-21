#include "shiyanlou.h"

using namespace std;




int main(int argc, char const *argv[])
{
	int command=0;
	int sum=0;//课程总数
	string name[]={"Linux","C++","HTML","HTML5","NodeJS","Shell","Python"};
	
	
	vector<Course> v;//存放课程

	for (int i = 0; i < sizeof(name)/sizeof(string); ++i)//初始化课程列表
	{
		Course temp;
		temp.ID=i;
		temp.name=name[i];
		v.push_back(temp);
		sum++;
	}
	cin>>command;
	while(command!=5)//主循环
	{	

		switch(command)
		{
			case 0:
				printHelp();
				break;
			case 1:
				printCourse(v);
				break;
			case 2:
				printCourseNum(sum);
				break;
			case 3:
				printLangestCourseName(v);
				break;
			case 4:
				deleteLastCourse(v,sum);
				break;
			default :
				cout<<"Bad command\n"<<endl;
				printHelp();
				break;
		}
		cin.clear();
		cin.sync();
		cin>>command;
	}
	return 0;
}

void printHelp()
{
	cout<<"------------HELP-----------"<<endl;
	cout<<"1:打印程序中存储的所有课程ID和课程名\n"
	        <<"2:打印课程数量\n"
		    <<"3:打印出名字最长的课程信息\n"
			<<"4:删除最后一个课程\n"
			<<"5:退出程序"<<endl;
}

void printCourse(vector<Course> v)
{
	cout<<"ID"<<"\t"<<"Name"<<endl;
	cout<<"----------------"<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i].ID<<"\t"<<v[i].name<<endl;
};
void printCourseNum(int sum)
{
	cout<<"We have "<<sum<<" courses"<<endl;
};
void printLangestCourseName(vector<Course> v)
{
	int i;
	vector<int> length;
	for(i=0;i<v.size();i++)
		length.push_back((v[i].name).size());

	mysort(length,length.size());
	cout<<"Longest name: "<<length[0]<<endl;

};
void deleteLastCourse(vector<Course> &v,int &sum)
{
	if(v.size()!=0)
	{
		cout<<"Course:"<<v[v.size()-1].name<<" deleted"<<endl;
		v.pop_back();
		sum--;
	}
	else
		cout<<"Error : No course can be deleted"<<endl;
}
void mysort(vector<int> &a,int n)
{

	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}
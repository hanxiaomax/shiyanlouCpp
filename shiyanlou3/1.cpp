#include <iostream>
#include "2.h"

using namespace std;

int main()
{
	typedef shared_ptr<Course> ptr;//定义类型名

	//定义智能指针
	ptr p1=make_shared<Course>("python");
	ptr p2=make_shared<Course>("Linux");
	ptr p3=make_shared<Course>("GIT");
	ptr p4=make_shared<Course>("MySQL");

	
	vector<Course> v;
	
	v.push_back(*p1);//要调用拷贝构造函数
	v.push_back(*p2);
	v.push_back(*p3);

	CourseManager cm(v);
	cm.addCourse("C/C++");
	cm.addCourse(*p4);
	


	//cout<<cm.getCourseNum()<<endl;
	//cm.printCourseList();
	//cm.printCourse(0);
	//cm.printCourse("GIT");

	CmdManager cmdm(cm);
	//cmdm.printHelp();

	while(1)
	{
		string cmd;
		getline(cin,cmd);
		if(cmd=="exit")
			break;
		cmdm.Cmdparser(cmd);
		
	}
	

	system("pause");
}


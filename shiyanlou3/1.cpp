#include <iostream>
#include "2.h"

using namespace std;

int main()
{
	Course c_python("python"),c_linux("Linux"),c_git("GIT"),c_MySQL("MySQL");
	
	vector<Course> v;
	
	v.push_back(c_python);//要调用拷贝构造函数
	v.push_back(c_linux);
	v.push_back(c_git);

	CourseManager cm(v);
	cm.addCourse("C/C++");
	cm.addCourse(c_MySQL);
	


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


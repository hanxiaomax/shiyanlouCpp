#include "2.h"


Course::Course(string CourseName):CourseName(CourseName)
{
	CourseID=setID();
}

Course::Course(const Course& c)
{
	CourseID=c.CourseID;
	CourseName=c.CourseName;
}

void Course::printInfo()
{
	cout<<"ID: "<<CourseID<<"\t";
	cout<<"Name: "<<CourseName<<"\t";
	cout<<"Course Info: "<<info<<"\t"<<endl;
}

CourseManager::CourseManager(Course course[])
{
	for (int i = 0; i < sizeof(course)/sizeof(Course); ++i)
	{
		CourseList.push_back(course[i]);
	}
}

CourseManager::CourseManager(vector<Course> v)
{
	CourseList=v;	
	for(auto it=CourseList.begin();it!=CourseList.end();it++)
	{
		cout<<(*it).getName()<<endl;
	}
	
}

void CourseManager::addCourse(string name)
{
	Course c(name);//非拷贝初始化
	CourseList.push_back(c);
}
void CourseManager::addCourse(Course course)
{
	CourseList.push_back(course);
}

void CourseManager::deleteCourse(int id)
{
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
 		if((*it).getID()==id)
		{
			CourseList.erase(it);
			break;
		}
	}
}
void CourseManager::deleteCourse(string name)
{
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
 		if((*it).getName()==name)
		{
			CourseList.erase(it);
			break;
		}
	}
}

void  CourseManager::printCourse(int id)
{
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
		if((*it).getID()==id)
		{
			(*it).printInfo();
			break;
		}
	}
}
void  CourseManager::printCourse(string name)
{
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
		if((*it).getName()==name)
		{
			(*it).printInfo();
			break;
		}
	}
}


void CourseManager::printCourseList()
{
	cout<<"=========Course List============"<<endl;
	for (int i = 0; i < CourseList.size(); ++i)
	{
		CourseList[i].printInfo();
	}
	cout<<"================================"<<endl;
}


void CmdManager::printHelp()
{
	cout<<"==============Help=============="<<endl;
	for(auto it=cmdList.begin();it!=cmdList.end();it++)
	{
		cout<<"CMD: "<<(*it).cmd<<"\t"<<"Usage: "<<(*it).help<<endl;
	}
	cout<<"================================"<<endl;
}

CmdManager::CmdManager(CourseManager &cm):cm(cm)
{
	CMD cmd1={1,"add","add <course name>"},
		cmd2={2,"delete","delete <course id/name>"},
		cmd3={3,"help","print help"};

	cmdList.push_back(cmd1);
	cmdList.push_back(cmd2);
	cmdList.push_back(cmd3);
}


int CmdManager::getid(string cmd_name)
{
	for(auto it=cmdList.begin();it!=cmdList.end();it++)
	{
		if((*it).cmd==cmd_name)
			return (*it).id;
	}
	return -1;
}

void CmdManager::Cmdparser(string cmdstring)
{
	string cmd_name="";
	string temp="";
	vector<string> param_list;
	int i=0;

	while(i!=cmdstring.size()&&cmdstring[i]!=' ')
	{
		cmd_name+=cmdstring[i];
		i++;
	}


	for(i=i+1;i<=cmdstring.size();i++)
	{
		if(i<cmdstring.size()&&cmdstring[i]!=' ')
		{
			temp+=cmdstring[i];
		}
		else
		{
			param_list.push_back(temp);
			temp="";
		}

	}
	
	/*cout<<cmd_name<<" "<<endl;

	for(auto it=param_list.begin();it!=param_list.end();it++)
		cout<<(*it)<<endl;*/

	if(isValid(cmd_name,param_list))
	{
		switch(getid(cmd_name))
		{
		case 1://添加课程
			cm.addCourse(param_list[0]);
			break;
		case 2:
			break;
		case 3:
			printHelp();
			break;
		case 4:
			break;
		case 5:
			break;

		}
	}

	else
	{
		cout<<"unkonwn cmd"<<endl;
		printHelp();
		return ;
	}
}
bool CmdManager::isValid(string cmd,vector<string> param_list)
{
	int param_num[10]={-1,1,1,0};
	for(auto it=cmdList.begin();it!=cmdList.end();it++)
	{
		if((*it).cmd==cmd)
		{
			if(param_num[(*it).id]==param_list.size())
				return true;
			else
				return false;
		}
			
	}
	return false;
}
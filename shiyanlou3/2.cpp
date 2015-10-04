#include "2.h"


typedef shared_ptr<CMD> CMD_ptr;

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
	/*for(auto it=CourseList.begin();it!=CourseList.end();it++)
	{
		cout<<(*it).getName()<<endl;
	}*/
	
}

void CourseManager::addCourse(string name)
{
	Course c(name);//非拷贝初始化
	CourseList.push_back(c);
	cout<<"[succeed]"<<endl;
}
void CourseManager::addCourse(Course course)
{
	CourseList.push_back(course);
	cout<<"[succeed]"<<endl;
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
	cout<<"[succeed]"<<endl;
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
	cout<<"[succeed]"<<endl;
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
void  CourseManager::printCourse(Course c)
{
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
		if((*it).getID()==(*it).getID())//此处比较id，因为id是唯一的。也可以重载==来比较两个对象
		{
			(*it).printInfo();
			break;
		}
	}
}


void CourseManager::printCourseList()
{
	cout<<"============Course List==============="<<endl;
	for (int i = 0; i < CourseList.size(); ++i)
	{
		CourseList[i].printInfo();
	}
	cout<<"======================================"<<endl;
}

void CourseManager::printCourseList(vector<Course> v)
{
	cout<<"============Course List==============="<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		v[i].printInfo();
	}
	cout<<"======================================"<<endl;
}


void CmdManager::printHelp()
{
	cout<<"=================Help================="<<endl;
	for(auto it=cmdList.begin();it!=cmdList.end();it++)
	{
		cout<<"CMD: "<<(*it).cmd<<"\t"<<"Usage: "<<(*it).help<<endl;
	}
	cout<<"======================================"<<endl;
}

CmdManager::CmdManager(CourseManager &cm):cm(cm)
{
	CMD_ptr cmd1_p=make_shared<CMD>(1,"add","add <course name>"),
		cmd2_p=make_shared<CMD>(2,"delete","delete <course id/name>"),
		cmd3_p=make_shared<CMD>(3,"help","print help"),
		cmd4_p=make_shared<CMD>(4,"course","print course information"),
		cmd5_p=make_shared<CMD>(5,"log","print log"),
		cmd6_p=make_shared<CMD>(6,"courses","print course list"),
		cmd7_p=make_shared<CMD>(7,"sort","sort <up/down>"),
		cmd8_p=make_shared<CMD>(8,"find","find <name>");

		
	//cmdList.insert(cmdList.begin(),{cmd1,cmd2,cmd3,cmd4,cmd5,cmd6,cmd7,cmd8}); vs2010不支持
	cmdList.push_back(*cmd1_p);
	cmdList.push_back(*cmd2_p);
	cmdList.push_back(*cmd3_p);
	cmdList.push_back(*cmd4_p);
	cmdList.push_back(*cmd5_p);
	cmdList.push_back(*cmd6_p);
	cmdList.push_back(*cmd7_p);
	cmdList.push_back(*cmd8_p);

}
//升序
bool cmpincrease (const Course a, const Course b)
{
	return a.CourseName < b.CourseName;
}
//降序
bool cmpdecrease (const Course a, const Course b)
{
	return a.CourseName > b.CourseName;
}

//课程排序
vector<Course> CourseManager::Listsort(bool reverse)
{
	vector<Course> temp=CourseList;
	if(reverse)
		sort(temp.begin(),temp.end(), cmpdecrease);
	else
		sort(temp.begin(),temp.end(), cmpincrease);
	
	
	return temp;
}
bool CourseManager::findCourse(string courseName,Course &c)
{
	
	for (auto it=CourseList.begin(); it!=CourseList.end(); ++it)
	{	
		auto temp=((*it).getName()).find(courseName);
		if(temp!=string::npos)
		{
			c=*it;
			return true;
		}	
	}
	return false;
	
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

	//获取命令
	while(i!=cmdstring.size()&&cmdstring[i]!=' ')
	{
		cmd_name+=cmdstring[i];
		i++;
	}

	//获取参数
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
		
		if(cmd_name!="log")
			cmdlog.push_back(cmd_name);

		switch(getid(cmd_name))
		{
		case 1://添加课程
			cm.addCourse(param_list[0]);
			break;
		case 2:
			if(param_list.size()==1)
			{
				cm.deleteCourse(param_list[0]);//不能按id删除
			}
			else
			{
				cm.deleteLastCourse();
			}
			break;
		case 3:
			printHelp();
			break;
		case 4:
			cm.printCourse(param_list[0]);
			break;
		case 5:
			printLog();
			break;
		case 6:
			cm.printCourseList();
			break;
		case 7://排序，提供升序和降序两种方式
			{
				vector<Course> v;
				if(param_list[0]=="down")
					v=cm.Listsort(true);
				else
					v=cm.Listsort();
				cm.printCourseList(v);
				break;
			}
		case 8://查找
			{
				Course temp;
				if(cm.findCourse(param_list[0],temp))
					temp.printInfo() ;
				else
					cout<<"\""<<param_list[0]<<"\" Not Found"<<endl;
			}
			break;
		}
		return ;
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
	int param_num[20]={-1,1,1,0,1,0,0,1,1,1};
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


void  CmdManager::printLog()
{
	for(auto it= cmdlog.begin();it!= cmdlog.end();it++)
		cout<<(*it)<<endl;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static int id=0;
typedef struct
{
	int id;
	string cmd;
	string help;
		
}CMD;

class Course
{
public:
	Course(){};
	Course(string CourseName);//构造函数
	Course(iostream &is){};//
	Course(const Course&);//拷贝构造函数

	int setID(){return CourseID=id++;}
	int getID(){return CourseID;}

	void setName(string CourseName){CourseName=CourseName;}
	string getName(){return CourseName;}

	void printInfo();//打印课程信息
	~Course(){};
private:
	int CourseID;
	string CourseName;
	string info;
};




class CourseManager
{
public:
	CourseManager(){};
	CourseManager(Course course[]);//使用数组初始化
	CourseManager(vector<Course> CourseList);//使用vector初始化
	CourseManager(const CourseManager&){};//拷贝构造函数
	~CourseManager(){};

	int getCourseNum(){return CourseList.size();}//获取课程数量

	void addCourse(string name);//添加课程
	void addCourse(Course course);//添加课程

	void deleteLastCourse(){CourseList.pop_back();}//删除最新添加的课程


	void deleteCourse(int id);//删除课程
	void deleteCourse(string name);//删除课程

	void printCourseList();

	void printCourse(int id);//打印课程信息
	void printCourse(string name);//打印课程信息

	void write2file(){};
private:
	vector<Course> CourseList;	

};

class CmdManager
{
 public:
	 CmdManager(CourseManager &cm);
	 ~CmdManager(){};
 public:
 	void printHelp();//打印命令行帮助
 	void Cmdparser(string cmdstring);//解析命令
 	bool isValid(string cmd,vector<string> param_list);//判断命令是否合法
 	void printLog();

 private:
 	void add2log(string cmd,string result);
	int getid(string cmd);
 private:
	 vector<CMD> cmdList;
	 CourseManager &cm;
	 
};
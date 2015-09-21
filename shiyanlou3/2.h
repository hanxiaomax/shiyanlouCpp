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
	Course(string CourseName);//���캯��
	Course(iostream &is){};//
	Course(const Course&);//�������캯��

	int setID(){return CourseID=id++;}
	int getID(){return CourseID;}

	void setName(string CourseName){CourseName=CourseName;}
	string getName(){return CourseName;}

	void printInfo();//��ӡ�γ���Ϣ
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
	CourseManager(Course course[]);//ʹ�������ʼ��
	CourseManager(vector<Course> CourseList);//ʹ��vector��ʼ��
	CourseManager(const CourseManager&){};//�������캯��
	~CourseManager(){};

	int getCourseNum(){return CourseList.size();}//��ȡ�γ�����

	void addCourse(string name);//��ӿγ�
	void addCourse(Course course);//��ӿγ�

	void deleteLastCourse(){CourseList.pop_back();}//ɾ��������ӵĿγ�


	void deleteCourse(int id);//ɾ���γ�
	void deleteCourse(string name);//ɾ���γ�

	void printCourseList();

	void printCourse(int id);//��ӡ�γ���Ϣ
	void printCourse(string name);//��ӡ�γ���Ϣ

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
 	void printHelp();//��ӡ�����а���
 	void Cmdparser(string cmdstring);//��������
 	bool isValid(string cmd,vector<string> param_list);//�ж������Ƿ�Ϸ�
 	void printLog();

 private:
 	void add2log(string cmd,string result);
	int getid(string cmd);
 private:
	 vector<CMD> cmdList;
	 CourseManager &cm;
	 
};
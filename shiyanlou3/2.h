#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

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
	friend bool cmpincrease (const Course a, const Course b);//��������Ƚ�
	friend bool cmpdecrease (const Course a, const Course b);//���ڽ���Ƚ�
public:
	Course(){};
	Course(string CourseName);//���캯��
	Course(iostream &is){};//
	Course(const Course&);//�������캯��

	int setID(){return CourseID=id++;}
	int getID(){return CourseID;}

	void setName(string CourseName){CourseName=CourseName;}//���ÿγ���
	string getName(){return CourseName;}//��ȡ�γ���

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
	void printCourseList(vector<Course> v);

	void printCourse(int id);//��ӡ�γ���Ϣ
	void printCourse(string name);//��ӡ�γ���Ϣ
	void printCourse(Course c);

	void write2file(){};
	vector<Course> Listsort(bool reverse=false);//�γ����򲢴�ӡ��������ԭ�б�������

	bool findCourse(string courseName,Course &c);

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
	void printLog();//��ӡ�����¼

 private:
 	void add2log(string cmd,string result);
	int getid(string cmd);
 private:
	 vector<CMD> cmdList;
	 vector<string> cmdlog;
	 CourseManager &cm;
	 
};
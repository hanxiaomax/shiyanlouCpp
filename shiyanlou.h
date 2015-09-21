#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct course
{
	int ID;
	string name;
	
}Course;

void printCourse(vector<Course> v);//打印课程信息
void printCourseNum(int sum);//打印课程数量
void printLangestCourseName(vector<Course> v);//打印最长名字
void deleteLastCourse(vector<Course> &v,int &sum);//删除最后一个课程
void printHelp();//打印帮助
void mysort(vector<int> &a,int n);//排序
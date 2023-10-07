#ifndef __TEACHER_STUDENT_H__
#define __TEACHER_STUDENT_H__

#include "teacher.h"
#include "student.h"

class TeacherStudent : public Teacher, public Student{
	public:
		TeacherStudent(){}
		TeacherStudent(int age, float height, float salary, int no, const char *name);
		void setA(int a);
		void show();
		~TeacherStudent(){cout << "TeacherStudent析构方法" << endl;}
};


#endif

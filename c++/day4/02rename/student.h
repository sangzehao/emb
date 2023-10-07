#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "person.h"

class Student : public Person{
	public:
		Student(const char *name, int age, float score);
		void show();
	
	private:
		float _score;
};

#endif

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "person.h"

class Student : public Person
{
	public:
		Student(int age, const char *name, float core);
		void show();
	private:
		float m_score;
};

#endif

#ifndef __PERSON_H__
#define __PERSON_H__

class Person{
	public:
		Person();
		Person(int age, const char* m_name);
		virtual void show();

	protected:
		int m_age;
		const char *m_name;
};

#endif

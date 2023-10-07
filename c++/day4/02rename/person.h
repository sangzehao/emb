#ifndef __PERSON_H__
#define __PERSON_H__

class Person{
	public:
		Person(const char *name, int age);
		//void show();
		virtual void show();
	protected:
		const char *_name;
		int _age;

};

#endif

#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMESIZE 32

class Person{
	public:
		Person();
		Person(int age, float height = 160, const char *name = "无名");
		~Person();

		void show();
		void setName(const char *name);
		void setAge(int age);
		void setHeight(float height);
	protected:
		int m_age;
	protected:
		float m_height;
		int m_a;
	public:
		char m_name[NAMESIZE];
};

#endif

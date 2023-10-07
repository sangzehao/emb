#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMESIZE 64

class Person{
	public:
		Person();
		void setAge(int len);
		void setHeight(int height);
		void setName(const char *name);
		void show();

	private:
		int m_age;
		int m_height;
		char m_name[NAMESIZE];

};

#endif

#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMESIZE 64

class Person{
	public:
		Person(int r = 0);
		Person(int r, int age, float height = 160, const char *name = "she");
		~Person();//析构方法 

		void setAge(int len);
		void setHeight(int height);
		void setName(const char *name);
		void show();

	private:
		int m_age;
		int m_height;
		char m_name[NAMESIZE];

		//引用成员
		int &m_r;

};

#endif

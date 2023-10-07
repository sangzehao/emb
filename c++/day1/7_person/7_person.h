#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMESIZE 64

class Person{
	//动态行为
	public:
		
		//构造方法
		Person(){}
		Person(int age, float height = 160, const char *name = "他");

		void show();
		//提供公开的赋值方法
		void setName(const char *name);
		void setAge(int age);
		void setHeight(float height);

	//静态属性
	private:
		int m_age;
		int m_height;
		char m_name[NAMESIZE];

};

#endif

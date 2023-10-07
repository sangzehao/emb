#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMESIZE	32

class Person {
		// 动态行为
	public:
		// 构造方法
		Person();
		Person(int age, float height = 160, const char *name = "无名");
		~Person();

		void show();
		// 提供公开的赋值方法
		void setName(const char *name);
		void setAge(int age);
		void setHeight(float height);
	private:
		// 静态属性
		int m_age;
	protected:
		float m_height;
	public:
		char m_name[NAMESIZE];
};

#endif


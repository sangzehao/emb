#ifndef __SHEEP_H__
#define __SHEEP_H__

#include <stdint.h>

class Sheep{
	public:
		Sheep();
		Sheep(const char *name, uint8_t age);
		~Sheep();
		//静态成员函数，里边只能访问静态变量
		static int getCnt();

	private://这样是防止在main里随意修改
		//总羊数
		static int cnt;
	private:
		const char *m_name;
		uint8_t m_age;
};

#endif

#include <iostream>
#include "sheep.h"

using namespace std;

int main(void)
{
	//一次实例化了10个Sheep对象
	Sheep *s = new Sheep[10];

	cout << "共有" << Sheep::getCnt() << "只羊" << endl;

	Sheep *newSheep = new Sheep("毛毛", 1);
	cout << "新买了一只羊" << endl;
	cout << "共有" << Sheep::getCnt() << "只羊" << endl;

	cout << "烤了一只" << endl;
	delete newSheep;

	cout << "共有" << Sheep::getCnt() << "只羊" << endl;

	return 0;


}

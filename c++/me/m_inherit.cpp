#include <iostream>

using namespace std;

//多继承

class Shape{
	public:
		void setWidth(int width);
		void setLength(int length);
		int setArea();
	protected:
		int m_width;
		int m_length;
};

void Shape::setWidth(int width)
{
	m_width = width;
}
void Shape::setLength(int length)
{
	m_length = length;
}
int Shape::setArea()
{
	return m_length * m_width;
}

class Area{
	public:
		void showArea(int area){cout << area << endl;}
};

class Rectangle:public Shape, public Area{

};

int main(void)
{
	Rectangle myR;
	int area;

	myR.setWidth(10);
	myR.setLength(20);

	area = myR.setArea();

	myR.showArea(area);

	return 0;
}

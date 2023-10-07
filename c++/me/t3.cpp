#include <iostream>

//重载运算符

using namespace std;

class Box{
	public:
		void setLen(int len){length = len;}
		void setWid(int wid){width = wid;}
		void setHei(int hei){height = hei;}
		int getVolume(){return length * width * height;}

		//在类内，以成员函数的形式定义
		Box operator+(const Box& b)
		{
			Box box;
			box.length = this->length + b.length;
			box.width = this->width + b.width;
			box.height = this->height + b.height;
	
			cout << "this->length:" << this->length << endl;

			return box;
		}

	public:
		int length;
		int width;
		int height;	

};

//类外，非成员函数，不过要求成员变量为公有
/*
Box operator+(const Box& a, const Box& b)
{
	Box box;
	
	box.length = a.length + b.length;
	box.width = a.width + b.width;
	box.height = a.height + b.height;

	return box;
}
*/

int main(void)
{
	Box box1;
	Box box2;
	Box box3;
	
	int volume;
	int a = 1;
	int b = 2;

	box1.setLen(1);
	box1.setWid(2);
	box1.setHei(3);
	
	volume = box1.getVolume();
	cout << "box1:" << volume << endl;

	box2.setLen(5);
	box2.setWid(5);
	box2.setHei(6);

	volume = box2.getVolume();
	cout << "box2:" << volume << endl;

	box3 = box2 + box1;
	volume = box3.getVolume();
	cout << "box3.length:" << box3.length << endl;
	cout << "box3.width:" << box3.width << endl;
	cout << "box3:" << volume << endl;

	cout << "a + b:" << a + b << endl;

	return 0;
}

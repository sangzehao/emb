#ifndef __TEST_H__
#define __TESH_H__

class A{
	private:
		int a;
		int b;
		int c;
};

class B{
	public:
		void setA(int a){_a = a;}
		void setB(int b){_b = b;}
		void setC(int c){_c = c;}

	private:
		int _a;
		int _b;
		int _c;
};

#endif

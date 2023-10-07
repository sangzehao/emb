#ifndef __ARR_H__
#define __ARR_H__

class Array{
	public:
		Array(){}
		Array(int capacity);
		int inSert(int index, int elm);
		int aDelete(int elem);
		int aUpdate(int oldElm, int newElm);
		int getIndex(int i);
		void show();
		void menu();
		~Array();

	private:
		int m_capacity;
		int *m_array;
		int m_num;
};

#endif

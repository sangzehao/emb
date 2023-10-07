#include "arr.h"
#include <iostream>

using namespace std;

Array::Array(int capacity):m_capacity(capacity)
{
	this->m_array = new int[capacity];
	this->m_num = 0;
}

int Array::inSert(int index, int elm)
{
	int i = this->m_num;
	while(i > index)
	{
		if(i >= m_capacity)
		{
			i--;
			continue;
		}
		else{
			m_array[i + 1] = m_array[i];
			i--;
		}
	}
	m_array[i] = elm;
	m_num++;

	return 0;
}

int Array::aUpdate(int oldElm, int newElm)
{
	int i;
	
	for(i = 0; i < m_num; i++)
	{
		if(oldElm == m_array[i])	
			break;
	}

	if(i >= m_num)
		return 1;
	m_array[i] = newElm;

	return 0;
}

int Array::aDelete(int elem)
{
	int i;

	for(i = 0; i < m_num; i++)
	{
		if(m_array[i] == elem)
			break;
	}

	if(i == m_num)
		return 1;

	while(i < m_num)
	{
		m_array[i] = m_array[i + 1];
		i++;
	}
	m_num--;

	return 0;
}

int Array::getIndex(int i)
{
	if(i < m_num)
	{
		cout << m_array[i] << endl;
		return 0;
	}

	return 1;
}

void Array::show()
{
	int i;

	for(i = 0; i < m_num; i++)
		cout << m_array[i] << " ";
	cout << endl;
}

void Array::menu()
{
	cout << "输入选项序号:" << endl;
	cout << "1.插入"<< endl;
	cout << "2.删除" << endl;
	cout << "3.修改" << endl;
	cout << "4.访问" << endl;
	cout << "5.遍历" << endl;
	cout << "6.结束" << endl;
}

Array::~Array()
{
	delete[] m_array;
	m_array = NULL;
}



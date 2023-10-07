#include <iostream>
#include "arr.h"

using namespace std;

int main(void)
{
	int n;
	int index, value, ret;

	cout << "输入最大容量:" << endl;
	cin >> n;
	
	Array arr(n);

	while(1)
	{

		arr.menu();
		cin >> n;

		switch(n){
			case 1://插入
				cout << "输入下标和值" << endl;
				cin >> index;
				cin >> value;
				ret = arr.inSert(index, value);
				if(ret == 1)
					cout << "失败" << endl;
				break;
			case 2://删除
				cout << "输入删除的元素值" << endl;
				cin >> value;
				ret = arr.aDelete(value);
				if(ret == 1)
					cout << "失败" << endl;
				break;
			case 3://修改
				cout << "输入修改的元素值和新的元素值" << endl;
				cin >> value;
				cin >> index;
				ret = arr.aUpdate(value, index);
				if(ret == 1)
					cout << "失败" << endl;
				break;
			case 4://访问
				cout << "输入访问的下标值" << endl;
				cin >> index;
				ret = arr.getIndex(index);
				if(ret == 1)
					cout << "失败" << endl;
				break;
			case 5://遍历
				arr.show();
				break;
			case 6://结束
				goto END;
		}
	}

END:
	return 0;

}

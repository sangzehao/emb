#include <iostream>

using namespace std;

class Distance{
	public:
		Distance(){
			feet = 0;
			inches = 0;
		}

		Distance(int f, int i){
			feet = f;
			inches = i;
		}

		void show(){
			cout << "feet:" << feet << " inches:" << inches << endl;
		}

	private:
		int feet;
		int inches;
	
	public:
		Distance operator!()//不用传参，就是自己
		{
			this->feet = !this->feet;
			this->inches = !this->inches;

			return Distance(feet, inches);	
		}

		bool operator<(const Distance &b)
		{
			if(inches < b.inches)
				return true;
			else
				return false;
		}

		//输入输出重载
		friend ostream &operator<<(ostream &output, const Distance &D)
		{
			output << "F:" << D.feet << "I:" << D.inches; 
			return output;
		}

		friend istream &operator>>(istream &input, const Distance &D)
		{
			input >> D.feet >> D.inches;

			return input;
		}
};

int main(void)
{
	Distance D1, D2(1, 2), D3;

	!D1;
	D1.show();

	!D2;
	D2.show();

	if(D1 < D2)
		cout << "less" << endl;
	else
		cout << "noless" << endl;

	cout << "Enter the value of object" << endl;
	cin >> D3;
	cout << "D3" << D3 << endl;

	return 0;
}

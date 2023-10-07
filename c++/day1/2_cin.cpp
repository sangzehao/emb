#include <iostream>

using namespace std;

int main(void)
{
	int n;
	float f;
	int a[5];
	char s[5];
	int i;

	cout << "cout:";
	cin >> n;

	cout << "cout:";
	cin >> f;

	cout << "cout:" ;
	for(i = 0; i < 5; i++)
		cin >> a[i];
	cout << "cout:" ;
	for(i = 0; i < 5; i++)
		cin >> s[i];

	cout << "n:" << n << endl;
	cout << "f:" << f << endl;
	for(i = 0; i < 5; i++)
		cout << a[i] << endl;
	for(i = 0; i < 5; i++)
		cout << s[i] << endl;

	return 0;
}

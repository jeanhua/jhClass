#include<iostream>
#include "jhClass.h"
using namespace std;
void jhstring()
{
	cout << "jhString test------------------------------------\n";
	jhString str = "test";
	jhString str1;
	cout << str << endl;
	str1 = "hello world";
	cout << str1 << endl;
	str = str + " " + str1;
	cout << str << endl;
	str = "8.28";
	cout << "8.28+1=" << str.to_float() + 1 << endl;
	str = "1";
	cout << "1+1=" << str.to_int() + 1 << endl;
	str = "true";
	if (str == "true")cout << "true"; else cout << "false";
	cout << "\n" << str1.substr("he", "ld");
}
void jhfraction()
{
	cout << "jhNum test-------------------------------------------\n";
	jhFraction num, num1, num2;
	//cin >> num >> num1;
	num = jhFraction(1, 3);
	num1 = jhFraction(2, 4);
	num2 = num1 + num;
	if (num2 >= num1)
	{
		cout << "yes\n";
	}
	cout << num2 << endl;
	cout << num2.to_float();
}
void jhvector2()
{
	cout << "jhvector2 test-------------------------------------------\n";
	jhVector2 v1(1,1), v2(2,3);
	float a = v1.destance(v2);
	cout << a << endl;
	jhVector2 v3 = v1 + v2;
	cout << "v3=("<<v3.x<<","<<v3.y<<")" << endl;
}
int main()
{
	jhstring();
	cout << "\n";
	jhfraction();
	cout << "\n";
	jhvector2();
}
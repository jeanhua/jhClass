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
void jhnum()
{
	cout << "jhNum test-------------------------------------------\n";
	jhNum num, num1, num2;
	cin >> num >> num1;
	num2 = num1 + num;
	cout << num2 << endl;
	cout << num2.to_float();
}
int main()
{
	jhstring();
	cout << "\n";
	jhnum();
}
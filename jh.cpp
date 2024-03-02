#include<iostream>
#include "jhClass.h"
using namespace std;
int main()
{
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
}
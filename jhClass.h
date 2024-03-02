#pragma once
#include<string>
#include<iostream>
using namespace std;
//jhString¿‡
class jhString
{
public:
	friend ostream& operator<<(ostream& cout, jhString& str);
	friend istream& operator>>(istream& cin, jhString& str);
	jhString();
	jhString(string str);
	jhString(const char* str);
	jhString operator+(jhString str);
	jhString operator=(jhString str);
	jhString operator+=(jhString str);
	bool operator==(jhString str);
	int to_int();
	float to_float();
	string to_stdString();

private:
	string str;
};
ostream& operator<<(ostream& cout, jhString& str)
{
	cout << str.str;
	return cout;
}
istream& operator>>(istream& cin, jhString& str)
{
	cin >> str.str;
	return cin;
}
jhString::jhString()
{
	this->str = "";
}
jhString::jhString(string str)
{
	this->str = str;
}
jhString::jhString(const char* str)
{
	this->str = string(str);
}
jhString jhString::operator+(jhString str)
{
	this->str += str.str;
	return *this;
}
jhString jhString::operator=(jhString str)
{
	this->str = str.str;
	return *this;
}
jhString jhString::operator+=(jhString str)
{
	this->str += str.str;
	return *this;
}
bool jhString::operator==(jhString str)
{
	if (this->str == str.str)
	{
		return true;
	}
	else return false;
}
int jhString::to_int()
{
	return atoi(this->str.c_str());
}
float jhString::to_float()
{
	return atof(this->str.c_str());
}
string jhString::to_stdString()
{
	return this->str;
}
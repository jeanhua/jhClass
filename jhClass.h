#pragma once
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

//jhString类:字符串类型
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
	//字符串转换为整型数据(如果可以)
	int to_int();
	//字符串转换为浮点型数据(如果可以)
	float to_float();
	//返回字符串索引，从0开始
	int indexOf(string str);
	//返回字符串索引，从0开始
	int indexOf(jhString str);
	//转换为std::string
	string to_stdString();
	//字符串截取
	string substr(int begin, int end);
	//字符串截取
	string substr(string leftStr, string rightStr);

private:
	string str;
};

//jhFraction类:s/m分数类
class jhFraction
{
public:
	friend ostream& operator<<(ostream& cout, jhFraction& num);
	friend istream& operator>>(istream& cin, jhFraction& num);
	jhFraction();
	jhFraction(int sm);
	jhFraction(int s,int m);
	void simplify();
	float to_float();
	jhFraction operator+(jhFraction& num);
	jhFraction operator-(jhFraction& num);
	jhFraction operator*(jhFraction& num);
	jhFraction operator/(jhFraction& num);
	bool operator>(jhFraction& num);
	bool operator>(float num);
	bool operator>=(jhFraction& num);
	bool operator>=(float num);
	bool operator<(jhFraction& num);
	bool operator<(float num);
	bool operator<=(jhFraction& num);
	bool operator<=(float num);
	bool operator==(jhFraction& num);
	bool operator==(float num);
	jhFraction& operator+=(jhFraction& num);
private:
	int s, m;/* （s/m分数类型）*/
};

//jhVector2类，二维向量，坐标
class jhVector2
{
public:
	float x, y;
	jhVector2();
	jhVector2(float x,float y);
	jhVector2& operator=(jhVector2& v2);
	jhVector2 operator+(jhVector2& v2);
	jhVector2 operator-(jhVector2& v2);
	//求坐标距离
	double destance(jhVector2& objective);
};

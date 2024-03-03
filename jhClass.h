#pragma once
#include<string>
#include<iostream>
using namespace std;

//jhString类
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
	string substr(int begin, int end);
	string substr(string leftStr, string rightStr);

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
	return jhString(this->str+str.str);
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
string jhString::substr(int begin, int end)
{
	if (end <= begin)
		return this->str.substr(begin, end - begin + 1);
	else
		return this->str;
}
string jhString::substr(string leftStr, string rightStr)//取出中间字符串
{
	int left = this->str.find(leftStr);
	int right = this->str.find(rightStr);
	if (left==-1)return "";//找不到左边，返回空
	if (right!=-1)//找到右边
	{
		if (left < right)
		{
			return this->str.substr(left + leftStr.length(), right - (left + leftStr.length()));
		}
		else//左边在右边之后，返回右边字符串(leftStr)到末尾
			return this->str.substr(left+1);
	}
	else//找不到右边，截取从左边到末尾
		return this->str.substr(left+1);
}




//jhNum类
class jhNum
{
public:
	friend ostream& operator<<(ostream& cout, jhNum& num);
	friend istream& operator>>(istream& cin, jhNum& num);
	jhNum();
	jhNum(int sm);
	jhNum(int s,int m);
	void simplify();
	float to_float();
	jhNum operator+(jhNum num);
	jhNum operator-(jhNum num);
	jhNum operator*(jhNum num);
	jhNum operator/(jhNum num);
	jhNum& operator+=(jhNum num);
private:
	int s, m;/* （s/m分数类型）*/
};
ostream& operator<<(ostream& cout, jhNum& num)
{
	if (num.m != 1&&num.s!=0)
		cout << num.s << "/" << num.m;
	else
		cout << num.s;
	return cout;
}
istream& operator>>(istream& cin, jhNum& num)
{
	int s, m;
	scanf("%d/%d", &s, &m);
	num.s = s;
	if (m != 0)
		num.m = m;
	else
		num.m = 1;
	num.simplify();
	return cin;
}
void jhNum::simplify()
{
	if (s >= 0 && m > 0)
	{
		for (int i = 1; i <= (s < m ? s : m); i++)
		{
			if (s % i == 0 && m % i == 0)
			{
				s /= i; m /= i;
			}
		}
	}
	if (s <= 0 && m > 0)
	{
		s = -s;
		for (int i = 1; i <= (s < m ? s : m); i++)
		{
			if (s % i == 0 && m % i == 0)
			{
				s /= i; m /= i;
			}
		}
		s = -s;
	}
}
jhNum::jhNum()
{
	s = 0; m = 1;
}
jhNum::jhNum(int sm)
{
	s = sm;
	m = 1;
}
jhNum::jhNum(int s,int m)
{
	if ((s < 0 && m < 0)|| (s > 0 && m < 0))
	{
		s = -s; m = -m;
	}
	this->s = s;
	if (m != 0)
		this->m = m;
	else
		this->m = 1;
	simplify();
}
float jhNum::to_float()
{
	return float(s) / m;
}

jhNum jhNum::operator+(jhNum num)
{
	return jhNum(this->s * num.m + this->m * num.s, this->m * num.m);
}
jhNum jhNum::operator-(jhNum num)
{
	return jhNum(this->s * num.m - this->m * num.s, this->m * num.m);
}
jhNum jhNum::operator*(jhNum num)
{
	return jhNum(this->s * num.s, this->m * num.m);
}
jhNum jhNum::operator/(jhNum num)
{
	return jhNum(this->s * num.m , this->m * num.s);
}
jhNum& jhNum::operator+=(jhNum num)
{
	*this = *this + num;
	return *this;
}

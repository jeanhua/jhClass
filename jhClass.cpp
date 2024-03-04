#include "jhClass.h"

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
	return jhString(this->str + str.str);
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
int jhString::indexOf(string str)
{
	return this->str.find(str);
}
int jhString::indexOf(jhString str)
{
	return this->str.find(str.str);
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
string jhString::substr(string leftStr, string rightStr)//È¡³öÖÐ¼ä×Ö·û´®
{
	int left = this->str.find(leftStr);
	int right = this->str.find(rightStr);
	if (left == -1)return "";//ÕÒ²»µ½×ó±ß£¬·µ»Ø¿Õ
	if (right != -1)//ÕÒµ½ÓÒ±ß
	{
		if (left < right)
		{
			return this->str.substr(left + leftStr.length(), right - (left + leftStr.length()));
		}
		else//×ó±ßÔÚÓÒ±ßÖ®ºó£¬·µ»ØÓÒ±ß×Ö·û´®(leftStr)µ½Ä©Î²
			return this->str.substr(left + 1);
	}
	else//ÕÒ²»µ½ÓÒ±ß£¬½ØÈ¡´Ó×ó±ßµ½Ä©Î²
		return this->str.substr(left + 1);
}


ostream& operator<<(ostream& cout, jhFraction& num)
{
	if (num.m != 1 && num.s != 0)
		cout << num.s << "/" << num.m;
	else
		cout << num.s;
	return cout;
}
istream& operator>>(istream& cin, jhFraction& num)
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
void jhFraction::simplify()
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
jhFraction::jhFraction()
{
	s = 0; m = 1;
}
jhFraction::jhFraction(int sm)
{
	s = sm;
	m = 1;
}
jhFraction::jhFraction(int s, int m)
{
	if ((s < 0 && m < 0) || (s > 0 && m < 0))
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
float jhFraction::to_float()
{
	return float(s) / m;
}

jhFraction jhFraction::operator+(jhFraction& num)
{
	return jhFraction(this->s * num.m + this->m * num.s, this->m * num.m);
}
jhFraction jhFraction::operator-(jhFraction& num)
{
	return jhFraction(this->s * num.m - this->m * num.s, this->m * num.m);
}
jhFraction jhFraction::operator*(jhFraction& num)
{
	return jhFraction(this->s * num.s, this->m * num.m);
}
jhFraction jhFraction::operator/(jhFraction& num)
{
	return jhFraction(this->s * num.m, this->m * num.s);
}
bool jhFraction::operator>(jhFraction& num)
{
	if (this->s * num.m - num.s - this->m > 0)
		return true;
	else
		return false;
}
bool jhFraction::operator>(float num)
{
	if (this->to_float() > num)
		return true;
	else
		return false;
}
bool jhFraction::operator>=(jhFraction& num)
{
	if (*this > num || *this == num)
	{
		return true;
	}
	else
		return false;
}
bool jhFraction::operator>=(float num)
{
	if (this->to_float() >= num)
		return true;
	else
		return false;
}
bool jhFraction::operator<=(jhFraction& num)
{
	if (*this < num || *this == num)
	{
		return true;
	}
	else
		return false;
}
bool jhFraction::operator<=(float num)
{
	if (this->to_float() <= num)
		return true;
	else
		return false;
}
bool jhFraction::operator<(jhFraction& num)
{
	if (this->s * num.m - num.s - this->m > 0)
		return false;
	else
		return true;
}
bool jhFraction::operator<(float num)
{
	if (this->to_float() < num)
		return true;
	else
		return false;
}
bool jhFraction::operator==(jhFraction& num)
{
	if (this->s * num.m - num.s - this->m == 0)
		return true;
	else
		return false;
}
bool jhFraction::operator==(float num)
{
	if (this->to_float() == num)
		return true;
	else
		return false;
}
jhFraction& jhFraction::operator+=(jhFraction& num)
{
	*this = *this + num;
	return *this;
}



jhVector2::jhVector2()
{
	x = 0; y = 0;
}
jhVector2::jhVector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
jhVector2& jhVector2::operator=(jhVector2& v2)
{
	this->x = v2.x;
	this->y = v2.y;
	return *this;
}
jhVector2 jhVector2::operator+(jhVector2& v2)
{
	return jhVector2(this->x + v2.x, this->y + v2.y);
}
jhVector2 jhVector2::operator-(jhVector2& v2)
{
	return jhVector2(this->x - v2.x, this->y - v2.y);
}
double jhVector2::destance(jhVector2& obj)
{
	return sqrt(pow(this->x - obj.x, 2) + pow(this->y - obj.y, 2));
}

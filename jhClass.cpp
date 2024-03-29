#include "jhClass.h"

ostream& operator<<(ostream& cout,const jhString& str)
{
	cout << str.str;
	return cout;
}
istream& operator>>(istream& cin,const jhString& str)
{
	cin >> str.str;
	return cin;
}
jhString::jhString()
{
	this->str = "";
}
jhString::jhString(const string& str)
{
	this->str = str;
}
jhString::jhString(const char* str)
{
	this->str = string(str);
}
jhString jhString::operator+(const jhString& str)
{
	return jhString(this->str + str.str);
}
jhString jhString::operator=(const jhString& str)
{
	this->str = str.str;
	return *this;
}
jhString jhString::operator+=(const jhString& str)
{
	this->str += str.str;
	return *this;
}
bool jhString::operator==(const jhString& str)
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
int jhString::indexOf(const string& str)
{
	return this->str.find(str);
}
int jhString::indexOf(const jhString& str)
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
string jhString::substr(const string& leftStr,const string& rightStr)//取出中间字符串
{
	int left = this->str.find(leftStr);
	int right;
	if (left == -1)
	{
		return "";//找不到左边，返回空
	}
	else
	{
		right = this->str.find(rightStr,left);
	}
	if (right != -1)//找到右边
	{
		return this->str.substr(left + leftStr.length(), right - (left + leftStr.length()));
	}
	else//找不到右边，截取从左边到末尾
	{
		return this->str.substr(left + 1);
	}
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

jhFraction jhFraction::operator+(const jhFraction& num)
{
	return jhFraction(this->s * num.m + this->m * num.s, this->m * num.m);
}
jhFraction jhFraction::operator-(const jhFraction& num)
{
	return jhFraction(this->s * num.m - this->m * num.s, this->m * num.m);
}
jhFraction jhFraction::operator*(const jhFraction& num)
{
	return jhFraction(this->s * num.s, this->m * num.m);
}
jhFraction jhFraction::operator/(const jhFraction& num)
{
	return jhFraction(this->s * num.m, this->m * num.s);
}
bool jhFraction::operator>(const jhFraction& num)
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
bool jhFraction::operator>=(const jhFraction& num)
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
bool jhFraction::operator<=(const jhFraction& num)
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
bool jhFraction::operator<(const jhFraction& num)
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
bool jhFraction::operator==(const jhFraction& num)
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
jhFraction& jhFraction::operator+=(const jhFraction& num)
{
	*this = *this + num;
	return *this;
}
jhFraction& jhFraction::operator-=(const jhFraction& num)
{
	*this = *this - num;
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
jhVector2& jhVector2::operator=(const jhVector2& v2)
{
	this->x = v2.x;
	this->y = v2.y;
	return *this;
}
jhVector2 jhVector2::operator+(const jhVector2& v2)
{
	return jhVector2(this->x + v2.x, this->y + v2.y);
}
jhVector2& jhVector2::operator+=(const jhVector2& v2)
{
	this->x += v2.x;
	this->y += v2.y;
	return *this;
}
jhVector2 jhVector2::operator-(const jhVector2& v2)
{
	return jhVector2(this->x - v2.x, this->y - v2.y);
}
jhVector2& jhVector2::operator-=(const jhVector2& v2)
{
	this->x -= v2.x;
	this->y -= v2.y;
	return *this;
}
jhVector2 jhVector2::operator*(float i)
{
	return jhVector2(this->x * i, this->y * i);
}
jhVector2 jhVector2::operator/(float i)
{
	return jhVector2(this->x / i, this->y / i);
}
bool jhVector2::operator==(const jhVector2& v2)
{
	if (this->x == v2.x && this->y == v2.y)
		return true;
	else
		return false;
}
double jhVector2::destance(const jhVector2& obj)
{
	return sqrt(pow(this->x - obj.x, 2) + pow(this->y - obj.y, 2));
}

double jhVector2::cross_product(const jhVector2& objective)
{
	return this->x * objective.y - this->y * objective.x;
}

double jhVector2::dot_product(const jhVector2& objective)
{
	return this->x * objective.x + this->y * objective.y;
}

template<typename T>
void jhList<T>::addList(T value)
{
	node* newlist = new node;
	newlist->p_next = NULL;
	newlist->value = value;
	node* p = this->p_first;
	while (p->p_next != NULL)
	{
		p = p->p_next;
	}
	newlist->p_back = p;
	p->p_next = newlist;
}

template<typename T>
void jhList<T>::deleteList(node* list)
{
	if (list->p_back != NULL)
	{
		if (list->p_next != NULL)
		{
			node* p = list->p_back;
			p->p_next = list->p_next;
			node* p1 = list->p_next;
			p1->p_back = p;
			delete list;
		}
		else
		{
			node* p = list->p_back;
			p->p_next = NULL;
			delete list;
		}
	}
	else
	{
		if (list->p_next != NULL)
		{
			node* p = list->p_next;
			p->p_back = NULL;
			p_first = p;
			delete list;
		}
		else
		{
			delete list;
		}
	}
}

template<typename T>
jhList<T>::jhList()
{
	p_first = new node;
	p_first->p_next = NULL;
	p_first->p_back = NULL;
}

template<typename T>
jhList<T>::jhList(T initialValue)
{
	p_first = new node;
	p_first->p_next = NULL;
	p_first->p_back = NULL;
	p_first->value = initialValue;
}

template<typename T>
jhList<T>::~jhList()
{
	for (node* it = this->p_first; it != NULL; it = it->p_next)
	{
		if (it->p_back != NULL)
			delete it->p_back;
		if (it->p_next == NULL)
		{
			delete it;
			break;
		}
	}
}
//模板实例化
template class jhList<int>;
template class jhList<char>;
template class jhList<float>;
template class jhList<double>;
template class jhList<string>;
template class jhList<jhString>;
template class jhList<jhFraction>;
template class jhList<jhVector2>;
template class jhList<void*>;
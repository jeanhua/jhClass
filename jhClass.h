#pragma once
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

/*
	自定义类：jhString类，jhFraction类，jhVector2类，jhList类
*/

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
	//字符串截取，从起始位置截取到终点位置，从0开始
	string substr(int begin, int end);
	//字符串截取,从左边字符截取到右边字符(不包含边界)，若找不到左边，返回空；若找到左边，但找不到右边，返回左边到末尾
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

//jhVector2类：二维向量，坐标
class jhVector2
{
public:
	float x, y;
	jhVector2();
	jhVector2(float x,float y);
	jhVector2& operator=(jhVector2& v2);
	jhVector2 operator+(jhVector2& v2);
	jhVector2 operator-(jhVector2& v2);
	bool operator==(jhVector2 & v2);
	//求坐标距离
	double destance(jhVector2& objective);
	//求向量叉乘
	double cross_product(jhVector2& objective);
	//求向量点乘
	double dot_product(jhVector2& objective);
};
//jhList:链表类
template<typename T>
class jhList
{
public:
	struct node
	{
		node* p_back;
		node* p_next;
		T value;
	};
	//链表头
	node* p_first;
	//在后面添加节点
	void addList(T value)
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
	//删除节点
	void deleteList(node* list)
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
	jhList()
	{
		p_first = new node;
		p_first->p_next = NULL;
		p_first->p_back = NULL;
	}
	jhList(T initialValue)
	{
		p_first = new node;
		p_first->p_next = NULL;
		p_first->p_back = NULL;
		p_first->value = initialValue;
	}
	~jhList()
	{
		for (node* it = this->p_first; it!= NULL; it = it->p_next)
		{
			delete it;
		}
	}
};

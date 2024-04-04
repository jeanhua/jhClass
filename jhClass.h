#pragma once
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

/*
	自定义类：jhString类，jhFraction类，jhVector2类，jhList类，jhMatrix类
*/

//jhString类:字符串类型
class jhString
{
public:
	friend ostream& operator<<(ostream& cout,const jhString& str);
	friend istream& operator>>(istream& cin,const jhString& str);
	jhString();
	jhString(const string& str);
	jhString(const char* str);
	jhString operator+(const jhString& str);
	jhString operator=(const jhString& str);
	jhString operator+=(const jhString& str);
	bool operator==(const jhString& str);
	//字符串转换为整型数据(如果可以)
	int to_int();
	//字符串转换为浮点型数据(如果可以)
	float to_float();
	//返回字符串索引，从0开始
	int indexOf(const string& str);
	//返回字符串索引，从0开始
	int indexOf(const jhString& str);
	//转换为std::string
	string to_stdString();
	//字符串截取，从起始位置截取到终点位置，从0开始
	string substr(int begin, int end);
	//字符串截取,从左边字符截取到右边字符(不包含边界)，若找不到左边，返回空；若找到左边，但找不到右边，返回左边到末尾
	string substr(const string& leftStr,const string& rightStr);

private:
	string str;
};

//jhFraction类:s/m分数类
class jhFraction
{
public:
	friend ostream& operator<<(ostream& cout,const jhFraction& num);
	friend istream& operator>>(istream& cin,jhFraction& num);
	jhFraction();
	jhFraction(int num);
	jhFraction(double num);
	jhFraction(int s,int m);
	void simplify();
	void print();
	float to_float();
	jhFraction operator+(const jhFraction& num);
	jhFraction& operator+=(const jhFraction& num);
	jhFraction operator-(const jhFraction& num);
	jhFraction& operator-=(const jhFraction& num);
	jhFraction operator*(const jhFraction& num);
	jhFraction operator/(const jhFraction& num);
	bool operator>(const jhFraction& num);
	bool operator>(float num);
	bool operator>=(const jhFraction& num);
	bool operator>=(float num);
	bool operator<(const jhFraction& num);
	bool operator<(float num);
	bool operator<=(const jhFraction& num);
	bool operator<=(float num);
	bool operator==(const jhFraction& num);
	bool operator==(float num);
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
	jhVector2& operator=(const jhVector2& v2);
	jhVector2 operator+(const jhVector2& v2);
	jhVector2& operator+=(const jhVector2& v2);
	jhVector2 operator-(const jhVector2& v2);
	jhVector2& operator-=(const jhVector2& v2);
	jhVector2 operator*(float i);
	jhVector2 operator/(float i);
	bool operator==(const jhVector2& v2);
	//求坐标距离
	double destance(const jhVector2& objective);
	//求向量叉乘
	double cross_product(const jhVector2& objective);
	//求向量点乘
	double dot_product(const jhVector2& objective);
};

//jhList:链表模板类(无序链表)
template<typename T>
class jhList
{
public:
	struct node
	{
		node* p_back=NULL;
		node* p_next=NULL;
		T value;
	};
	//链表头
	node* p_first;
	//在后面添加节点
	void addList(T value);
	//删除节点
	void deleteList(node* list);
	//默认构造函数
	jhList();
	//有参构造函数,initialValue:链表头初始值
	jhList(T initialValue);
	//析构函数
	~jhList();
};

//jhMatrix类，矩阵类
class jhMatrix
{
private:

	float** matrix;
	int row, column;
	void init(int row,int column)
	{
		this->row = row;
		this->column = column;
		this->matrix = new float* [row];
		for (int i = 0; i < this->row; i++)
		{
			this->matrix[i] = new float[this->column];
		}
	}
public:

	// 默认构造函数
	jhMatrix(int row, int column);
	//用另一个矩阵构造
	jhMatrix(const jhMatrix& other);
	// jhVector2构造函数
	jhMatrix(const jhVector2& v2);
	// 二维数组转换的一维指针构造
	jhMatrix(float* other, int row, int column);
	// 析构函数
	~jhMatrix();
	// 设置矩阵值
	void setValue(int row, int column, float value);
	//打印矩阵
	void print(bool isFraction=false);
	// 取转置矩阵
	jhMatrix getTransposeMatrix();
	// 取逆矩阵
	jhMatrix getInverseMatrix();
	//取行列式
	float getDeterminant();
	// 交换行
	void swapRows(int row1, int row2);
	// 将某行所有元素除以一个数
	void divideRow(int row, float divisor);
	// 将一行加到另一行的倍数
	void addToRow(int sourceRow, int destRow, float multiple);
	// 矩阵运算
	jhMatrix operator+(const jhMatrix& other);
	jhMatrix operator-(const jhMatrix& other);
	jhMatrix operator*(const jhMatrix& other);
	jhMatrix operator*(float num);
	jhMatrix operator=(const jhMatrix& other);
	bool operator==(const jhMatrix& other);
};

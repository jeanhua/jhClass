#pragma once
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

/*
	�Զ����ࣺjhString�࣬jhFraction�࣬jhVector2�࣬jhList�࣬jhMatrix�࣬jhObject2D�����ռ�{transform��,circle��,rectangle��,triangle��,diamond��,trapezium��}
*/

#define PI 3.14

// �������
class jhstring;
class jhFraction;
class jhVector2;
template<typename T> class jhList;
class jhMatrix;

//jhString��:�ַ�������
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
	//�ַ���ת��Ϊ��������(�������)
	int to_int();
	//�ַ���ת��Ϊ����������(�������)
	float to_float();
	//�����ַ�����������0��ʼ
	int indexOf(const string& str);
	//�����ַ�����������0��ʼ
	int indexOf(const jhString& str);
	//ת��Ϊstd::string
	string to_stdString();
	//�ַ�����ȡ������ʼλ�ý�ȡ���յ�λ�ã���0��ʼ
	string substr(int begin, int end);
	//�ַ�����ȡ,������ַ���ȡ���ұ��ַ�(�������߽�)�����Ҳ�����ߣ����ؿգ����ҵ���ߣ����Ҳ����ұߣ�������ߵ�ĩβ
	string substr(const string& leftStr,const string& rightStr);

private:
	string str;
};

//jhFraction��:s/m������
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
	int s, m;/* ��s/m�������ͣ�*/
};

//jhVector2�ࣺ��ά����������
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
	//���������
	double destance(const jhVector2& objective);
	//���������
	double cross_product(const jhVector2& objective);
	//���������
	double dot_product(const jhVector2& objective);
	//��ת
	void rotate(const jhVector2& center, float angle);
};

//jhList:����ģ����(��������)
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
	//����ͷ
	node* p_first;
	//�ں�����ӽڵ�
	void addList(T value);
	//ɾ���ڵ�
	void deleteList(node* list);
	//Ĭ�Ϲ��캯��
	jhList();
	//��������
	~jhList();
};

//jhMatrix�࣬������
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

	// Ĭ�Ϲ��캯��
	jhMatrix(int row, int column);
	//����һ��������
	jhMatrix(const jhMatrix& other);
	// jhVector2���캯��
	jhMatrix(const jhVector2& v2);
	// ��ά����ת����һάָ�빹��
	jhMatrix(float* other, int row, int column);
	// ��������
	~jhMatrix();
	// ���þ���ֵ
	void setValue(int row, int column, float value);
	//��ӡ����
	void print(bool isFraction=false);
	// ȡת�þ���
	jhMatrix getTransposeMatrix();
	// ȡ�����
	jhMatrix getInverseMatrix();
	//ȡ����ʽ
	float getDeterminant();
	// ������
	void swapRows(int row1, int row2);
	// ��ĳ������Ԫ�س���һ����
	void divideRow(int row, float divisor);
	// ��һ�мӵ���һ�еı���
	void addToRow(int sourceRow, int destRow, float multiple);
	// ��������
	jhMatrix operator+(const jhMatrix& other);
	jhMatrix operator-(const jhMatrix& other);
	jhMatrix operator*(const jhMatrix& other);
	jhMatrix operator*(float num);
	jhMatrix operator=(const jhMatrix& other);
	bool operator==(const jhMatrix& other);
};

namespace jhObject2D
{
	// ������
	class transform;
	class circle;
	class rectangle;
	class triangle;
	class diamond;

	//���ʵ��

	// �������
	class transform
	{
	public:
		// Ĭ�Ϲ��캯��
		transform();
		// λ��(ͼ���������꣬�����Բ��������)
		jhVector2 position;
		// �������
		virtual float getAreaSize() = 0;
		// �������
		float getDistance(const transform& other);
		// �ж��Ƿ�����������
		virtual bool isTrigleEnter(const triangle& other) = 0;
		// �ж��Ƿ��ھ�����
		virtual bool isTrigleEnter(const rectangle& other) = 0;
		// �ж��Ƿ���������
		virtual bool isTrigleEnter(const diamond& other) = 0;
		// �ж��Ƿ���Բ����
		virtual bool isTrigleEnter(const circle& other) = 0;
	};

	// Բ��
	class circle :public transform
	{
	public:
		circle(float radius);
		float radius;
		virtual float getAreaSize();
		virtual bool isTrigleEnter(const triangle& other);
		virtual bool isTrigleEnter(const rectangle& other);
		virtual bool isTrigleEnter(const diamond& other);
		virtual bool isTrigleEnter(const circle& other);
	};

	// ����
	class rectangle :public transform
	{
	public:
		rectangle(float width, float height);
		float width;
		float height;
		virtual float getAreaSize();
		virtual bool isTrigleEnter(const triangle& other);
		virtual bool isTrigleEnter(const rectangle& other);
		virtual bool isTrigleEnter(const diamond& other);
		virtual bool isTrigleEnter(const circle& other);

	};

	// ������
	class triangle :public transform
	{
	public:
		triangle(jhVector2 pointA, jhVector2 pointB, jhVector2 pointC);
		triangle(jhVector2 center, float coLength);
		jhVector2 pointA, pointB, pointC;
		virtual float getAreaSize();
		virtual bool isTrigleEnter(const triangle& other);
		virtual bool isTrigleEnter(const rectangle& other);
		virtual bool isTrigleEnter(const diamond& other);
		virtual bool isTrigleEnter(const circle& other);

	};

	// ����
	class diamond :public transform
	{
	public:
		diamond(float lengthX, float lengthY);
		float lengthX, lengthY;
		virtual float getAreaSize();
		virtual bool isTrigleEnter(const triangle& other);
		virtual bool isTrigleEnter(const rectangle& other);
		virtual bool isTrigleEnter(const diamond& other);
		virtual bool isTrigleEnter(const circle& other);

	};
};
#pragma once
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

/*
	�Զ����ࣺjhString�࣬jhFraction�࣬jhVector2�࣬jhList��
*/

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
	friend ostream& operator<<(ostream& cout, jhFraction& num);
	friend istream& operator>>(istream& cin, jhFraction& num);
	jhFraction();
	jhFraction(int sm);
	jhFraction(int s,int m);
	void simplify();
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
};

//jhList:����ģ����(��������)
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
	//����ͷ
	node* p_first;
	//�ں�����ӽڵ�
	void addList(T value);
	//ɾ���ڵ�
	void deleteList(node* list);
	//Ĭ�Ϲ��캯��
	jhList();
	//�вι��캯��,initialValue:����ͷ��ʼֵ
	jhList(T initialValue);
	//��������
	~jhList();
};

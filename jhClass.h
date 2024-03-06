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
	friend ostream& operator<<(ostream& cout, jhString& str);
	friend istream& operator>>(istream& cin, jhString& str);
	jhString();
	jhString(string str);
	jhString(const char* str);
	jhString operator+(jhString str);
	jhString operator=(jhString str);
	jhString operator+=(jhString str);
	bool operator==(jhString str);
	//�ַ���ת��Ϊ��������(�������)
	int to_int();
	//�ַ���ת��Ϊ����������(�������)
	float to_float();
	//�����ַ�����������0��ʼ
	int indexOf(string str);
	//�����ַ�����������0��ʼ
	int indexOf(jhString str);
	//ת��Ϊstd::string
	string to_stdString();
	//�ַ�����ȡ������ʼλ�ý�ȡ���յ�λ�ã���0��ʼ
	string substr(int begin, int end);
	//�ַ�����ȡ,������ַ���ȡ���ұ��ַ�(�������߽�)�����Ҳ�����ߣ����ؿգ����ҵ���ߣ����Ҳ����ұߣ�������ߵ�ĩβ
	string substr(string leftStr, string rightStr);

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
	int s, m;/* ��s/m�������ͣ�*/
};

//jhVector2�ࣺ��ά����������
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
	//���������
	double destance(jhVector2& objective);
	//���������
	double cross_product(jhVector2& objective);
	//���������
	double dot_product(jhVector2& objective);
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

#include<iostream>
#include "jhClass.h"
using namespace std;
void test_jhstring()
{
	cout << "jhString test------------------------------------\n";
	jhString str = "test";
	jhString str1 = "hello world";
	cout << str << endl;
	cout << str1 << endl;
	str = str + " " + str1;
	cout << str << endl;
	str = "8.28";
	cout << "8.28+1=" << str.to_float() + 1 << endl;
	str = "1";
	cout << "1+1=" << str.to_int() + 1 << endl;
	str = "true";
	if (str == "true")cout << "true"; else cout << "false";
	cout << "\n" << str1.substr("he", "ld");
}
void test_jhfraction()
{
	cout << "jhNum test-------------------------------------------\n";
	jhFraction num, num1, num2;
	//cin >> num >> num1;
	num = jhFraction(1, 3);
	num1 = jhFraction(2, 4);
	num2 = num1 + num;
	if (num2 >= num1)
	{
		cout << "yes\n";
	}
	cout << num2 << endl;
	cout << num2.to_float();
}
void test_jhvector2()
{
	cout << "jhvector2 test-------------------------------------------\n";
	jhVector2 v1(1,1);
	//求坐标v1和v2的距离
	float a = v1.destance(jhVector2(2,3));
	cout << a << endl;
	jhVector2 v3 = v1 +jhVector2(2,3);
	cout << "v3=("<<v3.x<<","<<v3.y<<")" << endl;
}
void test_jhlist()
{
	cout << "jhlist test-------------------------------------------\n";
	//创建整型链表
	jhList<int> list1;
	list1.addList(1);
	list1.addList(2);
	list1.addList(3);
	list1.addList(4);
	list1.addList(111);
	list1.addList(111);
	list1.addList(113);
	list1.addList(114);
	//遍历链表
	for (auto it = list1.p_first; it!= NULL; it = it->p_next)
	{
		if (it->value == 0)
		{
			list1.deleteList(it);//删除节点
		}
	}
	//遍历链表
	for (auto it = list1.p_first; it!= NULL; it = it->p_next)
	{
		cout << it->value << endl;
	}
}
void test_jhmatrix()
{
	float a[3][3] = {
		{1,2,-1},
		{-2,1,0},
		{1,0,3}
	};
	float b[3][2] = {
		{2,3},
		{1,1},
		{1,-1}
	};
	try {
		jhMatrix A((float*)a, 3, 3);
		jhMatrix B((float*)b, 3, 2);
		A.print();
		cout << A.getDeterminant() << endl;
		jhMatrix in = A.getInverseMatrix();
		in.print(true);
		jhMatrix tran = A.getTransposeMatrix();
		tran.print();
		jhMatrix mul = A * B;
		mul.print();
	}
	catch(const exception& e)
	{
		cout << e.what();
	}
}

int main()
{
	test_jhmatrix();
}
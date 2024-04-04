#include "jhClass.h"
#include<stdexcept>
#include<vector>
#include<cmath>

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


ostream& operator<<(ostream& cout,const jhFraction& num)
{
	if (num.m != 1 && num.s != 0)
		cout << num.s << "/" << num.m;
	else
		cout << num.s;
	return cout;
}
istream& operator>>(istream& cin,jhFraction& num)
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
				i = 1;
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
				i = 1;
			}
		}
		s = -s;
	}
}
void jhFraction::print()
{
	cout << s << "/" << m;
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
jhFraction::jhFraction(double num)
{
	int M=1;
	while (num-int(num)!=0)
	{
		num *= 10;
		M *= 10;
	}
	s = num; m = M;
	simplify();
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



jhMatrix::jhMatrix(int row, int column)
{
	this->init(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

jhMatrix::jhMatrix(const jhMatrix& other)
{
	this->row = other.row;
	this->column = other.column;
	this->row = other.row;
	this->column = other.column;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}

jhMatrix::~jhMatrix()
{
	for (int i = 0; i < this->row; i++)delete[] this->matrix[i];
	delete[] this->matrix;
}

jhMatrix::jhMatrix(const jhVector2& v2)
{
	this->init(int(v2.x), int(v2.y));
}

jhMatrix::jhMatrix(float* other, int row, int column)
{
	this->init(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			this->matrix[i][j] = *(other+i*column+j);
		}
	}
}

void jhMatrix::setValue(int row, int column, float value)
{
	this->matrix[row][column] = value;
}

void jhMatrix::print(bool isFraction)
{
	if(isFraction==false)
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	else
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cout << jhFraction(matrix[i][j]) << " ";
			}
			cout << endl;
		}
}

void jhMatrix::swapRows(int row1, int row2) {
	if (row1 < 0 || row1 >= row || row2 < 0 || row2 >= row) {
		throw std::out_of_range("Row index out of range");
	}
	float* temp = matrix[row1];
	matrix[row1] = matrix[row2];
	matrix[row2] = temp;
}

void jhMatrix::divideRow(int row, float divisor) {
	if (row < 0 || row >= this->row) {
		throw std::out_of_range("Row index out of range");
	}
	else if (divisor == 0)
	{
		throw std::invalid_argument("Can't be divided by 0");
	}
	for (int j = 0; j < column; ++j) {
		matrix[row][j] /= divisor;
	}
}

void jhMatrix::addToRow(int sourceRow, int destRow, float multiple) {
	if (sourceRow < 0 || sourceRow >= row || destRow < 0 || destRow >= row) {
		throw std::out_of_range("Row index out of range");
	}
	for (int j = 0; j < column; ++j) {
		matrix[destRow][j] += matrix[sourceRow][j] * multiple;
	}
}


jhMatrix jhMatrix::getTransposeMatrix()
{
	jhMatrix transpose(column, row); // 新建一个矩阵，行列互换
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j) 
		{
			transpose.matrix[j][i] = matrix[i][j]; // 转置
		}
	}
	return transpose;
}
float calDeterminant(float** det, int n)//det-行列式，n:行列式的阶数
{
	float detVal = 0;//行列式的值
	if (n == 1)//递归终止条件 
		return det[0][0];
	float** tempdet = new float* [n - 1];//用来存储余相应的余子式
	for (int i = 0; i < n - 1; i++)
		tempdet[i] = new float[n - 1];
	for (int i = 0; i < n; i++)//第一重循环，行列式按第一行展开 
	{
		for (int j = 0; j < n - 1; j++)
			for (int k = 0; k < n - 1; k++)
			{
				if (k < i)
					tempdet[j][k] = det[j + 1][k];
				else
					tempdet[j][k] = det[j + 1][k + 1];
			}
		detVal += det[0][i] * pow(-1.0, i) * calDeterminant(tempdet, n - 1);
	}
	for (int i = 0; i < n - 1; i++)delete[] tempdet[i]; delete[] tempdet;
	return detVal;
}

//使用高斯消元法对矩阵进行求逆
jhMatrix jhMatrix::getInverseMatrix() {
	if (row != column) {
		throw std::invalid_argument("Matrix is not square.");
	}
	// 创建扩增矩阵
	double** augmentedMatrix = new double* [row];
	for (int i = 0; i < row; ++i) {
		augmentedMatrix[i] = new double[2 * row];
		for (int j = 0; j < row; ++j) {
			augmentedMatrix[i][j] = matrix[i][j];
			augmentedMatrix[i][j + row] = (i == j) ? 1 : 0; // 对角线置为1，其余置为0
		}
	}
	// 高斯消元
	for (int i = 0; i < row; ++i) {
		// 判断主元素是否为0，如果是则交换行
		if (augmentedMatrix[i][i] == 0) {
			int swapRow = i + 1;
			while (swapRow < row && augmentedMatrix[swapRow][i] == 0) {
				++swapRow;
			}
			if (swapRow == row) {
				throw std::invalid_argument("Matrix is singular.");
			}
			std::swap(augmentedMatrix[i], augmentedMatrix[swapRow]);
		}
		// 将主元素归一
		double pivot = augmentedMatrix[i][i];
		for (int j = 0; j < 2 * row; ++j) {
			augmentedMatrix[i][j] /= pivot;
		}
		// 使用主元素消去其他行
		for (int j = 0; j < row; ++j) {
			if (j != i) {
				double factor = augmentedMatrix[j][i];
				for (int k = 0; k < 2 * row; ++k) {
					augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
				}
			}
		}
	}
	// 提取逆矩阵
	jhMatrix inverse(row, column);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			inverse.matrix[i][j] = augmentedMatrix[i][j + row];
		}
	}
	// 释放内存
	for (int i = 0; i < row; ++i) {
		delete[] augmentedMatrix[i];
	}
	delete[] augmentedMatrix;
	return inverse;
}


float jhMatrix::getDeterminant()
{
	if (row != column) {
		throw std::invalid_argument("Cannot calculate determinant for non-square matrix");
	}
	if (row == 1) {
		return matrix[0][0];
	}
	else 
	{
		return calDeterminant(this->matrix, row);
	}
}

// 矩阵加法
jhMatrix jhMatrix::operator+(const jhMatrix& other) {
	if (row != other.row || column != other.column) {
		throw std::invalid_argument("Matrix dimensions do not match for addition");
	}
	jhMatrix result(row, column);
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < column; ++j) 
		{
			result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return result;
}

// 矩阵减法
jhMatrix jhMatrix::operator-(const jhMatrix& other)
{
	if (row != other.row || column != other.column) 
	{
		throw std::invalid_argument("Matrix dimensions do not match for subtraction");
	}
	jhMatrix result(row, column);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}
	return result;
}

// 矩阵乘法
jhMatrix jhMatrix::operator*(const jhMatrix& other) 
{
	if (column != other.row) 
	{
		throw std::invalid_argument("Matrix dimensions do not match for multiplication");
	}
	jhMatrix result(this->row, other.column);
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < other.column; ++j) 
		{
			result.matrix[i][j] = 0;
			for (int k = 0; k <this->column; ++k) 
			{
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return result;
}

// 矩阵与标量乘法
jhMatrix jhMatrix::operator*(float num)
{
	jhMatrix result(row, column);
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < column; ++j) 
		{
			result.matrix[i][j] = matrix[i][j] * num;
		}
	}
	return result;
}

jhMatrix jhMatrix::operator=(const jhMatrix& other)
{
	this->row = other.row;
	this->column = other.column;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}

bool jhMatrix::operator==(const jhMatrix& other)
{
	if (this->row != other.row || this->column != other.column)return false;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			if (this->matrix[i][j] != other.matrix[i][j])
				return false;
		}
	}
	return true;
}
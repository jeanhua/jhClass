#include "jhClass.h"
#include<stdexcept>
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
string jhString::substr(const string& leftStr,const string& rightStr)//ȡ���м��ַ���
{
	int left = this->str.find(leftStr);
	int right;
	if (left == -1)
	{
		return "";//�Ҳ�����ߣ����ؿ�
	}
	else
	{
		right = this->str.find(rightStr,left);
	}
	if (right != -1)//�ҵ��ұ�
	{
		return this->str.substr(left + leftStr.length(), right - (left + leftStr.length()));
	}
	else//�Ҳ����ұߣ���ȡ����ߵ�ĩβ
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

void jhVector2::rotate(const jhVector2& center, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	this->x = (x - center.x) * c - (y - center.y) * s + center.x;
	this->y = (x - center.x) * s + (y - center.y) * c + center.y;
}

template<typename T>
void jhList<T>::addList(T value)
{
	node* newlist = new node;
	newlist->p_next = NULL;
	newlist->value = value;
	if (this->p_first == NULL)
	{
		this->p_first = newlist;
		newlist->p_back = NULL;
	}
	else
	{
		node* p = this->p_first;
		while (p->p_next != NULL)
		{
			p = p->p_next;
		}
		newlist->p_back = p;
		p->p_next = newlist;
	}
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
	p_first = NULL;
	node_num = 0;
}

template<typename T>
jhList<T>::~jhList()
{
	node* now = this->p_first;
	while (now!=NULL)
	{
		node* tmp = now;
		now = now->p_next;
		delete tmp;
	}
}
//ģ��ʵ����
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
	jhMatrix transpose(column, row); // �½�һ���������л���
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j) 
		{
			transpose.matrix[j][i] = matrix[i][j]; // ת��
		}
	}
	return transpose;
}
float calDeterminant(float** det, int n)//det-����ʽ��n:����ʽ�Ľ���
{
	float detVal = 0;//����ʽ��ֵ
	if (n == 1)//�ݹ���ֹ���� 
		return det[0][0];
	float** tempdet = new float* [n - 1];//�����洢����Ӧ������ʽ
	for (int i = 0; i < n - 1; i++)
		tempdet[i] = new float[n - 1];
	for (int i = 0; i < n; i++)//��һ��ѭ��������ʽ����һ��չ�� 
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

//ʹ�ø�˹��Ԫ���Ծ����������
jhMatrix jhMatrix::getInverseMatrix() {
	if (row != column) {
		throw std::invalid_argument("Matrix is not square.");
	}
	// ������������
	double** augmentedMatrix = new double* [row];
	for (int i = 0; i < row; ++i) {
		augmentedMatrix[i] = new double[2 * row];
		for (int j = 0; j < row; ++j) {
			augmentedMatrix[i][j] = matrix[i][j];
			augmentedMatrix[i][j + row] = (i == j) ? 1 : 0; // �Խ�����Ϊ1��������Ϊ0
		}
	}
	// ��˹��Ԫ
	for (int i = 0; i < row; ++i) {
		// �ж���Ԫ���Ƿ�Ϊ0��������򽻻���
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
		// ����Ԫ�ع�һ
		double pivot = augmentedMatrix[i][i];
		for (int j = 0; j < 2 * row; ++j) {
			augmentedMatrix[i][j] /= pivot;
		}
		// ʹ����Ԫ����ȥ������
		for (int j = 0; j < row; ++j) {
			if (j != i) {
				double factor = augmentedMatrix[j][i];
				for (int k = 0; k < 2 * row; ++k) {
					augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
				}
			}
		}
	}
	// ��ȡ�����
	jhMatrix inverse(row, column);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			inverse.matrix[i][j] = augmentedMatrix[i][j + row];
		}
	}
	// �ͷ��ڴ�
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

// ����ӷ�
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

// �������
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

// ����˷�
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

// ����������˷�
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

jhObject2D::transform::transform()
{
	position = jhVector2(0, 0);
}

float jhObject2D::transform::getDistance(const transform& other)
{
	return this->position.destance(other.position);
}

jhObject2D::circle::circle(float radius):transform()
{
	this->radius = radius;
}

float jhObject2D::circle::getAreaSize()
{
	return PI * this->radius * this->radius;
}

bool jhObject2D::circle::isTrigleEnter(const triangle& other)
{
	//Բ���������ε���ײ���
	float a = this->position.destance(other.pointA)-radius;
	float b = this->position.destance(other.pointB)-radius;
	float c = this->position.destance(other.pointC)-radius;
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	if (s == 0)
		return true;
	else
		return false;
}

bool jhObject2D::circle::isTrigleEnter(const rectangle& other)
{
	//Բ������ε���ײ���
	float x = this->position.x;
	float y = this->position.y;
	float x1 = other.position.x - other.width / 2;
	float x2 = other.position.x + other.width / 2;
	float y1 = other.position.y - other.height / 2;
	float y2 = other.position.y + other.height / 2;
	if (x+radius >= x1 && x-radius <= x2 && y+radius >= y1 && y-radius <= y2)
		return true;
	else
		return false;
}

bool jhObject2D::circle::isTrigleEnter(const diamond& other)
{
	//Բ�������δ��Ե���ײ���
	float x = this->position.x;
	float y = this->position.y;
	float x1 = other.position.x - other.lengthX / 2;
	float x2 = other.position.x + other.lengthX / 2;
	float y1 = other.position.y - other.lengthY / 2;
	float y2 = other.position.y + other.lengthY / 2;
	if (x+radius >= x1 && x-radius <= x2 && y+radius >= y1 && y-radius <= y2)
		return true;
	else
		return false;
}

bool jhObject2D::circle::isTrigleEnter(const circle& other)
{
	//Բ����Բ�ε���ײ���
	if (this->position.destance(other.position) <= this->radius + other.radius)
		return true;
	else
		return false;
}


float jhObject2D::rectangle::getAreaSize()
{
	return this->height * this->width;
}

bool jhObject2D::rectangle::isTrigleEnter(const triangle& other)
{
	//�����������ε���ײ���
	float x1 = this->position.x - this->width / 2;
	float x2 = this->position.x + this->width / 2;
	float y1 = this->position.y - this->height / 2;
	float y2 = this->position.y + this->height / 2;
	if (other.pointA.x >= x1 && other.pointA.x <= x2 && other.pointA.y >= y1 && other.pointA.y <= y2)
		return true;
	else
		if (other.pointB.x >= x1 && other.pointB.x <= x2 && other.pointB.y >= y1 && other.pointB.y <= y2)
			return true;
		else
			if (other.pointC.x >= x1 && other.pointC.x <= x2 && other.pointC.y >= y1 && other.pointC.y <= y2)
				return true;
			else
				return false;

}

bool jhObject2D::rectangle::isTrigleEnter(const rectangle& other)
{
	//��������ε���ײ���
	float x1 = this->position.x - this->width / 2;
	float x2 = this->position.x + this->width / 2;
	float y1 = this->position.y - this->height / 2;
	float y2 = this->position.y + this->height / 2;
	float x3 = other.position.x - other.width / 2;
	float x4 = other.position.x + other.width / 2;
	float y3 = other.position.y - other.height / 2;
	float y4 = other.position.y + other.height / 2;
	if (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3)
		return true;
	else
		return false;

}

bool jhObject2D::rectangle::isTrigleEnter(const diamond& other)
{
	//���������ε���ײ���
	float x1 = this->position.x - this->width / 2;
	float x2 = this->position.x + this->width / 2;
	float y1 = this->position.y - this->height / 2;
	float y2 = this->position.y + this->height / 2;
	float x3 = other.position.x - other.lengthX / 2;
	float x4 = other.position.x + other.lengthX / 2;
	float y3 = other.position.y - other.lengthY / 2;
	float y4 = other.position.y + other.lengthY / 2;
	if (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3)
		return true;
	else
		return false;

}

bool jhObject2D::rectangle::isTrigleEnter(const circle& other)
{
	//������Բ�ε���ײ���
	float x1 = this->position.x - this->width / 2;
	float x2 = this->position.x + this->width / 2;
	float y1 = this->position.y - this->height / 2;
	float y2 = this->position.y + this->height / 2;
	if (other.position.x >= x1 && other.position.x <= x2 && other.position.y >= y1 && other.position.y <= y2)
		return true;
	else
		return false;

}

jhObject2D::rectangle::rectangle(float width, float height):transform()
{
	this->width = width;
	this->height = height;
}

float jhObject2D::triangle::getAreaSize()
{
	float a = this->pointA.destance(this->pointB);
	float b = this->pointB.destance(this->pointC);
	float c = this->pointC.destance(this->pointA);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool jhObject2D::triangle::isTrigleEnter(const triangle& other)
{
	//�������������ε���ײ���
	float x1 = this->pointA.x;
	float y1 = this->pointA.y;
	float x2 = this->pointB.x;
	float y2 = this->pointB.y;
	float x3 = this->pointC.x;
	float y3 = this->pointC.y;
	float x4 = other.pointA.x;
	float y4 = other.pointA.y;
	float x5 = other.pointB.x;
	float y5 = other.pointB.y;
	float x6 = other.pointC.x;
	float y6 = other.pointC.y;
	float a = (x1 - x2) * (y4 - y1) - (x4 - x1) * (y1 - y2);
	float b = (x1 - x2) * (y5 - y1) - (x5 - x1) * (y1 - y2);
	float c = (x1 - x2) * (y6 - y1) - (x6 - x1) * (y1 - y2);
	if (a * b > 0 && a * c > 0)
		return true;
	else
	{
		a = (x2 - x3) * (y4 - y2) - (x4 - x2) * (y2 - y3);
		b = (x2 - x3) * (y5 - y2) - (x5 - x2) * (y2 - y3);
		c = (x2 - x3) * (y6 - y2) - (x6 - x2) * (y2 - y3);
		if (a * b > 0 && a * c > 0)
			return true;
		else
		{
			a = (x3 - x1) * (y4 - y3) - (x4 - x3) * (y3 - y1);
			b = (x3 - x1) * (y5 - y3) - (x5 - x3) * (y3 - y1);
			c = (x3 - x1) * (y6 - y3) - (x6 - x3) * (y3 - y1);
			if (a * b > 0 && a * c > 0)
				return true;
			else
				return false;
		}
	}

}

bool jhObject2D::triangle::isTrigleEnter(const rectangle& other)
{
	//����������ε���ײ���
	float x1 = this->pointA.x;
	float y1 = this->pointA.y;
	float x2 = this->pointB.x;
	float y2 = this->pointB.y;
	float x3 = this->pointC.x;
	float y3 = this->pointC.y;
	float x4 = other.position.x - other.width / 2;
	float x5 = other.position.x + other.width / 2;
	float y4 = other.position.y - other.height / 2;
	float y5 = other.position.y + other.height / 2;
	if (x1 >= x4 && x1 <= x5 && y1 >= y4 && y1 <= y5)
		return true;
	else
		if (x2 >= x4 && x2 <= x5 && y2 >= y4 && y2 <= y5)
			return true;
		else
			if (x3 >= x4 && x3 <= x5 && y3 >= y4 && y3 <= y5)
				return true;
			else
				return false;

}

bool jhObject2D::triangle::isTrigleEnter(const diamond& other)
{
	//�����������ε���ײ���
	float x1 = this->pointA.x;
	float y1 = this->pointA.y;
	float x2 = this->pointB.x;
	float y2 = this->pointB.y;
	float x3 = this->pointC.x;
	float y3 = this->pointC.y;
	float x4 = other.position.x - other.lengthX / 2;
	float x5 = other.position.x + other.lengthX / 2;
	float y4 = other.position.y - other.lengthY / 2;
	float y5 = other.position.y + other.lengthY / 2;
	if (x1 >= x4 && x1 <= x5 && y1 >= y4 && y1 <= y5)
		return true;
	else
		if (x2 >= x4 && x2 <= x5 && y2 >= y4 && y2 <= y5)
			return true;
		else
			if (x3 >= x4 && x3 <= x5 && y3 >= y4 && y3 <= y5)
				return true;
			else
				return false;

}

bool jhObject2D::triangle::isTrigleEnter(const circle& other)
{
	//��������Բ�ε���ײ���
	float x1 = this->pointA.x;
	float y1 = this->pointA.y;
	float x2 = this->pointB.x;
	float y2 = this->pointB.y;
	float x3 = this->pointC.x;
	float y3 = this->pointC.y;
	float x = other.position.x;
	float y = other.position.y;
	float a = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
	float b = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
	float c = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);
	if (a * b > 0 && a * c > 0)
		return true;
	else
		return false;

}

jhObject2D::triangle::triangle(jhVector2 pointA, jhVector2 pointB, jhVector2 pointC)
{
	//�������������Բ��������
	jhVector2 center;

	// �����е�����
	jhVector2 midpointAB = { (pointA.x + pointB.x) / 2, (pointA.y + pointB.y) / 2 };
	jhVector2 midpointBC = { (pointB.x + pointC.x) / 2, (pointB.y + pointC.y) / 2 };

	// ����ߵ�б��
	double slopeAB = (pointB.y - pointA.y) / (pointB.x - pointA.x);
	double slopeBC = (pointC.y - pointB.y) / (pointC.x - pointB.x);

	// �����д��ߵ�б��
	double perpendicularSlopeAB = -1 / slopeAB;
	double perpendicularSlopeBC = -1 / slopeBC;

	// �����д��ߵĽؾ�
	double interceptAB = midpointAB.y - perpendicularSlopeAB * midpointAB.x;
	double interceptBC = midpointBC.y - perpendicularSlopeBC * midpointBC.x;

	// ����Բ������
	center.x = (interceptBC - interceptAB) / (perpendicularSlopeAB - perpendicularSlopeBC);
	center.y = perpendicularSlopeAB * center.x + interceptAB;

	this->position = center;


	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
}

jhObject2D::triangle::triangle(jhVector2 center, float coLength)
{
	this->position = center;
	this->pointA = jhVector2(center.x, center.y + coLength);
	this->pointB = jhVector2(center.x + coLength * sqrt(3) / 2, center.y - coLength / 2);
	this->pointC = jhVector2(center.x - coLength * sqrt(3) / 2, center.y - coLength / 2);
}

float jhObject2D::diamond::getAreaSize()
{
	return this->lengthX * this->lengthY / 2;
}

bool jhObject2D::diamond::isTrigleEnter(const triangle& other)
{
	//�����������ε���ײ���
	float x1 = this->position.x - this->lengthX / 2;
	float x2 = this->position.x + this->lengthX / 2;
	float y1 = this->position.y - this->lengthY / 2;
	float y2 = this->position.y + this->lengthY / 2;
	if (other.pointA.x >= x1 && other.pointA.x <= x2 && other.pointA.y >= y1 && other.pointA.y <= y2)
		return true;
	else
		if (other.pointB.x >= x1 && other.pointB.x <= x2 && other.pointB.y >= y1 && other.pointB.y <= y2)
			return true;
		else
			if (other.pointC.x >= x1 && other.pointC.x <= x2 && other.pointC.y >= y1 && other.pointC.y <= y2)
				return true;
			else
				return false;

}

bool jhObject2D::diamond::isTrigleEnter(const rectangle& other)
{
	//��������ε���ײ���
	float x1 = this->position.x - this->lengthX / 2;
	float x2 = this->position.x + this->lengthX / 2;
	float y1 = this->position.y - this->lengthY / 2;
	float y2 = this->position.y + this->lengthY / 2;
	float x3 = other.position.x - other.width / 2;
	float x4 = other.position.x + other.width / 2;
	float y3 = other.position.y - other.height / 2;
	float y4 = other.position.y + other.height / 2;
	if (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3)
		return true;
	else
		return false;

}

bool jhObject2D::diamond::isTrigleEnter(const diamond& other)
{
	//���������ε���ײ���
	float x1 = this->position.x - this->lengthX / 2;
	float x2 = this->position.x + this->lengthX / 2;
	float y1 = this->position.y - this->lengthY / 2;
	float y2 = this->position.y + this->lengthY / 2;
	float x3 = other.position.x - other.lengthX / 2;
	float x4 = other.position.x + other.lengthX / 2;
	float y3 = other.position.y - other.lengthY / 2;
	float y4 = other.position.y + other.lengthY / 2;
	if (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3)
		return true;
	else
		return false;

}

bool jhObject2D::diamond::isTrigleEnter(const circle& other)
{
	//������Բ�ε���ײ���
	float x1 = this->position.x - this->lengthX / 2;
	float x2 = this->position.x + this->lengthX / 2;
	float y1 = this->position.y - this->lengthY / 2;
	float y2 = this->position.y + this->lengthY / 2;
	float x = other.position.x;
	float y = other.position.y;
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
		return true;
	else
		return false;

}

jhObject2D::diamond::diamond(float lengthX, float lengthY) : transform()
{
	this->lengthX = lengthX;
	this->lengthY = lengthY;
}

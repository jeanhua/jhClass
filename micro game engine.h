#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<easyx.h>
#include "jhClass.h"

//��Ϸ������
class GameObject
{
public:
	friend class Game;
private:
	//�Ƿ�̬
	bool isStatic;
	//��ͼ
	IMAGE* img=new IMAGE;
	//��ͼ�ļ���ַ
	LPCTSTR img_fileName;
	//λ��
	jhVector2 position;
	//����
	string name;
	//��С(��ȣ��߶�)
	jhVector2 size;
	//��ײ���С(Բ��)
	float round;
	//����
	float mass;
	//����ϵ��
	float elasticity;
	//����
	jhVector2 force;
	//�ٶ�
	jhVector2 speed;
	//�Ƿ��ڵ���
	bool isGround;
public:
	//ʩ����
	void addForce(jhVector2 v);
	//������
	void resetForce();
	//�����ٶ�
	void setSpeed(jhVector2 direction);
	//�����ٶ�
	void resetSpeed();
};

//��Ϸ��
class Game
{
private:
	//��Ϸ�����߼�
	void gamePlay();
	//�����˶�
	void objectMove(vector<GameObject*>::iterator& gameObj);
	//��ײ���
	vector<GameObject*>::iterator collisionEnter(vector<GameObject*>::iterator& gameObj);
	//��ӡ����
	void printGameObject();

public:
	//�����Ϸ���壬�����ֱ�Ϊ name:�����ʶ��img_fileName����ͼ·����position�������ʼλ�����꣬mass��������elasticity������ϵ������ȣ�reWidth���߶ȣ�reHeight
	void addObject(string name, LPCTSTR img_fileName, jhVector2 position,float mass,float elasticity, int reWidth, int reHeight,bool isStatic=false);
	//��ȡ����
	vector<GameObject*>::iterator getObject(string name);
	//ɾ������
	bool deleteObject(vector<GameObject*>::iterator gameobj);
	//��ʼ����Ϸ����
	HWND initWindow(int width, int height);
	//֡���º�������ÿһ֡����
	void update();
	//��ʼ��Ϸ
	void gameStart();
	//����֡��
	void setFrame(int frame);
	//���ñ�����
	void setScale(float scale);
private:
	//��������
	vector<GameObject*>* gameObject=new vector<GameObject*>;
	//֡���ʱ��
	long deltaTime=0;
	//Ŀ��֡��
	int targetFrame = 60;
	//������
	float scale = 10;
	//�������ٶ�
	float Gravity = 9.8;
};
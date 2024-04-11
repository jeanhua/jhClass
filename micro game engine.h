#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<easyx.h>
#include "jhClass.h"

//游戏物体类
class GameObject
{
public:
	friend class Game;
private:
	//是否静态
	bool isStatic;
	//贴图
	IMAGE* img=new IMAGE;
	//贴图文件地址
	LPCTSTR img_fileName;
	//位置
	jhVector2 position;
	//名称
	string name;
	//大小(宽度，高度)
	jhVector2 size;
	//碰撞体大小(圆形)
	float round;
	//质量
	float mass;
	//弹性系数
	float elasticity;
	//受力
	jhVector2 force;
	//速度
	jhVector2 speed;
	//是否处于地面
	bool isGround;
public:
	//施加力
	void addForce(jhVector2 v);
	//重置力
	void resetForce();
	//设置速度
	void setSpeed(jhVector2 direction);
	//重置速度
	void resetSpeed();
};

//游戏类
class Game
{
private:
	//游戏运行逻辑
	void gamePlay();
	//物体运动
	void objectMove(vector<GameObject*>::iterator& gameObj);
	//碰撞检测
	vector<GameObject*>::iterator collisionEnter(vector<GameObject*>::iterator& gameObj);
	//打印物体
	void printGameObject();

public:
	//添加游戏物体，参数分别为 name:物体标识，img_fileName：贴图路径，position：物体初始位置坐标，mass：质量，elasticity：弹性系数，宽度：reWidth，高度：reHeight
	void addObject(string name, LPCTSTR img_fileName, jhVector2 position,float mass,float elasticity, int reWidth, int reHeight,bool isStatic=false);
	//获取物体
	vector<GameObject*>::iterator getObject(string name);
	//删除物体
	bool deleteObject(vector<GameObject*>::iterator gameobj);
	//初始化游戏窗口
	HWND initWindow(int width, int height);
	//帧更新函数，在每一帧调用
	void update();
	//开始游戏
	void gameStart();
	//设置帧率
	void setFrame(int frame);
	//设置比例尺
	void setScale(float scale);
private:
	//物体容器
	vector<GameObject*>* gameObject=new vector<GameObject*>;
	//帧间隔时间
	long deltaTime=0;
	//目标帧率
	int targetFrame = 60;
	//比例尺
	float scale = 10;
	//重力加速度
	float Gravity = 9.8;
};
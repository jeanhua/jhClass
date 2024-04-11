#include "micro game engine.h"
#include "putimgPNG.h"

HWND Game::initWindow(int width, int height)
{
    return initgraph(width, height,1);
}

void Game::objectMove(vector<GameObject*>::iterator& gameObj)
{
	//位置改变
	if ((*gameObj)->isStatic == true)
		return;
	(*gameObj)->position = (*gameObj)->position + ((*gameObj)->speed * ((float)deltaTime / 1000))*scale;
	//(*gameObj)->speed = (*gameObj)->speed * 0.999;
	//动量定理 V=F*t/m
	(*gameObj)->speed = (*gameObj)->speed + (*gameObj)->force * ((float)deltaTime / 1000) / (*gameObj)->mass;
	//碰撞检测
	collisionEnter(gameObj);
}

void Game::printGameObject()
{
	for (auto it = gameObject->begin(); it!= gameObject->end(); it++)
	{
		putimagePNG((*it)->position.x, (*it)->position.y, (*it)->img);
	}
}

void Game::gamePlay()
{
	clock_t endtime=0, starttime=0;
	//游戏循环
	BeginBatchDraw();
	while (1)
	{
		endtime = clock();
		//按帧循环
		while (endtime - starttime >= 1000/targetFrame)
		{
			cleardevice();
			//遍历物体
			for (auto gameobj = gameObject->begin(); gameobj!=gameObject->end(); gameobj++)
			{
				objectMove(gameobj);
			}
			update();
			printGameObject();
			FlushBatchDraw();
			deltaTime = endtime - starttime;
			starttime = clock();
		}
	}
	EndBatchDraw();
}
//碰撞处理
jhVector2 calculateCollisionVelocity(const jhVector2& velocity1, float mass1,float elas, const jhVector2& position1,
	const jhVector2& velocity2, float mass2, const jhVector2& position2) {
	jhVector2 resultVelocity1 = velocity1;
	// 计算碰撞后相对速度
	jhVector2 relativeVelocity;
	relativeVelocity.x = velocity2.x - velocity1.x;
	relativeVelocity.y = velocity2.y - velocity1.y;
	// 计算碰撞后的法线方向
	jhVector2 normal;
	normal.x = position2.x - position1.x;
	normal.y = position2.y - position1.y;
	float normalLength = std::sqrt(normal.x * normal.x + normal.y * normal.y);
	normal.x /= normalLength;
	normal.y /= normalLength;
	// 计算法线方向上的相对速度
	float normalRelativeVelocity = relativeVelocity.x * normal.x + relativeVelocity.y * normal.y;
	// 计算质量之比
	float massRatio = mass2 / mass1;
	// 计算碰撞后的速度
	resultVelocity1.x += (2.0f * massRatio * normalRelativeVelocity * normal.x)*elas / (1 + massRatio);
	resultVelocity1.y += (2.0f * massRatio * normalRelativeVelocity * normal.y)*elas / (1 + massRatio);

	return resultVelocity1;
}
// 计算两个小球的碰撞后位置
jhVector2 calculateCollisionPosition(const jhVector2& position1, const jhVector2& velocity1, float mass1,
	const jhVector2& position2, const jhVector2& velocity2, float mass2,
	float timeStep) {
	jhVector2 newPosition1 = position1;

	// 碰撞前的相对位置
	jhVector2 relativePosition;
	relativePosition.x = position2.x - position1.x;
	relativePosition.y = position2.y - position1.y;

	// 碰撞前的相对速度
	jhVector2 relativeVelocity;
	relativeVelocity.x = velocity2.x - velocity1.x;
	relativeVelocity.y = velocity2.y - velocity1.y;

	// 计算碰撞时的相对速度模长
	float relativeSpeed = std::sqrt(relativeVelocity.x * relativeVelocity.x + relativeVelocity.y * relativeVelocity.y);

	// 碰撞方向上的单位向量
	jhVector2 collisionDirection = { relativePosition.x / relativeSpeed, relativePosition.y / relativeSpeed };

	// 更新球体位置，避免重叠
	float overlapDistance = (mass1 + mass2) * timeStep; // 碰撞后两球体之间的重叠距离
	newPosition1.x -= collisionDirection.x * overlapDistance * (mass2 / (mass1 + mass2));
	newPosition1.y -= collisionDirection.y * overlapDistance * (mass2 / (mass1 + mass2));

	return newPosition1;
}
//碰撞检测
vector<GameObject*>::iterator Game::collisionEnter(vector<GameObject*>::iterator& gameObj)
{
	//边界判断
	if ((*gameObj)->position.x<0 || (*gameObj)->position.x + (*gameObj)->size.x>getwidth())
	{
		(*gameObj)->speed.x = -(*gameObj)->speed.x * (*gameObj)->elasticity;
		if ((*gameObj)->position.x < 0)
			(*gameObj)->position.x = 0;
		else
			(*gameObj)->position.x = getwidth() - (*gameObj)->size.x;
	}
	else if ((*gameObj)->position.y<0 || (*gameObj)->position.y + (*gameObj)->size.y>getheight())
	{
		if ((*gameObj)->position.y + (*gameObj)->size.y > getheight())
			(*gameObj)->speed.y = -(*gameObj)->speed.y * (*gameObj)->elasticity*(*gameObj)->elasticity;
		else
			(*gameObj)->speed.y = -(*gameObj)->speed.y * (*gameObj)->elasticity;
		if ((*gameObj)->position.y < 0)
			(*gameObj)->position.y = 0;
		else
			(*gameObj)->position.y = getheight() - (*gameObj)->size.y;
	}
	for (auto it = gameObject->begin(); it != gameObject->end(); it++)
	{
		jhVector2 middle2 = jhVector2((*it)->position.x + (*it)->size.x / 2, (*it)->position.y + (*it)->size.y / 2);
		jhVector2 middle1 = jhVector2((*gameObj)->position.x + (*gameObj)->size.x / 2, (*gameObj)->position.y + (*gameObj)->size.y / 2);
		jhVector2 position1 = (*gameObj)->position;
		jhVector2 position2 = (*it)->position;
		if (it!=gameObj && middle1.destance(middle2) <= (*it)->round + (*gameObj)->round)
		{
			cout << middle1.destance(middle2)<< " 发生碰撞！" << endl;
			jhVector2 v1_0 = (*gameObj)->speed;
			jhVector2 v2_0 = (*it)->speed;
			(*gameObj)->speed = calculateCollisionVelocity(v1_0, (*gameObj)->mass, (*gameObj)->elasticity,middle1, v2_0, (*it)->mass, middle2);
			(*it)->speed = calculateCollisionVelocity(v2_0, (*gameObj)->mass,(*it)->elasticity, middle2, v1_0, (*it)->mass, middle1);
			(*gameObj)->position = calculateCollisionPosition(position1, v1_0, (*gameObj)->mass, position2, v2_0, (*it)->mass, (float)deltaTime / 1000);
			(*it)->position = calculateCollisionPosition(position2, v2_0, (*it)->mass, position1, v1_0, (*gameObj)->mass, (float)deltaTime/1000);
			return it;
		}
	}
}
void Game::addObject(string name, LPCTSTR img_fileName, jhVector2 position, float mass, float elasticity,int reWidth, int reHeight,bool isStatic)
{
	GameObject *tmpdata=new GameObject;
	tmpdata->position = position;
	tmpdata->mass = mass;
	tmpdata->isStatic = isStatic;
	tmpdata->img_fileName = img_fileName;
	tmpdata->elasticity = elasticity;
	jhVector2 size = jhVector2(reWidth, reHeight);
	tmpdata->size = size;
	tmpdata->name = name;
	tmpdata->round = (tmpdata->size.x + tmpdata->size.y) / 4-11;
	loadimage(tmpdata->img, img_fileName, size.y, size.x);
	gameObject->push_back(tmpdata);
}

vector<GameObject*>::iterator Game::getObject(string name)
{
	for (auto it = gameObject->begin(); it != gameObject->end(); it++)
	{
		if ((*it)->name == name)
		{
			return it;
		}
	}
	return gameObject->end();
}

bool Game::deleteObject(vector<GameObject*>::iterator gameobj)
{
	for (auto it = gameObject->begin(); it != gameObject->end(); it++)
	{
		if (it==gameobj)
		{
			delete* it;
			gameObject->erase(it);
			return true;
		}
	}
	return false;
}

void Game::gameStart()
{
	gamePlay();
}

void Game::setFrame(int frame)
{
	if (frame > 0)
		targetFrame = frame;
	else
		targetFrame = 60;
}


void Game::setScale(float scale)
{
	this->scale = scale;
}

void GameObject::addForce(jhVector2 v)
{
	force += v;
}

void GameObject::resetForce()
{
	this->force = jhVector2(0, 0);
}

void GameObject::setSpeed(jhVector2 direction)
{
	speed = direction;
}

void GameObject::resetSpeed()
{
	speed = jhVector2(0,0);
}


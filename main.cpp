#include "micro game engine.h"

int main()
{
	//������Ϸ����
	Game game;
	//���ƴ���
	game.initWindow(1000, 800);
	game.setFrame(165);
	float ela = 0.95;
	game.addObject("dola", "./Doraemon.png", jhVector2(0, 300), 1, ela,100, 100);
	game.addObject("xiaoxin", "./xiaoxin.png", jhVector2(650, 300), 1, ela, 100, 100);
	game.addObject("cat", "./cat.png", jhVector2(800, 200), 1, ela, 100, 100);
	game.addObject("pkq", "./pkq.png", jhVector2(800, 400), 1, ela, 100, 100);
	(*game.getObject("dola"))->setSpeed(jhVector2(200, 10));
	/*game.getObject("dola")->addForce(jhVector2(0, 100));
	game.getObject("xiaoxin")->addForce(jhVector2(0,100));
	game.getObject("cat")->addForce(jhVector2(0,100));
	game.getObject("pkq")->addForce(jhVector2(0,100));*/
	//��ʼ��Ϸ
	game.gameStart();
}

//ÿ֡����һ��
void Game::update()
{
	char dtt[30];
	sprintf(dtt, "deltatime:%ld",deltaTime);
	cleardevice();
	outtextxy(0, 0,dtt);
}


#pragma once
#include "gamestatebase.h"
#include <list>
#include <cstdlib>

class Sprite2D;
class Sprite3D;
class Text;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();
	
	void SetNewPostionForBullet();

private:
	void DrawPipe();
	void UpdatePipePosition(float deltaTime);

	std::shared_ptr<Bird> m_Bird;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_score;
	std::list<std::shared_ptr<Sprite2D>> m_pipes;
	int _score;
	int _pipeCount;
	float _pipeSpace;
	int _pipeW;
	float _pipeSpeed;
	int _pipeLevel;
};


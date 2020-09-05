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
	void CheckScore();
	bool CheckCollision(Vector2 pipePosition);
	std::shared_ptr<Bird> m_Bird;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_score;
	std::list<std::shared_ptr<Sprite2D>> m_pipes;
	std::shared_ptr<Sprite2D> m_temp;
	std::shared_ptr<Sprite2D> m_tempPipe;
	int _score;
	int _pipeCount;
	float _pipeSpace;
	int _pipeW;
	float _pipeSpeed;
	int _pipeLevel;
	bool _endGame;
	//int _pipeSizeW;
	//int _pipeSizeH;
	Mix_Chunk* pointSound;
	Mix_Chunk* wingSound;
	Mix_Chunk* hitSound;
};


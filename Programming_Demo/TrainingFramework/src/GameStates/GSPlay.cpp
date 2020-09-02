#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	_score = 0;
	_pipeCount = 4;
	_pipeSpace = 200;
	_pipeW = 150;
	_pipeSpeed = 50;
	_pipeLevel = 100;

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background-day");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, "score: " + _score, TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//pipe
	DrawPipe();

	//bird
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("yellowbird-midflap");
	auto up_texture = ResourceManagers::GetInstance()->GetTexture("yellowbird-upflap");
	auto down_texture = ResourceManagers::GetInstance()->GetTexture("yellowbird-downflap");
	m_Bird = std::make_shared<Bird>(model, shader, texture);
	m_Bird->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_Bird->SetSize(50, 50);
	m_Bird->SetTextureState(down_texture, up_texture, texture);
	m_Bird->AddForce(1400);
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{
	
}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (bIsPressed) {
		m_Bird->AddForce(1400);
	}
}

void GSPlay::Update(float deltaTime)
{
	m_Bird->Update(deltaTime);
	UpdatePipePosition(deltaTime);
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	for (auto pipe : m_pipes) {
		pipe->Draw();
	}
	m_Bird->Draw();
	m_score->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}

void GSPlay::DrawPipe() 
{
	float startPos = screenWidth;
	int rand_y = 100;
	int w = screenWidth / 8;
	int h = screenHeight / 1.3;
	for (int i = 0; i < _pipeCount; i++) {

		rand_y = rand() % (screenHeight / 2) + _pipeLevel - h / 2;

		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
		auto texture = ResourceManagers::GetInstance()->GetTexture("pipe-green");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

		auto pipe = std::make_shared<Sprite2D>(model, shader, texture);
		pipe->Set2DPosition(startPos, rand_y);
		pipe->SetSize(screenWidth / 8, screenHeight / 1.3);

		texture = ResourceManagers::GetInstance()->GetTexture("pipe-green_2");
		auto pipe2 = std::make_shared<Sprite2D>(model, shader, texture);
		pipe2->Set2DPosition(startPos, rand_y + _pipeW + h);
		pipe2->SetSize(w, h);

		m_pipes.push_back(pipe);
		m_pipes.push_back(pipe2);
		startPos += _pipeSpace;
	}
}

void GSPlay::UpdatePipePosition(float deltaTime)
{
	int w = screenWidth / 8;
	int h = screenHeight / 1.3;
	int rand_y = 100;

	float lastX = m_pipes.back()->Get2DPosition().x;
	int count = 0;

	for (auto pipe : m_pipes) {
		// update x
		if (pipe->Get2DPosition().x < -w) {
			float x = lastX + _pipeSpace;
			float y = pipe->Get2DPosition().y;

			// update y
			if (count % 2 == 0) {
				rand_y = rand() % (screenHeight / 2) + _pipeLevel - h / 2;
				y = rand_y;
			}
			else {
				y = rand_y + _pipeW + h;
			}
			pipe->Set2DPosition(x, y);
		}
		else {
			float x = pipe->Get2DPosition().x;
			x -= _pipeSpeed * deltaTime;
			pipe->Set2DPosition(x, pipe->Get2DPosition().y);
		}
		if (count % 2 != 0) {
			lastX = pipe->Get2DPosition().x;
		}
		count += 1;
	}
}
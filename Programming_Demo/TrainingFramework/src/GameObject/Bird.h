#pragma once
#include "Sprite2D.h"
#include "Texture.h"

class Bird : public Sprite2D
{
public:
	Bird(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture) : Sprite2D(model, shader, texture) { };
	Bird(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, Vector4 color) : Sprite2D(model, shader, color) {  };
	void Update(float deltaTime);
	void AddForce(float force);
	void SetTextureState(std::shared_ptr<Texture> up, std::shared_ptr<Texture> down, std::shared_ptr<Texture> idle);
	void SetDie();
private:
	void ApplyAnimation(float param);
	float m_Gravity = 1000;
	float m_Force = 0;
	std::shared_ptr<Texture> up_Texture;
	std::shared_ptr<Texture> down_Texture;
	std::shared_ptr<Texture> idle_Texture;
};
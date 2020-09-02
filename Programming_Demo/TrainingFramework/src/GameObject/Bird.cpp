#include "Bird.h"

extern GLint screenWidth;
extern GLint screenHeight;

void Bird::AddForce(float force) {
	m_Force = force;
}
void Bird::Update(float deltaTime) {
	float pos_y = Get2DPosition().y;
	float total_force = m_Force - m_Gravity;
	pos_y -= total_force * deltaTime;
	pos_y = pos_y > screenHeight ? screenHeight : pos_y;

	Set2DPosition(Get2DPosition().x, pos_y);

	m_Force -= m_Gravity * deltaTime;
	m_Force = m_Force > 0 ? m_Force : 0;

	ApplyAnimation(total_force);
}

void Bird::ApplyAnimation(float param)
{
	if (param > 50) SetTexture(up_Texture);
	else if (param < -50) SetTexture(down_Texture);
	else SetTexture(idle_Texture);
}

void Bird::SetTextureState(std::shared_ptr<Texture> up, std::shared_ptr<Texture> down, std::shared_ptr<Texture> idle) 
{
	this->up_Texture = up;
	this->down_Texture = down;
	this->idle_Texture = idle;
}
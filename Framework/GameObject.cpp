// project includes
#include "GameObject.h"

GameObject::GameObject()
	: m_active(true)
{

}

void GameObject::Draw(sf::RenderTarget& _target)
{

}

void GameObject::Update(sf::Time _frameTime)
{

}

sf::FloatRect GameObject::GetBounds()
{
	return sf::FloatRect();
}
void GameObject::Collide(GameObject& _collider)
{

}

bool GameObject::IsActive()
{
	return m_active;
}

void GameObject::SetPosition(sf::Vector2f _position)
{

}

void GameObject::SetPosition(float _x, float _y)
{

}

sf::Vector2f GameObject::GetPosition()
{
	return sf::Vector2f();
}
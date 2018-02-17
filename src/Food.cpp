#include "Food.h"
#include <iostream>

// The food must be a rectangle with width == height.
Food::Food(sf::Vector2f size,sf::Vector2f pos, sf::Color color, sf::Texture* t)
:size(size), foodColor(color)
{
    food.setPosition(pos);
    food.setSize(size);
    if (t)
    {
        food.setTexture(t);
        food.setTextureRect(sf::IntRect(0,0,t->getSize().x/4,t->getSize().y/4));
    }
    else
        food.setFillColor(foodColor);

}

void Food::draw(sf::RenderWindow& w)
{
    w.draw(food);
}

void Food::moveTo(sf::Vector2f pos)
{
    food.setPosition(pos);
}

sf::Vector2f const& Food::getPos()const
{
    return food.getPosition();
}

sf::Vector2f const& Food::getSize()const
{
    return size;
}

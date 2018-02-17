#include "Snake.h"
#include <iostream>

// The snake parts must be rectangles with width == height.
Snake::Snake(sf::Vector2f size,sf::Vector2f pos, sf::Color color, float updateTime)
:size(size),snakeColor(color), updateTime(updateTime), speed(size.x)
{
    // create the head of the snake
    totalTime = 0.0f;
    grow();
    body[0].setPosition(pos);
}

void Snake::draw(sf::RenderWindow& w, float deltaTime)
{
    totalTime += deltaTime;
    if (totalTime >= updateTime)
    {
        totalTime -= updateTime;
        for (sf::RectangleShape& bodyPart : body)
            w.draw(bodyPart);
    }
}

void Snake::grow()
{
    sf::RectangleShape newPart(size);
    newPart.setFillColor(snakeColor);
    if (body.size() > 0)
        newPart.setPosition(body[0].getPosition());
    body.push_back(newPart);
}

bool Snake::moveTo(sf::Vector2f windowSize, Direction d)
{

    sf::Vector2f temp = body[0].getPosition();
    if (d == idle)
        return true;
    else if (d == up)
    {
        if (temp.y - speed >= 0)
                temp.y -= speed;
    }else if (d == down)
    {
        if (temp.y + speed < windowSize.y)
                temp.y += speed;
    }else if (d == left)
    {
        if (temp.x - speed >= 0)
                temp.x -= speed;
    }else if (d == right)
    {
        if (temp.x + speed < windowSize.x)
                temp.x += speed;
    }
    // Check if the snake is out of bounds.
    if (body[0].getPosition() == temp)
        return false;
    // Check if the snake eats itself.
    for (size_t i = 1; i < body.size(); ++i)
        if (temp == body[i].getPosition())
            return false;

    for (sf::RectangleShape& bodyPart : body)
    {
        sf::Vector2f nextPos = bodyPart.getPosition();
        bodyPart.setPosition(temp);
        temp = nextPos;
    }

    return true;
}

bool Snake::eats(Food food)
{
    return body[0].getPosition() == food.getPos();
}

sf::Vector2f const& Snake::getPos()const
{
    return body[0].getPosition();
}

sf::Vector2f const& Snake::getSize()const
{
    return size;
}

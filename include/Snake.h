#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Graphics.hpp"
#include "Food.h"


class Snake
{
    public:
        enum Direction
        {
            up, down, left, right, idle
        };

        Snake(sf::Vector2f size, sf::Vector2f pos, sf::Color color, float updateTime = 0.00001f);
        void draw(sf::RenderWindow& w,float deltaTime);
        void grow();
        bool moveTo(sf::Vector2f windowSize,Direction d);
        bool eats(Food food);
        sf::Vector2f const& getPos()const;
        sf::Vector2f const& getSize()const;
    private:
        std::vector<sf::RectangleShape> body;
        sf::Vector2f size;
        sf::Color snakeColor;
        float totalTime, updateTime;
        const float speed;
};

#endif // SNAKE_H

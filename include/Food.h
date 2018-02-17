#ifndef FOOD_H
#define FOOD_H

#include "Graphics.hpp"

class Food
{
    public:
        Food(sf::Vector2f size, sf::Vector2f pos, sf::Color color, sf::Texture* t = nullptr);
        void draw(sf::RenderWindow& w);
        void moveTo(sf::Vector2f pos);
        sf::Vector2f const& getPos()const;
        sf::Vector2f const& getSize()const;
    private:
        sf::RectangleShape food;
        sf::Vector2f size;
        sf::Color foodColor;
};

#endif // FOOD_H

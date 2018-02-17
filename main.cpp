#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "RandomGenerator.h"

constexpr unsigned WIDTH = 800, HEIGHT = 600;


int main()
{
    util::RandomGenerator rg;

    sf::Text scoreScreen;
    scoreScreen.setPosition(sf::Vector2f(0.0f, (float)HEIGHT));
    sf::Font font;
    font.loadFromFile("media/rm_typerighter_medium.ttf");
    scoreScreen.setFont(font);

    sf::RenderWindow window(sf::VideoMode(WIDTH+scoreScreen.getCharacterSize(),HEIGHT+scoreScreen.getCharacterSize()), "Snake Game");

    if (!window.isOpen())
    {
        std::cerr << "Error: Could not open the window!" << std::endl;
        return 1;
    }

    window.setFramerateLimit(8);

    sf::Texture t;
    t.loadFromFile("media/Greedy_Mouse.png");

    Snake snake(sf::Vector2f(35.f,35.f),sf::Vector2f(0.0f,0.0f),sf::Color(255,255,255));
    Food food(sf::Vector2f(35.0f,35.0f), sf::Vector2f(0.0f,0.0f), sf::Color(255,0,0),&t);

    food.moveTo(sf::Vector2f(((float)(rg.randomInt(0, (WIDTH-food.getSize().x)/food.getSize().x))*food.getSize().x),(float)(rg.randomInt((HEIGHT-food.getSize().y)/food.getSize().y))*food.getSize().y));

    Snake::Direction direction = Snake::idle;
    sf::Clock clock;
    int score = 0;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            direction = Snake::left;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            direction = Snake::right;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            direction = Snake::up;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            direction = Snake::down;

        window.clear();

        if (!snake.moveTo(static_cast<sf::Vector2f>(window.getSize()) , direction))
            break;

        if (snake.eats(food))
        {
            snake.grow();
            sf::Vector2f newPos((float)(rg.randomInt((WIDTH-food.getSize().x)/food.getSize().x)*food.getSize().x),(float)(rg.randomInt((HEIGHT-food.getSize().y)/food.getSize().y)*food.getSize().y));
            score += 100;
            food.moveTo(newPos);
        }

        scoreScreen.setString("SCORE: " + std::to_string(score));

        window.draw(scoreScreen);
        snake.draw(window,deltaTime);
        food.draw(window);
        window.display();
    }

    return 0;
}

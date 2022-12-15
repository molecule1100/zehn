#include <SFML/Graphics.hpp>

class Figure
{

public:

    float x, y, speed = 0;
    sf::CircleShape circle;
    sf::RectangleShape rectangle;


    Figure(int X, int Y, sf::CircleShape Circle)
    {
        y = Y;
        x = X;
        circle = Circle;
    }

    Figure(int X, int Y, sf::RectangleShape Rectangle)
    {
        y = Y;
        x = X;
        rectangle = Rectangle;
    }


    void Update(float time)
    {
        if ((650 + circle.getRadius() > y) && (650 > y))
        {
            y += speed * time;

            speed = 0;

            circle.setPosition(x, y - rectangle.getSize().y - circle.getRadius() * 2);
            rectangle.setPosition(x - rectangle.getSize().x - circle.getRadius() * 2, y - rectangle.getSize().y - circle.getRadius() * 2);
        }
    }

};

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 650), "10 lab", sf::Style::Default, settings);

    sf::CircleShape shape(75.f);
    sf::RectangleShape rectangle(sf::Vector2f(150, 220));

    shape.setFillColor(sf::Color::Blue);
    rectangle.setFillColor(sf::Color::Red);

    Figure figure1(0, 0, shape);
    Figure figure2(550, 0, rectangle);

    sf::Clock clock;


    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }

        figure1.speed = 0.25;
        figure1.Update(time);

        figure2.speed = 0.35;
        figure2.Update(time);

        window.clear(sf::Color(22, 27, 34, 0));
        window.draw(figure1.circle);
        window.draw(figure2.rectangle);
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kairos' Window");

    // --- Load texture ---
    sf::Texture texture;
    if (!texture.loadFromFile("res/image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "No image for texture\n";
    }

    // --- Render to texture ---
    sf::RenderTexture renderTexture;
    renderTexture.create(800, 600);

    sf::Sprite sprite(texture);

    renderTexture.clear(sf::Color::Transparent);
    renderTexture.draw(sprite);
    renderTexture.display();

    sf::Sprite finalSprite(renderTexture.getTexture());

    // --- Load font and prepare text ---
    sf::Font font;
    if (!font.loadFromFile("res/font.ttf"))
        std::cout << "Could not load font\n";

    sf::Text text("Hello world", font, 24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    // --- Main loop ---
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(finalSprite);
        window.draw(text);

        window.display();
    }
}

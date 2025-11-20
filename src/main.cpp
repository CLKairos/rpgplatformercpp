#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kairos' Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    sf::Texture texture;
    if (!texture.loadFromFile("res/image.png", false, sf::IntRect({10, 10}, {32, 32})))
    {
        std::cout << "No image for texture";
    }

    // create a 500x500 render-texture
    sf::RenderTexture renderTexture({500, 500});

    // drawing uses the same functions
    texture.clear();
    texture.draw(sprite); // or any other drawable
    texture.display();

    // draw it to the window
    sf::Sprite sprite(texture);
    window.draw(sprite);

    sf::Text text(font); // a font is required to make a text object

    // set the string to display
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    ...

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);
}

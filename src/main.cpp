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

    // create a 500x500 render-texture
    sf::RenderTexture renderTexture({500, 500});

    // drawing uses the same functions
    renderTexture.clear();
    renderTexture.draw(sprite); // or any other drawable
    renderTexture.display();

    // get the target texture (where the stuff has been drawn)
    const sf::Texture& texture = renderTexture.getTexture();

    // draw it to the window
    sf::Sprite sprite(texture);
    window.draw(sprite);
}

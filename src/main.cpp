#include "functions.h"

int main()
{
    

    // create the window
    const auto screen = sf::VideoMode::getDesktopMode().size;
    sf::RenderWindow window(sf::VideoMode({(screen.x - 100) - (screen.x - 100) % 9, (screen.y - 148) - (screen.y - 148) % 9}), "Game of Life");
    const auto size = window.getSize();

    window.setPosition({
    (static_cast<int>(screen.x) - static_cast<int>(size.x)) / 2,
    ((static_cast<int>(screen.y) - static_cast<int>(size.y)) / 2) - 48
    });

    std::cout << size.x << " " << size.y << std::endl;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        //window.clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }

            if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {

                if (mouse->button == sf::Mouse::Button::Left)
                {
                    c_square(window, mouse->position.x, mouse->position.y);
                }
            }
        }

        // end the current frame
        window.display();
    }
}
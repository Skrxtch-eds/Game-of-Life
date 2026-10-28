#include "functions.h"

void c_square(sf::RenderWindow& window, int mouse_x, int mouse_y) {
    //std::cout << mouse_x << "\n" << mouse_y << "\n";
    
    mouse_x = (float)((mouse_x) - (mouse_x % 9));
    mouse_y = (float)((mouse_y) - (mouse_y % 9));

    sf::RectangleShape square({9.f, 9.f});
    square.setPosition({mouse_x, mouse_y});
    square.setFillColor(sf::Color::White);

    sf::RectangleShape centre({1.f, 1.f});
    centre.setPosition({mouse_x + 4, mouse_y + 4});
    centre.setFillColor(sf::Color::Red);

    window.draw(square);
    window.draw(centre);

}
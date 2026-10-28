#include "functions.h"

void c_square(sf::RenderWindow& window, int x, int y) {
    //std::cout << mouse_x << "\n" << mouse_y << "\n";
    
    x = (float)((x) - (x % 9));
    y = (float)((y) - (y % 9));

    sf::RectangleShape square({9.f, 9.f});
    square.setPosition({x, y});
    square.setFillColor(sf::Color::White);

    window.draw(square);
}

void c_point(std::vector<bool>* field, int width, int mouse_x, int mouse_y) {
    mouse_x = ((mouse_x) - (mouse_x % 9)) / 9;
    mouse_y = ((mouse_y) - (mouse_y % 9)) / 9;

    // std::cout << mouse_x << " " << mouse_y << std::endl;

    (*field)[(mouse_y * width) + mouse_x] = !(*field)[(mouse_y * width) + mouse_x];
}

void update_field(sf::RenderWindow& window, std::vector<bool>* field, int width) {
    sf::RectangleShape square({9.f, 9.f});

    for (int i = 0; i < field->size(); i++) {
        if ((*field)[i] == true) {
            square.setFillColor(sf::Color::White);
            int x = (i % width) * 9;
            int y = (i / width) * 9;

            square.setPosition({x, y});
            window.draw(square);
        } else {
            square.setFillColor(sf::Color::Black);
            int x = (i % width) * 9;
            int y = (i / width) * 9;

            square.setPosition({x, y});
            window.draw(square);
        }
        
    }
}
#include "functions.h"

void c_point(std::vector<bool>* field, int width, int mouse_x, int mouse_y) {
    mouse_x = ((mouse_x) - (mouse_x % 9)) / 9;
    mouse_y = ((mouse_y) - (mouse_y % 9)) / 9;

    // std::cout << mouse_x << " " << mouse_y << std::endl;

    (*field)[(mouse_y * width) + mouse_x] = !(*field)[(mouse_y * width) + mouse_x];
}

void rendering_field(sf::RenderWindow& window, std::vector<bool>* field, int width) {
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

void next_generation( std::vector<bool>* field_0,  std::vector<bool>* field_1, int width) {
    for (int i = 0; i < field_0->size(); i++) {
        int count = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {

                int x = i % width + dx;
                int y = i / width + dy;

                if ((dx != 0 || dy != 0) && 
                    (x >= 0 && x < width) &&
                    (y >= 0 && y < field_0->size() / width) &&
                    (*field_0)[i + dy * width + dx]) {
                    count++;
                }
            }
        }
        switch (count)
        {
        case 2:
            (*field_1)[i] = (*field_0)[i];
            break;

        case 3:
            (*field_1)[i] = true;
            break;

        default:
            (*field_1)[i] = false;
            break;
        }
    }
}
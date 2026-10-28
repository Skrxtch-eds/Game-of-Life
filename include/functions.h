#include <iostream>
#include <SFML/Graphics.hpp>

/* Создает квадрат на экране */
void c_square(sf::RenderWindow& window, int x, int y);

/* расчитывает клетку, в которой нахоится указатель мыши и при клике присваивает ей значение 1 */
void c_point(std::vector<bool>* field, int width, int mouse_x, int mouse_y);

/* обновляет изобраение по таблице */
void update_field(sf::RenderWindow& window, std::vector<bool>* field, int width);
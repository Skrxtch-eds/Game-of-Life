#include <iostream>
#include <SFML/Graphics.hpp>

/* расчитывает клетку, в которой нахоится указатель мыши и при клике инвертирует ее значение (0/1) */
void c_point(std::vector<bool>* field, int width, int mouse_x, int mouse_y);

/* обновляет изображение по таблице */
void rendering_field(sf::RenderWindow& window, std::vector<bool>* field, int width);

/* строит вектор 2-го поколения*/
void next_generation( std::vector<bool>* field_0,  std::vector<bool>* field_1, int width);
#include "functions.h"

int main() {

    //  получение размера экрана screen.x screen.y
    const auto screen = sf::VideoMode::getDesktopMode().size;

    // создание window
    sf::RenderWindow window(sf::VideoMode({(screen.x - 100) - (screen.x - 100) % 9, (screen.y - 148) - (screen.y - 148) % 9}), "Game of Life");
    
    // получение размера окна size.x size.y
    const auto size = window.getSize();
    // перемещение окна на центр экрана
    window.setPosition({
    (static_cast<int>(screen.x) - static_cast<int>(size.x)) / 2,
    ((static_cast<int>(screen.y) - static_cast<int>(size.y)) / 2) - 48});

    // вывод размера окна
    //std::cout << size.x << " " << size.y << std::endl;

    // задание иконки
    sf::Image icon;

    if (icon.loadFromFile("assets/icon.png")) {

        window.setIcon(icon.getSize(), icon.getPixelsPtr());
    }
    
    // основная программа

    const int height = size.y / 9; // количество строк таблицы
    const int width = size.x / 9; //количество столбцов таблицы

    std::vector<bool> field_0(height * width, 0);
    std::vector<bool> field_1(height * width, 0);

    bool run = false;
    sf::Clock timer;

    // выполнение команд, пока окно открыто
    while (window.isOpen()) {

        // проверка и выполнение в порядке очереди всех event в window 
        while (const std::optional event = window.pollEvent()) {

            // закрытие программы, при нажатии на крестик
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            // создание квадрата при нажатии lbm
            if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {

                if (mouse->button == sf::Mouse::Button::Left) {

                    c_point(&field_0, width, mouse->position.x, mouse->position.y);
                    g_rendering_field(window, &field_0, width);
                }
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {

                if (key->code == sf::Keyboard::Key::Space) {

                    next_generation(&field_0, &field_1, width);
                    field_0 = field_1;
                    g_rendering_field(window, &field_0, width);
                }
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {

                if (key->code == sf::Keyboard::Key::Enter) {

                    run = !run;
                    timer.restart();
                }
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {

                if (key->code == sf::Keyboard::Key::Escape) {

                    window.clear();
                    std::fill(field_0.begin(), field_0.end(), false);
                }
            }

        }

        if (run) {
            if (timer.getElapsedTime().asSeconds() >= 0.05f) {

                next_generation(&field_0, &field_1, width);
                field_0 = field_1;
                rendering_field(window, &field_0, width);
                timer.restart();
            }
        } else {
            g_rendering_field(window, &field_0, width);
        }

        window.display();
    }
}
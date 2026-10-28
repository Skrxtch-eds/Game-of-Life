#include "functions.h"

int main()
{
    //  получение размера экрана screen.x screen.y
    const auto screen = sf::VideoMode::getDesktopMode().size;

    // создание window
    sf::RenderWindow window(sf::VideoMode({(screen.x - 100) - (screen.x - 100) % 9, (screen.y - 148) - (screen.y - 148) % 9}), "Game of Life");
    
    // получение размера окна size.x size.y
    const auto size = window.getSize();
    // перемещение окна на центр экрана
    window.setPosition({
    (static_cast<int>(screen.x) - static_cast<int>(size.x)) / 2,
    ((static_cast<int>(screen.y) - static_cast<int>(size.y)) / 2) - 48
    });
    //вывод размера окна
    //std::cout << size.x << " " << size.y << std::endl;

    //задание иконки
    sf::Image icon;

    if (icon.loadFromFile("assets/icon.png"))
    {
        window.setIcon(icon.getSize(), icon.getPixelsPtr());
    }
    
    // выполнение команд, пока окно открыто
    while (window.isOpen())
    {
        //window.clear(sf::Color::Black);

        // проверка и выполнение в порядке очереди всех event в window 
        while (const std::optional event = window.pollEvent())
        {
            // закрытие программы, при нажатии на крестик
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }
            
            //создание квадрата при нажатии lbm
            if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {

                if (mouse->button == sf::Mouse::Button::Left)
                {
                    c_square(window, mouse->position.x, mouse->position.y);
                }
            }
        }

        // вывод этого экрана
        window.display();
    }
}
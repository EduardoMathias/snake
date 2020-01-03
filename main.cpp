#include "screen.hpp"
#include "objects.hpp"

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <random>

constexpr int delay = 80000;

pos spawnFood(std::uniform_int_distribution<std::mt19937::result_type> dist_x,
               std::uniform_int_distribution<std::mt19937::result_type> dist_y,
               std::mt19937 rng)
{
    return {dist_x(rng), dist_y(rng)};
}

int main(void)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist_x(1, 99);
    std::uniform_int_distribution<std::mt19937::result_type> dist_y(1, 37);
    auto scr = new Screen::Screen();
    if (!scr->enoughSize())
    {
        delete scr;
        std::cerr << "O terminal precisa ter pelo menos 38x100!" << std::endl;
        return 1;
    }
    auto snake = new Objects::Snake(scr->width / 2, scr->height / 2);
    int key;
    int y_dir = 0, x_dir = 1;
    auto food = spawnFood(dist_x, dist_y, rng);
    while ((key = getch()) != 'q')
    {
        clear();
        scr->drawBox();
        switch (key)
        {
        case KEY_LEFT:
            if (x_dir != 1)
            {
                x_dir = -1;
                y_dir = 0;
            }
            break;
        case KEY_RIGHT:
            if (x_dir != -1)
            {
                x_dir = 1;
                y_dir = 0;
            }
            break;
        case KEY_UP:
            if (y_dir != 1)
            {
                y_dir = -1;
                x_dir = 0;
            }
            break;
        case KEY_DOWN:
            if (y_dir != -1)
            {
                y_dir = 1;
                x_dir = 0;
            }
        }
        if (!snake->move(x_dir, y_dir))
            mvprintw(scr->height / 2, scr->width / 2 - 4, "Gameover");
        else
            snake->draw();
        mvprintw(food.y, food.x, "x");
        refresh();
        usleep(delay);
    }
    delete scr;
    return 0;
}
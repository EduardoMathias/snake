#include "screen.hpp"
#include "objects.hpp"

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

constexpr int delay = 80000;

int main(void)
{
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
    while ((key = getch()) != 'q')
    {
        clear();
        scr->drawBox();
        switch (key)
        {
        case KEY_LEFT:
            x_dir = -1;
            y_dir = 0;
            break;
        case KEY_RIGHT:
            x_dir = 1;
            y_dir = 0;
            break;
        case KEY_UP:
            y_dir = -1;
            x_dir = 0;
            break;
        case KEY_DOWN:
            y_dir = 1;
            x_dir = 0;
        }
        snake->move(x_dir, y_dir);
        for (auto &part : snake->positions)
        {
            mvprintw(part.y, part.x, "o");
        }
        mvprintw(snake->head()->y, snake->head()->x, "@");
        refresh();
        usleep(delay);
    }
    delete scr;
    return 0;
}
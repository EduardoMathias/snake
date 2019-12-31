#include "objects.hpp"

namespace Objects
{

Snake::Snake(int _x, int _y)
{
    _head = {_x, _y};
    for(auto i = 1; i <= 10; i++)
    {
        positions.push_back({_x - i, _y});
    }
    
}

Snake::~Snake()
{
}

pos *Snake::head()
{
    return &_head;
}

pos *Snake::tail()
{
    return &positions.back();
}

void Snake::move(int x_dir, int y_dir)
{
    auto head = this->head();
    auto prev = *head;
    head->x += x_dir;
    if(head->x >= 99)
    {
        head->x = 1;
    }
    else if (head->x < 0)
    {
        head->x = 98;
    }
    if(head->y >= 37)
    {
        head->y = 0;
    }
    else if(head->y <= 0)
    {
        head->y = 37;
    }
    head->y += y_dir;
    for (auto &part : positions)
    {
        auto _prev = part;
        part = prev;
        prev = _prev;
    }
}

} // namespace Objects
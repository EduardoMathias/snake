#pragma once
#include <list>

struct pos
{
    int x;
    int y;
};

namespace Objects
{
class Snake
{
private:
    pos _head;
public:
    std::list<pos> positions;
    Snake(int _x, int _y);
    ~Snake();
    pos *head();
    pos *tail();
    void move(int xdir, int ydir);
};

} // namespace Objects
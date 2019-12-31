#pragma once

namespace Screen
{

class Screen
{
private:
    /* data */
public:
    int height, width;
    Screen();
    ~Screen();
    bool enoughSize();
    void drawBox();
};

}; // namespace Screen

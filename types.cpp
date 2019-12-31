namespace invaders
{
class Element
{
public:
    int x, y;

    Element() {}
    Element(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
};

class Gunner : public Element
{
};

class Alien : public Element
{
};

} // namespace invaders
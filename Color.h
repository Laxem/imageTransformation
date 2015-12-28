#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <algorithm>

class Color{
    private:
        int red;
        int green;
        int blue;
    public:
        Color(int r, int g, int b): red(r), green(g), blue(b){}
        Color():red(0), green(0), blue(0){}
        void setRed(int r){red = std::min(std::max(r, 0), 255);}
        void setGreen(int g){green = std::min(std::max(g, 0), 255);}
        void setBlue(int b){blue = std::min(std::max(b, 0), 255);}
        int getRed(){return red;}
        int getGreen(){return green;}
        int getBlue(){return blue;}
        void setColor(int r, int g, int b){setRed(r); setGreen(g); setBlue(b);}
};

#endif // COLOR_H_INCLUDED






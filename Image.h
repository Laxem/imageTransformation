#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "Color.h"
#include <string>

using namespace std;

class Image{
    private:
        string name;
        int width;
        int height;
        Color *pixel;
    public:
        Image(string name, int width, int height);
        Image(string adresse);
        ~Image();
        void imageToAdresse(string adresse);
        void drawPoint(int x, int y, Color col);
        void drawPoint(int i, Color col);
        Color getPoint(int x, int y);
        Color getPoint(int i);
        int getWidth();
        int getHeight();
        string getName();
        void showLine(int contrast, string nomImage);
        bool testPixel(int x, int y, int contrast);
        void showBackground();
};

void traitementImage(Image& image);

bool testPixel(Image& image, int i, int j);


#endif // COLOR_H_INCLUDED





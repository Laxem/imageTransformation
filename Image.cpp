#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "Color.h"
#include "Image.h"
#include <time.h>
#include <vector>

using namespace std;

Image::Image(string n, int w, int h)
{
    width = w;
    height = h;
    name = n;
    pixel = new Color[width*height];

    for(int i=0; i<width*height; i++)
    {
        pixel[i].setColor(0, 0, 0);
    }
}

Image::Image(string adresse)
{
    ifstream fin(adresse.c_str(), ios::in);

    if(fin)
    {
        string trash;
        string sizeX;
        string sizeY;
        fin>>trash;
        fin>>sizeX;
        fin>>sizeY;
        fin>>trash;

        int x = std::atoi(sizeX.c_str());
        int y = std::atoi(sizeY.c_str());

        name = adresse;
        width = x;
        height = y;
        pixel = new Color[width*height];

        cout<<x<<" "<<y<<" "<<trash<<endl;

        string red;
        string green;
        string blue;

        int r;
        int g;
        int b;

        Color col;

        for(int i = 0; i < x*y; i++){
            fin>>red;
            fin>>green;
            fin>>blue;

            r = std::atoi(red.c_str());
            g = std::atoi(green.c_str());
            b = std::atoi(blue.c_str());

            col.setColor(r, g, b);
            drawPoint(i, col);
        }
        fin.close();
    }
    else
    {
        cout<<"erreur d'ouverture de fichier"<<endl;
    }
}

Image::~Image(){
    delete [] pixel;
}

Color Image::getPoint(int x, int y){
    return pixel[x+y*width];
}

Color Image::getPoint(int i){
    return pixel[i];
}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}

string Image::getName(){
    return name;
}

void Image::drawPoint(int x, int y, Color col)
{
    if(x>=0 and x<width and y>=0 and y<height)
    {
        int i = width*y+x;
        pixel[i].setColor(col.getRed(), col.getGreen(), col.getBlue());
    }
    else
    {
        std::cout<<"erreur de coordonnees"<<endl;
    }
}

void Image::drawPoint(int i, Color col)
{
    if(i>=0 and i<width*height)
    {
        pixel[i].setColor(col.getRed(), col.getGreen(), col.getBlue());
    }
    else
    {
        std::cout<<"erreur de coordonnees"<<endl;
    }
}

void Image::imageToAdresse(string adresse)
{
    ofstream fout(adresse.c_str());

    if(fout)
    {
        fout<<"P3"<<endl;
        fout<<width<<" "<<height<<endl;
        fout<<"255"<<endl;
        for(int i=0; i<width*height; i++)
        {
            fout<<pixel[i].getRed()<<" ";
            fout<<pixel[i].getGreen()<<" ";
            fout<<pixel[i].getBlue()<<endl;
        }
    }
    else
    {
        cout<<"erreur d'ouverture de flux"<<endl;
    }

}

void Image::showLine(int contrast, string nomImage){
    Image result(getName(), getWidth(), getHeight());

    Color line(0, 0, 0);
    Color background(255, 255 ,255);

    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            if(testPixel(j, i, contrast)){
                result.drawPoint(j, i, line);
            }
            else{
                result.drawPoint(j, i, background);
            }
        }
    }

    char numstr[21];
    sprintf(numstr, "%d", contrast);
    string adr1 = "image/";
    string adr2 = "_C";
    string adr3 = ".ppm";
    string adrReturn = adr1 + nomImage + adr2 + numstr + adr3;
    result.imageToAdresse(adrReturn);

}

bool Image::testPixel(int x, int y, int contrast){
    int sumcolor;
    int sumcolor2;
    Color color = getPoint(x, y);
    Color colorDiff;
    int diffColor = 0;
    for(int i = -1 ; i<2 ; i++){
        for(int j = -1; j<2 ; j++){
            if((i!=0 or j!=0) and x+i>=0 and y+j>=0 and x+i<width and y+j<height){
                colorDiff = getPoint((x+i)+(y+j)*width);
                diffColor += abs(color.getRed() - colorDiff.getRed());
                diffColor += abs(color.getGreen() - colorDiff.getGreen());
                diffColor += abs(color.getBlue() - colorDiff.getBlue());
                if(diffColor>contrast)return true;
            }
            diffColor = 0;
        }
    }
    return false;
}

void Image::showBackground(){
    Color line(0, 0, 0);
    Color background(255, 0 ,0);

    Color tabColor[255*255*255];

    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){

            /*if(getPoint(j, i)){
                drawPoint(j, i, line);
            }
            else{
                drawPoint(j, i, background);
            }*/
        }
    }
}

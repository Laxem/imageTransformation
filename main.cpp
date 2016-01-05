#include "Image.h"
#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    string adresse= "image/";
    string nomImage = "test_Image";

    cout<<"lecture image"<<endl;
    Image pict(adresse+nomImage+".ppm");

    int contrast = 30;
    pict.showLine(contrast, nomImage);

    cout<<"traitement fini"<<endl;

    return 0;
}

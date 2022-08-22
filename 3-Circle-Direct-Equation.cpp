#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int CLR = 15;
void CircleDirectEquiation(int r){
    int x = 0, y = r;
    int tr = r + 10;
    putpixel(x, y, CLR);
    while(x <= y){
        x++;
        y = round(sqrt(r*r - x*x));
        putpixel(x + tr, y + tr, CLR);
        putpixel(-x + tr, y + tr, CLR);
        putpixel(x + tr, -y + tr, CLR);
        putpixel(-x + tr, -y + tr, CLR);
        putpixel(y + tr, x + tr, CLR);
        putpixel(-y + tr, x + tr, CLR);
        putpixel(y + tr, -x + tr, CLR);
        putpixel(-y + tr, -x + tr, CLR);
    }
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    int r = 100;
    CircleDirectEquiation(r);
    getch();
    closegraph();
    cout<<"finished"<<endl;
}

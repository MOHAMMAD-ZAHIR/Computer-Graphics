#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int CLR = 15;
void CircleBresenham(int r){
    int x = 0, y = r;
    int tr = r + 10;
    int d = 3 - 2 * r;
    while(x <= y){
        putpixel(x + tr, y + tr, CLR);
        putpixel(-x + tr, y + tr, CLR);
        putpixel(x + tr, -y + tr, CLR);
        putpixel(-x + tr, -y + tr, CLR);

        putpixel(y + tr, x + tr, CLR);
        putpixel(-y + tr, x + tr, CLR);
        putpixel(y + tr, -x + tr, CLR);
        putpixel(-y + tr, -x + tr, CLR);

        x++;
        if(d<0) d += 4*x + 6;
        else {
            d += 4*(x-y) + 10;
            y--;
        }
    }
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    int r = 100;
    CircleBresenham(r);
    getch();
    closegraph();
    cout<<"finished"<<endl;
}

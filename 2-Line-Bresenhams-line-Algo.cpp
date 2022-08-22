#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int CLR = 15;
void BresenhamsLineAlgorithm(int x1, int y1, int x2, int y2){
    putpixel(x1, y1, CLR);
    int dX = x2 - x1;
    int dY = y2 - y1;

    int d = 2 * dY - dX;
    int dT = 2* (dY - dX);
    int dS = 2 * dY;

    while(x1 < x2){
        x1++;
        if(d<0) d += dS;
        else{
            d += dT;
            y1++;
        }
        putpixel(x1, y1, CLR);
    }
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );

    int x1 = 100, y1 = 200, x2 = 300, y2 = 400;
    BresenhamsLineAlgorithm(x1, y1, x2, y2);

    getch();
    closegraph();
    cout<<"finished"<<endl;
    return 0;
}


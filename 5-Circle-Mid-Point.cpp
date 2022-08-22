#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int CLR = 15;
void CircleMidPoint(int r){
    int x = 0, y = r;
    int tr = r + 10;
    int p = 1 - r;
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
        if(p<0) p += 2*x + 3;
        else {
            p += 2*(x-y) + 5;
            y--;
        }
    }
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    int r = 100;
    CircleMidPoint(r);
    getch();
    closegraph();
    cout<<"finished"<<endl;
}

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int CLR = 15;
void LineDirectEquiation(int x1, int y1, int x2, int y2){
    if(x1 == x2){ 
        for(int y = y1; y <= y2; y++)
            putpixel((int)x1, y, CLR);
        return; 
    }
    double m = (y1 - y2) * 1.0 / (x1 - x2);
    double c = y1 - m * x1;
    if(abs(x1 - x2) >= abs(y1 - y2)){
        for(int x = x1; x <= x2; x++){
            int y = round(m * x + c);
            putpixel(x, y, CLR);
        }
    }
    else{
        for(int y = y1; y <= y2; y++){
            int x = round((y - c) / m);
            putpixel(x, y, CLR);
        }
    }
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );

    int x1 = 100, y1 = 100, x2 = 300, y2 = 300;
    LineDirectEquiation(x1, y1, x2, y2);

    getch();
    closegraph();
    cout<<"finished"<<endl;
    return 0;
}

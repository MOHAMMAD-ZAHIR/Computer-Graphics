#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void flood(int,int, int, int);

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int L,T,R,B;
    cout<<"Enter the rectangle values: L T R B "<<endl;
    cin>>L>>T>>R>>B;
    rectangle(L,T,R,B);

    int p,q;
    cout<<endl<<"Enter a point inside this rectangle ";
    cin>>p>>q;
    flood(p,q,RED,BLACK);
    getch();

}
void flood(int x, int y, int fillColor, int defaultColor){
    if(getpixel(x,y)==defaultColor){
        //delay(50);
        putpixel(x,y,fillColor);
        flood(x+1,y,fillColor,defaultColor);
        flood(x-1,y,fillColor,defaultColor);
        flood(x,y+1,fillColor,defaultColor);
        flood(x,y-1,fillColor,defaultColor);
    }
}

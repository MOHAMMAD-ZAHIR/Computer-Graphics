#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
    int xc,yc,r,x,y,p;
    int gDriver=DETECT;
    int gMode;
    initgraph(&gDriver,&gMode,"");

    cout<<"Enter the center of the circle : ";
    cin>>xc>>yc;

    cout<<endl<<"Enter the radius of the circle :";
    cin>>r;


    // Initial value
    x =0;
    y=r;

    //P is the Decision parameter
    p=3-2*r;

    do{
        putpixel(x+xc,y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);

        putpixel(y+xc,x+yc,WHITE);
        putpixel(y+xc,-x+yc,WHITE);
        putpixel(-y+xc,x+yc,WHITE);
        putpixel(-y+xc,-x+yc,WHITE);

        if(p<0){
            x++;
            y=y;
            p=p+4*x+6;
        }
        else{
            x++;
            y--;
            p=p+4*(x-y)+10;
        }
    }while(x<y);
    getch();



}

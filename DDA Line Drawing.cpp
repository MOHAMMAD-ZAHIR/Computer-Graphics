#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gDriver = DETECT;
    int gMode;
    initgraph(&gDriver,&gMode,"");

    int x1,x2,y1,y2;
    cout<<"Enter the first Coordinates: "<<endl;
    cout<<"x1 = ";
    cin>>x1;
    cout<<"y1 = ";
    cin>>y1;

    cout<<"Enter the second Coordinates: "<<endl;
    cout<<"x2 = ";
    cin>>x2;
    cout<<"y2 = ";
    cin>>y2;

    int dx,dy;
    int steps;
    if(abs(dx)> abs(dy))
    {
        steps=abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    int xInc = dx/steps;
    int yInc = dy/steps;
    for(int i=0; i<steps; i++)
    {
        if(x1<x2 && y1<y2)
        {
            putpixel(x1,y1,WHITE);
            x1 = x1+xInc;
            y1= y1 +yInc;
        }
    }
    getch();
    closegraph();
}

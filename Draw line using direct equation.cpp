#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
   int gDriver=DETECT;
   int gMode;
   initgraph(&gDriver,&gMode,"");

   double x1,x2,y1,y2;
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

   double dx,dy,m,b;
   dx=x2-x1;
   dy=y2-y1;
   m=dy/dx;
   int x = x1, y=y1;
   putpixel(x,y,WHITE);

   while(x<x2){
        if(m<=1){
    x=x+1;
    y=m*x+b;
   }
   else{
    y=y+1;
    x=(y-b)/m;
   }
   putpixel(x,y,WHITE);

   }
   getch();

}

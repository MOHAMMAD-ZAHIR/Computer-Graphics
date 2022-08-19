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

   double dx,dy,m,p;
   dx=x2-x1;
   dy=y2-y1;
   m=dy/dx;
   p = (2*dy)-dx;
   int x=x1, y=y1;

   putpixel(x,y,WHITE);
   while(x<x2){
          if(abs(m)<=1){
    if(p<0){
        x=x+1;
        p=p+2*dy;
    }else{
        x=x+1;
        y=y+1;
        p=p+2*dy-2*dx;
    }
   }else{
       if(p<0){
        y=y+1;
        p=p+2*dy;
       }else{
           y=y+1;
           x=x+1;
           p=p+2*dx-2*dy;
       }
   }
   putpixel(x,y,WHITE);

   }
   getch();

}

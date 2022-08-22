#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int midx = 319, midy = 239;
int maxx = 638, maxy = 479;
void AxisMaker(){
    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);
}
void WorkWithLine(int x1, int y1, int x2, int y2, double Sx, double Sy){
    setcolor(YELLOW);
    line(x1 + midx, y1 + midy, x2 + midx, y2 + midy);
    setcolor(WHITE);
    int x11 = round(x1 * Sx) + midx;
    int y11 = round(y1 * Sy) + midy;
    int x22 = round(x2 * Sx) + midx;
    int y22 = round(y2 * Sy) + midy;
    line(x11, y11, x22, y22);
}
void WorkWithCircle(int r, double Sr){
    int origin = r + 10;
    setcolor(YELLOW);
    circle(origin + midx, origin + midy, r);
    setcolor(WHITE);
    circle(origin  + midx, origin + midy, r * Sr);
}
void WorkWithTriangle(int x1, int y1, int x2, int y2, int x3, int y3, double Sx, double Sy){
    WorkWithLine(x1, y1, x2, y2, Sx, Sy);
    WorkWithLine(x1, y1, x3, y3, Sx, Sy);
    WorkWithLine(x3, y3, x2, y2, Sx, Sy);
}
void WorkWithRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double Sx, double Sy){
    WorkWithLine(x1, y1, x2, y2, Sx, Sy);
    WorkWithLine(x2, y2, x3, y3, Sx, Sy);
    WorkWithLine(x3, y3, x4, y4, Sx, Sy);
    WorkWithLine(x1, y1, x4, y4, Sx, Sy);
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    while(1){
        AxisMaker();
        system("cls");
        cout<<"1. Line"<<endl;
        cout<<"2. Circle"<<endl;
        cout<<"3. Triangle"<<endl;
        cout<<"4. Rectangle"<<endl;
        cout<<"5. Exit"<<endl;
        int n;
        cout<<endl<<"Select Your Choich: ";
        cin>>n;
        cleardevice();
        AxisMaker();
        if(n == 1){
            int x1,x2,y1,y2;
            double Sx, Sy;
            cout<<"Input your two points (x1, y1) (x2, y2): ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Input your Scaling value (Sx, Sy): ";
            cin>>Sx>>Sy;
            WorkWithLine(x1, y1, x2, y2, Sx, Sy);
        }
        else if(n == 2){
            int r;
            double Sr;
            cout<<"Input the radius of your circle: ";
            cin>>r;
            cout<<"Input your Scaling value (Sr - Radius Scaling): ";
            cin>>Sr;
            WorkWithCircle(r, Sr);
        }
        else if(n == 3){
            int x1, y1, x2, y2, x3, y3;
            double Sx, Sy;
            cout<<"Input three points of your triangle (x1, y1), (x2, y2), (x3, y3): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            cout<<"Input your Scaling value (Sx, Sy): ";
            cin>>Sx>>Sy;
            WorkWithTriangle(x1, y1, x2, y2, x3, y3, Sx, Sy);
        }
        else if(n == 4){
            int x1, y1, x2, y2, x3, y3, x4, y4;
            double Sx, Sy;
            cout<<"Input Four points of your rectangle (x1, y1), (x2, y2), (x3, y3), (x4, y4): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            cout<<"Input your Scaling value (Sx, Sy): ";
            cin>>Sx>>Sy;
            WorkWithRectangle(x1, y1, x2, y2, x3, y3, x4, y4, Sx, Sy);
        }
        else if(n == 5){
            exit(0);
        }
    }
    closegraph();
    cout<<"finished"<<endl;
}

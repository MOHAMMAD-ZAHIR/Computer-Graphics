#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int midx = 319, midy = 239;
int maxx = 638, maxy = 479;
void AxisMaker(){
    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);
}
void WorkWithLine(int x1, int y1, int x2, int y2, int Degree){
    setcolor(YELLOW);
    line(x1 + midx, y1 + midy, x2 + midx, y2 + midy);
    setcolor(WHITE);
    double radian = Degree * 3.1416 / 180.0;
    int x11 = round(x1*cos(radian) - y1*sin(radian)) + midx;
    int y11 = round(x1*sin(radian) + y1*cos(radian)) + midy;
    int x22 = round(x2*cos(radian) - y2*sin(radian)) + midx;
    int y22 = round(x2*sin(radian) + y2*cos(radian)) + midy;
    line(x11, y11, x22, y22);
}
void WorkWithTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int Degree){
    WorkWithLine(x1, y1, x2, y2, Degree);
    WorkWithLine(x1, y1, x3, y3, Degree);
    WorkWithLine(x3, y3, x2, y2, Degree);
}
void WorkWithRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Degree){
    WorkWithLine(x1, y1, x2, y2, Degree);
    WorkWithLine(x2, y2, x3, y3, Degree);
    WorkWithLine(x3, y3, x4, y4, Degree);
    WorkWithLine(x1, y1, x4, y4, Degree);
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    while(1){
        AxisMaker();
        system("cls");
        cout<<"1. Line"<<endl;
        cout<<"2. Triangle"<<endl;
        cout<<"3. Rectangle"<<endl;
        cout<<"4. Exit"<<endl;
        int n;
        cout<<endl<<"Select Your Choich: ";
        cin>>n;
        cleardevice();
        AxisMaker();
        if(n == 1){
            int x1,x2,y1,y2, Degree;
            cout<<"Input your two points (x1, y1) (x2, y2): ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            WorkWithLine(x1, y1, x2, y2, Degree);
        }
        else if(n == 2){
            int x1, y1, x2, y2, x3, y3, Degree;
            cout<<"Input three points of your triangle (x1, y1), (x2, y2), (x3, y3): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            WorkWithTriangle(x1, y1, x2, y2, x3, y3, Degree);
        }
        else if(n == 3){
            int x1, y1, x2, y2, x3, y3, x4, y4, Degree;
            cout<<"Input Four points of your rectangle (x1, y1), (x2, y2), (x3, y3), (x4, y4): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            WorkWithRectangle(x1, y1, x2, y2, x3, y3, x4, y4, Degree);
        }
        else if(n == 4){
            exit(0);
        }
    }
    closegraph();
    cout<<"finished"<<endl;
}

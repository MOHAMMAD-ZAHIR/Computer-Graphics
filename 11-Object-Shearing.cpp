#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int midx = 319, midy = 239;
int maxx = 638, maxy = 479;
void AxisMaker(){
    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);
}
void WorkWithLine(int x1, int y1, int x2, int y2, int Axis, double S){
    setcolor(YELLOW);
    line(x1 + midx, y1 + midy, x2 + midx, y2 + midy);
    setcolor(WHITE);
    if(Axis == 1) {
        x1 = x1 + S*y1;
        x2 = x2 + S*y2;
    }
    else{
        y1 = y1 + S*x1;
        y2 = y2 + S*x2;
    }
    line(x1 + midx, y1 + midy, x2 + midx, y2 + midy);
}
void WorkWithTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int Axis, double S){
    WorkWithLine(x1, y1, x2, y2, Axis, S);
    WorkWithLine(x1, y1, x3, y3, Axis, S);
    WorkWithLine(x3, y3, x2, y2, Axis, S);
}
void WorkWithRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Axis, double S){
    WorkWithLine(x1, y1, x2, y2, Axis, S);
    WorkWithLine(x2, y2, x3, y3, Axis, S);
    WorkWithLine(x3, y3, x4, y4, Axis, S);
    WorkWithLine(x1, y1, x4, y4, Axis, S);
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
            int x1,x2,y1,y2, Axis;
            double S;
            cout<<"Input your two points (x1, y1) (x2, y2): ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Which Axis? (input 1 for x axis and 2 y axis): ";
            cin>>Axis;
            cout<<"Input your shearing value: ";
            cin>>S;
            WorkWithLine(x1, y1, x2, y2, Axis, S);
        }
        else if(n == 2){
            int x1, y1, x2, y2, x3, y3, Axis;
            double S;
            cout<<"Input three points of your triangle (x1, y1), (x2, y2), (x3, y3): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            cout<<"Which Axis? (input 1 for x axis and 2 y axis): ";
            cin>>Axis;
            cout<<"Input your shearing value: ";
            cin>>S;
            WorkWithTriangle(x1, y1, x2, y2, x3, y3, Axis, S);
        }
        else if(n == 3){
            int x1, y1, x2, y2, x3, y3, x4, y4, Axis;
            double S;
            cout<<"Input Four points of your rectangle (x1, y1), (x2, y2), (x3, y3), (x4, y4): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            cout<<"Which Axis? (input 1 for x axis and 2 y axis): ";
            cin>>Axis;
            cout<<"Input your shearing value: ";
            cin>>S;
            WorkWithRectangle(x1, y1, x2, y2, x3, y3, x4, y4, Axis, S);
        }
        else if(n == 4){
            exit(0);
        }
    }
    closegraph();
    cout<<"finished"<<endl;
}



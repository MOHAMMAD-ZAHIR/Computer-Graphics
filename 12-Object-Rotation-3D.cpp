#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int midx = 319, midy = 239;
int maxx = 638, maxy = 479;
void AxisMaker(){
    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);
}
void WorkWithLine(int x1, int y1, int z1, int x2, int y2, int z2, int Axis, int Degree){ ///may be problem exist in y and z axis.
    setcolor(YELLOW);
    line(x1 + midx, y1 + midy, x2 + midx, y2 + midy);
    setcolor(WHITE);
    double radian = Degree * 3.1416 / 180.0;
    int x11, y11, z11, x22, y22, z22;
    if(Axis == 3){
        x11 = round(x1 * cos(radian) - y1 * sin(radian)) + midx;
        y11 = round(x1 * sin(radian) + y1 * cos(radian)) + midy;
        z11 = z1;
        x22 = round(x2 * cos(radian) - y2 * sin(radian)) + midx;
        y22 = round(x2 * sin(radian) + y2 * cos(radian)) + midy;
        z22 = z2;
    }
    else if(Axis == 2){
        x11 = round(x1 * cos(radian) + z1 * sin(radian)) + midx;
        y11 = y1 + midy;
        z11 = round(-x1 * sin(radian) + z1 * cos(radian));
        x22 = round(x2 * cos(radian) + z2 * sin(radian))  + midx;
        y22 = y2 + midy;
        z22 = round(-x2 * sin(radian) + z2 * cos(radian));
    }
    else if(Axis == 1){
        x11 = x1 + midx;
        y11 = round(y1 * cos(radian) - z1 * sin(radian)) + midy;
        z11 = round(y1 * sin(radian) + z1 * cos(radian));
        x22 = x2 + midx;
        y22 = round(y2 * cos(radian) - z2 * sin(radian)) + midy;
        z22 = round(y2 * sin(radian) + z2 * cos(radian));
    }
//    cout<<x11 - midx<<" "<<y11 - midy<<" "<<z11<<" "<<x22 - midx<<" "<<y22 - midy<<" "<<z22<<endl;
    line(x11, y11, x22, y22);
}
void WorkWithTriangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int Axis, int Degree){
    WorkWithLine(x1, y1, z1, x2, y2, z2, Axis, Degree);
    WorkWithLine(x1, y1, z1, x3, y3, z3, Axis, Degree);
    WorkWithLine(x3, y3, z3, x2, y2, z2, Axis, Degree);
}
void WorkWithRectangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int Axis, int Degree){
    WorkWithLine(x1, y1, z1, x2, y2, z2, Axis, Degree);
    WorkWithLine(x2, y2, z2, x3, y3, z3, Axis, Degree);
    WorkWithLine(x3, y3, z3, x4, y4, z4, Axis, Degree);
    WorkWithLine(x1, y1, z1, x4, y4, z4, Axis, Degree);
}
void WorkWithCube(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6, int x7, int y7, int z7, int x8, int y8, int z8, int Axis, int Degree){
    WorkWithRectangle(x1, y1 , z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, Axis, Degree);
    WorkWithRectangle(x5, y5 , z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, Axis, Degree);

    WorkWithRectangle(x1, y1 , z1, x5, y5, z5, x8, y8, z8, x4, y4, z4, Axis, Degree);
    WorkWithRectangle(x2, y2 , z2, x6, y6, z6, x7, y7, z7, x3, y3, z3, Axis, Degree);
}
int main(){
    int gmode = DETECT, gdriver;
    int Axis;
    initgraph ( &gmode, &gdriver, "" );
    while(1){
        AxisMaker();
        system("cls");
        cout<<"1. Line"<<endl;
        cout<<"2. Triangle"<<endl;
        cout<<"3. Rectangle"<<endl;
        cout<<"4. Cube"<<endl;
        cout<<"5. Exit"<<endl;
        int n;
        cout<<endl<<"Select Your Choich: ";
        cin>>n;
        cleardevice();
        AxisMaker();
        if(n == 1){
            int x1, x2, y1, y2, z1, z2, Degree;
            cout<<"Input your two points (x1, y1, z1) (x2, y2, z2): ";
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            cout<<"In which axis you want to rotate (1=>x, 2=>y, 3=>z): ";
            cin>>Axis;
            WorkWithLine(x1, y1, z1, x2, y2, z2, Axis, Degree);
        }
        else if(n == 2){
            int x1, y1, x2, y2, x3, y3, z1, z2, z3, Degree;
            cout<<"Input three points of your triangle (x1, y1, z1), (x2, y2, z2), (x3, y3, z3): ";
            cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            cout<<"In which axis you want to rotate (1=>x, 2=>y, 3=>z): ";
            cin>>Axis;
            WorkWithTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, Axis, Degree);
        }
        else if(n == 3){
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, Degree;
            cout<<"Input Four points of your rectangle (x1, y1, z1), (x2, y2, z2), (x3, y3, z3), (x4, y4, z4): ";
            cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3>>x4>>y4>>z4;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            cout<<"In which axis you want to rotate (1=>x, 2=>y, 3=>z): ";
            cin>>Axis;
            WorkWithRectangle(x1, y1 , z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, Axis, Degree);
        }
        else if(n == 4){
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, Degree;
            cout<<"Input Four points of your rectangle (x1, y1, z1), (x2, y2, z2), (x3, y3, z3), (x4, y4, z4): ";
            cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3>>x4>>y4>>z4;
            cout<<"Input your Rotation value (Degree): ";
            cin>>Degree;
            cout<<"In which axis you want to rotate (1=>x, 2=>y, 3=>z): ";
            cin>>Axis;
            int t = 20;
            WorkWithCube(x1, y1 , z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x1 + t, y1 + t, z1 + t, x2 + t, y2 + t, z2 + t, x3 + t, y3 + t, z3 + t, x4 + t, y4 + t, z4 + t, Axis, Degree);
        }
        else if(n == 5){
            exit(0);
        }
    }
    closegraph();
    cout<<"finished"<<endl;
}


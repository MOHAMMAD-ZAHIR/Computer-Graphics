#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void WorkWithLine(int x1, int y1, int x2, int y2, int tx, int ty){
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    setcolor(WHITE);
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
}
void WorkWithCircle(int r, int tx, int ty){
    int origin = r + 10;
    setcolor(YELLOW);
    circle(origin, origin, r);
    setcolor(WHITE);
    circle(origin + tx, origin + ty, r);
}
void WorkWithTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty){
    WorkWithLine(x1, y1, x2, y2, tx, ty);
    WorkWithLine(x1, y1, x3, y3, tx, ty);
    WorkWithLine(x3, y3, x2, y2, tx, ty);
}
void WorkWithRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int tx, int ty){
    WorkWithLine(x1, y1, x2, y2, tx, ty);
    WorkWithLine(x2, y2, x3, y3, tx, ty);
    WorkWithLine(x3, y3, x4, y4, tx, ty);
    WorkWithLine(x1, y1, x4, y4, tx, ty);
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );

    while(1){
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
        if(n == 1){
            int x1,x2,y1,y2, tx, ty;
            cout<<"Input your two points (x1, y1) (x2, y2): ";
            cin>>x1>>y1>>x2>>y2;
            cout<<"Input your transformation value (tx, ty): ";
            cin>>tx>>ty;
            WorkWithLine(x1,y1, x2, y2, tx, ty);
        }
        else if(n == 2){
            int r, tx, ty;
            cout<<"Input the radius of your circle: ";
            cin>>r;
            cout<<"Input your transformation value (tx, ty): ";
            cin>>tx>>ty;
            WorkWithCircle(r, tx, ty);
        }
        else if(n == 3){
            int x1, y1, x2, y2, x3, y3, tx, ty;
            cout<<"Input three points of your triangle (x1, y1), (x2, y2), (x3, y3): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            cout<<"Input your transformation value (tx, ty): ";
            cin>>tx>>ty;
            WorkWithTriangle(x1, y1, x2, y2, x3, y3, tx, ty);
        }
        else if(n == 4){
            int x1, y1, x2, y2, x3, y3, x4, y4, tx, ty;
            cout<<"Input Four points of your rectangle (x1, y1), (x2, y2), (x3, y3), (x4, y4): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
            cout<<"Input your transformation value (tx, ty): ";
            cin>>tx>>ty;
            WorkWithRectangle(x1, y1, x2, y2, x3, y3, x4, y4, tx, ty);
        }
        else if(n ==5){
            exit(0);
        }
    }

    closegraph();
    cout<<"finished"<<endl;
}

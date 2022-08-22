#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
vector<pair<int, int> > points;
int borderColor = 15;
void Flood_Fill(int x, int y, int clr){
    int ColorGot = getpixel(x, y);
    if(ColorGot == clr || ColorGot == borderColor) return;
    putpixel(x, y, clr);
    Flood_Fill(x + 1, y, clr);
    Flood_Fill(x - 1, y, clr);
    Flood_Fill(x, y + 1, clr);
    Flood_Fill(x, y - 1, clr);
}
void make_Polygon(){
    for(int i=1; i<points.size(); i++) line(points[i-1].first, points[i-1].second, points[i].first, points[i].second);
    line(points[0].first, points[0].second, points[points.size() - 1].first, points[points.size() - 1].second);
}
int main(){
    int gmode = DETECT, gdriver;
    initgraph ( &gmode, &gdriver, "" );
    int n, x, y;
    cout<<"To make a Polygon, how many points you want to input (n>2): ";
    cin>>n;
    while(n<3){
        cout<<"You must input at least 3\nInput Again: ";
        cin>>n;
    }
    for(int i=0; i<n; i++){
        cin>>x>>y;
        points.push_back({x, y});
    }
    make_Polygon();
    cout<<"Input a Valid Point (x,y = inside the polygon): ";
    cin>>x>>y;
///    floodfill(x, y, 15); ///build in
    Flood_Fill(x, y, 15);
    getch();
    closegraph();
    return 0;
}

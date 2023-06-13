#include <iostream>
#include <bits/stdc++.h>
#define ll long long
const ll mod= 1e9+7;
const ll INF=2e14+10;
using namespace std;

// https://www.spoj.com/problems/MKJUMPS/
typedef struct{
    int ymin;
    int ymax;
}LIMIT;


LIMIT row[12];
bool visited[12][12];
int n;
int totalCells=0,okCells=0;


int dirX[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int dirY[] = { 1, 2, 2, 1,-1,-2,-2,-1};


bool isValid(int x, int y){
    if(x<1 || x>n || y< row[x].ymin || y>row[x].ymax) return false;
    return true;
}


void solve(int x, int y, int total){
    // base condition
    if(total>okCells) okCells = total;
    
    for(int i=0;i<8;i++){
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        if(isValid(newX,newY) && visited[newX][newY]==false){
            visited[newX][newY]=true;
            solve(newX,newY,total+1);
            visited[newX][newY]=false;
        }
    }
    return;
}
                
int main(){
    cin>>n;
    int t=1;
    do{
        totalCells=0;
        for(int i=1;i<=n;i++){
            int col,len;
            cin>>col>>len;
            row[i].ymin = col+1;
            row[i].ymax = row[i].ymin + len -1;
            totalCells+=len;
            
            for(int j=row[i].ymin ;j<=row[i].ymax;j++) visited[i][j]=false;
        }
        okCells=0;
        visited[1][1]=true;
        solve(1,1,1);
        cout<<"Case "<<t++ <<", "<<(totalCells-okCells);
        if(totalCells-okCells == 1) cout<<" square can not be reached.";
        else cout<<" squares can not be reached.";
        cout<<"\n";
        cin>>n;
    }while(n!=0);
    return 0;
}

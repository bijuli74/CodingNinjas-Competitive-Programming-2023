#include <bits/stdc++.h>
using namespace std;

int main() {
	double b; char c;
    cin>>b>>c;
    if(c=='A'){
        cout<<lround(1.59*b+1700);
    }
    else if(c=='B'){
        cout<<lround(1.59*b+1500);
    }
    else 
        cout<<lround(1.59*b+1300);
	
}

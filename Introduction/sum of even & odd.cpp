#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int n; cin>>n;
    int odd=0, even=0;
    while(n>0){
        int m=n%10;
        if(m&1) odd+=m;
        else even+=m;
        n/=10;
    }
    cout<<even<<" "<<odd;
	
}

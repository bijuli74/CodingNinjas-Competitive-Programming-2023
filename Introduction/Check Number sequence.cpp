#include<iostream>
using namespace std;

int main() {
	int n; cin>>n;
    int cur=0, prev=0, inc=0;
    for(int i=0;i<n; ++i){
        cin>>cur;
        if(cur==prev) { cout<<"false"; return 0;}
        else if(cur<prev){
            if(inc>0){ cout<<"false"; return 0;}
        
        }
        else if(cur>prev&&i>0) ++inc;
        prev=cur;
    }
    
    cout<<"true";
	
}

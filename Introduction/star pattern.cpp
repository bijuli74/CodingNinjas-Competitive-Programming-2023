#include<iostream>
using namespace std;

int main(){
    int n; cin>>n; n+=1;
    int k, j;
    for(int i=0; i<n; ++i){
        for(k=0; k<=n-i-2; ++k)
            cout<<" ";
        k=0;
        for(j=0; j<2*i-1; ++j)
            cout<<"*";
    	j=0;
        cout<<'\n';
    }
}


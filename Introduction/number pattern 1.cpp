#include<iostream>
using namespace std;


int main(){
	int n; cin>>n;
    for(int i=1; i<=n; ++i){
        for(int j=i, c=i; c>0; ++j, --c)
            cout<<j;
        cout<<'\n';
    }
  
}

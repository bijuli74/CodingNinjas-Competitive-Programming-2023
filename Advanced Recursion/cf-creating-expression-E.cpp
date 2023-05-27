ll n,x;
bool f(int sum,int k, vector<ll> v,int i){
    if(i==v.size()){
        if(sum==x){
            return true;
        }
        return false;
    }
    bool b =f(sum-v[i],k,v,i+1);
    bool c=f(sum+v[i],k,v,i+1);
	return b||c;
}               
signed main()
{
    
    cin>>n>>x;
    vector<ll> v(n);
    fori(i,0,n){
        cin>>v[i];
    }
    if(f(v[0],x,v,1)==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}

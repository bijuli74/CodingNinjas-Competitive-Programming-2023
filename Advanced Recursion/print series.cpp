vector<int> printSeries(int n, int k)
{
    vector<int> ans;
    int x=n;
    while(n>0){
      ans.push_back(n);
      n -= k;
        
    }
    while(n!=x){
      ans.push_back(n);
      n += k;
       
    }
    ans.push_back(x);
    return ans;
}

int maxOfK(int n, int k, vector<int> &a)
{
    int cursum=0, ans;
    deque<int> q;
    for(int i=0; i<k; ++i){
        cursum+=a[i];
        q.push_back(a[i]);
    }
    ans=cursum;
    for(int i=k; i<n; ++i){
        int x = q.front();
        q.pop_front();
        ans = max(cursum, cursum-x);

    }
    return ans;
}

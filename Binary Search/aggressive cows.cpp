int n;
bool canArrange(vector<int>& stalls, int mid, int k){
    int total=1, last=0;
    for(int i=1; i<n; i++){
        if(stalls[i]-stalls[last]>=mid){
            total++;
            last=i;
        }
    }
    return total>=k;
}

int aggressiveCows(vector<int> &stalls, int k)
{   
    n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int l=1, r=stalls[n-1]-stalls[0];
    int ans=1e9+5;
    while(l<=r){
        int mid = l+(r-l)/2;
        if (canArrange(stalls, mid, k)) {
          l = mid + 1;
          ans=mid;
        } else {
          r = mid-1;
        }
    }
    return ans;
}

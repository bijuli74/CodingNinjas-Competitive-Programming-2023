#include <algorithm>

bool comp(vector<int>& x, vector<int>& y){
    
    if(x[1]*y[2]<x[2]*y[1]) return 1;
    else if(x[1]*y[2]>x[2]*y[1]) return 0;
    else {
        if(x[0]<y[0]) return 1;
        else return 0;
    }
}

vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    vector<vector<int>> a(n, vector<int>(3));
    vector<int> ans;
    for(int i=0; i<n; ++i){
        a[i][0]=i+1;
        a[i][1]=time[i];
        a[i][2]=loss[i];
    }
    sort(begin(a), end(a), comp);
    for(int i=0; i<n; ++i) ans.push_back(a[i][0]);
    return ans;

}

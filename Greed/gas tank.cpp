#include <algorithm>
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    const int gasses = accumulate(begin(gas), end(gas), 0);
    const int costs = accumulate(begin(cost), end(cost), 0);
    if(gasses-costs<0) return -1;
    int ans=0, sum=0;
    for(int i=0; i<gas.size(); ++i){
        sum+=gas[i]-cost[i];
        if(sum<0){
            sum=0;
            ans=i+1;
        }
    }
    return ans;
}

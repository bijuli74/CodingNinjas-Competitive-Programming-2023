#include <bits/stdc++.h>
bool checkOverlappingIntervals(long* start, long* end, int n)
{
    vector<pair<long, long>> intervals;
    for(int i=0; i<n; ++i){
        intervals.push_back(make_pair(start[i], end[i]));
     }

     if(intervals.empty())
        return 0;
    
    sort(intervals.begin(), intervals.end() );
    // int cur_end = intervals[0].first;

    for(int i=1; i<n; ++i){
        if(intervals[i-1].second > intervals[i].first)
            return 1;
    }
    return 0;

    // int mx = 0;
    // for(int i=0; i<n; ++i){
    //     if( mx < intervals[i][0])
    //         mx = intervals[i][0];
    // }
    // int aux[mx + 1] = {0};
    // for(int i=0; i<n; ++i){
    //     int st = intervals[i][1];
    //     int ed = intervals[i][0];
    //     aux[st]++, aux[ed]--;
    // }
    // for(int i=1; i<=mx; i++){
    //     aux[i] += aux[i-1];
    //     if(aux[i] > 1)
    //         return 1;
    // }
    // return 0;

}



 

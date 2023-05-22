#include <bits/stdc++.h>

long calcdist(int x1, int x2, int y1, int y2){
    long d =( (long)(x1) - (long)(x2) )*( (long)(x1) - (long)(x2) ) + ( (long)(y1) - (long)(y2) )*( (long)(y1) - (long)(y2) );
    return d;
}

long bruteForce(pair<int, int>* a, int n){
    long mn = LONG_MAX;
    for(int i=0; i<n; ++i){
        int x1 = a[i].first, y1 = a[i].second;
        for(int j=i+1; j<n; ++j){
            int x2 = a[j].first, y2 = a[j].second;
            long d = calcdist(x1, x2, y1, y2);
            if(d<mn)
                mn = d;
        }

    }
    return mn;
}

long stripClosest(pair<int, int>* strip, int size, long d){
    long min = d; 
 
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j){
            long dist = calcdist(strip[i].first, strip[j].first, strip[i].second, strip[j].second);
            if ( dist < min)
                min = dist;
        }
 
    return min;
}

long helper(pair<int, int>* a, pair<int, int>* ax, pair<int, int>* ay, int n){
       if(n<=3) return bruteForce(a, n);

    int mid = n/2;
    // pair<int, int> midpoint = ax[mid];

    pair<int, int> ayl[mid];
    pair<int, int> ayr[n-mid];
    int li=0;
    int ri=0;
    for(int i=0; i<n; ++i){
        if((ay[i].first<ax[mid].first || (ay[i].first==ax[mid].first && ay[i].second<ay[i].second)) && li<mid)
            ayl[li++]=ay[i];
            else
                ayr[ri++]=ay[i];
    }

    long dl = helper(a, ax, ayl, mid);
    long dr = helper(a, ax+mid, ayr, n-mid);

    long d = min(dl, dr);
    
    pair<int, int> strip[n];
    int j=0;
    for(int i=0; i<n; i++){
        if(abs(ay[i].first - ax[mid].first) < d)
            strip[j] = ay[i], ++j;
    }
    return stripClosest(strip, j, d);
}

long closestPair(pair<int, int>* a, int n){
    if(n<=1e4){
        return bruteForce(a, n);
    }
    pair<int, int> ax[n];
    pair<int, int> ay[n];
    for (int i = 0; i < n; i++){
        ax[i] = a[i];
        ay[i] = a[i];
    }
 
    sort(ax, ax+n, [](pair<int, int>& a, pair<int, int>& b){ return a.first < b.first;});
    sort(ay, ay+n, [](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second; });
 
    // Use recursive function to find the smallest distance
    return helper(a, ax, ay, n);
}

 
    

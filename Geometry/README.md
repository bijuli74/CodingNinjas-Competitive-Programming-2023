## Collinear Points
You are given a set of 3 points in a 2-D plane. You have to find out whether they are collinear or not.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t; cin>>t;
    while(t--){
        int x1, x2, y1, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if((x3-x2)*(y2-y1)==(y3-y2)*(x2-x1)) cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}
```
## Circle Intersection
You have been given the coordinates of the center of two circle by (‘X1’,’Y1’) and (‘X2’,’Y2’) respectively with radius ‘R1’ and ‘R2’ you have to find if they intersect each other or not. If they are touching each other that is also called an intersection here.
```cpp
#define ll long long
bool intersectCircle(int x1, int y1, int x2, int y2, int r1, int r2) {
  ll d = (ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2);
  ll r = (ll)(r1 + r2) * (r1 + r2);
  return d > r ? 0 : 1;
}
```
## Maximum Points On Straight Line
You are given a 2-D plane, and some 'N' integer coordinates in the form of (X, Y), where 'X' is the x-coordinate and 'Y' is the y-coordinate, all of which lie on that plane. You need to find the maximum number of coordinates among these which can form a straight line.
Note:
1. All the coordinates are integer coordinates.
2. There can be two identical coordinates.

```cpp
#include <bits/stdc++.h>

int maxPointsOnLine(vector<vector<int>>& points, int n){
  int res=0;
  if(n<=2) return n;

  for(int i=0; i<n; ++i){
    unordered_map<string, int> mp;
    int dup=1;

    for(int j=i+1; j<n; ++j){
      if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
        ++dup;
      else{
        int delx = points[i][0]-points[j][0];
        int dely = points[i][1]-points[j][1];
        int g = __gcd(delx, dely);
        int dx = delx/g, dy=dely/g;
        string s = to_string(dx)+","+to_string(dy);
        mp[s]++;
      }
    }
    res = max(res, dup);
    for(auto p: mp)
      res = max( res, p.second+dup);
  }

  return res;
}

// double slope(vector<int> &a, vector<int> &b) {

//   int x = b[0] - a[0];

//   int y = b[1] - a[1];

//   if (x == 0)

//     return (double)INT_MAX;

//   else

//     return (double)y / x;
// }

// int maxPointsOnLine(vector<vector<int>> &points, int n) {

//   int maxi = INT_MIN;

//   for (int i = 0; i < points.size(); i++) {

//     unordered_map<double, int> ans;

//     for (int j =0; j < points.size(); j++) {

//       if (i != j) {

//         double cnt = slope(points[i], points[j]);

//         ans[cnt]++;
//       }
//     }

//     for (auto it : ans) {

//       maxi = max(maxi, it.second);
//     }
//   }

//   return maxi + 1;
// }
```
## Check Square
You are given four points on a two-dimensional coordinate system.
Can you check if those four points make a square?
Example:
Let the input be [1,0,2,1] and [0,1,1,2].
So, the coordinates of the four points be [ {1, 0}, {0, 1}, {2, 1}, {1, 2} ]

```cpp
#define ll long long
#include <bits/stdc++.h>
bool isSquare(vector<int> x, vector<int> y) {
      vector<ll> dsq;
      for(int i=0; i<4; ++i)
        for(int j=i+1; j<4; ++j)
                dsq.push_back((ll)(x[i]-x[j])*(x[i]-x[j]) + (ll)(y[i]-y[j])*(y[i]-y[j]));

        sort(begin(dsq), end(dsq));

        if(dsq[0]==dsq[1] && dsq[1]==dsq[2] && dsq[2]==dsq[3] &&
                dsq[5]==dsq[4] && dsq[0] *2LL == dsq[4] && dsq[0]>0)  
        return 1;
        
        return 0;

}
```

## Morning Walk
Every morning, Alex and Bob go for their regular morning walk. There are some fixed paths for both of them. Alex starts at point A and goes till point B, and Bob starts at point C and goes till point D. Given the values of A, B, C, and D, can you tell whether they will meet at a point or intersect or never meet each other?
You will output a string containing:
“Never” if they never meet.
“Point” if they meet at a point.
“Intersect” if they intersect each other.

```cpp
string morningWalk(int a,int b,int c,int d){
  int alexStart = min(a, b);
  int alexEnd = max(a, b);
  int bobStart = min(c, d);
  int bobEnd = max(c, d);

  int end = min(alexEnd, bobEnd);
  int start = max(alexStart, bobStart);

  /*
      If start is equal to end then end point of
      Bob's path is equal to starting point of Alex's
      path and vice versa.
  */

  if (start == end) {
    return "Point";
  }

  // If start is less than end then their path intersect.
  if (end > start) {
    return "Intersect";
  }

  // Else they never meet.
  return "Never";
}
```
## Probability of Survival $$
A prisoner has escaped the prison and is now on the run. Initially, the prisoner is at position (x0, y0). The prisoner can run at a constant speed of ‘V’. There are ‘N’ circular hiding places that have a center at (x[i], y[i]) and a radius of r[i] for each 1 ≤ i ≤ N. Prisoner has ‘T’ seconds to hide before police drone hunts him down and kills him immediately.
The prisoner follows the following strategy: He randomly picks a direction and then starts running in that direction with a constant speed of ‘V’. If he reaches any hiding place at some time t ≤ ‘T’, he stops immediately and is thus saved. Otherwise, he is killed by the police drone. You have to find out the probability of survival of the prisoner.
Answer is supposed to be correct if it is accurate to 4 decimal places.

```cpp
#include <bits/stdc++.h>


// const double pi = acos(-1.0); 
// // const double PI = 2*acos(0.0);

// struct interval {
//   double start, end;
//   bool operator<(const interval &t) const { return start < t.start; }
// };

// interval solve(int x, int y, int r, int x0, int y0, double h, double tangent){
//     double theta1 = acos(h/tangent);
//     double theta2 = atan((y-y0)/(x-x0));
//     double a = theta2 - theta1;
//     double b = theta2 + theta1;
//     interval pt;
//     pt.start = a;
//     pt.end = b;
//     return pt;

// }
// interval solve2(int x, int y, int r, int x0, int y0, double h, double dis ){
//     double theta1 = acos( (dis*dis + h*h - r*r) / (2*dis*h));         // cosA = (b^2 + c^2 -a^2)/2bc;
//     double theta2 = atan( (y-y0)/(x-x0));
//     double a = theta2 - theta1;
//     double b = theta2 + theta1;
//     interval pt;
//     pt.start = a;
//     pt.end = b;
//     return pt;
// }


// double intersect(double start1, double end1, double start2, double end2) {
//   return min(end1, end2) - max(start1, start2);
// }

// double union_angle(vector<interval> intervals) {
//   sort(intervals.begin(), intervals.end());
//   double angle = 0, start = 0, end = 0;
//   for (int i = 0; i < intervals.size(); i++) {
//     if (intervals[i].start <= end) {
//       end = max(end, intervals[i].end);
//     } else {
//       angle += intersect(start, end, 0, pi * 2);
//       start = intervals[i].start;
//       end = intervals[i].end;
//     }
//   }
//   angle += intersect(start, end, 0, pi * 2);
//   return angle / (2 * pi);
// }

// double probabilityOfSurvival(int x0, int y0, int v, int t, vector<int> &x, vector<int> &y, vector<int> &r)
// { 
//     cout << fixed << setprecision(4);

//     double dis = v*t*1.0;
//     int n = x.size();
//     vector<interval> intervals;

//     for(int i=0; i<n; ++i){
//         double originTocentre = sqrt((x0-x[i])*(x0-x[i])+(y0-y[i])*(y0-y[i]));
//         double tangent = sqrt(originTocentre*originTocentre -r[i]*r[i]);

//         if(dis>= tangent){  //case 1
//             intervals.push_back( solve(x[i], y[i], r[i], x0, y0, originTocentre, tangent) );
//         }
//         else if(dis >= originTocentre-r[i]){ //case 2
//             intervals.push_back( solve2(x[i], y[i], r[i], x0, y0, originTocentre, dis) );
//         }
//     }

//     // take union off all angles
//     double ans = union_angle(intervals);
//     // cout << ans << endl;
//     return ans;
// }



double calc(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double probabilityOfSurvival(int x0, int y0, int v, int t, vector<int> &x,
                             vector<int> &y, vector<int> &r) {

  const double eps = 1e-9;
  const double PI = acos(-1.0);
  double r0 = 1.0 * v * t;
  int n = x.size();
  vector<pair<double, int>> a;

  for (int i = 0; i < n; i++) {

    double d = calc(x[i], y[i], x0, y0);

    if (d < 1.0 * r[i] * r[i] + eps) { //origin lies inside circle
      return 1.0;
    }

    d = sqrt(d);
    if (r[i] + r0 < d - eps) {// cannot reach circle 
      continue;
    }

    double angL, angR, ang;
    double angM = atan2(y[i] - y0, x[i] - x0);
    if (angM < 0) {
      angM += 2 * PI;
    }

    double tLen = sqrt(d * d - 1.0 * r[i] * r[i]); //tangent
    if (tLen < r0 + eps) { //case 1 when we can visit all the angles in the circle
      ang = asin(r[i] / d); 
    }

    else {
      ang = acos((d * d + r0 * r0 - 1.0 * r[i] * r[i]) / (2 * d * r0));  //case 2 when we can only visit a circle segment cosA= (b2+c2-a2)/2bc
    }

    angL = angM - ang; //alpha
    angR = angM + ang; //beta

    if (angL < 0) {
      a.push_back(make_pair(angL + 2 * PI, 1));
      a.push_back(make_pair(2 * PI, -1));
      a.push_back(make_pair(0.0, 1));
      a.push_back(make_pair(angR, -1));
    }

    else if (angR > 2 * PI) {
      a.push_back(make_pair(angL, 1));
      a.push_back(make_pair(2 * PI, -1));
      a.push_back(make_pair(0.0, 1));
      a.push_back(make_pair(angR - 2 * PI, -1));
    }

    else {
      a.push_back(make_pair(angL, 1));
      a.push_back(make_pair(angR, -1));
    }
  }

  sort(a.begin(), a.end());

  double last = 0;
  int c = 0;
  double ans = 0;

  for (auto &p : a) {
    if (c > 0) {
      ans += p.first - last;
    }
    c += p.second;
    last = p.first;
  }

  ans /= 2 * PI;
  return ans;
}
```

## METEOR GARDEN
Ninja owns a garden which is in a rectangular shape on a planet named ‘Asgard’. He somehow manages to get information that his garden is the target of the coming meteor which is in a circular shape and ninja knows the radius and the coordinates of the center of the circle so he wants to know whether the meteor will overlap with his garden or not.
So your task is to check whether the meteor will overlap with the garden or not. You were provided with the coordinates of the bottom left corner and top right corner of the garden which is rectangular in shape and the center coordinates and radius of a meteor which is circular in shape.
Note :
If any point of the circle lies on the rectangle or inside the rectangle we say the circle is overlapping the rectangle.

```cpp
bool meteorGarden(int xC, int yC, int rad, int x1, int y1, int x2, int y2) 
{
	int closestX = max(x1, min(x2, xC));
	int closestY = max(y1, min(y2, yC));
	return (xC-closestX)*(xC-closestX)+(yC-closestY)*(yC-closestY) <= rad*rad;
}
```

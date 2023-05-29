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
## Area of Polygon
A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.
Given the vertices of a polygon, return its exact area.
Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t; cin>>t;

    int n;
    
    vector<double> x(n), y(n);
    while(t--){
      double area = 0;
      cin >> n;
      for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

      for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (i == n - 1)
          j = 0;

        area += ((y[i] + y[j]) * (x[i] - x[j])) / 2;
            
        }
        cout << (long long) abs(area) <<'\n';
    }

    return 0;
}
```
## Convex Hull
You are given N points in a 2-D plane and you have to find the convex hull using the most optimized approach.

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Point {
  ll x;
  ll y;
};

const int N = 1e5;
Point points[N + 1];
Point p0;

int orientation(Point a, Point b, Point c) {
  ll o = (c.x - b.x) * (b.y - a.y) - (c.y - b.y) * (b.x - a.x);

  // 0 = collinear
  //-1 = anti-clockwise
  // 1 = clockwise
  if (o == 0)
    return 0;
  else if (o > 0)
    return 1;
  else
    return -1;
}

ll dist(Point a, Point b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;

  return dx * dx + dy * dy;
}

bool comp(Point a, Point b) {
  int o = orientation(p0, a, b);

  if (o == 0) {
    return dist(p0, a) <= dist(p0, b);
  } else {
    return o == -1;
  }
}

int main() {

  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> points[i].x >> points[i].y;

      if (i == 1)
        p0 = points[i];
      else if (points[i].x < p0.x)
        p0 = points[i];
      else if (p0.x == points[i].x && p0.y > points[i].y)
        p0 = points[i];
    }

    sort(points + 1, points + n + 1, comp);

    // taking care of collinear points
    int i = n - 1;

    while (i > 1 && orientation(p0, points[i], points[n]) == 0)
      i--;
    reverse(points + i + 1, points + n + 1);

    vector<Point> hull;
    for (int i = 1; i <= n; i++) {
      while (hull.size() > 1 &&
             orientation(hull[hull.size() - 2], hull[hull.size() - 1],
                         points[i]) >= 0) {
        hull.pop_back();
      }

      hull.push_back(points[i]);
    }

    for (Point p : hull)
      cout << p.x << " " << p.y << endl;
  }
  return 0;
}
```

## Select Box $
You are given ‘N’ boxes of rectangle shape each having coordinates at (0, 0), (xi, 0), (0, yi), (xi, yi). Each box also has a cost associated with it ‘ci’. If you select some boxes then the value of them will be:
Area of union minus the sum of the cost of every selected box.
You have to print the maximum value which you can get by selecting some of the boxes.
```cpp
int selectBox(int n, vector<vector<int>> &v)
{
  vector<int> dp(n+1, 0);
  // sort(begin(v), end(v));

  dp[0]=v[0][0]*v[0][1]-v[0][2];
  for (int i = 0; i < n; i++) {
    dp[i] = v[i][0]*v[i][1]-v[i][2];
    for (int j = 0; j < i; j++) {
      dp[i] = max(dp[i], dp[j] + (v[i][0] * v[i][1] - v[i][2]) - v[j][0] * v[i][1]); 
    }
  }

 int ans = *max_element(begin(dp), end(dp));
  return ans;
// return dp[n-1];
}
```
## Polygon Mastery $$
Ninja loves polygons. His friend gave him two polygons, in an infinite ‘2D’ grid where no ‘3’ consecutive vertex of each polygon are in the same line.
The first polygon is a convex polygon represented by the ‘N’ vertex in a 2D grid, all ‘N’ points are in a clockwise direction.
The second polygon is an arbitrary polygon represented by the ‘M’ vertex in the same 2D grid, all ‘M’ points are in a clockwise direction.
The second polygon is said to be ‘WELL FITTED’ if it lies strictly inside the first polygon, which your friend finds hard to check. He wants your help in finding the same.
Can you help your friend in finding if the second polygon is well fitted?
Example :
N = 3
POLY1 = [ [ 1, 2 ], [ 5, 5 ], [ 6, 1 ] ]
M = 3
POLY2 = [ [ 4, 3 ], [ 5, 2 ], [ 3, 2] ] 
The second polygon lies strictly inside the first polygon so it is ‘WELL FITTED’, the answer is ‘1’.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases are as follows.

The first line of each test case contains the integer ‘N’ denoting the number of a vertex in the first polygon.

The next ‘N’ lines contain the ‘2’ integers denoting the position of each vertex in a graph in a clockwise direction.

The next line of each test case contains the integer ‘M’ denoting the number of a vertex in the second polygon.

The next ‘M’ lines contain the ‘2’ integers denoting the position of each vertex in a graph in a clockwise direction.
Output format :
For each test case, print “YES” if the second polygon is “WELL FITTED”, else print “NO”.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
```
Constraints :
1 <= T <= 10
1 <= N  <= 10^5
-10^9 <= POLY1[i][0] , POLY1[i][1] <= 10^9
 1 <= M  <= 10^4
-10^9 <= POLY2[i][0] , POLY2[i][1] <= 10^9

Sum of N <= 10^5 and M <= 10^4

Time Limit: 1 sec
Sample Input 1 :
2
3
1 2
5 5
6 1
3
4 3
5 2
3 2
4
-10 -10
-10 10
10 10
10 -10
3
0 10
2 2
1 5
Sample Output 1 :
YES
NO
```

```cpp
//90% AC

#define ll long long
bool isInside(ll x, ll y, vector<vector<int>> &polygon) {
  int n = polygon.size();
  ll prev_x = polygon[n - 1][0], prev_y = polygon[n - 1][1];
  ll cur_x, cur_y;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    cur_x = polygon[i][0];
    cur_y = polygon[i][1];

    long double m = (prev_x-cur_x);
    m *= (y-cur_y);
    m /= (prev_y-cur_y);
    m += cur_x;

    if ((cur_y > y) != (prev_y > y) && x*1.0 <m)
      flag = !flag;
    prev_x = cur_x;
    prev_y = cur_y;
  }
  return flag;
}

string wellFitted(int n, vector<vector<int>> polygon1, int m,
                  vector<vector<int>> polygon2) {
   

   if(polygon1==polygon2) return "YES";
   
  for (int i = 0; i < m; i++) {
    if (!isInside(polygon2[i][0], polygon2[i][1], polygon1))
      return "NO";
  }
  return "YES";
}
```

```cpp
//100% AC SOL
/*
Time Complexity : O( (N + M)*log(N + M) )
Space Complexity : O( N + M )
Where 'N + M' is total number of points in both polygons.
*/
struct Point {
int x, y;
Point(int x = 0, int y = 0) : x(x), y(y) {}
inline Point operator - (const Point& p) const {
return Point(x - p.x, y - p.y);
}
inline long long operator * (const Point& p) const {
return (long long)x * p.y - (long long)y * p.x;
}
inline bool operator < (const Point& p) const {
return x < p.x || (x == p.x && y < p.y);
}
};
inline int convexHall(int n, Point p[], Point q[]) {
if (n < 3) {
memcpy(q, p, sizeof(Point) * n);
return n;
} else {
int c;
sort(p, p + n);
for (int i = c = 0; i < n; q[c++] = p[i++]) {
for (; c > 1 && (q[c - 1] - q[c - 2]) * (p[i] - q[c - 1]) < 0; --c);
}
for (int i = n - 2, j = c; i >= 0; q[c++] = p[i--]) {
for (; c > j && (q[c - 1] - q[c - 2]) * (p[i] - q[c - 1]) < 0; --c);
}
return c - 1;
}
}
string wellFitted(int n, vector < vector < int > > polygon1 , int m, vector < vector < int > > polygon2)
{
// We will create a Structred points for both Polygons and a an array convex which stores convex hall.
Point p[n + m] , convex[n + m];
// Two set stores points of inital two polygons,'POLY1' for first and 'POLY2' for second.
set < Point > poly1 , poly2;
// Inserting first polygon into set and 'P'.
for(int i = 0;i<n;i++) {
p[i].x = polygon1[i][0] , p[i].y = polygon1[i][1];
poly1.insert(p[i]);
}
// Inserting second polygon into set and 'P'.
for(int i = 0;i<m;i++) {
p[i + n].x = polygon2[i][0] , p[i + n].y = polygon2[i][1];
poly2.insert(p[i + n]);
}
// Calculating the Convex Hall.
int N = convexHall(n + m , p , convex);
// 'WILLFIT' is a bool check if it is in fit.
bool wellfit = true;
// If current point in Convex Hall is not in our set we will return false and break.
for(int i = 0;i<N;i++){
if(poly1.find(convex[i]) == poly1.end()) {
wellfit = false;
break;
}
if(poly2.find(convex[i]) != poly2.end()) {
	wellfit = false;
	break;
	}
}
// If "WELLFIT" is true, return "YES", else return "NO"
if(wellfit){
	return "YES";
}
return "NO";
}
	

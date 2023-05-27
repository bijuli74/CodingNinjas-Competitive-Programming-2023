#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>a, int n, int K) {
    vector<vector<int>>ans;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int target = K - a[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back) {
            int sum = a[front] + a[back];

            if (sum < target) {
                front++;
            }

            else if (sum > target) {
                back--;
            }

            else {
                int x = a[front];
                int y = a[back];
                ans.push_back({a[i], a[front], a[back]});

                while (front < back && a[front] == x) {
                    front++;
                }
                while (front < back && a[back] == y) {
                    back--;
                }
            }
        }

        while (i + 1 < n && a[i] == a[i + 1]) {
            i++;
        }
    }
    return ans;
}


vector<int> kLargest(int a[], int n, int k) {
    partial_sort(a, a+k, a+n, greater<int>());
    vector<int> ans;
    ans.assign(a, a+k);
    return ans;

}

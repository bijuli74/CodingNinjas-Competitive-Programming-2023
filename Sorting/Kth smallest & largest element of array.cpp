#include <algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(begin(arr), end(arr));
	int small=arr[k-1], large=arr[n-k];
	return {small, large};
}

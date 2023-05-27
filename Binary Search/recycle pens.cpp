#define ll long long
int recyclePens(int n, int R, int k, int c ){

	int l=0, r=n;
	int ans=0;
	while(l<=r){
		ll mid = (l+r)/2;
		ll recyclecost=(n-mid)*k;
		ll totalcost=recyclecost+R;
		if(totalcost>=mid*c){
			l=mid+1;
			ans=mid;
                } else {
                  r = mid - 1;
                }
        }
        return ans;
}

#define ll  long long int
ll  power(ll  b, ll  p, ll  m){
	ll  r=1;
	b%=m;
	while(p>0){
		if(p&1){
			r = r * b % m;
		}
		b= b * b % m;
		p>>=1;
	}
	return r;
}

ll  factorialAgain(ll  n, ll  p)
{
	n =  ( (n*3)%p + p)%p;   //most weird shit ever. Giving WA otherwise
	ll  dem = power(6, n/3, p);
	//weird cannot gives WA if dem is calculated before hand like power(6, n, p);
	ll  num = p-1;
	for(int i=n+1; i<=p-1; ++i)
		num = (num * power(i, p-2, p))%p;
	ll  ans = num * power(dem, p-2, p)%p;
	return ans;
}

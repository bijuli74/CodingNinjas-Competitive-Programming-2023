#include <vector>

vector<int> nextGreaterElement(vector<int> a) {
	int n=a.size();
	vector<int> ng(n, -1);
	for(int i=0; i<n; ++i){
		ng[i]=i+1;
		while(ng[i]<n && a[ng[i]]<a[i]){
			ng[i]=ng[ng[i]];
		}
		
	}
	return ng;
	// vector<int> ng;
	// int nxt;
	// for(int i=0; i<n; ++i){
	// 	nxt=-1;
	// 	for(int j=i+1; j<n; ++j){
	// 		if(a[i]<a[j]){
	// 			nxt=a[j];
	// 			break;
	// 		}
	// 	}
	// 	ng.push_back(nxt);
	// }
	// return ng;

}

#include <algorithm>
int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{
	int cnt=0;
    for(int i=0; i<pants.size(); ++i){
        for(int j=0; j<shirts.size(); ++j){
            for(int k=0; k<shoes.size(); ++k){
                for(int l=0; l<skirts.size(); ++l){
                    if(pants[i]+shirts[j]+shoes[k]+skirts[l]<=budget)
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

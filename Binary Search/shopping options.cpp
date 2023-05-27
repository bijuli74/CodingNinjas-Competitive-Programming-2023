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

/*
Time Complexity: O((R * S + P * Q) * log(P * Q))
Space Complexity: O(P * Q)
Where ‘P’, ‘Q’, ‘R’, and ‘S’ denote the number of pants, shirts, shoes, skirts respectively.
*/
#include<algorithm>
// To find number of smaller values in an array than the given value.
int getSmallerNumbers(vector<int> vec, int val)
{
int left = 0, right = vec.size();
while (left < right)
{
int mid = (left + right) / 2;
if (vec[mid] <= val)
{
left = mid + 1;
}
else
{
right = mid;
}
}
return left;
}
int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int
budget)
{
//To store number of ways to buy
int answer = 0;
vector<int> sumOfPantsAndShirts((int)(pants.size() * shirts.size()));
int counter = 0;
// To generate every possible combinations of pants and shirts.
for (int i = 0; i < pants.size(); i++)
{
for (int j = 0; j < shirts.size(); j++)
{
// Store the sum in the array
sumOfPantsAndShirts[counter] = pants[i] + shirts[j];
counter = counter + 1;
}
}
// Sort all the combinations in ascending order.
sort(sumOfPantsAndShirts.begin(), sumOfPantsAndShirts.end());
for (int i = 0; i < shoes.size(); i++)
{
for (int j = 0; j < skirts.size(); j++)
{
// To store remaining amount
int remainingAmount = budget - shoes[i] - skirts[j];
// Adding all smaller or equal numbers than remainingAmount.
answer = answer + getSmallerNumbers(sumOfPantsAndShirts, remainingAmount);
}
}
return answer;
}

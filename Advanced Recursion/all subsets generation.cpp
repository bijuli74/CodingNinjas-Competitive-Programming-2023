void subsets(vector<int>& arr, int i, vector<int> tmp, int n, vector<vector<int>>& ans){
    if(i==arr.size()){
        if(tmp.size()>0) ans.push_back(tmp);
        return;
    }
    subsets(arr, i+1, tmp, n, ans);

    tmp.push_back(arr[i]);
    subsets(arr, i+1, tmp, n, ans);
}
vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> tmp;
    subsets(arr, 0, tmp, n, ans);
    return ans;

}

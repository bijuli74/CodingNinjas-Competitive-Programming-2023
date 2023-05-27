#include <bits/stdc++.h>
using namespace std;

const int N = 10;

void printout(vector<string>& mat, int n){
    for(int i=0; i<n; i++)
			cout<<mat[i]<<'\n';
}

vector<string> checkHorz(int x, int y, vector<string> mat, string cur_word){
	int n = cur_word.size();
	for(int i=0; i<n; i++){
		if(mat[x][y+i]=='-' || mat[x][y+i]==cur_word[i])
			mat[x][y+i] = cur_word[i];
		else{
			mat[0][0] = '@';
			return mat;
		}
	}
	return mat;
}

vector<string> checkVert(int x, int y, vector<string> mat, string cur_word){
	int n = cur_word.size();
	for(int i=0; i<n; i++){
		if(mat[x+i][y]=='-' || mat[x+i][y]==cur_word[i])
			mat[x+i][y] = cur_word[i];
		else{
			mat[0][0] = '@';
			return mat;
		}
	}
	return mat;
}

void solve(vector<string>& words, vector<string> mat, int idx, int n){
	if(idx < words.size()){
		string cur_word = words[idx];
		int mx_len = n - cur_word.size();

		for(int i=0; i<n; i++){
			for(int j=0; j<=mx_len; j++){
				vector<string> tmp = checkVert(j, i, mat, cur_word);
				if(tmp[0][0] != '@')
					solve(words, tmp, idx+1, n);
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<=mx_len; j++){
				vector<string> tmp = checkHorz(i, j, mat, cur_word);

				if(tmp[0][0] != '@')
					solve(words, tmp, idx+1, n);
			}
		}

	}
	else{
		printout(mat, n);
        cout<<endl;

		return;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<string> mat;
    
	for(int i=0; i<10; ++i){
        string s; cin>>s;
        mat.push_back(s);
    }

	vector<string> words;
	string s; cin>>s;
	int st=0;
	for(int i=0; i<s.size(); ++i){
		if(s[i]==';'){
			words.push_back(s.substr(st, i-st));
			st=i+1;
		}
	}
	words.push_back(s.substr(st, s.size()-st));
    
    //for(auto m: mat) cout<<m<<endl;
    //for(auto w: words) cout<<w<<" ";

	solve(words, mat, 0, N);
    return 0;
}

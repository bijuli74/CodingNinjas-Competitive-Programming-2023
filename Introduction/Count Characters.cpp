#include<iostream>
using namespace std;

int main() {
	char c;
	c = cin.get();
	int cnt=0, cnt1=0, cnt2=0;
	while (c != '$') {
		if('a'<=c&&c<='z') ++cnt;
		if('0'<=c&&c<='9') ++cnt1;
		if(c==' '||c=='\n'||c=='\t') ++cnt2;
		c = cin.get();
	}
	cout << cnt << " " << cnt1 << " " << cnt2;
}

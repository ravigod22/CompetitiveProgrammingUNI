#include <bits/stdc++.h>

using namespace std;

const string compare[7] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	bool ans = false;
	for(int i = 0; i < 7; i++){
		if(s == compare[i]){
			ans = true;
			break;
		}
	}
	
	cout << (ans ? "Yes" : "No") << '\n';
	return 0;
} 

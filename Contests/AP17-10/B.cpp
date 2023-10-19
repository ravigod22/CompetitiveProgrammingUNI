#include <bits/stdc++.h>

using namespace std;

const int MAX = 115;

vector<vector<char>> matrix(MAX, vector<char> (MAX, '0'));

void imprimir(int a, int b){
	for(int x = a - 1; x < a + 10; x++){
		for(int y = b - 1; y < b + 10; y++){
			cout << matrix[x][y] << ' ';
		}
		cout << '\n';	
	}
	cout << '\n';
}

bool takcode(int i, int j){
	
	bool ans = true;
	for(int a = i; a <= i + 2; a++){
		for(int b = j; b <= j + 2; b++){
			if(matrix[a][b] != '#') ans = false;
		}
	}
	for(int a = i + 6; a < i + 9; a++){
		for(int b = j + 6; b < j + 9; b++){
			if(matrix[a][b] != '#') ans = false;
		}
	}
	
	
	for(int b = i; b <= i + 3; b++){
		 //if(matrix[i - 1][b] == '#') return 0;
		 if(matrix[i + 3][b] != '.' or matrix[i + 5][b + 5] != '.') ans = false;
		 //if(matrix[i + 9][b + 6] == '#') return 0;
 	}
 	for(int a = j; a <= j + 3; a++){
		 //if(matrix[a][j - 1] == '#') return 0;
		 if(matrix[a][j + 3] != '.' or matrix[a + 5][j + 5] != '.') ans = false;
		 //if(matrix[a + 6][j + 9] == '#') return 0;
 	}
 	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			char x;
			cin >> x;
			matrix[i][j] = x;
		}
	}
	vector<pair<int,int>> ans;
	
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(takcode(i, j)){
				cout << i << " " << j << '\n';
				imprimir(i ,j);
				ans.push_back({i, j});
			}
		}
	}
	imprimir(1, 10);
	sort(ans.begin(), ans.end());
	
	for(auto e : ans){
		cout << e.first << " " << e.second << "\n";
	}
	
	return 0;
}

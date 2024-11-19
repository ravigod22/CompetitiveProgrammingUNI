#include <bits/stdc++.h>
using namespace std;
long long square(int x) {
	return 1ll * x * x;
}
bool is_colineal(vector<pair<int, int>>& p) {
    for (int i = 0; i < 4; ++i) {
    	set<int> x;
    	set<int> y;
        int p1_x = p[i].first;
        int p1_y = p[i].second;
        int p2_x = p[(i + 1) % 4].first;
        int p2_y = p[(i + 1) % 4].second;
        int p3_x = p[(i + 2) % 4].first;
        int p3_y = p[(i + 2) % 4].second;
        x.emplace(p1_x);
        x.emplace(p2_x);
        x.emplace(p3_x);
        y.emplace(p1_y);
        y.emplace(p2_y);
        y.emplace(p3_y);
        if ((int)x.size() == 1) return true;
        if((int)y.size() == 1) return true;
        x.clear(), y.clear();
    }
	return false;
}
bool is_square(vector<pair<int,int>>& p) {
	set<long long> d;
	for (int i = 0; i < 4; ++i) {
		long long dis = square(p[(i + 1) % 4].first - p[i].first) + square(p[(i + 1) % 4].second - p[i].second);
		d.emplace(dis);
	}
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int m1_y = p[(i + 3) % 4].second - p[i].second;
		int m1_x = p[(i + 3) % 4].first - p[i].first;
		int m2_y = p[(i + 1) % 4].second - p[i].second;
		int m2_x = p[(i + 1) % 4].first - p[i].first;
		if (1ll * m1_x * m2_x == 1ll * -1 * m1_y * m2_y) cnt++;
	}
	int cnt_1 = 0;
	for (int i = 0; i < 2; ++i) {
		int m1_y = p[i + 1].second - p[i].second;
		int m1_x = p[i + 1].first - p[i].first;
		int m2_y = p[(i + 3) % 4].second - p[i + 2].second;
		int m2_x = p[(i + 3) % 4].first - p[i + 2].first;
		if (1ll * m1_y * m2_x == 1ll * m1_x * m2_y) cnt_1++;
	}
	if (cnt == 4 && (int)d.size() == 1 && cnt_1 == 2) return true;
	return false;
}
bool is_rectangle(vector<pair<int,int>>& p) {
	set<long long> d;
	for (int i = 0; i < 4; ++i) {
		long long dis = square(p[(i + 1) % 4].first - p[i].first) + square(p[(i + 1) % 4].second - p[i].second);
		d.emplace(dis);
	}
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int m1_y = p[(i + 3) % 4].second - p[i].second;
		int m1_x = p[(i + 3) % 4].first - p[i].first;
		int m2_y = p[(i + 1) % 4].second - p[i].second;
		int m2_x = p[(i + 1) % 4].first - p[i].first;
		if (1ll * m1_x * m2_x == 1ll * -1 * m1_y * m2_y) cnt++;
	}
	int cnt_1 = 0;
	for (int i = 0; i < 2; ++i) {
		int m1_y = p[i + 1].second - p[i].second;
		int m1_x = p[i + 1].first - p[i].first;
		int m2_y = p[(i + 3) % 4].second - p[i + 2].second;
		int m2_x = p[(i + 3) % 4].first - p[i + 2].first;
		if (1ll * m1_y * m2_x == 1ll * m1_x * m2_y) cnt_1++;
	}
	if (cnt == 4 && (int)d.size() == 2 && cnt_1 == 2) return true;
	return false;
}
bool is_rombe(vector<pair<int,int>>& p) {
	set<long long> d;
	for (int i = 0; i < 4; ++i) {
		long long dis = square(p[(i + 1) % 4].first - p[i].first) + square(p[(i + 1) % 4].second - p[i].second);
		d.emplace(dis);
	}
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int m1_y = p[(i + 3) % 4].second - p[i].second;
		int m1_x = p[(i + 3) % 4].first - p[i].first;
		int m2_y = p[(i + 1) % 4].second - p[i].second;
		int m2_x = p[(i + 1) % 4].first - p[i].first;
		if (1ll * m1_x * m2_x == 1ll * -1 * m1_y * m2_y) cnt++;
	}
	if (cnt == 0 && (int)d.size() == 1) return true;
	return false;
}
bool is_paralelogram(vector<pair<int,int>>& p) {
	set<long long> d;
	for (int i = 0; i < 4; ++i) {
		long long dis = square(p[(i + 1) % 4].first - p[i].first) + square(p[(i + 1) % 4].second - p[i].second);
		d.emplace(dis);
	}
	int cnt = 0;
	for (int i = 0; i < 2; ++i) {
		int m1_y = p[i + 1].second - p[i].second;
		int m1_x = p[i + 1].first - p[i].first;
		int m2_y = p[(i + 3) % 4].second - p[i + 2].second;
		int m2_x = p[(i + 3) % 4].first - p[i + 2].first;
		if (1ll * m1_y * m2_x == 1ll * m1_x * m2_y) cnt++;
	}
	if (cnt == 2 && (int)d.size() == 2) return true;
	return false;
}
bool is_trapezium(vector<pair<int,int>>& p) {
	int cnt = 0;
	for (int i = 0; i < 2; ++i) {
		int m1_y = p[i + 1].second - p[i].second;
		int m1_x = p[i + 1].first - p[i].first;
		int m2_y = p[(i + 3) % 4].second - p[i + 2].second;
		int m2_x = p[(i + 3) % 4].first - p[i + 2].first;
		if (1ll * m1_y * m2_x == 1ll * m1_x * m2_y) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}
bool is_kite(vector<pair<int,int>>& p) {
	set<long long> d;
	for (int i = 0; i < 4; ++i) {
		long long dis = square(p[(i + 1) % 4].first - p[i].first) + square(p[(i + 1) % 4].second - p[i].second);
		d.emplace(dis);
	}
	int cnt = 0;
	for (int i = 0; i < 2; ++i) {
		int m1_y = p[i + 1].second - p[i].second;
		int m1_x = p[i + 1].first - p[i].first;
		int m2_y = p[(i + 3) % 4].second - p[i + 2].second;
		int m2_x = p[(i + 3) % 4].first - p[i + 2].first;
		if (1ll * m1_y * m2_x == 1ll * m1_x * m2_y) cnt++;
	}
	if (cnt == 0 && (int)d.size() == 2) return true;
	return false;
}
void solve() {
	vector<pair<int,int>> point;
	for (int i = 0; i < 4; ++i) {
		int x, y;
		cin >> x >> y;
		point.emplace_back(x, y);
	}
	if(is_colineal(point)) {
		cout << "none\n";
		return;
	}
	if(is_square(point)) {
		cout << "square\n";
	}
	else if (is_rectangle(point)) {
		cout << "rectangle\n";
	}
	else if (is_rombe(point)) {
		cout << "rhombus\n";
	}
	else if (is_paralelogram(point)) {
		cout << "parallelogram\n";
	}
	else if (is_trapezium(point)) {
		cout << "trapezium\n";
	}
	else if(is_kite(point)) {
		cout << "kite\n";
	}
	else {
		cout << "none\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}

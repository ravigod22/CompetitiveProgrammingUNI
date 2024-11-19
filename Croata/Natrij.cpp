#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int n = s1.size();
    
    int h;
    int m;
    int s;
    h = (s1[0] - '0') * 10 + (s1[1] - '0');
    m = (s1[3] - '0') * 10 + (s1[4] - '0');
    s = (s1[6] - '0') * 10 + (s1[7] - '0');
    int num1 = h * 3600 + m * 60 + s;
    
    h = (s2[0] - '0') * 10 + (s2[1] - '0');
    m = (s2[3] - '0') * 10 + (s2[4] - '0');
    s = (s2[6] - '0') * 10 + (s2[7] - '0');

    int num2 = h * 3600 + m * 60 + s;
    if(num2 < num1) num2 += 3600*24;
    int c = num2 - num1;

    char ans[8];
    ans[2] = ans[5] = ':';

    int x = (c/3600);
    int y = (c - x*3600)/60;
    int z = c % 60;
    
    int tmp, tmp2;
    if(x > 10){
        tmp = x/10;
        tmp2 = x%10;
        ans[0] = (char) (tmp + '0');
        ans[1] = (char) (tmp2 + '0');
    }
    else{
        ans[0] = '0';
        ans[1] = (char) (x + '0');
    }

    if(y > 10){
        tmp = y/10;
        tmp2 = y%10;
        ans[3] = (char) (tmp + '0');
        ans[4] = (char) (tmp2 + '0');
    }
    else{
        ans[3] = '0';
        ans[4] = (char) (y + '0');
    }

    if(z > 10){
        tmp = z/10;
        tmp2 = z%10;
        ans[6] = (char) (tmp + '0');
        ans[7] = (char) (tmp2 + '0');
    }
    else{
        ans[6] = '0';
        ans[7] = (char) (z + '0');
    }
    for(int i = 0; i < 8; i++){
        cout << ans[i];
    }
    return 0;
}

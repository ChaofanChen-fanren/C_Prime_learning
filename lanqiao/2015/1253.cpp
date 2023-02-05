#include <bits/stdc++.h>
using namespace std;
int dfs(int u,int cnt)
{
    if (cnt == 13)
        return 1;
    if(u > 13 || cnt > 13) return 0;

    int res = 0;
    for(int i = 0;i <= 4;i++){
        res += dfs(u + 1,cnt + i);
    }
    return res;
}
void slove2()
{
    cout<<dfs(1, 0)<<endl;
}
void slove3()
{
    int f[14][14] = {0};// 枚举前i个字牌，且已经枚举完了j个位置
    f[0][0]       = 1;
    for(int i = 1;i <= 13;i++){
        for(int j = 0;j <= 13;j++){
            for(int k = 0;k <= min(j,4);k++){
                f[i][j] += f[i - 1][j - k];
            }
        }
    }
    cout<<f[13][13]<<endl;
}
int main()
{
    //1.纯暴力枚举
    //2.dfs
    //3.动态规划
    // slove2();
    slove3();
    return 0;    
}

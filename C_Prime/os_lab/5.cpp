/*
如果内存中有该页，那么访问位置1，指针指向该位置+1
如果内存中没有该页，那么顺着指针循环遍历
遇到访问位为1的置0，遇到访问位为0的置换页面，且指针+1。
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;      // 物理块个数、作业页面个数
int page[20];  // 需要访问的页面
struct Mem
{               // 内存
    int pnum;   // 页面号
    int visit;  // 访问位
} mem[10];
int idx = 1;   // 内存指针
int lack_cnt;  // 缺页次数

// 输入一个页面号，返回内存中的位置，返回-1则没有
int find(int x)
{
    for (int i = 1; i <= n; i++) {
        if (mem[i].pnum == x)
            return i;
    }
    return -1;
}

// 输出当前内存的情况
void myprint()
{
    for (int i = 1; i <= n; i++)
        cout << '|' << mem[i].pnum << "|" << mem[i].visit << '|' << '\t';
    cout << endl;
}

int main()
{
    cout << "请输入物理块的个数" << endl;
    cin >> n;
    cout << "请输入页面个数" << endl;
    cin >> m;
    cout << "请依次输入作业的页面走向" << endl;
    for (int i = 1; i <= m; i++)
        cin >> page[i];
    cout << endl;

    // 遍历页面
    for (int i = 1; i <= m; i++) {
        int j = find(page[i]);
        if (j == -1) {   // 如果内存没有
            lack_cnt++;  // 缺页次数++
            while (1) {
                // 遇到访问位为1,置0
                if (mem[idx].visit == 1) {
                    mem[idx].visit = 0;
                }
                else {  // 访问位为0，置换页面
                    mem[idx].pnum = page[i];
                    mem[idx].visit = 1;
                    break;
                }
                // 指针循环遍历
                idx++;
                if (idx == n + 1)
                    idx = 1;
            }
        }
        else {  // 内存中有，引用置1，指针定位
            idx = j;
            mem[idx].visit = 1;
        }
        idx++;
        if (idx == n + 1)
            idx = 1;
        cout << "当前页面" << page[i] << endl;
        myprint();
    }
    cout << endl;
    cout << "缺页次数:" << lack_cnt << '\t' << "缺页率:" << lack_cnt << '/' << m
         << endl;
    return 0;
}
/*
4
12
4 3 2 1 4 3 5 4 3 2 1 5

6
12
4 3 2 1 4 3 5 4 3 2 1 5
*/

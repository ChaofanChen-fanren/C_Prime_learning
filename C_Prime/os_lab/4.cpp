/*
 缺页中断
 最近最久未使用置换算法
 */
#include <algorithm>
#include <iostream>
#include <vector>
#define MLim 50   // 设置内存中页表长度上限
#define Mnum 100  // 设置所要访问的页面的最大个数
using namespace std;
int sum = 0;  // 缺页次数
int t = -1;   // 顺序
class CLOCK {
  public:
    CLOCK(int page, int visit[], int nv)
        : v(visit, visit + nv), st(page, 0), p(page, -1)
    {
        plen = page;
        idx = 0;
    }
    int isInPage(int x);  // 所要访问的页面x是否在内存中
    void PageFault();     // 缺页中断

  private:
    vector<int> v;     // 所要访问的页面
    vector<int> p;     // 内存中页表
    vector<int> st;    // 访问位
    int plen;          // 内存中页表长度
    int idx;           // 内存指针
};
int CLOCK::isInPage(int x)
{
    for(int i = 0;i < p.size();i++){
        if(p[i] == x) return i;
    }
    return -1;  // 不在页表中
}
void CLOCK::PageFault()
{
    int i, j;
    for (i = 0; i < v.size(); i++) {
        if (isInPage(v[i]) == -1) {  // 不在内存
            sum++;
            int pre_page = -1;
            while (1) {
                // 遇到访问位为1,置0
                if (st[idx] == 1) {
                    st[idx] = 0;
                }
                else {  // 访问位为0，置换页面
                    pre_page = p[idx];
                    p[idx] = v[i];
                    st[idx] = 1;
                    break;
                }
                // 指针循环遍历
                idx++;
                if (idx == plen)
                    idx = 0;
            }
            if (pre_page == -1) {
                cout << "Page: " << v[i] << " put in the empty memory block"
                     << endl;
            }
            else {
                cout << "Page: " << v[i]
                     << " put in the  memory block and change page : "
                     << pre_page << endl;
            }
        }
        else {  // 内存中有，引用置1，指针定位
            cout << "Page :" << v[i] << "  in memory block" << endl;
            idx = isInPage(v[i]);
            st[idx] = 1;
        }
        idx++;
        if (idx == plen)
            idx = 0;
    }
    cout << "缺页次数为：" << sum << endl;
    cout << "缺页率为：" << sum * 100.0 / v.size() << "%"<<endl;
}

int main()
{
    int visit[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int page = 3;
    cout << "Quest Page: ";
    for (int i = 0; i < 12; i++) {
        cout << visit[i] << " ";
    }
    cout << endl;
    CLOCK f(3, visit, 12);
    f.PageFault();
    return 0;
}

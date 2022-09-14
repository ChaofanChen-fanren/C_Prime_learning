#include <iostream>
using namespace std;
int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,otherCnt = 0;
    char ch;
    while(cin >> ch){
        switch (ch){
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }

    cout<<aCnt<<" "<<eCnt<<" "<<iCnt<<" "<<oCnt<<" "<<uCnt<<endl;
    cout<<otherCnt<<endl;

    return 0;
}

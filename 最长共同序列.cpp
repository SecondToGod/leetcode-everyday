#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
#define N 10
int findMatch(const char *a,const char *b){
    int index = 0,ans = 0;
    string s0 = a,s1 = b;
    int times = min(s0.size(),s1.size());
    if(s0.size()!=s1.size()) return -1;
    for(int i=0;i<times;++i){
        if(int(a[i])>57 || int(a[i])<48) return -1;//
        else{
            if(a[i] == b[i]) {
                index++;
            }
            else{
                ans = max(index,ans);
                index = 0;
            }
        }
        ans = max(index,ans);
    }
    return ans;
}
int main(){
    char *num0 = new char[N],*num1 = new char[N];
    cin >> num0 >> num1;
    int result = findMatch(num0,num1);
    cout<<result<<endl;
    delete [] num0;
    delete [] num1;
    system("pause");
    return 0;
}
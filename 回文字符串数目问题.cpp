#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
//采取向两边扩展的方法
void palistr(string &s){
    unsigned int len = s.size();
    unsigned int n;//p,n分别指向子串首尾位置
    unsigned int ans = len;
    unsigned int count;
    cout<<ans<<endl;
    for(int i=0;i<len;i+=count){
        n=i+1;
        int offset = 1;
        count = 1;
        while(s[n] == s[i]){//出现相邻重复项    
            count++;
            n++;
        }
        n--;//返回最后重复位置
        if(count%2 == 0){//偶数个重复则将重复看成一个整体向两边扩展
            cout<<i<<n<<count<<ans<<endl;
            if(count > 2) ans += count;//若只有两个连续，则只需加一
            else ans++;
            while(i-offset>=0 && n+offset<len && s[i-offset] == s[n+offset]){
                ans++;
                offset++;
            }
        }
    }//计算重复部分

   for(int i=1;i<len;++i){
       int offset = 1;//以中心位置的偏移
       while(i-offset>=0 && i+offset<len && s[i-offset] == s[i+offset]){      
            ans++;
            offset++;
       }
   }
   cout<<"共有回文子串"<<ans<<"个"<<endl;
} 
int main(){
    string s;
    char flag;
    do{
        cout<<"请输入字符串：";
        cin>>s;
        palistr(s);
        cout<<"继续？ y/n"<<endl;
        cin>>flag;
    }while(flag == 'y');
    system("pause");
    return 0;
}
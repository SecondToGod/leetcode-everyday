#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define N 100
void addBigNumber(string s1,string s2){
    int result[N+1]={0},arr1[N]={0},arr2[N]={0};
    for(int i=s1.length()-1,j=0;i>=0;--i,++j){
        arr1[j] = s1[i]-'0';//字符转数字
    }
    for(int i=s2.length()-1,j=0;i>=0;--i,++j){
        arr2[j] = s2[i]-'0';
    }
    int len = max(s1.length(),s2.length());
    int sum = 0,index;//结果位
    for(index=0;index<len;index++){
        sum += arr1[index] + arr2[index];
        result[index] = sum % 10;
        sum = sum /10;
    }
    if(sum > 0) {
        result[index] = sum;//高位进位
        len++;
    }
    int pos;
    for(index;index>=0;index--){
        if(result[index]!=0) {
            pos=index;break;
        }
    }
    for(index=pos;index>=0;index--){  
            cout<<result[index];
    }
}
int main(){
    //int n = 0;
    //cin>>n;
    //int target;
    char arr1[N]={'0'},arr2[N]={'0'};
    cin.getline(arr1,N);
    cin.getline(arr2,N);
    string s1 = arr1,s2 = arr2;
    /*int ele;
    while(cin >> ele){
        arr1.insert(arr.begin(),ele);
    }
    while(cin>>ele){
        arr2.insert(arr.begin(),ele);
    }
    cin.clear();*/
    //cin>>target;
    addBigNumber(s1,s2);
    /*char *number0 = new char[N],*number1=new char[N];
    cin>>number0;
    cin>>number1;
    int result = findMatch(number0,number1);
    cout<<result<<endl;*/
    system("pause");
    return 0;
}
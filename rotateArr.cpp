#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define N 100
//三次反转数组即可
//时间复杂读O(n),空间O(1)
void rotateArr(vector<int> &arr,int step){
    int len = arr.size();
    reverse(arr.begin(),arr.begin()+len-step);
    reverse(arr.begin()+len-step,arr.end());
    reverse(arr.begin(),arr.end());
    for(auto i:arr){
        cout<<i<<" ";
    }
}
int main(){
    //int n = 0;
    //cin>>n;
    int step;
    // char arr1[N]={'0'},arr2[N]={'0'};
    // cin.getline(arr1,N);
    // cin.getline(arr2,N);
    // string s1 = arr1,s2 = arr2;
    int ele;
    vector<int> arr;
    while(cin >> ele){
        arr.push_back(ele);
    }
    // while(cin>>ele){
    //     arr2.insert(arr.begin(),ele);
    // }
    cin.clear();
    cin>>step;
    rotateArr(arr,step);
    /*char *number0 = new char[N],*number1=new char[N];
    cin>>number0;
    cin>>number1;
    int result = findMatch(number0,number1);
    cout<<result<<endl;*/
    system("pause");
    return 0;
}
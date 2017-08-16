#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//排好序的数组
vector<int> deduplicate(vector<int> &arr){
    int index = 1;//index标记数组不同元素数目
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();++i){
       if(arr[i]!=arr[index-1]){
           ans.push_back(arr[i]);
           arr[index++] = arr[i];
       }
    }
    return ans;
}
int main(){
    //int n = 0;
    //cin>>n;
    //int target;
    vector<int> arr;
    int ele;
    while(cin>>ele){
        arr.push_back(ele);
    }
    cin.clear();
    vector<int>ans = deduplicate(arr);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    system("pause");
    return 0;
}
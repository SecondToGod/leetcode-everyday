#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//排好序的数组
vector<int> deDuplicatePlus(vector<int> &arr){
    int index = k;//index标记数组不同元素数目,k为允许重复次数
    vector<int> ans;
    for(int i = 0; i<index; i++) ans.push_back(arr[i]);
    for(int i=index;i<arr.size();++i){
       if(arr[i]!=arr[index-2]){//如果当前元素不等于目标数组-2的元素
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
    vector<int>ans = deDuplicatePlus(arr);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    system("pause");
    return 0;
}
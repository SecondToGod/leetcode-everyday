#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
//无序的数组
vector<int> consectiveSequence(vector<int> &arr){
    vector<int> ans;
    unordered_set<int> myset;
    for(auto i:arr){
        myset.insert(i);
    }
    int longest = 0;
    for(auto i:arr){
        int length=0;
            ans.push_back(i);
        for(int j=i-1;myset.find(j)!=myset.end();j--){
            ans.push_back(j);
            length++;
            reverse(ans.begin(),ans.end());//反转
        }//向左扩张
        for(int j=i+1;myset.find(j)!=myset.end();j++){
            ans.push_back(j);
            length++;
        }//向右扩张
        if(longest > length) ans.clear();
        longest = max(longest,length);
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
    vector<int>ans = consectiveSequence(arr);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    system("pause");
    return 0;
}
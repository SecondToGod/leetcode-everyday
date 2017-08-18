#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
#define N 9999
//无序数组
//先排序，再遍历,中间夹逼
//O(n) = min(nlogn,n^2)
int threeSumCloset(vector<int> &arr,const int target){
   int min_gap = N;
   int sum,gap;
   sort(arr.begin(),arr.end());
   for(auto i=arr.begin();i<arr.end()-2;++i){
        if(*i == *(i-1)) continue;
        auto j = next(i);
        auto k = prev(arr.end());
        while(j<k){
            sum = *i+*j+*k;
            gap = abs(sum-target);
            min_gap = min(gap,min_gap);
            if(sum < target){
                j++;
                while(*j == *(j-1)) j++;
            }
            else{
                k--;
                while(*k == *(k+1)) k--;
            }
        }
    }
    return min_gap; 
}
int main(){
    //int n = 0;
    //cin>>n;
    //int target;
    vector<int> arr;
    int ele,target;
    while(cin >> ele){
        arr.push_back(ele);
    }
    cin.clear();
    cin>>target;
    int ans = threeSumCloset(arr,target);
    cout<<ans<<endl;
    /*for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<< ans[i][j]<<", ";
        }
        cout<<endl;
    }*/
    /*char *number0 = new char[N],*number1=new char[N];
    cin>>number0;
    cin>>number1;
    int result = findMatch(number0,number1);
    cout<<result<<endl;*/
    system("pause");
    return 0;
}
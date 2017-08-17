#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define N 5
//无序数组
//先排序，再遍历,中间夹逼
//O(n) = min(nlogn,n^2)
vector< vector<int> > threeSum(vector<int> &arr){
    vector< vector<int> > ans;
    int target = 0;
    sort(arr.begin(),arr.end());
    for(auto i = arr.begin();i<arr.end()-2;++i){
        if(*i == *(i-1)) continue;
        auto j = i+1;
        auto k = arr.end();
        while(j < k){
            if(*i + *j + *k > target){
                --k;
                while(*k == *(k+1) && j<k) --k;
            }
            else if(*i + *j + *k < target){
                ++j;
                while(*j == *(j-1) && j<k) ++j;
            }
            else{
                ans.push_back({*i,*j,*k});
                ++j;
                --k;
                while(*k == *(k+1) && j<k) --k;
                while(*j == *(j-1) && j<k) ++j;
            }
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
    vector< vector<int> > ans = threeSum(arr);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<< ans[i][j]<<", ";
        }
        cout<<endl;
    }
    /*char *number0 = new char[N],*number1=new char[N];
    cin>>number0;
    cin>>number1;
    int result = findMatch(number0,number1);
    cout<<result<<endl;*/
    system("pause");
    return 0;
}
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void twosum(vector<int> &arr,int target){
    unordered_map<int,int> mymap;
    for(int i=0;i<arr.size();++i){
        mymap[arr[i]] = i;
    }
    for(int j=0;j<arr.size();++j){
        int rest = target - arr[j];
        if(mymap.find(rest)!=mymap.end()){
            int index = mymap[rest];
            if(index == j) continue;
            if(index<j){
                cout<<index<<","<<j<<endl;
                break;
            }
            else{
                cout<<j<<","<<index<<endl;
                break;
            }
        }
    }
}
int main(){
    //int n = 0;
    //cin>>n;
    int target;
    vector<int> arr;
    int ele;
    while(cin>>ele){
        arr.push_back(ele);
    }
    cin.clear();
    cout<<"please input target value:"<<endl;
    cin>>target;
    twosum(arr,target);
    system("pause");
    return 0;
}
#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define N 9999
//先扫描一边数组，存储较小的两个数，如果右边发现较大的数则存在解
//j先查找第二小的数，然后查找第三个小的数
bool incresingTriplets(vector<int> &nums) {
    int first ,second ;  
    for(auto i = nums.begin();i<=nums.end()-3;++i){ 
        auto j = next(i);
        if(*j > *i){
            first = *i;
            second = *j;
        }else{//找递增的第二个数
            while(*j <= *i && j != nums.end()-1){
                first = *j;
                j++;
            }
            if(j == nums.end()-1) continue;
            else second = *j;
        }
        j++;//赵递增的第三个数
        while(*j <= second && j!= nums.end()){
            j++;
        }
        if(j == nums.end()) return false;
        else return true;
    }
    return false;
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
    //cin>>target;
    bool ans = incresingTriplets(arr);
    cout<<ans<<endl;
    /*for(int i=0;i<ans.size();++i){
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
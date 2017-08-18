#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define N 9999
//无序数组
//先排序，再遍历,中间夹逼
//使用hash先缓存两个数的值  
//O(n) = min(nlogn,n^2)
vector< vector<int> > fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) return result;
    sort(nums.begin(), nums.end());

    unordered_map<int, vector<pair<int, int> > > cache;
    for (size_t a = 0; a < nums.size(); ++a) {
        for (size_t b = a + 1; b < nums.size(); ++b) {
            cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
        }
    }

    for (int c = 0; c < nums.size(); ++c) {
        for (size_t d = c + 1; d < nums.size(); ++d) {
            const int key = target - nums[c] - nums[d];
            if (cache.find(key) == cache.end()) continue;

            const auto &vec = cache[key];
            for (size_t k = 0; k < vec.size(); ++k) {
                if (c <= vec[k].second)
                    continue; // 有重叠

                result.push_back( { nums[vec[k].first],
                        nums[vec[k].second], nums[c], nums[d] });
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
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
    vector< vector<int> > ans = fourSum(arr,target);
    //cout<<ans<<endl;
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
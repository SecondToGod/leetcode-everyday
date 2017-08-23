#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define N 3
//90度旋转n*n图像矩阵
//先沿对角线翻转，再演中轴线翻转
void rotateIMG(vector<vector<int> > &arr){
    int n = arr.size();
    for(int i=0;i<n-1;++i){//对角线
        for(int j=0;j<n-i-1;++j){
            swap(arr[i][j],arr[n-i-1][n-j-1]);
        }
    }
    for(int i=0;i<n/2;i++){//中轴线
        for(int j=0;j<n;j++){
            swap(arr[i][j],arr[n-i-1][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
int main(){
    //int n = 0;
    //cin>>n;
    // char arr1[N]={'0'},arr2[N]={'0'};
    // cin.getline(arr1,N);
    // cin.getline(arr2,N);
    // string s1 = arr1,s2 = arr2;
    int ele;
    vector<int> temp[N];
    vector< vector<int> > arr;
    for(int i=0;i<N;i++){
        while(cin >> ele){
            temp[i].push_back(ele);
        }
        cin.clear();
        arr.push_back(temp[i]);
    } 
    // while(cin>>ele){
    //     arr2.insert(arr.begin(),ele);
    // }
    rotateIMG(arr);
    /*char *number0 = new char[N],*number1=new char[N];
    cin>>number0;
    cin>>number1;
    int result = findMatch(number0,number1);
    cout<<result<<endl;*/
    system("pause");
    return 0;
}
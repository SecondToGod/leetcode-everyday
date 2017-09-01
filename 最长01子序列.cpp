#include<iostream>
#include<cstdlib>
int main(){
	int n ;
	std::cin>>n;
	int a[10000];
	for(int i=0;i<n;++i){
		std::cin>>a[i];
	}
	int temp=1,ans=1;
	int j=0;
	while(j < n-1){
		while(a[j]^a[j+1] && j<n-1){
			 temp++;
			 j++;
		}
		if(temp > ans){
			ans = temp;				
		}
		temp = 1;
		j++;
	}
	std::cout<<ans<<std::endl;
	std::system("pause");
return 0;
}
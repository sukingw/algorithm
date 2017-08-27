/*************************************************************************
	> File Name: InsertSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 07:07:53 PM CST
 ************************************************************************/
// 直接插入排序算法程序

#include<iostream>
#include<vector>

using namespace std;

void SelectSort(vector<int> &a){
    int i,j;
    int temp;
    for(i=1;i < a.size();++i){
        if(a[i]<a[i-1]){
            temp = a[i];
            for(j=i;a[j-1]>temp && j > 0;--j){
                a[j] = a[j-1];
            }
            a[j] = temp;
        }
    }
}

int main(){
    int a;
    vector<int> input;
    while(cin>>a){
        input.push_back(a);
    }
    SelectSort(input);
    for(auto it = input.begin();it != input.end();++it){
        cout<<*it<< " ";
    }
    cout<<endl;
    return 0;
}

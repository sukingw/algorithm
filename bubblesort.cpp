/*************************************************************************
	> File Name: bublesort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 05:07:49 PM CST
 ************************************************************************/
// 本程序是冒泡算法的练习

#include<iostream>
using namespace std;

// 冒泡排序算法
void BublleSort(int a[],int n){
    int i,j;
    int flag = 1;
    for(i=0; i<n-1 && flag; ++i){
        flag =0;
        for(j = n-2; j >= i; --j){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                flag = 1;
            }
        }
    }
}

// 主函数
int main(){
    int a[] = {8,9,2,4,5,3,1,6,8,23,45,12,33};
    int n = 13;
    cout<<"排序前的数字是："<<a[0];
    for (int i = 1; i < n; i++){
        cout<<" "<< a[i];
    }
    cout<<endl;

    BublleSort(a,n);
    
    cout<<"排序后的数字是："<<a[0];
    for (int i = 1; i < n; i++){
        cout<<" "<< a[i];
    }
    cout<<endl;
}

/*************************************************************************
	> File Name: SelectSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 06:33:51 PM CST
 ************************************************************************/
// 本程序是练习简单选择排序算法

#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
using namespace std;

// 简单选择排序算法
void SelectSort(vector<int> &a){
    int i,j;
    int min;
    for(i=0;i<a.size()-1;++i){
        min = i;
        for(j = i+1; j< a.size();++j ){
            if(a[min]>a[j]){
                min = j;
            }
        }
        swap(a[min],a[i]);
    }
}
// 主函数
int main(){
    vector<int> a{8,9,2,4,5,3,1,6,8,23,45,12,33};
    cout<<"排序前的数字是："<<a[0];
    for (int i = 1; i < a.size(); i++){
        cout<<" "<< a[i];
    }
    cout<<endl;

    SelectSort(a);
    
    cout<<"排序后的数字是："<<a[0];
    for (int i = 1; i < a.size(); i++){
        cout<<" "<< a[i];
    }
    cout<<endl;
}

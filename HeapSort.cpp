/*************************************************************************
	> File Name: HeapSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 09:07:07 PM CST
 ************************************************************************/
// 堆排序算法的练习

#include<iostream>
#include<vector>
using namespace std;

void HeapAdjust(vector<int> &a, int i, int l){
    int temp,j;
    temp = a[i];
    
    for(j = 2*i+1;j< l; j = j*2+1){
        if(j < l-1 && a[j]<a[j+1]){
            ++j;
        }
        if(temp>a[j]){
            break;
        }
        a[i] = a[j];
        i = j;
    }
    a[i] = temp;
}

void HeapSort(vector<int> &a){
    int i;
    for(i=(a.size()-1)/2-1;i >= 0; --i){
        HeapAdjust(a,i,a.size());
    }
    
    for(i = a.size()-1;i>0;--i ){
        swap(a[0],a[i]);
        HeapAdjust(a,0,i);
    }
}

int main(){
    int a;
    vector<int> input;
    while(cin>>a){
        input.push_back(a);
    }
    HeapSort(input);
    for(auto it = input.begin();it != input.end();++it){
        cout<<*it<< " ";
    }
    cout<<endl;
    return 0;
}

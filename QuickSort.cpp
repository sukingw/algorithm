/*************************************************************************
	> File Name: QuickSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Mon 28 Aug 2017 05:09:15 PM CST
 ************************************************************************/
// 快速排序练习

#include<iostream>
#include<vector>
using namespace std;

int partation(vector<int> &a,int s, int e){
    int partkey = a[s];
    while(s<e){
        while(s<e && a[e]>=partkey){
            e--;
        }
        swap(a[s],a[e]);
        while(s<e&&a[s]<= partkey){
            s++;
        }
        swap(a[s],a[e]);
    }
}

void QuickSort(vector<int> &a,int s,int e){
    if(s<e){
        int part;
        part = partation(a,s,e);
        QuickSort(a,s,part-1);
        QuickSort(a,part+1,e);
    }
}


int main(){
    int a;
    vector<int> input;
    while(cin>>a){
        input.push_back(a);
    }
    QuickSort(input,0,input.size()-1);
    for(auto it = input.begin();it != input.end();++it){
        cout<<*it<< " ";
    }
    cout<<endl;
    return 0;
}

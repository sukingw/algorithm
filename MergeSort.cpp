/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 10:59:54 PM CST
 ************************************************************************/

// 归并排序排序算法的练习

#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &a,vector<int> &b,int s,int mid,int e){
    int i,j,k;
    for(i = s,j = mid+1;s <= mid && j <= e; ++i){
        if(a[s]<a[j]){
            b[i] =a[s++]; 
        }
        else{
            b[i] = a[j++]; 
        }
    }
    if(s<=mid){
        for(k = 0;k <= mid-s;++k){
            b[i+k] = a[s+k];
        }
    }
    if(j<=e){
        for(k = 0;k <= e-j;++k){
            b[i+k] = a[j+k];
        }
    }
}

void MergeSort(vector<int> &a,vector<int> &b,int s,int e){
    int mid;
    if(s == e){
        b[s] = a[s];
    }
    else{
        mid = (s+e)/2;
        MergeSort(b,a,s,mid);
        MergeSort(b,a,mid+1,e);
        Merge(a,b,s,mid,e);
    }
}

int main(){
    int a;
    vector<int> input;
    while(cin>>a){
        input.push_back(a);
    }
    vector<int> b(input.begin(),input.end());
    MergeSort(input,b,0,input.size()-1);
    for(auto it = b.begin();it != b.end();++it){
        cout<<*it<< " ";
    }
    cout<<endl;
    return 0;
}

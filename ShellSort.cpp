/*************************************************************************
	> File Name: ShellSort.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 27 Aug 2017 08:07:10 PM CST
 ************************************************************************/
// 本程序是希尔排序算法练习
#include<iostream>
#include<vector>
using namespace std;

void ShellSort(vector<int> &a){
    int i,j;
    int temp;
    int pathlong = a.size();
    do{
        pathlong = pathlong/3+1;
        for(i=pathlong; i<a.size();i += pathlong){
            if(a[i] < a[i-pathlong]){
                temp = a[i];
                for(j = i; j-pathlong >= 0 && a[j-pathlong]>temp; j -= pathlong){
                    a[j] = a[j-pathlong];
                }
                a[j] = temp;
            }
        }
    }while(pathlong >1);
}

int main(){
    int a;
    vector<int> input;
    while(cin>>a){
        input.push_back(a);
    }
    ShellSort(input);
    for(auto it = input.begin();it != input.end();++it){
        cout<<*it<< " ";
    }
    cout<<endl;
    return 0;
}

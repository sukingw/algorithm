/*************************************************************************
	> File Name: ReverseStr.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Mon 28 Aug 2017 10:25:41 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>

using namespace std;

void ReverseStr(char *str){
    char temp = *str;
    int len = strlen(str);
    *str = *(str+len-1);
    *(str+len-1) = '\0';
    if(strlen(str)>1){
        ReverseStr(str+1);
    }
    *(str+len-1) = temp;
}
int main(){
    char str[] = "hello world";
    cout<< str<<endl;
    ReverseStr(str);
    cout<<str<<endl;
}

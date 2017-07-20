/*************************************************************************
	> File Name: jz66.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 16 Jul 2017 10:12:48 PM CST
 ************************************************************************/

#include<iostream>

class Solution{
public:
    int row;
    int col;
    bool hasPath(char *matrix, int rows, int cols, char *str){
        if(rows <= 0 || cols <= 0)
            return false;                           // 判断 rows 和 cols 是否合法
        if(strlen(str) == 0)                        // 判断 str 是否合法
            return true;
        row = rows;
        col =cols;
        std::vector<std::vector<bool>> used(rows, std::vector<bool>(cols, false));          // 初始化访问记录
        for( int i = 0;i < rows;i++ ){                                                      // 遍历起始地点
            for(int j =0; j<cols;j++){
                if(matrix[i*cols+j] == str[0]){
                    bool res = solv(matrix, i, j, used, str, 0);
                    if(res)
                        return true;
                }
            }
        }
        return false;
    }

    bool solv (char *matrix, int x, int y, std::vector<std::vector<bool>> &used, char *str, int index){
        if (x<0 || x >= used.size() || y < 0 || y >= used[0].size()){
            return false;
        }
        if( used[x][y] ){
            return false;
        }
        if(index >= strlen(str)){
            return false;
        }
        if(matrix[x*col+y] != str[index]){
            return false;
        }
        if( index == strlen(str)-1 ){
            return true;
        }
        used[x][y] = true;
        bool res = solv( matrix, x-1, y, used, str, index+1 ) ||
                    solv( matrix, x+1, y, used, str, index+1 ) ||
                    solv( matrix, x, y-1, used, str, index+1 ) ||
                    solv( matrix, x, y+1, used, str, index+1 );
        used[x][y] = false;
        return res;
    }
};


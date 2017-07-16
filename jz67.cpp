/*************************************************************************
	> File Name: jz67.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Sun 16 Jul 2017 09:26:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited = new bool[rows*cols];
        for (int i=0; i<rows*cols; ++i){
            visited[i] = false;
        }
        int count = movingCountCore(threshold, rows, cols, 0,0,visited);
        delete[] visited;
        return count;
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col,bool * visited){
        int count =0;
        if(check(threshold, rows, cols, row, col, visited)){                    // 判断是否需要访问（1、是否出界 2、是否符合限定条件 3、是否已经访问过）
            visited[row*cols+col]=true;                                         // 将当前点设置为已经访问过
            count = 1+ movingCountCore(threshold,rows,cols,row-1,col,visited）  // 对其周围的所有点进行判断
                    +movingCountCore(threshold,rows,cols,row,col-1,visited)
                    +movingCountCore(threshold,rows,cols,row+1,col,visited)
                    +movingCountCore(threshold,rows,cols,row,col+1,visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols,int row, int col,bool*visited){    // 检查当前点的可访问性
        if(row >= 0 && row <rows && col >= 0 && col <cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols+col]){
            return true;
        }
        return false;
    }
private:
    int getDigitSum(int number){
        int sum =0;
        while(number > 0){
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

/*
 * =====================================================================================
 *
 *       Filename:  recursive.c
 *
 *    Description:  递归阶乘
 *
 *        Version:  1.0
 *        Created:  2015/11/23 11时15分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhiqiangbuxi|forbetter@vip.qq.com|http://zhiqiangbuxi.cn (), 
 *   Organization:  life = thanks + regards + hope
 *
 * =====================================================================================
 */
#include <stdio.h>
int recursive(int num){
    if(num < 0){
        return 0;
    }else if(num == 0){
        return 1;
    }else{
        return num*recursive(num-1); 
    }
}
int main(int argc,char* argv[]){
    int result = 0;
    printf("Pls input a int num:\n");
    scanf("%d",&result);
    if(result <= 0){
        printf("%d is not a legal num \n",result);
    }else{
        result = recursive(result);
        printf("The result is %d\n",result);
    }
    return 0;
}


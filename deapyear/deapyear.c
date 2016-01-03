/*
 * =====================================================================================
 *
 *       Filename:  deapyear.c
 *
 *    Description:  判断闰年
 *
 *        Version:  1.0
 *        Created:  2015/11/23 10时42分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhiqiangbuxi|forbetter@vip.qq.com|http://zhiqiangbuxi.cn (), 
 *   Organization:  life = thanks + regards + hope
 *
 * =====================================================================================
 */
#include <stdio.h>
int deapyear(int year){
    if(year <=0 || year >=9999){
        return -1;
    }
    if((year % 400 == 0)||(year % 4 == 0 && year % 100 != 0)){
        return 1;
    }else{
        return 0;
    }
}
int main(int argc,char* argv[]){
    int year,result;
    year = result = 0;
    printf("Pls input a year,exm 2014.\n");
    scanf("%d",&year);
    result = deapyear(year);
    if(result == 1){
        printf("%d is a deap year\n",year);
    }else if(result == -1){
        printf("%d is not legal\n",year);
    }else{
        printf("%d is not  a deap year\n",year);
    }
    return 0;
}


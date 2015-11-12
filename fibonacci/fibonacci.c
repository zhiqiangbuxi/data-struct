/*
 * =====================================================================================
 *
 *       Filename:  fibonacci.c
 *
 *    Description: 菲波那切数列 
 *
 *        Version:  1.0
 *        Created:  2015/11/12 15时06分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhiqiangbuxi|forbetter@vip.qq.com|http://zhiqiangbuxi.cn (), 
 *   Organization:  life = thanks + regards + hope
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _soft_array{
    int len;
    int array[];
}SoftArr;
SoftArr* createFid(int size){
    SoftArr* ret = NULL;
    int i = 0;
    if(size>0){
        ret = (SoftArr*)malloc(sizeof(*ret)+sizeof(*(ret->array)) * size);
        ret->len = size;
    }
    if(NULL!=ret){
       if(ret->len == 1){
            ret->array[0] = 1; 
       }else{
            ret->array[1] = 1;
            ret->array[0] = 1;
            for(i=2;i<ret->len;i++){
                ret->array[i] = ret->array[i-1] + ret->array[i-2];
            }
       }
    }
    return ret;
}
void destroyFid(SoftArr* fid){
    free(fid);
} 
int main(int argc,char* argv[]){
    int i = 0;
    SoftArr* test = createFid(10);
    for(i=0;i<test->len;i++){
        printf("%d\n",test->array[i]);
    }
    destroyFid(test);
    return 0;
}



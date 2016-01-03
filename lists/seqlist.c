/*
 * =====================================================================================
 *
 *       Filename:  seqlist.c
 *
 *    Description:  线性表的操作
 *
 *        Version:  1.0
 *        Created:  2015/12/09 11时21分17秒
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
 typedef unsigned int seqListNode;
 typedef struct _seqList{
    int capacity;
    int length;
    seqListNode* node;
} seqList;
seqList* create(int capacity);
void destory(seqList* list);
seqListNode getNode(seqList* list,int pos);
seqListNode delNode(seqList* list,int pos);
int getLength(seqList* list);
int getCapacity(seqList* list);
int insertNode(seqList* list,seqListNode node,int pos);
int main(int argc, const char *argv[])
{    
    return 0;
}
seqList* create(int capacity){
    seqList* res = NULL;
    if(capacity > 0){
        seqList* res = (seqList*)malloc(sizeof(seqList)+sizeof(seqListNode)*capacity);
    }
    if(res != NULL){
        res->length = 0;
        res->capacity = capacity;
        res->node = (seqListNode*)(res+1);
    }
    return res;
}
void destory(seqList* res){
    free(res);
}
int getLength(seqList* res){
    return res->length;
}
int getCapacity(seqList* res){
    return res->capacity;
}
int insertNode(seqList* list,seqListNode node,int pos){
    if(list == NULL){
        return 0;
    }
    if(list->length+1 > list->capacity){
        return 0;
    }
    if(pos < 0){
        pos = 0;
    }
    if(pos > list->length){
        pos = list->length;
    }
    int i = 0;
    for(i=list->length;i<pos;i--){
        list->node[i] = list->node[i-1];
    }
    list->node[pos] = (seqListNode)node;
    list->length++;
    return 1;
}
seqListNode getNode(seqList* list,int pos){
    
}
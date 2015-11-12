#include <stdio.h>
#include <stdlib.h>
typedef unsigned int listNode;
typedef struct _stuctList
{
    int capacity;
    int length;
    listNode* node;
} structList;
//定义创建线性表
void* listCreate(int capacity);
void listDestory(structList* list);
void listClear(structList* list);
int listLength(structList* list);
int listCapacity(structList* list);
int listInsert(structList* list,listNode* node,int pos);
void* listGet(structList* list,int pos);
void* listDel(structList* list,int pos);
int main(int argc, const char *argv[])
{
    structList * test = listCreate(10);
    int i = 1;
    int j = 2;
    int k = 3;
    int m = 4;
    int n = 5;
    listInsert(test,&i,0);
    listInsert(test,&j,0);
    listInsert(test,&k,0);
    listInsert(test,&m,8);
    listInsert(test,&n,0);
    printf("%d\n",test);
    int len = listLength(test);
    int f = 0;
    for(f;f<len;f++){
        listNode* index= listGet(test,f);
        printf("%d\n",*index);
    }
    puts("last:\n");
    listDel(test,0);
    int g = 0;
    int len2 = listLength(test);
    printf("len2:%d",len2);
    for(g;g<len2;g++){
        listNode* index= listGet(test,g);
        printf("%d\n",*index);
    }
    //listClear(test);
   // printf("%d\n",test);
    //listDestory(test);
    //printf("%d\n",test);
    return 0;
}
//创建线性表函数
void* listCreate(int capacity){
    structList* res = NULL;
    if(capacity>0){
        //动态创建内存空间
        res = (structList*)malloc(sizeof(structList)+sizeof(listNode)*capacity);
    }
    if(res!= NULL){
        res->capacity = capacity;
        res->length = 0;
        res->node = (listNode*)(res+1);
    }
    return res;
}
void listDestory(structList* list){
    free(list);
}
void listClear(structList* list){
    structList* tlist = (structList*)list;
    if(tlist != NULL){
        tlist->length = 0;
        tlist->node = NULL;
    }
}
int listLength(structList* list){
    structList* tlist = (structList*)list;
    int res = -1;
    if(tlist != NULL){
        res = tlist->length;
    }
    return res;
}
int listCapacity(structList* list){
    structList* tlist = (structList*)list;
    int res = -1;
    if(tlist != NULL){
        res = tlist->capacity;
    }
    return res;
}
int listInsert(structList* list,listNode* node,int pos){
    structList* tlist = (structList*)list;
    int res = (tlist!=NULL);
    if(pos > tlist->length){
        pos = tlist->length;
    }else if(pos < 0){
        pos = 0;
    }
    res = res&&((tlist->length+1) < tlist->capacity);
    //插入节点
    if(res){
        int i=tlist->length;
        for(i;pos<i;i--){
            tlist->node[i] = tlist->node[i-1];
        }
        tlist->node[pos] = *node;
        tlist->length++;
    }
    return res;
}
void* listGet(structList* list,int pos){
    structList* tlist = (structList*)list;
    int res = (tlist!=NULL);
    if(pos > tlist->length){
        pos = tlist->length;
    }else if(pos < 0){
        pos = 0;
    }
    return (listNode*)(&tlist->node[pos]);
}
void* listDel(structList* list,int pos){
    structList* tlist = (structList*)list;
    int res = (tlist!=NULL);
    if(pos >= 0 && pos < tlist->length){
        int l = tlist->length;
        int i = pos;
        for(i;i<l;i++){
            tlist->node[i] = tlist->node[i+1];
        }
        tlist->length--;
    }
    return tlist;
}

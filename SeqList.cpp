#include<iostream>
#include<stdlib.h>
using namespace std;

#define Maxsize 10

typedef struct {
        int data[Maxsize];
        int length;
}SeqList;

void InitList (SeqList &L ){
        L.length=0;
}
void DispList(SeqList  &L){
    for(int i=0;i<L.length;i++){
        cout << L.data[i]<<endl;
    }
    cout << "length=" << L.length << endl;
}
void CreatList(SeqList  &L,int a[],int n)
{
        int i=0, k=0;
        while(i<n)
        {
                L.data[k]=a[i];
                k++;
                i++;
        }
        L.length=k;
}

bool GetElement(SeqList L,int i,int &e){
    if (i<1||i>L.length)
        return false;
    e=L.data[i-1];
    return true;
}
int LocateElem(SeqList L,int e){
    int i=0;
while (i<L.length&&L.data[i]!=e)
    i++;
    if (i>=L.length)
        return 0;
    else return i+1;
}
bool Insertelem(SeqList &L,int i,int e){
    i--;
    for (int j=L.length;j>i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i]=e;
    L.length++;
    return true;

}
bool Delelem(SeqList &L,int i){
    i--;
    for (int j=i;j<L.length;j++)
    L.data[i]=L.data[i+1];
    L.length--;
}
int main(){
    int a[3]={1,3,5};
    int l=3;
    SeqList L;
    InitList(L);
    CreatList(L,a,l);
    DispList(L);
    Insertelem(L,2,8);
    DispList(L);
    Delelem(L,2);
    DispList(L);
}

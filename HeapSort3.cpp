#include<bits/stdc++.h>
using namespace std;
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Max_Heapify(int *A,int i,int n){
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(A[l]>A[i] && l<n)
        largest=l;
    if(A[r]>A[largest]&& r<n)
        largest=r;
    if(largest!=i){
    swap(A[i],A[largest]);
    Max_Heapify(A,largest,n);
    }
    return;
}
void Build_Max_Heap(int *A,int n){
    for (int i=floor(n/2);i>=0;i--){
            Max_Heapify(A,i,n);
    }
}
void HeapSort(int *A,int n){
    int m=n;
    Build_Max_Heap(A,n);
    for (int i=n-1;i>0;i--){
        swap(A[0],A[i]);
         m=m-1;
        Max_Heapify(A,0,m);
    }
}
int main(){
    int A[]={16,14,13,12,11,17};
    int length=sizeof(A)/sizeof(int);
    HeapSort(A,length);
    for(int e:A){
        cout<<e<<"  ";
    }
    cout<<endl;
return 0;
}
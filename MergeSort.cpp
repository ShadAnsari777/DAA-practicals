/*
mergeSort(A,p,q){
    if p>q{
        r=floor(p+q)/2;
        mergeSort(A,p,r);
        mergeSort(A,r+1,q);
        merge(A,p,q);
    }
}
*/
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
void merge(int A[],int p,int q,int r){
    int n1=p+r-1;
    int n2=q-r;
    int L[n1+1];
    int R[n2+1];
    for(int i=0;i<n1;i++)
        L[i]=A[p+i-1];
    
        for(int j=0;j<n2;j++)
          R[j]=A[j+q];
        
          L[n1]=INT_MAX;
          R[n2]=INT_MAX;
          int i=0;
          int j=0;
            for(int k=p;k<=q;k++){
                if(L[i]<=R[j])
                 {
                    A[k]=L[i];
                    i++;
                 }else{
                    A[k]=R[j];
                    j++;
                 }
            }
    
    return;
}
void mergeSort(int A[],int p,int q){
    if(p<q){
        int r=floor(p+q)/2;
        mergeSort(A,p,r);
        mergeSort(A,r+1,q);
        merge(A,p,q,r);
    }
    return;
}

int main(){
int A[5]={3,1,5,2,8};
int p=0;
int q=4;
mergeSort(A,p,q);
for(int i=0;i<5;i++){
    cout<<A[i]<<"  ";
}
cout<<endl;
return 0;
}
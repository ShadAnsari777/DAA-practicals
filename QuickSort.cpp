//Implementation of Quick Sort Algorithm by taking the last element as the PIVOT : 

#include<iostream>
using namespace std;

// Creating the Exchange function : 
void exchange(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

// Creating the Partition Function :
int Partition(int A[], int p,int r){
int x=A[r];
int i=(p-1);
for(int j=p;j<=r-1;j++){
if(A[j] <=x){
    i=i+1;
    exchange(A[i],A[j]);
}
}
exchange(A[i+1],A[r]);
return (i+1);
}

//Creating Quicksort Function :
void QuickSort(int A[], int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

//main Function :
int main(){
    // int A[]={16,14,13,12,11,17};
    int A[]={ 10, 7, 8, 9, 1, 5 };
    int length=sizeof(A)/sizeof(A[0]);
    int r=length-1;
    QuickSort(A,0,r);
    cout<<r<<endl;
    cout<<"The Array After Sorting : "<<endl;
    for(int e:A){
         cout<<e<<"  ";
     }
    return 0;
}
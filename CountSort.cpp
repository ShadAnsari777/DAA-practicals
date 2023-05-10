// Implementation of Count Sort :
/* Count is a non comparision based Sorting technique which sortes the elements in the linear time 
 i.e: O(n) :
 but it applies some constraints to the input like the range of input should not be more than that of 
 the number of input , infact it should perform good if the range is only 0.25 of the input size :
 that is the if the size of the array is 100 then there range of the input should be 25 
 let n be the number of inputs and k be the range 
 therefore ,order depends on K because it comes out to be O(k+n):
 so if K is greater than n then it will start depending on n:
 It is also  a very memory hungry algorithm */

#include<iostream>
using namespace std;
void countSort(int A[],int n,int k,int B[]){
    int C[k];
    for (int i=0;i<k;i++)
        C[i]=0;

for(int j=0;j<n;j++)
    C[A[j]]=C[A[j]]+1;

for(int i=1;i<k;i++)
    C[i]=C[i]+C[i-1];
for (int j=n-1;j>=0;j--){
    
    B[C[A[j]]]= A[j];
    C[A[j]]=C[A[j]]-1;
 }
}
int main(){
 int A[]={3,2,4,1,3,4,1,4,3,2,5};
 int len=sizeof(A)/sizeof(A[0]);
 int B[len];
 countSort(A,len,6,B);
 std::cout<<"Printing the sorted array :  ";
 for(int e:B){
    std::cout<<e<<"  ";
 }
    return 0;
}
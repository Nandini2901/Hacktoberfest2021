//  PROBLEM STATEMENT: Sorting the given array using merge sort
//  COMPLEXITY: O(n*Log n)
#include <bits/stdc++.h>
using namespace std;

//Merging the two arrays 
void merge(int arr[], int l,  int mid, int r)
{
    int lsize=mid-l+1;
    int rsize=r-(mid+1)+1;
    int L[lsize+1];
    int R[rsize+1];
    for(int i=0;i<lsize;i++){
        L[i]=arr[i+l];
    }
    for(int i=0;i<rsize;i++){
        R[i]=arr[i+mid+1];
    }
    L[lsize]=R[rsize]=INT_MAX;
    int li=0,ri=0;
    for(int i=l;i<=r;i++){
        if(L[li]<=R[ri]){
            arr[i]=L[li];
            li++;
        }
        else{
            arr[i]=R[ri];
            ri++;
        }
    }
}

//Divide and conquer for sorting
void mergesort(int arr[], int l,  int r)
{
    //Single element present
    if(l==r){
        return ;
    }
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main()
{
    int arr[] = {4 ,9,2,0,-1,8,0};
    mergesort(arr,0, 6);
    for (int a = 0; a < 6; a++)
    {
        cout << arr[a]<<" ";
    }
    return 0;
}

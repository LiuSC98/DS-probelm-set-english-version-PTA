#include <iostream>
using namespace std;

template<typename T>
void merge(T arr[],T arr_tmp[],int L,int R, int RE){
    int LE=R-1;
    int temp=L;
    int numofElements=RE-L+1;
    while (L<=LE && R<=RE)
    {
        if (arr[L]<=arr[R]) arr_tmp[temp++]=arr[L++]; 
        else arr_tmp[temp++]=arr[R++];
    }
    while (L<=LE) arr_tmp[temp++]=arr[L++];
    while (R<=RE) arr_tmp[temp++]=arr[R++];
    
    for (numofElements; numofElements>=0; numofElements--)
    {
        arr[RE-numofElements]=arr_tmp[RE-numofElements];
    }
}

template<typename T>
void merge_pass( T arr[], T arr_temp[], int N, int len)
{ 
    int i, j;
    for ( i=0; i <= N-2*len; i += 2*len ) merge( arr, arr_temp, i, i+len, i+2*len-1 );
    if ( i+len < N ) merge( arr, arr_temp, i, i+len, N-1);
}


template<typename T>
void mergeSort(int N, T arr[]){
    T *arr_tmp = new T[N];
    int len=1;

    while (len<N)
    {
        merge_pass(arr,arr_tmp,N,len);
        len*=2;
    }
    
    delete[] arr_tmp;
}




int main(){
    int N;
    cin>>N;
    int *arr= new int[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }

    mergeSort(N,arr);

    for (int i = 0; i < N; i++)
    {
        cout<<arr[i]<<' ';
    }
    
    delete[] arr;
    return 0;
}
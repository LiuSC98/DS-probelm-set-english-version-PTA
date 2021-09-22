/*
7-13 Insert or Merge (25 points)
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0

Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/


#include <iostream>
#define MAXN 101
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
void mergeSort(int N, T arr[], int len){
    if(len>=N||len<=0) return;
    T *arr_tmp = new T[N];
    merge_pass(arr,arr_tmp,N,len);
    delete[] arr_tmp;
}

template<typename T>
void insertionSort(int N, T arr[], int iteration){
    if (iteration>=N||iteration<=0) return;
    int j;
    T temp;
    temp=arr[iteration];
    for (j = iteration; j>0 && arr[j-1]>temp; j--)
    {
        arr[j]=arr[j-1];
    }
    arr[j]=temp;
}



int main(){
    int N,arr1[MAXN],arr2[MAXN],arr3[MAXN];
    
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>arr3[i];
        arr2[i]=arr3[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin>>arr1[i];
    }

    int iteration=1,len=1;
    bool flag_insert=0,flag_merge=0;
    while (iteration < N)
    {
        insertionSort(N,arr2,iteration);
        iteration++;
        mergeSort(N,arr3,len);
        if(len<=N/2){len*=2;}
        flag_insert=1;
        flag_merge=1;
        for (int i = 0; i < N; i++)
        {
            if (flag_insert && arr2[i]!=arr1[i]) flag_insert=0;
            if (flag_merge && arr3[i]!=arr1[i]) flag_merge=0;
            if(!flag_insert && !flag_merge) break;
        }

        if (flag_insert){
            insertionSort(N,arr2,iteration);
            cout<<"Insertion Sort"<<endl;
            for (int j = 0; j < N; j++)
            {
                if(j) cout<<' ';
                cout<<arr2[j];
            }
            break;
        }
        else if (flag_merge){
            mergeSort(N,arr3,len);
            cout<<"Merge Sort"<<endl;
            for (int j = 0; j < N; j++)
            {
                if(j) cout<<' ';
                cout<<arr3[j];
            }
            break;
        }
    }
    
    return 0;
}
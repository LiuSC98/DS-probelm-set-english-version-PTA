/*
7-14 Insertion or Heap Sort (25 points)
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0

Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9

Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/


#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

template<typename T>
void heapSort(int N,T arr[], int iteration){
    if (iteration>=N||iteration<=0) return;
    pop_heap(arr,arr+N+1-iteration,less<T>());
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
    int N;
    cin>>N;
    int *arr1=new int[N],*arr2=new int[N],*arr3=new int[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr3[i];
        arr2[i]=arr3[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin>>arr1[i];
    }

    int iteration=1;
    bool flag_insert=0,flag_heap=0;
    make_heap(arr3,arr3+N,less<int>());
    while (iteration < N)
    {
        insertionSort(N,arr2,iteration);
        heapSort(N,arr3,iteration);
        iteration++;
        flag_insert=flag_heap=1;
        for (int i = 0; i < N; i++)
        {
            if (flag_insert && arr2[i]!=arr1[i]) flag_insert=0;
            if (flag_heap && arr3[i]!=arr1[i]) flag_heap=0;
            if(!flag_insert && !flag_heap) break;
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
        else if (flag_heap){
            heapSort(N,arr3,iteration);
            cout<<"Heap Sort"<<endl;
            for (int j = 0; j < N; j++)
            {
                if(j) cout<<' ';
                cout<<arr3[j];
            }
            break;
        }
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
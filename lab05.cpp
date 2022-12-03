#include <iostream>
#include <chrono>
#include<stdlib.h>
using namespace std;

void swap(int *a,int *b){
int c;
c=*a;
*a=*b;
*b=c;
}

void bubbleSort(int A[], int n){

int i, j;
for (i = 0; i < n-1; i++){
for (j = 0; j < n-i-1; j++) if (A[j] > A[j+1]) swap(&A[j], &A[j+1]);
}
}

void maintainHeap(int arr[], int n, int i)
{
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;
  
if (l < n && arr[l] > arr[largest])largest = l;
  
if (r < n && arr[r] > arr[largest])largest = r;
  
if (largest != i) {
swap(arr[i], arr[largest]);
  
maintainHeap(arr, n, largest);
}
}

void heapSort (int A[], int n){
for (int i = n / 2 - 1; i >= 0; i--)
maintainHeap(A, n, i);
for (int i = n - 1; i >= 0; i--) {
swap(A[0], A[i]);
maintainHeap(A, i, 0);
}
}

int min(int a, int b) {
return (a<b)? a :b;
}

void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;

int arr1[n1], arr2[n2];

for (i = 0; i < n1; i++)
arr1[i] = arr[l + i];
for (j = 0; j < n2; j++)
arr2[j] = arr[m + 1+ j];

i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (arr1[i] <= arr2[j])
{
arr[k] = arr1[i];
i++;
}
else
{
arr[k] = arr2[j];
j++;
}
k++;
}

while (i < n1)
{
arr[k] = arr1[i];
i++;
k++;
}

while (j < n2)
{
arr[k] = arr2[j];
j++;
k++;
}
}

void mergeSort (int A[], int n){
int curr_size;
int ls;

for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
{
for (ls=0; ls<n-1; ls += 2*curr_size)
{
int mid = min(ls + curr_size - 1, n-1);

int re = min(ls + 2*curr_size - 1, n-1);

merge(A, ls, mid, re);
}
}
}

int main()

{

int size[] = {10,100,1000,10000};

for(int i = 0; i < 5; i ++){

int unsortedArray[size[i]];

cout << "The current array size is: " << size[i] << endl;

for(int j=0; j<size[i]; j++){

unsortedArray[j] = rand() % 1000000;

}

  


cout<<"Bubble Sort"<<endl;
auto start = std::chrono::high_resolution_clock::now();

bubbleSort(unsortedArray,size[i]);

auto finish = std::chrono::high_resolution_clock::now();   
chrono::duration<double> elapsed = finish - start;
cout << "Elapsed time: " << elapsed.count() <<endl;

cout<<"Heap Sort : "<<endl;

start = std::chrono::high_resolution_clock::now();

heapSort(unsortedArray,size[i]);

finish = std::chrono::high_resolution_clock::now();   
elapsed = finish - start;
cout << "Elapsed time: " << elapsed.count() <<endl;

cout<<"Merge Sort : "<<endl;
start = std::chrono::high_resolution_clock::now();

mergeSort(unsortedArray,size[i]);

finish = std::chrono::high_resolution_clock::now();   
elapsed = finish - start;
cout << "Elapsed time: " << elapsed.count() <<endl;


}

}
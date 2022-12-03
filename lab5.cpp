// Jaidan Dovala
// CPSC 2430
// Mar 3, 2022
// Lab05
// Different type of sorting algo and the time needed to execute each given random numbers and array size.





#include <iostream>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;




//helper 
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}



void bubbleSort(int A[], int n){
    // bubble sort here
   for(int i = 0; i< n-1; i++){
       for(int j = 0; j < n-i-1; j++){
           //swappig according to if
           if(A[j] > A[j+1]){
               int temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
           }
       }
   }
}

void heapify(int A[], int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest])
        largest = l;
        if (r < n && A[r] > A[largest])
            largest = r;
        if (largest != i) {
            swap(A[i], A[largest]);
            heapify(A, n, largest);
        }
}
void heapSort (int A[], int n){
    // heap sort here
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i >= 0; i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

void merge(int A[], int left, int middle, int right){

    
    int f = middle - left + 1;
    int s = right - middle;
    //creating two temporary arrays
    int t1[f], t2[s];
    //copying the data from the two halves into two temporary arrays
    for (int m = 0; m < f; m++)
        t1[m] = A[left + m];
    for (int n = 0; n < s; n++)
        t2[n] = A[middle + 1 + n];
    //merging the temporary arrays into a single array
    int a = 0;
    int b = 0;
    int c = left;
    while (a < f && b < s) {
        if (t1[a] <= t2[b]) {
            A[c] = t1[a];
            a++;
        }
        else {
            A[c] = t2[b];
            b++;
        }
        c++;
    }
    while (a < f) {
        A[c] = t1[a];
        a++;
        c++;
    }
    while (b < s) {
        A[c] = t2[b];
        b++;
        c++;
        }
}

void mergeSort (int A[], int n){
    // merge sort here
    int cur;
    int ls;

    for(cur =1; cur<=n-1;cur = 2*cur){
        for(ls = 0; ls<n-1; ls += 2*cur){
            int mid = min(ls + cur-1, n-1);
            int re = min(ls + 2*cur-1, n-1);
            merge(A,ls,mid,re);
        }
    }
}

void printsort(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << "" <<A[i]<< endl;
    }
    cout << "\n";
}



int main()
{
    
    
    int size[] = {10,100,1000,10000};
   
    for(int i = 0; i <4; i ++){
        int unsortedArray[size[i]]; 
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }
        
        // for(int j=0; j<size[i]; j++){
        //     cout << unsortedArray[j] << endl;
        // }
        
        
        // call different sorting functions here and measure the execution time here
        // ...

        //testigm sorts

        // cout << "\n";
        // cout << "sorted arrays:\n";
        // cout << "BubbleSort:\n";
        // bubbleSort(unsortedArray, size[i]);
        // printsort(unsortedArray,size[i]);

        
        // cout << "HeapSort:\n";
        // heapSort(unsortedArray,size[i]);
        // printsort(unsortedArray,size[i]);

        // cout<< "MergeSort\n";
        // mergeSort(unsortedArray,size[i]);
        // printsort(unsortedArray,size[i]);


        cout<<"Bubble Sort"<<endl;
        auto start = std::chrono::high_resolution_clock::now();

        bubbleSort(unsortedArray,size[i]);

        auto finish = std::chrono::high_resolution_clock::now();   
        chrono::duration<double> elapsed = finish - start;
        cout << "Time: " << elapsed.count() <<endl;

        cout<<"Heap Sort : "<<endl;

        start = std::chrono::high_resolution_clock::now();

        heapSort(unsortedArray,size[i]);

        finish = std::chrono::high_resolution_clock::now();   
        elapsed = finish - start;
        cout << "Time: " << elapsed.count() <<endl;

        cout<<"Merge Sort : "<<endl;
        start = std::chrono::high_resolution_clock::now();

        mergeSort(unsortedArray,size[i]);

        finish = std::chrono::high_resolution_clock::now();   
        elapsed = finish - start;
        cout << "Time: " << elapsed.count() <<endl;
        

        //=======================NANOSECONDS=====================
        
        // cout<<"Bubble Sort"<<endl;
        // auto start = high_resolution_clock::now();

        // bubbleSort(unsortedArray,size[i]);

        // auto finish = high_resolution_clock::now();   
        // auto duration = duration_cast<nanoseconds>(finish - start);
        // cout << "Time: " << duration.count() <<endl;

        // cout<<"Heap Sort : "<<endl;

        // auto s = high_resolution_clock::now();

        // heapSort(unsortedArray,size[i]);

        // auto f = high_resolution_clock::now();  
        // auto dur = duration_cast<nanoseconds>(f-s);
        // cout << "Time: " << dur.count() <<endl;

        // cout<<"Merge Sort : "<<endl;
        // auto st = high_resolution_clock::now();

        // mergeSort(unsortedArray,size[i]);

        // auto fi = high_resolution_clock::now();
        // auto du = duration_cast<nanoseconds>(fi-st);
        // cout << "Time: " << du.count() <<endl;

        
        
       
    }
     
    
} 

// tested sorts with size of 10d
// The current array size is: 10
// 16807
// 475249
// 650073
// 943658
// 108930
// 211272
// 27544
// 850878
// 777923
// 237709

// sorted arrays:
// BubbleSort:
// 16807
// 27544
// 108930
// 211272
// 237709
// 475249
// 650073
// 777923
// 850878
// 943658

// HeapSort:
// 16807
// 27544
// 108930
// 211272
// 237709
// 475249
// 650073
// 777923
// 850878
// 943658

// MergeSort
// 16807
// 27544
// 108930
// 211272
// 237709
// 475249
// 650073
// 777923
// 850878
// 943658
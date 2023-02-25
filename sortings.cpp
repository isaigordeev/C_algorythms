//
// Created by Isai Gordeev on 06/02/2023.
//

#include <iostream>
#include <vector>
using namespace std;

void increment(int &a){
    ++a;
}

void decrement(int &a){
    --a;
}

// bubble
int bubble_sort(int a[], int n){
    int num_itt = 0;
    for(int j = 0; j < n; ++j)
        for(int i = 0; i < n-j-1; ++i){
            if (a[i] > a[i+1]){
                int flag = 0;
                flag = a[i+1];
                a[i+1] = a[i];
                a[i] = flag;
                ++num_itt;
            }
    }
    return num_itt;
}

// hoar
unsigned partition_by_pivot(int data[], unsigned l_ind, unsigned r_ind, unsigned pivot){
    while(true){
        while (data[l_ind] < pivot) ++l_ind;
        while (pivot < data[r_ind]) --r_ind;

        if (r_ind <= l_ind)
            return r_ind;

        swap(data[l_ind++], data[r_ind--]);
    }
}

void quick_sort(int arr[], unsigned l_ind, unsigned r_ind){
    if(l_ind >= r_ind)
        return;
    auto split_ind = partition_by_pivot(arr, l_ind, r_ind,
                                        arr[l_ind + (r_ind-l_ind)/2]);
    quick_sort(arr, l_ind, split_ind);
    quick_sort(arr, split_ind+1, r_ind);
}

// hoar iterative for to be implemented



// merge_sort

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// itterative merge sort (vector supports n len functions )

void merge(vector<unsigned long> &arr, unsigned long l, unsigned long m, unsigned long r) {
    unsigned long i, j, k;
    unsigned long n1 = m - l + 1;
    unsigned long n2 = r - m;

    vector<unsigned long> L, R;

    for (i = 0; i < n1; i++) {
        L.push_back(arr[l + i]);
    }
    for (j = 0; j < n2; j++) {
        R.push_back(arr[m + 1 + j]);
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void iterativeMergeSort(vector<unsigned long> &arr) {
    unsigned long n = arr.size();
    unsigned long current_size;
    unsigned long left_start;
    int itt = 0;
    for (current_size = 1; current_size <= n - 1; current_size = 2 * current_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
            unsigned long mid = left_start + current_size - 1;
            unsigned long right_end = min(left_start + 2 * current_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
            itt++;
        }
    }
//    cout << itt << endl;
}






int main() {
    int arr[] = {10, 11, 2,3, 12, 5, 1};
    vector<unsigned long> arr_vector = {10, 11, 2, 3, 12, 5, 1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n/2 << endl;


    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    cout << endl;
//    mergeSort(arr, 0, n - 1);
    iterativeMergeSort(arr_vector);

    for (int i = 0; i < n; i++)
        std::cout << arr_vector[i] << " ";

    return 0;
}


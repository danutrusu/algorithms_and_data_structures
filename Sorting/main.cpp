#include <iostream>
#include <algorithm>
using namespace std;

void print_arr(int *arr,int n);
int* read_arr(int length);

//--------- quicksort start-----------//
void quick_sort(int *arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr [ (left+right)/2 ];
    while(i <= j) {
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i++],arr[j--]);
        }
    }

    if (i < right) {
        quick_sort(arr, i, right);
    }

    if (j > left) {
        quick_sort(arr, left, j);
    }
}
//--------- quicksort stop-----------//

//--------- mergesort start-----------//
void merge(int *arr,int left,int mid,int right)
{
    int i = left, j = mid + 1, index = 0, *help_arr = new int [ right - left + 1];

    for(int ind = 0; ind < right - left + 1; ++ind) {
        help_arr[ind] = arr[left + ind];
    }

    while (i<=mid && j<=right) {
        if ( arr[i] < arr[j] ) {
            help_arr[index++] = arr[i++];
        }
        else {
            help_arr[index++] = arr[j++];
        }
    }

    while( i <= mid) {
        help_arr[index++] = arr[i++];
    }
    while(j <= right) {
        help_arr[index++] = arr[j++];
    }

    for(int ind = 0; ind < right - left + 1; ++ind) {
        arr[left+ind] = help_arr[ind];
    }

}

void mergesort(int *arr, int left, int right)
{
    if (left < right) {
        int mid = (left+right) / 2;
        mergesort(arr,left, mid);
        mergesort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}
void mergesort(int *arr, int n)
{
    mergesort(arr,0,n);
}
//--------- mergesort stop-----------//

int main() {
    int *array, length;
    cin >> length;
    array = read_arr(length);

    mergesort(array, length - 1);

    print_arr(array,length);
    random_shuffle(&array[0],&array[length]);

    quick_sort(array,0,length-1);

    print_arr(array,length);

    return 0;
}


void print_arr(int *arr, int n)
{
    for(int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
int* read_arr(int length)
{
    int *arr = new int[length];
    for(int i = 0; i < length; ++i) {
        cin>>arr[i];
    }
    return arr;
}
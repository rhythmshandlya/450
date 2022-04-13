#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <climits>
using namespace std;
typedef long long int lli;
/*
    1)BubbleSort
    2)SelectionSort
    3)InsersionSort
    4)MergeSort
    5)QuickSort
    6)CountSort
    7)RedixSort
    8)BucketSort
*/

/*
    BUBBLE SORT:
    O(n^2) WORSE, O(n) BEST
    The Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements
    if they are in wrong order.
*/

void bubbleSort(vector<int> &arr)
{
    // flag to stop iteration when the array is already sorted,this is determined is no swaps are made.
    bool swapped = false;

    /*
        In every iteration the last unsorted element is brought to its correct position
        Sorting is being done from the end, one element at a time.
    */
    for (int i = 0; i < arr.size() - 1; i++)
    {
        /*
            The size()-i-1Th largest element is swapped and brought to its correct position.
        */
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped = false)
            break;
    }
}

/*
    SELECTION SORT
    O(n^2)
    The selection sort algorithm sorts an array by repeatedly finding the minimum element from
    unsorted part and putting it at the beginning. The algorithm maintains two subarrays
    in a given array.
    1) The subarray which is already sorted.
    2) Remaining subarray which is unsorted.

    64 25 12 22 11

    Find the minimum element in arr[0...4] and place it at beginning
    11 25 12 22 64
    Find the minimum element in arr[1...4]  and place it at beginning of arr[1...4]
    11 12 25 22 64
    .
    .
    .
    11 12 22 25 64
*/
void selectionSort(vector<int> &arr)
{
    /*
        In every iteration the first unsorted element is brought to its original position.
        Sorting is dont from the beginning, one element at a time.
    */
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < arr.size(); j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        // Swapping the min element in the unsorted subarray to the beginning of the subarray.
        swap(arr[i], arr[minIndex]);
    }
}

/*
    INSERTION SORT
    The array is virtually split into a sorted and an unsorted part.
    Values from the unsorted part are picked and placed at the correct position in the sorted part.

    To sort an array of size n in ascending order:
    1: Iterate from arr[1] to arr[n] over the array.
    2: Compare the current element (key) to its predecessor.
    3: If the key element is smaller than its predecessor,shift the element to right and compare
       it to the elements before. Move the greater elements one position up to make space for
       the swapped element.
*/
void insersionSort(vector<int> &arr)
{
    /*
        Picking elements from the unsorted sub-array storing it in val in every iteration.
    */
    for (int i = 1; i < arr.size(); i++)
    {
        int val = arr[i], j = i - 1;
        /*
            Looping through the sorted sub-array and make place for the new val
        */
        while (j >= 0 && arr[j] > val)
            arr[j-- + 1] = arr[j];
        /*
            OR
            {
                arr[j + 1] = arr[j];
                j--;
            }
        */
        arr[j + 1] = val;
    }
}

/*
    MERGE SORT
    Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves,
    calls itself for the two halves, and then merges the two sorted halves. The mergeSortUtility() function
    is used for merging two halves.
*/

/*
    Utility function to merget two sorted sub-array into one.
    arrayOne[first...mid] and arrayTwo[mid+1...last].
*/

void mergeSortUtility(vector<int> &vec, int first, int mid, int last)
{
    vector<int> newVec(last - first + 1);
    int i = first, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= last)
    {
        if (vec[i] <= vec[j])
            newVec.at(k++) = vec.at(i++);
        if (vec[j] < vec[i])
            newVec.at(k++) = vec.at(j++);
    }
    while (i <= mid)
    {
        newVec.at(k++) = vec.at(i++);
    }
    while (j <= last)
    {
        newVec.at(k++) = vec.at(j++);
    }
    for (int i = first, j = 0; i <= last; i++, j++)
    {
        vec[i] = newVec[j];
    }
}

void realMergeSort(vector<int> &vec, int first, int last)
{
    if (first >= last)
        return;

    int mid = (first + last) / 2;

    // Calling mergeSort on first part of the array.
    realMergeSort(vec, first, mid);

    // Calling mergeSort in second part of the array.
    realMergeSort(vec, mid + 1, last);

    // Function to merge the above two parts sub-array and constructing a single sorted array.
    mergeSortUtility(vec, first, mid, last);
}
/*
    Helper function to pass arguments to the recursive realMergeSort();
*/
void mergeSort(vector<int> &vec)
{
    realMergeSort(vec, 0, vec.size() - 1);
}

/*
    QUICK SORT
    The key process in quickSort is partition(). Target of partitions is, given an array and
    an element x of array as pivot, put x at its correct position in sorted array and put all
    smaller elements (smaller than x) before x, and put all greater elements (greater than x)
    after x. All this should be done in linear time. After partition we just apply quickSort()
    on the remaining sub-array
*/

int partition(vector<int> &arr, int first, int last)
{
    int i = first, j = first;
    while (j < last)
    {
        if (arr[j] <= arr[last])
            swap(arr[i++], arr[j]);
        j++;
    }
    swap(arr[last], arr[i]);
    return i;
}

void realQuickSort(vector<int> &vec, int first, int last)
{
    if (first >= last)
        return;
    int pvtIndex = partition(vec, first, last);
    realQuickSort(vec, first, pvtIndex - 1);
    realQuickSort(vec, pvtIndex + 1, last);
}

void quickSort(vector<int> &vec)
{
    realQuickSort(vec, 0, vec.size() - 1);
}

/*
    Bucket sort is mainly useful when input is uniformly distributed over a range.
    Like sorting a large set of floating point numbers which are in range from 0.0 to 1.0
    and are uniformly distributed across the range.
*/
void insersionSortList(list<double> li)
{
}
void bucketSort(vector<double> &arr)
{
    vector<list<double>> bucket(10);

    for (int i = 0; i < arr.size(); i++)
    {
        int bi = arr[i] * 10;
        bucket[bi].push_back(arr[i]);
    }

    for (int i = 0; i < bucket.size(); i++)
    {
        /*
            More prefered!
            insersionSortList(bucket[i]);
            But easy to use inquilt sort.
        */
        bucket[i].sort();
    }

    int index = 0;
    for (int i = 0; i < bucket.size(); i++)
    {
        list<double>::iterator it;
        for (it = bucket[i].begin(); it != bucket[i].end(); ++it)
            arr[index++] = *it;
    }
}

/*
    COUNT SORT O(N+k)
    Counting sort is a sorting technique based on keys between a specific range. It works
    by counting the number of objects having distinct key values.Then doing some arithmetic
    to calculate the position of each object in the output sequence.
    It is a stable algorithm.
*/
vector<int> countSort(vector<int> &vec, int min, int max)
{
    // Determine the range;
    int range = max - min + 1;

    // Allocating memory for the vector which will store the number of occourances numbers.
    vector<int> count(range, 0), ans(vec.size()); // answer vector

    // Storing the frequency of every element in the range
    for (int i = 0; i < vec.size(); i++)
        count[vec[i] - min]++;

    // TO MAKE THIS ALGO INPLACE
    //  Converting the count array into a prefix-sum array
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    /*
        For the algo to be stable we must not disrupt the sequence in which the numbers
        appear in the original array. Though the nu
        For the algo to be stable we must not disrupt the sequence in which the numbers
        appear in the original array. Though the numbers are equal the might be associated
        with some other property whose order must not be disrupted. Like if we arragge
        students with same grade must appear in order of their rollNo.
    */
    for (int i = vec.size() - 1; i >= 0; i--)
        ans[--count[vec[i] - min]] = vec[i];

    return ans;
}

/*
    Radix Sort
    The idea of Radix Sort is to do digit by digit sort starting from least significant
    digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
*/
/*
    Count sort as a utitilty function for redix sort.
    The exp decides on basis of which significant digit are we sorthing the array.
*/
void countSort(vector<int> &vec, int exp)
{
    // The compariso is of the digits soo 0-9 are the only keys required.
    vector<int> count(10, 0), ans(vec.size());

    for (int i = 0; i < vec.size(); i++)
        count[(vec[i] / exp) % 10]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = vec.size() - 1; i >= 0; i--)
        ans[--count[(vec[i] / exp) % 10]] = vec[i];

    for (int i = 0; i < vec.size(); i++)
        vec[i] = ans[i];
}

void redixSort(vector<int> &vec)
{
    int max = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
        if (max < vec[i])
            max = vec[i];

    int exp = 1;
    /*
        Applying count sort on the array for N number of times.
        N = Number of digits in the largest number in the array to be sorted.
    */
    while (max > 0)
    {
        countSort(vec, exp);
        exp *= 10;
        max /= 10;
    }
}

int main()
{
    srand(time(0));
    int n = 10000000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    // bubbleSort(arr);
    // selectionSort(arr);
    // insersionSort(arr);
    // mergeSort(arr);
    // quickSort(arr);
    // arr = countSort(arr, 0, 100);
    redixSort(arr);
    cout << "\n\n\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    /*
    //For bucket sort
    vector<double> b = {0.43, 0.45, 0.78, 0.76, 0.87, 0.21, 0.12, 0.67, 0.23, 0.888};
    bucketSort(b);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    */
    cout << endl;
    system("pause");
    return 0;
}
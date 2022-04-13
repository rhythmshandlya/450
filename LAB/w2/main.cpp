#include <iostream>
#include <climits>
#include <vector>
#include <ctime>
#include <cmath>

/*
    1)BubbleSort-----
    2)SelectionSort--
    3)InsersionSort--
    4)MergeSort------DONE
    5)QuickSort------DONE
    6)CountSort------
    7)RedixSort------
    8)BucketSort-----
    9)HeapSort-------
*/

using namespace std;


// MergeSort
void merge(vector<int> &arr, int f, int mid, int l) {

	int len = f + l ;
	vector<int> v(len);

	int i = f, j = mid + 1, k = 0;
	while (i <= mid && j <= l) {
		if (arr[i] <= arr[j])
			v[k++] = arr[i++];
		else
			v[k++] = arr[j++];
	}
	while (i <= mid)
		v[k++] = arr[i++];
	while (j <= l)
		v[k++] = arr[j++];

	k = 0;
	for (i = f; i <= l; i++, k++)
		arr[i] = v[k];

}

void mergeSort(vector<int> &arr, int f, int l) {
	if (f < l) {
		int mid = (f + l) / 2;
		mergeSort(arr, f, mid);
		mergeSort(arr, mid + 1, l);
		merge(arr, f, mid, l);
	}
}

// QuickSort
/*
    QUICK SORT
    The key process in quickSort is partition(). Target of partitions is, given an array and
    an element x of array as pivot, put x at its correct position in sorted array and put all
    smaller elements (smaller than x) before x, and put all greater elements (greater than x)
    after x. All this should be done in linear time.
    After partition we just apply quickSort() on the remaining sub-array
*/

int partition(vector<int> &a, int f, int l) {
	int i = f, j = f;

	int pivot = rand() % (l - f + 1) + f;
	swap(a[l], a[pivot]);

	while (j < l)
	{
		if (a[j] <= a[l])
			swap(a[i++], a[j]);
		j++;
	}
	swap(a[l], a[i]);
	return i;
}

void quickSort(vector<int> &a, int f, int l) {
	if (f < l) {
		int pvt_i = partition(a, f, l);
		quickSort(a, f, pvt_i - 1);
		quickSort(a, pvt_i + 1, l);
	}
}

vector<int> countSort(vector<int> &vec, int min, int max)
{
	int range = max - min + 1;

	vector<int> count(range, 0), ans(vec.size());

	for (int i = 0; i < vec.size(); i++)
		count[vec[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = vec.size() - 1; i >= 0; i--)
		ans[--count[vec[i] - min]] = vec[i];

	return ans;
}

vector<int> redixCountSort(vector<int> vec, int exp) {
	vector<int> count(10, 0), ans(vec.size());

	for (int i = 0; i < vec.size(); i++)
		count[(vec[i] / exp) % 10]++;

	//Creating a positions array
	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = vec.size() - 1; i >= 0; i--) {
		ans[--count[(vec[i] / exp) % 10]] = vec[i];
	}
	return ans;
}


void redixSort(vector<int> &vec) {

	cout << "In redix..";
	int mx = INT_MIN;
	for (int i = 0; i < vec.size(); i++)
		if (mx < vec[i])
			mx = vec[i];

	int expo = 1;

	while (mx > 0) {
		vec = redixCountSort(vec, expo);
		expo *= 10;
		mx /= 10;
	};
}



int main() {
	srand(time(0));
	int n = 100;
	vector<int> arr(n);
	cout << "\n-----------------------------------\n";
	cout << "RANDOM INPUT: ";
	cout << "\n-----------------------------------\n\n";
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		cout << arr[i] << " ";
		if (i % 14 == 13) {
			cout << endl;
		}
	}

	redixSort(arr);

	cout << "\n\n-----------------------------------\n";
	cout << "SORTED OUTPUT: ";
	cout << "\n-----------------------------------\n\n";


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		if (i % 14 == 13) {
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}
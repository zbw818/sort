#include "sort.h"


int main() {
	vector<int> arr{ 3, 5, 8, 12, 6, 4, 7, 15, 9};
	int len = arr.size();

	printarr(arr, 'b');
	//MergeSort(arr, 1, len);
	//QuickSort(arr, 0, len - 1);
	BucketSort(arr);
	printarr(arr, 'a');
	cout << endl << endl << endl;

	system("pause");
	return 0;
}



#include "sort.h"


int main() {
	vector<int> arr{ 3, 5, 8, 12, 6, 4, 7, 15, 9};
	int len = arr.size();

	/*printarr(arr, 'b');
	MergeSort(arr, 1, len);
	QuickSort(arr, 0, len - 1);
	BucketSort(arr);
	printarr(arr, 'a');
	cout << endl << endl << endl;*/

	hash_search(arr, 15);




	//数组使用memset函数初始化的操作
	/*int a[8][8];
	cout << sizeof a << endl;
	cout << sizeof a[0] << endl;
	memset(a, 0, sizeof a);
	for (int i = 0; i < sizeof a/32; i++) {
		for (int j = 0; j < sizeof a[0]/4; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;*/


	//vector数组使用memset函数初始化的操作
	/*vector<int>test1(len,9);
	vector<vector<int> >test2(7,vector<int>(8,6));
	for (auto t : test1) {
		cout << t << '\t';
	}
	cout << endl; 

	memset(&test1[0], 0, test1.size() * sizeof test1[0]);
	for (int i = 0; i < test2.size(); i++) {
		memset(&test2[i][0], 0, test2[0].size() * sizeof test2[i][0]);
	}
	
	 
	cout << test1.size() << endl;
	cout << test2.size() << endl;
	cout << test2[0].size() << endl;

	for (auto t : test1) {
		cout << t << '\t';
	}
	cout << endl;
	cout << endl;
	vector<int>tem;
	for (vector<vector<int> >::iterator item = test2.begin(); item != test2.end(); item++) {
		tem = *item;
		for (vector<int>::iterator it = tem.begin(); it != tem.end(); it++) {
			cout << *it << '\t';
		}
		cout << endl;
	}
	cout << endl;*/





	system("pause");
	return 0;
}



















//#include <iostream>
//#include <vector>
//using namespace std;
//using namespace std;
//
//void BubbleSort(vector<int>& arr) {
//	for (int i = 0; i < arr.size() - 1; i++) {
//		for (int j = 0; j < arr.size() - 1 - i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tem = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tem;
//			}
//		}
//	}
//}
//int main() {
//	vector<int> arr{ 14, 5, 86, 22, 6, 54, 30, 54, 29 };
//
//	cout << "before sort: " << endl;
//	for (auto a : arr) {
//		cout << a << "\t";
//	}
//	cout << endl;
//
//	BubbleSort(arr);
//
//	cout << "after sort: " << endl;
//	for (auto a : arr) {
//		cout << a << "\t";
//	}
//	cout << endl;
//
//
//	system("pause");
//	return 0;
//}
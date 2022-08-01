#include "sort.h"
#define bef "before sort: "
#define aft "after sort: "
void printarr(vector<int> arr,char ch) {
	if (ch == 'b') {
		cout << "\t" << bef << endl;
		for (auto a : arr) {
			cout << "\t" << a << "   ";
		}
		cout << endl;
	}
	if (ch == 'a') {
		cout << "\t" << aft << endl;
		for (auto a : arr) {
			cout << "\t" << a << "   ";
		}
		cout << endl;
	}
}

//冒泡排序
void BubbleSort(vector<int>& arr) {
	for(int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tem = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tem;
			}
		}
	}
}
//插入排序
void InsertSort(vector<int>& arr) {
	for(int i = 1; i < arr.size(); i++) {
		int index = i;
		int tem = arr[index];
		while (index > 0 && arr[index - 1] > tem) {
			arr[index] = arr[index - 1];
			index--;
		}
		if (index != i) {
			arr[index] = tem;
		}
	}
}
//选择排序
void SelectSort(vector<int>& arr) {
	for(int i = 1; i < arr.size(); i++) {
		int min_index = i-1;
		for (int j = i; j < arr.size(); j++) {
			if (arr[j] <  arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i-1) {
			int tem = arr[i-1];
			arr[i-1 ] = arr[min_index];
			arr[min_index] = tem;
		}
	}
}
//希尔排序
void ShellSort(vector<int>& arr) {
	int interval = 1;
	while (interval < arr.size() / 3) {
		interval = interval * 3 + 1;
	}
	int tem;
	while (interval>0){
		for (int i = interval; i < arr.size(); i++) {
			for (int j = i; j >= interval && arr[j] < arr[j - interval]; j -= interval) {
				tem = arr[j];
				arr[j] = arr[j - interval];
				arr[j - interval] = tem;
			}
		}
		interval /= 3;
	}
}
void merge(vector<int>& arr, int start, int mid, int end) {
	int i, j;
	vector<int>subleft(100);
	vector<int>subright(100);
	for (i = 0; i < mid - start + 1; i++) {
		subleft[i] = arr[start - 1 + i];
	}
	subleft[i] = INT_MAX;
	for (i = 0; i < end - mid; i++) {
		subright[i] = arr[mid + i];
	}
	subright[i] = INT_MAX;
	i = 0, j = 0;
	for (int k = start; k <= end; k++) {
		if (subleft[i] <= subright[j]) {
			arr[k-1] = subleft[i];
			i++;
		}
		else {
			arr[k-1] = subright[j ];
			j++;
		}
	}
}
//归并排序
void MergeSort(vector<int>& arr, int start, int end) {
	if (arr.empty() || start > end || start == end) return;
	int mid;
    mid = (start + end) / 2;
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
int position(vector<int>& arr, int start, int end) {
	int left = start;
	int right = end - 1;
	int target = arr[end];
	int tem;
	while (true) {
		while (arr[left] < target) left++;
		while (right > 0 && arr[right] > target) right--;
		if (left >= right) break;
		tem = arr[left];
		arr[left] = arr[right];
		arr[right] = tem;
		left++;
		right--;
	}
	arr[end] = arr[left];
	arr[left] = target;
	return left;	
}
//快速排序
void QuickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return;
	int par;
	par = position(arr, start, end);
	QuickSort(arr, start, par-1);
	QuickSort(arr, par+1, end);
}
//计数排序
void CountSort(vector<int>& arr) {
	int Max = arr[0];
	for (int i = 1; i < arr.size();i++) {
		Max = arr[i] > Max ? arr[i] : Max;
	}
	
	vector<int>array(Max+1, 0);
	vector<int>tem(arr.size(), 0);
	
	for (int i = 0; i < arr.size(); i++) {
		array[arr[i]]++;
	}
	for (int i = 1; i < array.size(); i++) {
		array[i] = array[i - 1] + array[i];
	}
	for (int i = 0; i < arr.size(); i++) {
		tem[array[arr[i]] - 1] = arr[i];
		array[arr[i]]--;
	}
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = tem[i];
	}
}
//基数排序
void RadixSort(vector<int>& arr) {
	int Max = arr[0];
	int d = 1;//记录最大值的位数
	for (int i = 1; i < arr.size(); i++) {
		Max = Max > arr[i] ? Max : arr[i];
	}
	while (Max > 10) {
		Max /= 10;
		d++;
	}

	int radix = 1;
	for (int i = 1; i <= d; i++) {
		vector<int> array(10, 0);//计数排序数组
		vector<int> tem(arr.size(), 0);
		int index;
		for (int j = 0; j < arr.size(); j++) {
			index = (arr[j] / radix) % 10;
			array[index]++;
		}
		for (int j = 1; j < 10; j++) array[j] = array[j - 1] + array[j];
		//倒序存放(FIFO)，保持位数上数值相同的元素在原始数组中的相对位置
		for (int j = tem.size()-1; j >= 0; j--) {
			index = (arr[j] / radix) % 10;
			tem[array[index]-1] = arr[j];
			array[index]--;
		}
		for (int j = 0; j < arr.size(); j++) {
			arr[j] = tem[j];
		}
		radix *= 10;
	}
}
//桶排序
void BucketSort(vector<int>& arr) {
	int len = arr.size();
	int Max = INT_MIN;
	for (auto a : arr) {
		Max = Max > a ? Max : a;
	}
	vector<vector<int> >bucket(Max + 1);

	for (auto a : arr) {
		bucket[a].push_back(a);
	}
	int j = 0;
	for (int i = 0; i < bucket.size(); i++) {
		while (!bucket[i].empty()) {
			arr[j++] = bucket[i].back();
			bucket[i].pop_back();
		}
	}
}

//插值查找
void insert_serch(vector<int>& arr, int num, int begin, int end) {
	sort(arr.begin(), arr.end());
	if (begin > end) {
		cout << "no number in array!" << endl;
		return;
	}
	if (begin == end) {
		if (num == arr[begin]) cout << "the index of number is: " << begin << endl;
		else cout << "no number in array!" << endl;
		return;
	}

	int mid = begin + (end - begin) / (arr[end] - arr[begin]) * (num - arr[begin]);
	if (num == arr[mid]) {
		cout<< "the index of number is: " << mid << endl;
		return;
	}
	else if (num <= arr[mid]) {
		insert_serch(arr, num, begin, mid - 1);
	}
	else {
		insert_serch(arr, num, mid + 1, end);
	}
}
//哈希查找
void hash_search(vector<int>& arr, int num) {
	int Max = INT_MIN;
	for (auto a : arr) {
		Max = Max > a ? Max : a;
	}
	vector<int>hashlist(Max * 2);
	int index;
	for (auto a : arr) {
		index = a % 10;
		while (hashlist[index] != 0) {
			index++;
		}
		hashlist[index] = a;
	}
	int target = num % 10;
	while (hashlist[target] != num) {
		target++;
		if (hashlist[target] == 0 || target == num % 10) {
			cout << "no number here!" << endl;
			return;
		}
	}
	cout << "find it! the index in hashlist is: ";
	cout << target << endl;
}
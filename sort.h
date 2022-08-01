#pragma once
//#include <iostream>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;
void printarr(vector<int> arr,char ch);
void BubbleSort(vector<int>& arr);
void InsertSort(vector<int>& arr);
void SelectSort(vector<int>& arr);
void ShellSort(vector<int>& arr);

void MergeSort(vector<int>& arr, int start, int end);
void merge(vector<int>& arr, int start, int mid, int end);

void QuickSort(vector<int>& arr, int start, int end);
int position(vector<int>& arr, int start, int end);

void CountSort(vector<int>& arr);
void RadixSort(vector<int>& arr);
void BucketSort(vector<int>& arr);


void insert_serch(vector<int>& arr, int num, int begin, int end);
void hash_search(vector<int>& arr, int num);
#pragma once
#include<iostream>
#include<string>
using namespace std;
void bubbleSort(int * _array,int _size) {
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int)*_size);
	bool exchange = false;
	int counts = 0; 
	int begin = clock();
	for (int i = 1; i < _size; i++) {
		exchange = false;
		for (int j = _size - 1; j >= i; j--) {
			if (s_array[j] < s_array[j - 1]) {
				int temp = s_array[j-1];
				s_array[j - 1] = s_array[j];
				s_array[j] = temp;
				counts++;
				exchange = true;
			}
		}
		if (exchange == false) {
			break;
		}
	}
	int end = clock();
	cout << "冒泡排序交换次数:" << counts << endl;
	cout << "冒泡排序所用时间" << end - begin << endl;
}

void selectionSort(int * _array, int _size) {
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int)*_size);
	int counts = 0;
	int begin = clock();
	for (int i = 0; i < _size; i++) {
		int min = INT_MAX; int anc = 0;
		for (int j = i; j < _size; j++) {
			if (s_array[j] < min) {
				min = s_array[j]; anc = j;
			}
		}
		int temp = s_array[i];
		s_array[i] = s_array[anc];
		s_array[anc] = temp;
		counts++;
	}
	int end = clock();
	cout << "选择排序交换次数:" << counts << endl;
	cout << "选择排序所用时间" << end - begin << endl;
}

void insertSort(int * _array, int _size) {
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int)*_size);
	int counts = 0;
	int begin = clock();
	for (int i = 0; i < _size-1; i++) {
		if (s_array[i + 1] < s_array[i]) {
			int temp = s_array[i + 1];
			int scaner = i;
			while (scaner >= 0 && s_array[scaner] > temp) {
				s_array[scaner + 1] = s_array[scaner];
				scaner--;
			}
			s_array[scaner + 1] = temp;
			counts++;
		}
	}
	int end = clock();
	cout << "直接插入排序交换次数:" << counts << endl;
	cout << "直接插入排序所用时间" << end - begin << endl;
}

void shellSort(int *_array, int _size) {
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int)*_size);
	int counts = 0;
	int begin = clock();
	int gap = _size - 1 - 1 + 1;
	while (gap >= 1) {
		for (int i = 0; i + gap < _size; i++) {
			if (s_array[i] > s_array[i + gap]) {
				int temp = s_array[i + gap];
				int scaner = i;
				while (scaner >= 0 && s_array[scaner] > temp) {
					s_array[scaner + gap] = s_array[scaner];
					scaner -= gap;
				}
				s_array[scaner + gap] = temp;
				counts++;
			}
		}

		if (gap != 1) {
			gap = gap / 3 + 1;
		}
		else {
			break;
		}
	}
	int end = clock();
	cout << "希尔排序交换次数:" << counts << endl;
	cout << "希尔排序所用时间" << end - begin << endl;

}
int Partition(int * s_array, int _size, int &counts) {
	int pivotpos = 0; int pivot = s_array[0];
	for (int i = 1; i < _size; i++) {
		if (s_array[i] < pivot) {
			pivotpos++;
			if (pivotpos != i) {
				int temp = s_array[i];
				s_array[i] = s_array[pivotpos];
				s_array[pivotpos] = temp;
				counts++;
			}
		}
	}
	s_array[0] = s_array[pivotpos]; s_array[pivotpos] = pivot;
	counts++;
	return pivotpos;
}
void quickSort(int * s_array, int _size,int &counts) {
	if (_size > 1) {
		int pivotpos = Partition(s_array, _size,counts);
		quickSort(s_array, pivotpos ,counts);
		quickSort(s_array + pivotpos + 1, _size - pivotpos-1,counts);
	}
}
void quickSortHelp(int *_array, int _size) {
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int)*_size);
	int counts = 0;
	int start = clock();
	quickSort(s_array, _size, counts);
	int end = clock();
	cout << "快速排序交换次数:" << counts << endl;
	cout << "快速排序所用时间" << end - start << endl;
}


//堆排序
void HeapAdjust(int * s_array, int i, int _size,int &count) {
	int temp = s_array[i];//先取出当前元素i
	for (int k = i * 2 + 1; k<_size; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
		if (k + 1<_size && s_array[k]<s_array[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
			k++;
		}
		if (s_array[k] >temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			s_array[i] = s_array[k];
			i = k;
			count++;
		}
		else {
			break;
		}
	}
	s_array[i] = temp;//将temp值放到最终的位置
}
void heapSort(int * _array,int _size) {
	int *s_array= new int[_size];;
	int begin, end;
	int count = 0;
	memcpy(s_array, _array, sizeof(int) * _size);
	begin = clock();
	for (int i = _size / 2 - 1; i >= 0; --i) {
		HeapAdjust(s_array, i, _size, count);
	}
	for (int i = _size - 1; i >= 0; i--) {
		count++;
		int temp = s_array[i];
		s_array[i] = s_array[0];
		s_array[0] = temp;
		HeapAdjust(s_array, 0, i,count);
	}

	end = clock();
	delete[] s_array;
	cout << "堆排序交换次数:" << count << endl;
	cout << "堆排序所用时间:" << end - begin  << endl;
}



void merge(int* s_array, int mid, int _size,int &count) {
	int * temp = new int[_size];
	int i = 0;//左序列指针
	int j = mid + 1;//右序列指针
	int t = 0;//临时数组指针
	while (i <= mid && j < _size) {
		if (s_array[i] <= s_array[j]) {
			temp[t++] = s_array[i++];
			count++;
		}
		else {
			temp[t++] = s_array[j++];
			
		}
	}
	while (i <= mid) {//将左边剩余元素填充进temp中
		temp[t++] = s_array[i++];
	}
	while (j < _size) {//将右序列剩余元素填充进temp中
		temp[t++] = s_array[j++];
	}
	t = 0;
	//将temp中的元素全部拷贝到原数组中
	memcpy(s_array, temp, sizeof(int) * _size);
	delete[]temp;
}

void mergeSort(int * s_array, int _size,int &count) {
	if (_size > 1) {
		int mid = (_size - 1) / 2;//中间元素的下标
		mergeSort(s_array, mid + 1,count);//_size是mid+1
		mergeSort(s_array + mid + 1, _size - mid - 1,count);//右边归并排序，使得右子序列有序
		merge(s_array, mid, _size,count);//将两个有序子数组合并操作
	}
}
void mergeSortHelp(int * _array, int _size) {
	int *s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int) * _size);
	int count = 0;
	int start = clock();
	mergeSort(s_array, _size,count);
	int end = clock();
	cout << "归并排序比较次数:" << count << endl;
	cout << "归并排序所用时间" << end - start << endl;
}

int getMax(int s_array[], int _size)
{
	int i, max;
	max = s_array[0];
	for (i = 1; i < _size; i++)
		if (s_array[i] > max)
			max = s_array[i];
	return max;
}


void countSort(int * s_array, int _size, int exp)
{         
	int i, buckets[10] = { 0 };
	int * outputs = new int[_size];

	for (i = 0; i < _size; i++)
		buckets[(s_array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1];

	for (i = _size - 1; i >= 0; i--)
	{
		outputs[buckets[(s_array[i] / exp) % 10] - 1] = s_array[i];
		buckets[(s_array[i] / exp) % 10]--;
	}

	for (i = 0; i < _size; i++)
		s_array[i] = outputs[i];
}

void radixSort(int * _array, int _size)
{
	int start = clock();
	int exp;    // 指数。当对数组按各位进行排序时，exp=1；按十位进行排序时，exp=10；...
	int max = getMax(_array, _size);    // 数组a中的最大值
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int) * _size);				   // 从个位开始，对数组a按"指数"进行排序
	for (exp = 1; max / exp > 0; exp *= 10) {
		countSort(s_array, _size, exp);
	}
	int end = clock();
	cout << "基数排序比较次数:" << 0 << endl;
	cout << "基数排序所用时间" << end - start << endl;
}

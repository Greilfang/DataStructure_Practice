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
	cout << "ð�����򽻻�����:" << counts << endl;
	cout << "ð����������ʱ��" << end - begin << endl;
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
	cout << "ѡ�����򽻻�����:" << counts << endl;
	cout << "ѡ����������ʱ��" << end - begin << endl;
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
	cout << "ֱ�Ӳ������򽻻�����:" << counts << endl;
	cout << "ֱ�Ӳ�����������ʱ��" << end - begin << endl;
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
	cout << "ϣ�����򽻻�����:" << counts << endl;
	cout << "ϣ����������ʱ��" << end - begin << endl;

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
	cout << "�������򽻻�����:" << counts << endl;
	cout << "������������ʱ��" << end - start << endl;
}


//������
void HeapAdjust(int * s_array, int i, int _size,int &count) {
	int temp = s_array[i];//��ȡ����ǰԪ��i
	for (int k = i * 2 + 1; k<_size; k = k * 2 + 1) {//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
		if (k + 1<_size && s_array[k]<s_array[k + 1]) {//������ӽ��С�����ӽ�㣬kָ�����ӽ��
			k++;
		}
		if (s_array[k] >temp) {//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
			s_array[i] = s_array[k];
			i = k;
			count++;
		}
		else {
			break;
		}
	}
	s_array[i] = temp;//��tempֵ�ŵ����յ�λ��
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
	cout << "�����򽻻�����:" << count << endl;
	cout << "����������ʱ��:" << end - begin  << endl;
}



void merge(int* s_array, int mid, int _size,int &count) {
	int * temp = new int[_size];
	int i = 0;//������ָ��
	int j = mid + 1;//������ָ��
	int t = 0;//��ʱ����ָ��
	while (i <= mid && j < _size) {
		if (s_array[i] <= s_array[j]) {
			temp[t++] = s_array[i++];
			count++;
		}
		else {
			temp[t++] = s_array[j++];
			
		}
	}
	while (i <= mid) {//�����ʣ��Ԫ������temp��
		temp[t++] = s_array[i++];
	}
	while (j < _size) {//��������ʣ��Ԫ������temp��
		temp[t++] = s_array[j++];
	}
	t = 0;
	//��temp�е�Ԫ��ȫ��������ԭ������
	memcpy(s_array, temp, sizeof(int) * _size);
	delete[]temp;
}

void mergeSort(int * s_array, int _size,int &count) {
	if (_size > 1) {
		int mid = (_size - 1) / 2;//�м�Ԫ�ص��±�
		mergeSort(s_array, mid + 1,count);//_size��mid+1
		mergeSort(s_array + mid + 1, _size - mid - 1,count);//�ұ߹鲢����ʹ��������������
		merge(s_array, mid, _size,count);//����������������ϲ�����
	}
}
void mergeSortHelp(int * _array, int _size) {
	int *s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int) * _size);
	int count = 0;
	int start = clock();
	mergeSort(s_array, _size,count);
	int end = clock();
	cout << "�鲢����Ƚϴ���:" << count << endl;
	cout << "�鲢��������ʱ��" << end - start << endl;
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
	int exp;    // ָ�����������鰴��λ��������ʱ��exp=1����ʮλ��������ʱ��exp=10��...
	int max = getMax(_array, _size);    // ����a�е����ֵ
	int * s_array = new int[_size];
	memcpy(s_array, _array, sizeof(int) * _size);				   // �Ӹ�λ��ʼ��������a��"ָ��"��������
	for (exp = 1; max / exp > 0; exp *= 10) {
		countSort(s_array, _size, exp);
	}
	int end = clock();
	cout << "��������Ƚϴ���:" << 0 << endl;
	cout << "������������ʱ��" << end - start << endl;
}

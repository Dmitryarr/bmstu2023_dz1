#include "sorts.h"

int GetMax(int* ar, int size) {
	int max = 0;
	int i = 1;
	while (i < size) {
		if (ar[max] < ar[i])
			max = i;
		i++;
	}
	return max;
}
void SelectionSort(int* ar, int len) {
	while (len) {
		int indMax = GetMax(&ar[0], len);
		std::swap(ar[indMax], ar[len - 1]);
		len--;
	}
}
void insertionSort(int* ar, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int temp = ar[i];
		int j = i - 1;
		while (j >= left && ar[j] > temp) {
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j + 1] = temp;
	}
}
void InsertionSort(int* ar, int len) {
	insertionSort(ar, 0, len - 1);
}
void BubbleSort(int* ar, int len) {
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (ar[j] > ar[j + 1]) {
				std::swap(ar[j], ar[j + 1]);
			}
		}
	}
}
void CountingSort(int* ar, int len) {
	int i, max = -1;
	int* counter;
	for (i = 0; i < len; i++)
		if (abs(ar[i]) > max)
			max = abs(ar[i]);
	counter = new int[max * 2 + 1];
	for (i = 0; i < max * 2 + 1; i++)
		counter[i] = 0;
	for (i = 0; i < len; i++)
		counter[ar[i] + max]++;
	for (int i = 0, j, k = 0; i < max * 2 + 1; i++) {
		if (counter[i] > 0) {
			j = counter[i];
			for (; j > 0; j--) {
				ar[k] = i - max;
				k++;
			}
		}
	}
	delete[] counter;
}
int Partition(int* ar, int first, int last) {
	int pivot = ar[(first + last) / 2];
	int i = first, j = last;
	while (true) {
		while (ar[i] < pivot)
			i++;
		while (ar[j] > pivot)
			j--;
		if (i >= j)
			break;
		std::swap(ar[i], ar[j]);
		i++;
		j--;
	}
	return j;
}
void quickSort(int* ar, int last, int first) {
	if (first < last) {
		int p = Partition(ar, first, last);
		quickSort(ar, p, first);
		quickSort(ar, last, p + 1);
	}
}
void QuickSort(int* ar, int len) {
	quickSort(ar, len - 1, 0);
}
void Merge(int* ar, int l, int m, int r) {
	int len1 = m - l + 1, len2 = r - m;
	int* left = new int[len1];
	int* right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = ar[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = ar[m + 1 + i];
	int i = 0;
	int j = 0;
	int k = l;
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			ar[k] = left[i];
			i++;
		}
		else {
			ar[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1) {
		ar[k] = left[i];
		k++;
		i++;
	}
	while (j < len2) {
		ar[k] = right[j];
		k++;
		j++;
	}
	delete[] left;
	delete[] right;
}
void mergeSort(int* ar, int right, int left) {
	if (left < right)
		if (right - left == 1) {
			if (ar[right] < ar[left]) {
				std::swap(ar[right], ar[left]);
			}
		}
		else {
			mergeSort(ar, left + (right - left) / 2, left);
			mergeSort(ar, right, left + (right - left) / 2 + 1);
			Merge(ar, left, left + (right - left) / 2, right);
		}
}
void MergeSort(int* ar, int len) {
	mergeSort(ar, len - 1, 0);
}
void ShellSort(int* ar, int len) {
	for (int d = len / 2; d > 0; d /= 2)
		for (int i = d; i < len; i += d)
			for (int j = i; j > 0; j -= d)
				if (ar[j] < ar[j - d])
					std::swap(ar[j], ar[j - d]);
}
void GnomeSort(int* ar, int len) {
	for (int i = 0; i < len;) {
		if (i == 0)
			i++;
		if (ar[i] >= ar[i - 1])
			i++;
		else {
			std::swap(ar[i], ar[i - 1]);
			i--;
		}
	}
}
void Heapify(int* ar, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && ar[l] > ar[largest])
		largest = l;
	if (r < n && ar[r] > ar[largest])
		largest = r;
	if (largest != i) {
		std::swap(ar[i], ar[largest]);
		Heapify(ar, n, largest);
	}
}
void HeapSort(int* ar, int len) {
	for (int i = len / 2 - 1; i >= 0; i--)
		Heapify(ar, len, i);
	for (int i = len - 1; i >= 0; i--) {
		std::swap(ar[0], ar[i]);
		Heapify(ar, i, 0);
	}
}

FILE* fLog = fopen("test1.txt", "w");
void (*funcAr[9])(int*, int) = { SelectionSort, InsertionSort, BubbleSort, CountingSort, QuickSort, MergeSort, ShellSort, GnomeSort, HeapSort };
int GetRandomNumber(int min, int max) {
	int num = rand() % (max - min) + min;
	return num;
}
void Sort(int index, int* ar, int len) {
	funcAr[index](ar, len);
}
void Megatest() {
	fprintf(fLog, "%10s", "BEGIN:         SelectionSort ");
	fprintf(fLog, "%10s", "   InsertionSort ");
	fprintf(fLog, "%10s", "   BubbleSort ");
	fprintf(fLog, "%10s", "   CountingSort ");
	fprintf(fLog, "%10s", "   QuickSort ");
	fprintf(fLog, "%10s", "   MergeSort ");
	fprintf(fLog, "%10s", "   ShellSort ");
	fprintf(fLog, "%10s", "   GnomeSort ");
	fprintf(fLog, "%10s", "   HeapSort");
	srand(static_cast<unsigned int>(time(NULL)));
	int* ar = new int[10000000];
	int* funcOut = new int[9];
	for (int i = 0; i < 9; i++) {
		funcOut[i] = 0;
	}
	for (int len = 100, step = 100, count = 1;; len += step, count++) {
		fprintf(fLog, "\n");
		fprintf(fLog, "%10d", len);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; funcOut[i] == 0 && j < 21; j++) {
				int times[21];
				for (int i = 0; i < len; i++)
					ar[i] = GetRandomNumber(-1000, 1000);
				auto begin = std::chrono::steady_clock::now();
				Sort(i, ar, len);
				auto end = std::chrono::steady_clock::now();
				auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
				int Time = elapsed_ms.count();
				if (Time > 2000) {
					funcOut[i] = 1;
					break;
				}
				times[j] = Time;
				if (j == 20) {
					BubbleSort(times, 21);
					Time = (times[7] + times[8] + times[9] + times[10] + times[11] + times[12] + times[13]) / 7;
					fprintf(fLog, "    %10d", Time);
				}
			}
			if (funcOut[i] == 1) {
				fprintf(fLog, "%10s", "END.");
			}
		}
	}
	delete[] ar;
	fclose(fLog);
}
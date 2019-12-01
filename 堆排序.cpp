#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void max_heapfy(int arr[], int i, int heap_size)
{
	int temp, largest = i;
	if (arr[i] < arr[2 * i + 1] && 2 * i + 1 <= heap_size) { largest = 2 * i + 1; }
	if (arr[largest] < arr[2 * i + 2] && 2 * i + 2 <= heap_size) { largest = 2 * i + 2; }
	if (i != largest)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapfy(arr, largest, heap_size);
	}
}
void build_maxheap(int arr[], int arr_size)
{
	for (int j = arr_size / 2 - 1; j >= 0; j--)
	{
		max_heapfy(arr, j, arr_size - 1);
	}
}
void heapsort(int * const arr, int arr_size)
{
	//while (*s++ = *t++);
	build_maxheap(arr, arr_size);
	int heap_size = arr_size - 1, temp;
	for (int i = arr_size - 1; i >= 1; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heap_size--;
		max_heapfy(arr, 0, heap_size);
	}
}
int main()
{
	int a[100] = { 0 }, i;
	for (i = 0; i<100; i++)
		a[i] = -i * 2 + 82;
	heapsort(a, 100);
	for (int i = 0; i < 100; i++)
		cout << a[i] << " ";
	return 0;
}
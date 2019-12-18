#include <iostream>
using namespace std;
int partition(int array[], int first, int last)
{
	int pivot = array[last];
	int i = (first - 1);

	for (int j = first; j <= last - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			int temp=array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
	int temp=array[i+1];
	array[i+1]=array[last];
	array[last]=temp;
	return (i + 1);
}
void quickSort(int array[], int first, int last)
{
	if (first < last)
	{
		int pi = partition(array, first, last);
		quickSort(array, first, pi - 1);
		quickSort(array, pi + 1, last);
	}
}
void display(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
int main()
{
	int array[] = {100, 7, 8, 9000, 1, 5};
	int n = sizeof(array) / sizeof(array[0]);
	quickSort(array, 0, n - 1);
	cout << "Finally array is sorted: \n";
    display(array, n);
	return 0;
}

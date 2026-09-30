#include <iostream>
using namespace std;

// Function to maintain Max Heap property
void heapify(int arr[], int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not the largest, swap and heapify again
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move maximum element to the end
        swap(arr[0], arr[i]);

        // Restore Max Heap property
        heapify(arr, i, 0);
    }
}

// Function to display the array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}
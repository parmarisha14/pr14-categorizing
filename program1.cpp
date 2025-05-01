#include <iostream>
#include <vector>
using namespace std;
// selection sort
void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
// merge sort
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// merge sort for the recive
void merge_sort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// linearSearch
int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// binarySearch
int binarySearch(vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
// Display
void display(vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    int choice;
    int n;
    cout << "Enter the total number elements:";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements:";
        cin >> arr[i];
    }
    do
    {
        cout << "Enter the choice:";
        cin >> choice;
        if (choice == 0)
        {
            cout << "The exit the program. " << endl;
            break;
        }
        cout << "Press 1 For The Selection Sort." << endl
             << "Press 2 For The Merge Sort." << endl
             << "Press 3 For The Linear Search." << endl
             << "Press 4 for The Binary Search." << endl;
             
     
        switch (choice)
        {
        case 1:
            selection_sort(arr);
            cout << "After sorted:" << endl;
            display(arr);
            break;
        case 2:
            merge_sort(arr, 0, arr.size() - 1);
            cout << "Array after Merge Sort:\n";
            display(arr);
            break;

        case 3:
        {
            display(arr);
            int target;
            cout << "Enter the target: ";
            cin >> target;
            int result = linearSearch(arr, target);
            if (result != -1)
            {
                cout << "Element found at index: " << result << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;
        }
        case 4:
        {
            int key, result;
            if (arr.size() != 0)
            {

                merge_sort(arr, 0, arr.size() - 1);
                cout << "Sorted array before Binary Search:";
                display(arr);

                cout << "Enter target: ";
                cin >> key;
                result = binarySearch(arr, key);
            }
            else
            {
                cout << "Array is Empty." << endl;
                return 0;
            }
            if (result != -1)
                cout << "The value " << key << " is at index " << result << endl;
            else
                cout << "The value " << key << " not found" << endl;
        }
        break;
        default:
            cout << "Invalid Number." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
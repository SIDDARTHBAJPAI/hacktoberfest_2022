#include <iostream>
#include <math.h>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter the limit" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched" << endl;
    cin >> key;
    cout << linearSearch(arr, n, key);
    return 0;
}

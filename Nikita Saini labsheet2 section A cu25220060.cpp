//Linear Search in cpp

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            return 0;
        }
    }

    cout << "Element not found";

    return 0;
}



//Binary Search in cpp

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0;
    int high = 4;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            cout << "Element found at position " << mid + 1;
            return 0;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Element not found";

    return 0;
}

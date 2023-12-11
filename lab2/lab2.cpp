#include <iostream>
#include <vector>
using namespace std;

//Завдання перше
int task1(bool nums[])
{
    int max = 0, k = 0;
    for (int i = 0; i < sizeof(nums); i++)
    {
        if (nums[i] == 1)
            k += 1;
        else {
            if (k > max)
                max = k;
            k = 0;
        }
    }
    return max;
}

//Завдання друге допоміжна функція
int number(int n, int k)
{
    if (n == 0)
    {
        return k;
    }
    else return number(n/10, k+1);
}
//Завдання друге
int task2(int n[])
{
    int summ = 0;
    for (int i = 0; i < sizeof(n); i++)
    {
        if (number(n[i], 0) % 2 == 0)
            summ++;
    }
    return summ;
}

//Завдання третє
int* task3(int n[], int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        n[i] *= n[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = n[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr; 
}

//Завдання четверте варіант виконання 1
vector<int> task4(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            arr[size - 1] = 0;
            for (int j = size-1; j > i; j--)
            {
                int m = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = m;
                
            }
            i++;
        }
    }
    return arr;
}
//Завдання четверте варіант виконання 2
vector<int> task41(vector<int> arr)
{
    int originalSize = arr.size();    

    for (int i = 0; i < originalSize; i++)
    {
        if (arr[i] == 0)
        {
            arr.push_back(0);
        }
    }

    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = size - 1; j > i; j--)
            {
                int m = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = m;

            }
            i++;
        }
    }

    return arr;
}
 
//Завдання 5
int* task5(int* nums1, int nums2[], int m, int n) {
    int k = 0;
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[k];
        k++;
    }

    for (int i = 0; i < m+n; i++) {
        for (int j = i + 1; j < m + n; j++) {
            if (nums1[i] > nums1[j]) {
                int temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
    return nums1;
}

//Завдання 6
int* task6(int* nums, int n) {
    int i = 0, j=0;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++)
        {
            if (nums[i] == nums[j])
                nums[j] = 101;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }            
        }
    }

    return nums;
}

//Завдання 7
bool task7(int arr[], int n)
{
    bool an = false;
    int i = 0, j=0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (arr[i] == arr[j] * 2)
            {
                an = true;
            }
        }
    }
    return an;
}

//Завдання 8
bool task8(int arr[], int n)
{
    bool an = true;
    int max = 0, i=0, maxi=0;

    for (i = 0; i < n; i++) {
        if (max < arr[i])
        {
            max = arr[i];
            maxi = i;
        }
    }

    for (i = 0; i < maxi-1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            an = false;
        }
    }

    for (i = maxi; i < n-1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            an = false;
        }
    }
    return an;
}

//Завдання 9
int* task9(int* arr, int n)
{
    int i = 0, j=0, max=0;    
    for (i = 0; i <n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
            }
        }
        arr[i] = max;
        max = 0;
    }
    arr[n - 1] = -1;
    return arr;
}

//Завдання 10
int* task10(int* nums, int n) {
    int i = 0, j = 0, t=0;
    int left = 0, right = n - 1;

    while (left < right) {
        while (left < right && nums[left] % 2 == 0) { 
            left++;
        }
        while (left < right && nums[right] % 2 != 0) {
            right--;
        }

        if (left < right) { 
            swap(nums[left], nums[right]); 
            left++;
            right--;
        }
    }

    return nums;
}

int main()
{
    int i = 0;
    bool nums1[] = { 1, 0, 1, 1, 0, 1 };
    int nums2[] = { 555, 901, 482, 1771 };
    int nums3[] = { -7, -3, 2, 3, 11 };
    vector<int> arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
    int* nums = new int[5];
    int nums4[] = { 1, 2, 3, 0, 0, 0 };
    int m = 3, n = 3;
    int nums5[3] = { 2, 5, 6 };
    int nums7[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int arr3[] = { 10, 2, 5, 3 };
    int arr4[] = { 3, 1, 7, 11 };
    int arr5[] = { 0, 3, 2, 1 };
    int arr6[] = { 0, 2, 3, 3, 5, 2, 1 };
    int arr7[] = {17, 18, 5, 4, 6, 1};
    int nums9[] = { 1,2,3,4,5,6 };
    //До завдання 1
    int max = task1(nums1);

    //До завдання 2
    cout << max << "\n" << task2(nums2) << "\n";

    //До завдання 3
    nums = task3(nums3, 5); 

    //До завдання 4
    vector<int> arr1 = task4(arr);
    vector<int> arr2 = task41(arr);
    for (i = 0; i < 5; i++) {
        std::cout << nums[i] << ", ";
    }
    cout << "\n";
    for (i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    for (i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    //До завдання 5
    int* nums6 = task5(nums4, nums5, m, n);
    for (i = 0; i < n+m; i++)
    {
        cout << nums6[i] << " ";
    }
    cout << "\n";

    //До завдання 6
    int* nums8 = task6(nums7, 10);
    for (i = 0; i < 10; i++)
    {
        if (nums8[i] == 101)
        {
            cout << "_ ";
        }
        else 
            cout << nums8[i] << " ";
    }

    //До завдання 7
    cout << "\n" << task7(arr3, 4) << " " << task7(arr4, 4);

    //До завдання 8
    cout << "\n" << task8(arr5, 4) << " " << task8(arr6, 7);

    //До завдання 9
    cout << "\n";
    int* arr8 = task9(arr7, 6);
    for (i = 0; i < 6; i++)
    {
        cout << arr8[i] << " ";
    }

    //До завдання 10
    cout << "\n";
    int* nums10 = task10(nums9, 6);
    for (i = 0; i < 6; i++)
    {
        cout << nums10[i] << " ";
    }
    delete[] nums;
}

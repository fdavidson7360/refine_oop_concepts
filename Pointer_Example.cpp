#include <iostream>

int main() {
    //==== Example 1

    int a = 4;
    int *p = &a;
    a += 2;     // a = a + 2 = 4 + 2= 6; *p = a = 6;
    *p += 3;    // a = a + 3; *p = *p + 3 = 6 + 3 = 9; 
    a -= 1;     // a = a -1 = 9 - 1 = 8; *p = a = 8;
    std::cout << a;  // Output: 8

    //==== Example 2
    int arr[] = {2, 4, 6, 8};
    int *p = arr;

    std::cout << *p << std::endl;      // Output: 2
    std::cout << *(p+1) << std::endl;  // Output: 4
    std::cout << *(p+2) << std::endl;  // Output: 6

    //==== Example 3 Calculate an average of an array using pointers
    int ages[] = {19, 24, 36, 45, 56, 52, 21, 27, 24, 34, 29, 60, 40, 42, 45, 47, 22, 30, 34, 20, 18, 26, 51, 43, 47, 39, 22, 34, 56, 52, 21, 27, 24, 37, 19, 24, 36, 45, 44, 49, 23, 25, 19, 40, 29, 60, 40, 42, 45, 47, 61, 30, 19, 43, 47, 39, 41, 46, 29, 24, 21, 25, 28};
    
    int total_of_ages=0;
    
    int size = 63;
    
    int *p = ages;
    int average_age;

    
    
    for(int i=0;i<size;i++) {
        //cout << *p << endl;
        total_of_ages += *p;
        p++;
    }
    average_age = total_of_ages/size;

    std::cout << average_age << std::endl;

    //==== Example 4 Dynamically allocate an array of integers using pointers
    int size = 8;

    int *p = new int[size]; // Dynamically allocate an array of integers of size 8

    p[0] = 128;  // Asigns the first element of the array to 128
    p[1] = 888;  // Asigns the second element of the array to 888
    p[2] = 9;    // Asigns the third element of the array to 9

    std::cout << *(p+1);     // Output: 888

    //==== Example 5 Dynamically allocate an array of integers using pointers and delete it
    int n;
    std::cout << "Enter a size for the array"<< std::endl;
    std::cin >> n; //size of the array
    //your code goes here
    
    int *nums = new int [n];
    std::cout << "Enter the array elements:";
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    
    
    int max = nums[0];
    for(int i=0; i<n; i++) {
        if(nums[i]>max)
            max = nums[i];
    }
    std::cout << max;
    
    delete nums;



    return 0;
}
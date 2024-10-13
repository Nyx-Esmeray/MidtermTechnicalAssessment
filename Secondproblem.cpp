#include <iostream> //This is for the input and output
#include <vector> //This is for dynamic arrays
#include <cmath> //This is for mathematical functions like the square root(sqrt) and power (pow)
#include <ctime>     //This is for the clock() and CLOCKS_PER_SEC

using namespace std;


/*Problem 2: Implement BubbleSort and MergeSort for sorting a list of delivery times*/
/*This is the Bubble Sort Algorithm that compares adjacent elements 
and swaps them if they are in the wrong order*/
void bubbleSort(vector<int> &arr) {
    int y = arr.size();
    //Outer loop: This is the outer loop where it iterate over the entire array
    for (int x = 0; x < y - 1; x++) {
        //Inner loop: This is the inner loop where it compares each pair of adjacent elements
        for (int z = 0; z < y - x - 1; z++) {
            //This is where it compares where if the current element is greater than the next then it will swap them
            if (arr[z] > arr[z + 1]) {
                swap(arr[z], arr[z + 1]);
            }
        }
    }
}

//This function merges two sorted halves of the array it will merge them and it will be sorted into one
void merge(vector<int> &arr, int left_part, int middle_part, int right_part) {
    int firstinput = middle_part - left_part + 1; //This is the size of the left subarray
    int secondinput = right_part - middle_part; //This is the size of the right subarray

    //This will be a temporary subarrays to hold the left half and right half
    vector<int> Left_half(firstinput), Right_half(secondinput);

    //This will copy the data to the temporary array of the left_half and Right_half
    for (int x = 0; x < firstinput; x++) Left_half[x] = arr[left_part + x];
    for (int x = 0; x < secondinput; x++) Right_half[x] = arr[middle_part + 1 + x];

    //This will merge the temporary arrays so that it will back to the original array
    int x = 0, z = 0, w = left_part; //These are the initial indexes of the subarrays and the merge arrays
    //This will compare the elements from the left_half and right_half then it will copy the smaller one into the original array
    while (x < firstinput && z < secondinput) {
        if (Left_half[x] <= Right_half[z]) {
            arr[w] = Left_half[x];
            x++;
        } else {
            arr[w] = Right_half[z];
            z++;
        }
        w++;
    }

    //This will copy the remaining elements of the left half
    while (x < firstinput) {
        arr[w] = Left_half[x];
        x++;
        w++;
    }

    //This will copy the remaining elements of the left half
    while (z < secondinput){
        arr[w] = Right_half[z];
        z++;
        w++;
    }
}

/*This is the merge sort, it is a divide-conquer algorithm that divides the array into two halves
then it will recursively sorts them and then it merges the sorted halves*/
void mergeSort(vector<int> &arr, int left_part, int right_part) {
    if (left_part < right_part){
        //This find the middle part
        int middle_part = left_part + (right_part - left_part) / 2;
        //This recursively sort the left and right half
        mergeSort(arr, left_part, middle_part);
        mergeSort(arr, middle_part + 1, right_part);
        //This merge the sorted halves
        merge(arr, left_part, middle_part, right_part);
    }
}

//This will print the elements of the array
void printArray(const vector<int> & arr) {
    for (int value : arr) {
        cout << value << " "; //This will print the elements of the array
    }
    cout << endl; //This will end after printing the array
}

int main() {
    int D; //This variable is the number of delivery times
    cout << "Enter number of delivery times: "; //This will ask the user to input the number of delivery times
    cin >> D;

    vector<int> deliveryTimes(D); //This will vector to store the delivery times 
    cout << "Enter delivery times (minutes): " << endl; //This where the user input the delivery times 
    for (int x = 0; x < D; x++) {
        cin >> deliveryTimes[x];
    }

    //This copy the original array for both the bubblesort and the mergesort
    vector<int> bubbleSorted = deliveryTimes;
    vector<int> mergeSorted = deliveryTimes;

    //Measure bubble sort time
    clock_t startoftheBubblesortime = clock(); //This is the start clock for the bubblesort
    bubbleSort(bubbleSorted);
    clock_t endoftheBubblesortime = clock(); //This is the end clock for the bubblsort

    //This will print the result of the bubblesort
    cout << "Bubble Sort result: ";
    printArray(bubbleSorted);
    //This calculate and print the bubblesort time
    double timeoftheBubblesort = double(endoftheBubblesortime - startoftheBubblesortime) / CLOCKS_PER_SEC;
    cout << "Bubble Sort Time: " << timeoftheBubblesort << " seconds" << endl;

    //Measure merge sort time
    clock_t startoftheMergesortime = clock(); //This is the start clock for the mergesort
    bubbleSort(bubbleSorted);
    mergeSort(mergeSorted, 0, D - 1);
    clock_t endoftheMergesortime = clock(); //This is the end clock for the mergesort

    //This will print the result of the merge sort
    cout << "Merge Sort result: ";
    printArray(mergeSorted);
    //This will calculate and print the mergesort time
    double timeoftheMergesort = double(endoftheMergesortime - startoftheMergesortime) / CLOCKS_PER_SEC;
    cout << "Merge Sort Time: " << timeoftheMergesort << " seconds" << endl;

    //This will print the time complexity of the two algorithms
    cout << "\nTime Complexity Analysis:" << endl;
    cout << "Bubble Sort: O(N^2)" << endl;
    cout << "Merge Sort: O(N log N)" << endl;

    return 0; //It will return to 0 if it the program success in executing or there is no errors
}

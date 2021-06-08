#include <fstream>
#include <iostream>

using namespace std;

// func def
int FileLen(ifstream &file);
void ReadData(ifstream &file, string arr[]);
void ReadData(ifstream &file, int arr[]);
void PrintArr(string arr[], int size, int i);
void PrintArr(int arr[], int size, int i);
void MergeSort(string arr[], int size);
void MergeSort(int arr[], int size);
void PrintMatchingNonDupeStrings(string arr1[], string arr2[], int s1, int s2);
void PrintMatchingNonDupeInt(int arr1[], int arr2[], int s1, int s2);

int main(int argc, char **argv) {
    ifstream fileOne, fileTwo;
    // string *arrOneString = nullptr, *arrTwoString = nullptr;
    // int *arrOneInt = nullptr, *arrTwoInt = nullptr;
    char intOrString = argv[1][0];

    fileOne.open(argv[2]);
    fileTwo.open(argv[3]);
    int fileOneSize = FileLen(fileOne);
    int fileTwoSize = FileLen(fileTwo);
    if (intOrString == 's') {
        string *arrOneString = new string[fileOneSize];
        string *arrTwoString = new string[fileTwoSize];
        ReadData(fileOne, arrOneString);
        ReadData(fileTwo, arrTwoString);
        MergeSort(arrOneString, fileOneSize);
        MergeSort(arrTwoString, fileTwoSize);
        // PrintArr(arrOneString, fileOneSize, 0);
        // PrintArr(arrTwoString, fileTwoSize, 0);
        PrintMatchingNonDupeStrings(arrOneString, arrTwoString, fileOneSize,
                                    fileTwoSize);
        delete[] arrOneString;
        delete[] arrTwoString;
    } else {
        int *arrOneInt = new int[fileOneSize];
        int *arrTwoInt = new int[fileTwoSize];
        ReadData(fileOne, arrOneInt);
        ReadData(fileTwo, arrTwoInt);
        MergeSort(arrOneInt, fileOneSize);
        MergeSort(arrTwoInt, fileTwoSize);
        // PrintArr(arrOneInt, fileOneSize, 0);
        // PrintArr(arrTwoInt, fileTwoSize, 0);
        PrintMatchingNonDupeInt(arrOneInt, arrTwoInt, fileOneSize, fileTwoSize);
        delete[] arrOneInt;
        delete[] arrTwoInt;
    }
    return 0;
}

int FileLen(ifstream &file) {
    int count = 0;
    string text;
    while (file >> text) {
        count++;
    }
    file.clear();
    file.seekg(0);
    return count;
}

void ReadData(ifstream &file, string arr[]) {
    int count = 0;
    while (file >> arr[count]) {
        count++;
    }
    file.close();
}

void PrintArr(string arr[], int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << arr[i] << endl;
    return PrintArr(arr, size, i + 1);
}
void PrintArr(int arr[], int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << arr[i] << endl;
    return PrintArr(arr, size, i + 1);
}

void MergeSort(string arr[], int size) {
    if (size == 1) return;
    int mid = size / 2;
    int sizeOne = mid, sizeTwo = size - mid;
    string arrOne[sizeOne], arrTwo[sizeTwo];
    for (int i = 0; i < sizeOne; i++) {
        arrOne[i] = arr[i];
    }
    for (int i = 0; i < sizeTwo; i++) {
        arrTwo[i] = arr[mid + i];
    }

    MergeSort(arrOne, sizeOne);
    MergeSort(arrTwo, sizeTwo);
    int i = 0, j = 0, l = 0;
    while (i < sizeOne && j < sizeTwo) {
        if (arrOne[i] <= arrTwo[j]) {
            arr[l] = arrOne[i];
            i++;
            l++;
        } else {
            arr[l] = arrTwo[j];
            j++;
            l++;
        }
    }
    while (i < sizeOne) {
        arr[l] = arrOne[i];
        i++;
        l++;
    }
    while (j < sizeTwo) {
        arr[l] = arrTwo[j];
        j++;
        l++;
    }
}

void PrintMatchingNonDupeStrings(string arr1[], string arr2[], int s1, int s2) {
    int i = 0;
    int j = 0;
    while (i < s1 && j < s2) {
        if (arr1[i] > arr2[j]) {
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else  // ==
        {
            string tempText = arr1[i];
            j++;
            i++;
            cout << tempText << endl;
            while (i < s1 && arr1[i] == tempText) i++;
            while (j < s2 && arr2[j] == tempText) j++;
        }
    }
}

// functions for integers
void ReadData(ifstream &file, int arr[]) {
    int count = 0;
    while (file >> arr[count]) {
        count++;
    }
}

void MergeSort(int arr[], int size) {
    if (size == 1) return;
    int mid = size / 2;
    int sizeOne = mid, sizeTwo = size - mid;
    int arrOne[sizeOne], arrTwo[sizeTwo];
    for (int i = 0; i < sizeOne; i++) {
        arrOne[i] = arr[i];
    }
    for (int i = 0; i < sizeTwo; i++) {
        arrTwo[i] = arr[mid + i];
    }

    MergeSort(arrOne, sizeOne);
    MergeSort(arrTwo, sizeTwo);
    int i = 0, j = 0, l = 0;
    while (i < sizeOne && j < sizeTwo) {
        if (arrOne[i] <= arrTwo[j]) {
            arr[l] = arrOne[i];
            i++;
            l++;
        } else {
            arr[l] = arrTwo[j];
            j++;
            l++;
        }
    }
    while (i < sizeOne) {
        arr[l] = arrOne[i];
        i++;
        l++;
    }
    while (j < sizeTwo) {
        arr[l] = arrTwo[j];
        j++;
        l++;
    }
}

void PrintMatchingNonDupeInt(int arr1[], int arr2[], int s1, int s2) {
    int i = 0;
    int j = 0;
    while (i < s1 && j < s2) {
        if (arr1[i] > arr2[j]) {
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else  // ==
        {
            int tempNum = arr1[i];
            j++;
            i++;
            cout << tempNum << endl;
            while (i < s1 && arr1[i] == tempNum) i++;
            while (j < s2 && arr2[j] == tempNum) j++;
        }
    }
}
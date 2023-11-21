
/*
1) Initialize an integer array of 8 elements from the user and print the third smallest and third 
larger numbers in that array.
Sample output:
Elements of array: 4 1 3 9 6 2 7 5
Third smallest number: 3
Third larger number: 6

*/

#include <iostream>

int main(){
    int arr[8];
    std::cout << "Enter 8 elements: ";
    for(int i = 0; i < 8; i++){
        std::cin >> arr[i];
    }
    std::cout << "Elements of array: ";
    for(int i = 0; i < 8; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Sorted array: " << std::endl;

    int temp;
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }

    for(int i = 0; i < 8; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Third smallest number: " << arr[2] << std::endl;
    std::cout << "Third largest number: " << arr[5] << std::endl;
    return 0;
}

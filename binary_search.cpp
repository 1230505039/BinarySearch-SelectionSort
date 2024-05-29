#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int binarySearch(int array[], int size, int * index, int target){

    do{
        
        if(array[*index] < target){
            *index = (*index + size + 1) / 2;
        }

        else if(array[*index] > target){
            *index = *index / 2;
        }
    }while(array[*index] != target);

    return *index;
}

void swap(int * newKey, int * oldKey){

    int temp = *newKey;
    *newKey = *oldKey;
    *oldKey = temp;
}

void selectionSort(int array[], int size){

    for(int i = 0 ; i < size ; i++){

        int key = array[i];
        int indexKey = i;

        for(int j = i + 1 ; j < size ; j++){

            if(array[j] < key){
                key = array[j];
                indexKey = j;
            }
        }
        swap(&array[indexKey], &array[i]);
    }
}

void print(int array[], int size){
    for(int i = 0 ; i < size ; i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    system("cls");

    int size;

    cout<<"Enter size of the array: ";

    cin>>size;

    int array[size];

    for(int i = 0 ; i < size ; i++){
        cout<<"Enter "<<i + 1<<". elemen: ";
        cin>>array[i];
    }

    cout<<endl;

    int target;

    cout<<"Enter target number: ";
    cin>>target;

    int midIndex = (size / 2) - 1;

    selectionSort(array, size);

    print(array, size);

    int newIndex = binarySearch(array, size, &midIndex, target);

    cout<<endl<<"'"<<target<<"'"<<" is at "<<newIndex;
    return 0;
}
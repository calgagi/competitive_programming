#include<iostream>

using namespace std;

void merge(int array[], int left, int middle, int right){
  int counter1 = 0;
  int counter2 = 0;
  int size1 = middle - left + 1;
  int size2 = right - middle;
  int A1[size1];
  int A2[size2];

  for(int i = 0; i < size1; i++){
    A1[i] = array[left + i];
  }
  for(int i = 0; i < size2; i++){
    A2[i] = array[middle + 1 + i];
  }

  while(counter1 < size1 && counter2 < size2){
    if(A1[counter1] < A2[counter2]){
      array[left+counter1+counter2] = A1[counter1];
      counter1++;
    }else{
      array[left+counter1+counter2] = A2[counter2];
      counter2++;
    }
  }

  while(counter1 < size1){
    array[left+counter1+counter2] = A1[counter1];
    counter1++;
  }
  while(counter2 < size2){
    array[left+counter1+counter2] = A2[counter2];
    counter2++;
  }
}

void merge_sort(int array[], int left, int right){
  if(left < right){
    int middle = ((right - left) / 2) + left;

    merge_sort(array, left, middle);
    merge_sort(array, middle+1, right);

    merge(array, left, middle, right);
  }
}

int main(){
  int array[] = {1, 5, 2, 5, 3, 6, 7, 3, 6, 7};
  int array_size = sizeof(array) / sizeof(array[0]);

  cout << "Not sorted....";
  for(int i = 0; i < array_size; i++){
    cout << array[i] << " ";
  }
  cout << endl;

  merge_sort(array, 0, array_size - 1);

  cout << "Sorted........";
  for(int i = 0; i < array_size; i++){
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}

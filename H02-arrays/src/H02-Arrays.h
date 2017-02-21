// Example program
#include <iostream>
//#include <string>
 
int n1; // declare global variables that indicate size of arrays to be added.
int n2;
int main()
{std::cout << "Enter size of first array: ";
   std::cin >> n1;
  int *array1 = new int[n1];
  std::cout << "Enter members of array 1. " <<std::endl;
  for (auto i=0; i<n1; i++)
      std::cin >> array1[i];
  
  std::cout << "Enter size of second array: ";
   std::cin >> n2;
  int *array2 = new int[n2];
  std::cout << "Enter members of array 2. " <<std::endl;
  for (auto i=0; i<n2; i++)
      std::cin >> array2[i];
  return 0;
   
}
int Add_Array (int * a, int * b){ //use pointers to access the dynamic arrays. a[0] would indicate the first element of array a points to.
    if (n1==n2)
        int array[n1];
        for (auto i=0; i<n1; i++)
            array[i] = a[i] + b[i];
    return 0;
}
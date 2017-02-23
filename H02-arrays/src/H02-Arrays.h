
#include <iostream>
//#include <string>
 
int n1; // declare global variables that indicate size of arrays to be added.
int n2;
int Add_Array(int*a, int*b){ //use pointers to access the arrays. a[0] would indicate the first element of array a points to.
    if (n1==n2){
	int array3[n1]; //define output array for function that stores the result.
    for (auto i=0; i<n1; i++)
        array3[i] = a[i] + b[i]; //initialize output array.
std::cout<<"The output array is "<<std::endl;        
    for (auto i=0; i<n1; i++)//create loop to stream the array output.
    std::cout<< array3[i]<<std::endl;}
	else
		std::cout<< "Sorry! Array sizes have to be equal for them to be added."<<std::endl;
	return 0;
}

int main()
{std::cout << "Enter size of first array: ";
   std::cin >> n1;//input array size.
  int array1[n1];//declare input array 1.
  std::cout << "Enter members of array 1. " <<std::endl;
  for (auto i=0; i<n1; i++)//initialize input array 1.
      std::cin >> array1[i];
  
  std::cout << "Enter size of second array: ";
   std::cin >> n2;
  int array2[n2];
  std::cout << "Enter members of array 2. " <<std::endl;
  for (auto i=0; i<n2; i++)
      std::cin >> array2[i];
Add_Array(array1,array2);
  return 0;
   
}


#include <stdio.h>  
  
  
int LinearSearch(int arr[],  int search,int index,int n);  
int main()  
{  
    int n, search, result, m = 0, arr[100];  
 
    printf("Enter the total elements in the array\n");  
    scanf("%d", &n);  
  
    printf("Enter the array elements\n");  
    for (int i = 0; i < n; i++)  
    {  
        scanf("%d", &arr[i]);  
    }  
  
    printf("Enter the element to search \n");  
    scanf("%d", &search);  
  
  
    result =  LinearSearch(arr,  search,0,n);  
    if (result != 0)  
    {  
        printf("Element found at pos %d\n ", result);  
    }  
    else  
    {  
        printf("Element not found");  
    }  
return 0;  
}  
int LinearSearch(int arr[],  int search,int index,int n)  
{  
    int arrpos=0;  
    if(index>=n)  
    {  
        return 0;  
    }  
        if (arr[index] == search)  
        {  
            arrpos = index + 1;  
            return arrpos;  
              
        }  
        else  
        {  
        return LinearSearch(arr, search,index+1,n);  
        }  
  
      
    return arrpos;  
} 
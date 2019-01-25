#include <stdio.h>
#include <stdlib.h>
#include "search.h"
int main()
{
    int arr[5]={1,3,5,7,9};
   int index;
   index=binary_search(arr,5,5);
   printf("%d  ",index);
    return 0;
}

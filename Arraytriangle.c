#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void PrintTriangle(int* data, size_t SizeArr);
int* IndexTriangle(int* data, int i, int j);

int main()
{
    printf("Enter indexes:");
    int i = 0, j = 0;
    scanf("%d %d", &i, &j);

    int data[] = {10, 
                  20, 21, 
                  30, 31, 32, 
                  40, 41, 42, 43};


    printf("data[%d][%d] = %d ", i, j, *IndexTriangle((int*)data, i, j));
    
    // size_t SizeArr = sizeof(data) / sizeof(data[0]);
    
    // PrintTriangle(data, SizeArr);

    return 0; 
}




void PrintTriangle(int* data, size_t SizeArr)
{
    size_t count = 1; 
    
    for(size_t x = 0; x < SizeArr; x = x + count - 1 )
    {
        for (size_t y = 0; y <  count ; y ++ )
        {
            printf("data[%llu] = %d ",  x + y, data[x + y]);
        }
        count ++;
        printf("\n");

    } 
}

int* IndexTriangle(int* data, int i, int j)
{
    assert(j <= i);
    assert(i < 4);

    int index = 0;
    index = (i*(i+1))/2;
    
    return ((int*)data + index + j);
}


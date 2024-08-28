#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void PrintArray(int* data, size_t SizeX, size_t SizeY);
void AddMatrix(int* data1, int* data2, int* dataResult, size_t SizeX, size_t SizeY);

int main()
{
    
    int data1[5][4] = {{11, 12, 13, 14},
                       {21, 22, 23, 24},
                       {31, 32, 33, 34},
                       {41, 42, 43, 44},
                       {51, 52, 53, 54}};
    int data2[5][4] = {{101, 102, 103, 104},
                       {201, 202, 203, 204},
                       {301, 302, 303, 304},
                       {401, 402, 403, 404},
                       {501, 502, 503, 504}};
    int dataResult[5][4] = { 0 };
    

    size_t SizeX = sizeof(data1) / sizeof(data1[0]), 
    SizeY = sizeof(data1[0]) / sizeof(data1[0][0]);
    
    AddMatrix((int*)data1, (int*)data2, (int*)dataResult, SizeX, SizeY);

    PrintArray((int*)dataResult, SizeX, SizeY);

    return 0;
}


void PrintArray(int* data, size_t SizeX, size_t SizeY)
{
    assert(isfinite(SizeX));
    assert(isfinite(SizeY));

    for(size_t x = 0; x < SizeX; x++)
    {
        for(size_t y = 0; y < SizeY; y++)
        {
            printf("data[%llu][%llu] = %d ", x, y, *((int*)data + x * SizeY + y));
        }
        printf("\n");
    }
}


void AddMatrix(int* data1, int* data2, int* dataResult, size_t SizeX, size_t SizeY)
{

    for(size_t x = 0; x < SizeX * SizeY; x++)
    {
        *((int*)dataResult + x ) = *((int*)data1 + x ) + *((int*)data2 + x * SizeY );
    }
}

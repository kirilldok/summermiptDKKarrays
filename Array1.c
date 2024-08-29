#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void PrintArray(int* data, size_t SizeX, size_t SizeY);
// void AddMatrix(int* data1, int* data2, int* dataResult, size_t SizeX, size_t SizeY);
bool MultiplyMatrix(int* data1, int* data2, int* dataResult,  size_t SizeX1, size_t SizeY1, size_t SizeX2, size_t SizeY2);

int main()
{
    
    int data1[3][3] = {{1, 2, 1},
                       {4, 2, 2},
                       {0, 1, 7}};
    int data2[2][3] = {
                       {2, 1, 2},
                       {4, 3, 4}};
    // int dataResultadd[5][4] = { 0 };
    

    size_t SizeX1 = sizeof(data1) / sizeof(data1[0]), 
    SizeY1 = sizeof(data1[0]) / sizeof(data1[0][0]);
    size_t SizeX2 = sizeof(data2) / sizeof(data2[0]), 
    SizeY2 = sizeof(data2[0]) / sizeof(data2[0][0]);
    
    // AddMatrix((int*)data1, (int*)data2, (int*)dataResultadd,  SizeX1, SizeY1);
    int* dataResult = (int*)(calloc(SizeX1 * SizeY2, sizeof(int)));
    
    bool t = MultiplyMatrix((int*)data1, (int*)data2, (int*)dataResult, SizeX1, SizeY1, SizeX2, SizeY2);

    if (t)
    {
        PrintArray((int*)dataResult, SizeX1, SizeY2);
    }
    // PrintArray((int*)dataResult, SizeX1, SizeY2);
    free(dataResult); dataResult = NULL;
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


// void AddMatrix(int* data1, int* data2, int* dataResult, size_t SizeX, size_t SizeY)
// {
//     for(size_t x = 0; x < SizeX * SizeY; x++)
//     {
//         *((int*)dataResult + x ) = *((int*)data1 + x ) + *((int*)data2 + x * SizeY );
//     }
// }


bool MultiplyMatrix(int* data1, int* data2, int* dataResult,  size_t SizeX1, size_t SizeY1, size_t SizeX2, size_t SizeY2)
{
    if (SizeY1 != SizeX2)
    {
        printf("Impossible to multiply Matrix %llu * %llu and %llu * %llu \n", SizeX1, SizeY1, SizeX2, SizeY2);
        return false;
    }


    for(size_t i = 0; i < SizeX1; i ++)
    {
        for(size_t j = 0; j < SizeY2; j++)
        {
            int sum = 0;
            for(size_t k = 0; k < SizeY1; k++)
            {
                sum = sum + (*((int*)data1 + i * SizeY1 + k)) * (*((int*)data2 + k * SizeY2 + j));
            }
            *((int*)dataResult + i * SizeY2 + j) = sum;
        }
    }

    return true;
}
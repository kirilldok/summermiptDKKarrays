#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct ArrLength{
    int* DataNotConst;
    int MaxLength;
};

void InputMatrix(int** ArrAddress, ArrLength Arr, int nLines);
void OutputMatrix( int** ArrAdress, int nLines);

int main()
{
    printf("Any Array Output\n");
    printf("Enter number of lines:");
    int nLines = 0;
    scanf("%d", &nLines);

    int**  ArrAddress = (int**)calloc(nLines + 1, sizeof(int*));
    int MaxLength = 1;
    int*  Data = (int*)calloc(MaxLength, sizeof(int));
    
    ArrLength Arr = {Data, MaxLength} ;

    InputMatrix(ArrAddress, Arr, nLines);
    printf("%d", nLines);

    OutputMatrix(ArrAddress, nLines);

    free(ArrAddress); ArrAddress = NULL;
    free(Data); Data = NULL;
    free(ArrAddress);
    free(Data);

    return 0;
}


void InputMatrix(int** ArrAddress, ArrLength Arr, int nLines)
{
    printf("Enter digits of the line \n" 
           "If You want to end the line, enter '-t' or any letter\n");
    
    ArrAddress[0] = (int*)0;
    int count = 0;

    for(int x = 0; x < nLines; x++)
    {
        int k = 0;
        
        do
        {
            if (count >= Arr.MaxLength)
            {
                Arr.DataNotConst =  (int*)realloc(Arr.DataNotConst, Arr.MaxLength * 2 * sizeof(int*));
                Arr.MaxLength =  Arr.MaxLength * 2;
                
                if (!Arr.DataNotConst)
                {
                    return;
                }
            }
            k = scanf("%d", (Arr.DataNotConst + count));
            count++;
        } while(k == 1);
        while(getchar() != '\n') {}
        count--;
        ArrAddress[x + 1] = (int*)(uintptr_t)(count);
    }

    for(int x = 0; x <= nLines; x++)
    {
        ArrAddress[x] = (Arr.DataNotConst + (uintptr_t)(ArrAddress[x]));
    }
}


void OutputMatrix(int** ArrAdress, int nLines)
{

    for(int x = 0; x < nLines; x++)
    {
        for(int y = 0; y < ((ArrAdress[x + 1]) - (ArrAdress[x])); y++)
        {
            printf("DataN[%d][%d] = %d ", x, y, ArrAdress[x][y]);
        }
        printf("\n");
    }
}


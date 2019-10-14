#include<stdio.h>


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{

    int holding[1000];
    int fibo[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int testCase, total_holding;
    int safeCount,breakCount;
    int safeList[1000],breakList[1000];

//    freopen ("input.txt","r",stdin);
//    freopen ("output.txt","w",stdout);


    scanf("%d",&testCase);
    //printf("%d\n",testCase);

    for(int m=0;m<testCase;m++)
    {
        safeCount=0;
        breakCount=0;

        scanf("%d",&total_holding);
        //printf("%d\n",total_holding);

        for(int j=0;j<total_holding;j++)
        {
            scanf("%d",&holding[j]);
            //printf("%d , ",holding[j]);
        }

        quickSort(holding,0,total_holding-1);

        /*for(int j=0;j<total_holding;j++)
        {
            printf("%d - ",holding[j]);
        }*/
        int flag=0,holdingCounter=0;;
        for(int i=0;i<15;i++)
        {

            for(int j=0;j<fibo[i];j++)
            {
                safeList[safeCount]=holding[holdingCounter];
                safeCount++;
                holdingCounter++;
                if(holdingCounter==total_holding)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
            else{
                breakList[breakCount]=holding[holdingCounter];
                breakCount++;
                holdingCounter++;
                if(holdingCounter==total_holding)
                {
                    flag=1;
                    break;
                }
            }

        }
        printf("Result %d:\n",m+1);
        printf("Safe List: ");
        for(int j=0;j<safeCount;j++)
        {
            printf("(%d)",safeList[j]);
        }
        printf("\nBreak List: ");
        for(int j=0;j<breakCount;j++)
        {
            printf("(%d)",breakList[j]);
        }

        printf("\n");
    }


//    fclose(stdin);
//    fclose(stdout);

    return 0;
}

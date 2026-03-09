
#include <stdio.h>
#include <float.h>
#include <stdbool.h>



void swap(float* xp, float* yp){
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//gfg bubble sort implementation
void bubbleSort(float arr[], float idxArr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&idxArr[j], &idxArr[j + 1]);  //mirrors the swaps on sales array in order to print out the right month with the sort sales data
                                                   //in hightolow
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}


const char* getMonth(int n){   //switch statement used to pass in iterator values in order to return the namesof the months
    switch(n){
        case 0:
            return "January";
            break;
        case 1:
            return "Feburary";
            break;
        case 2:
            return "March";
            break;
        case 3:
            return "April";
            break;
        case 4:
            return "May";
            break;
        case 5:
            return "June";
            break;
        case 6:
            return "July";
            break;
        case 7:
            return "August";
            break;
        case 8:
            return "Septmeber";
            break;
        case 9:
            return "October";
            break;
        case 10:
            return "November";
            break;
        case 11:
            return "December";
            break;
            
    }
}

void sixMonthMovingAvg(float arr[], int len){           //generates the six month moving average
    printf("\nSix-Month moving average report:\n\n");

    for (int i = 0; i <= len - 6; i++){
        float sum = 0;
        for (int j = i; j < i + 6; j++){
            sum += arr[j];
        }
        printf("%-10s%-12s %.2f\n", getMonth(i), getMonth(i + 5), sum);
        
    }
}

void higtToLow(float arr[], int len){               //uses bubble sort to get sorted arr
    float idxArr[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    bubbleSort(arr, idxArr, len);
    
    printf("\nSales report (highest to lowest):\n\n");
    
    for (int i = len -1 ; i >= 0; i--){
        printf("%-12s $%.2f (%s)\n", arr[i], getMonth(idxArr[i]));
    }
}

void printYearly(float arr[], int len)              //prints monthly sales in calendar order
{
    printf("\nMonthly Sales Report for 2026:\n\n");
    printf("%-12s %s\n", "Month", "Sales");
    printf("%-12s $%.2f\n", "January", arr[0]);
    printf("%-12s $%.2f\n", "February", arr[1]);
    printf("%-12s $%.2f\n", "March", arr[2]);
    printf("%-12s $%.2f\n", "April", arr[3]);
    printf("%-12s $%.2f\n", "May", arr[4]);
    printf("%-12s $%.2f\n", "June", arr[5]);
    printf("%-12s $%.2f\n", "July", arr[6]);
    printf("%-12s $%.2f\n", "August", arr[7]);
    printf("%-12s $%.2f\n", "September", arr[8]);
    printf("%-12s $%.2f\n", "October", arr[9]);
    printf("%-12s $%.2f\n", "November", arr[10]);
    printf("%-12s $%.2f\n", "December", arr[11]);
}

void salesSum(float arr[], int len)     //calculates and prints min/max/avg sales
{
    float max = 0;
    int max_idx;
    float min = FLT_MAX;
    int min_idx;
    float sum = 0;
    for (int i = 0; i < len; i++){
        if (arr[i] > max){
            max = arr[i];
            max_idx = i;
        }
        if (arr[i] < min){
         min = arr[i];
         min_idx = i;
        }
         
        sum += arr[i];
    }
     
    float avg = sum/len;
    
     
    printf("\nSales summary report:\n\n");
    printf("Minimum sales: $%f (%s)\n", min, getMonth(min_idx));
    printf("Maximum sales: $%f (%s)\n", max, getMonth(max_idx));
    printf("Average sales: %f\n\n", avg);
    
}

int main()
{
    float salesArr[12];
    int len = 12;

    
    FILE *fp = fopen("sales.txt", "r");

    for (int i = 0; i < len; i++){
        if (fscanf(fp, "%f", &salesArr[i]) != 1){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    
    
    // for (int i = 0; i < len; i++){
    //     printf("%d\n", salesArr[i]);
    // }
    
    printYearly(salesArr, len);
    salesSum(salesArr, len);
    higtToLow(salesArr, len);
    sixMonthMovingAvg(salesArr, len);
    return 0;
    
}



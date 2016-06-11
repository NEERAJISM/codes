#include<stdio.h>
int array[100000], array1[100000];
void radix(int n)
{
	int k, i, j, temp, t, min=0;
	for (k = 0; k < 6; k++)
    {    
        for (i = 0; i < n; i++)
        {
            min = array[i] % 10;        /* To find minimum lsd */
            t = i;
            for (j = i + 1; j < n; j++)    
            {
                if (min > (array[j] % 10))
                {
                    min = array[j] % 10; 
                    t = j;
                }
            }
            temp = array1[t];
            array1[t] = array1[i];
            array1[i] = temp;
            temp = array[t];
            array[t] = array[i];
            array[i] = temp;
 
        }
        for (j = 0; j < n; j++)        /*to find MSB */
            array[j] = array[j] / 10;
    }
}


int main()
{
	    
    int i,n;
    printf("Enter size of array :");
    scanf("%d", &n);
    printf("Enter elements into array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        array1[i] = array[i];
    }
    radix(n);
    printf("Sorted Array (lSdradix sort) : ");
    for (i = 0; i < n; i++)
    printf("%d ", array1[i]);
    
        return 0;
}

#include <stdio.h>

#define MAXELT          100
#define INFINITY        32760


#define SMALLSIZE       10
#define STACKSIZE       100

int list[MAXELT+1];

struct {
        int a,b
} stack[STACKSIZE];

int top=-1;

void main()
{
        int i=-1,j,n;
        char t[10];
        void quicksort(int);

        do {
                if (i!=-1)
                        list[i++]=n;
                else
                        i++;
                printf("\nEnter the numbers <End by #>");
                fflush(stdin);
                scanf("%[^\n]",t);
                if (sscanf(t,"%d",&n)<1)
                        break;
        } while (1);

        quicksort(i-1);

        printf("The list obtained is ");

        for (j=0;j<i;j++)
                printf("\n %d",list[j]);
}

void interchange(int *x,int *y)                  //swap
{
        int temp;

        temp=*x;
        *x=*y;
        *y=temp;
}

void split(int first,int last,int *splitpoint)
{
        int x,i,j,s,g;


        if (list[first]<list[(first+last)/2]) {  //find median
                s=first;
                g=(first+last)/2;
        }
        else {
                g=first;
                s=(first+last)/2;
        }
        if (list[last]<=list[s])
                x=s;
        else if (list[last]<=list[g])
                x=last;
        else
                x=g;
        interchange(&list[x],&list[first]);

        x=list[first];
        i=first;
        j=last+1;
        while (i<j) {
                do {
                        j--;
                } while (list[j]>x);
                do {
                        i++;
                } while (list[i]<x);
                interchange(&list[i],&list[j]);
        }
        interchange(&list[i],&list[j]);
        interchange(&list[first],&list[j]);

        *splitpoint=j;
}

void push(int a,int b)                           //push
{
        top++;
        stack[top].a=a;
        stack[top].b=b;
}

void pop(int *a,int *b)                          //pop
{
        *a=stack[top].a;
        *b=stack[top].b;
        top--;
}

void insertion_sort(int first,int last)
{
        int i,j,c;

        for (i=first;i<=last;i++) {
                j=list[i];
                c=i;
                while ((list[c-1]>j)&&(c>first)) {
                        list[c]=list[c-1];
                        c--;
                }
                list[c]=j;
        }
}

void quicksort(int n)
{
        int first,last,splitpoint;

        push(0,n);
        while (top!=-1) {
                pop(&first,&last);
                for (;;) {
                        if (last-first>SMALLSIZE) {
                                                 //find the larger sub-list
                                split(first,last,&splitpoint);
                                                 //push the smaller list
                                if (last-splitpoint<splitpoint-first) {
                                        push(first,splitpoint-1);
                                        first=splitpoint+1;
                                }
                                else {
                                        push(splitpoint+1,last);
                                        last=splitpoint-1;
                                }
                        }
                        else {                   //sort the smaller sub-lists
                                                 //through insertion sort
                                insertion_sort(first,last);
                                break;
                        }
                }
        }
}

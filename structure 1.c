#include<stdio.h>
struct student
{
    char name[10];
    int roll;
    float serial;

};
void display(struct student *,struct student *);
int main()
{
    struct student nj={"Neeraj",754,0.109};
    struct student dk={"dikshant",699,0.102};
    struct student *ptr1,*ptr2;
    ptr1=&nj;
    ptr2=&dk;
    display(ptr1,ptr2);
    return 0;

}
void display(struct student *ptr1,struct student *ptr2)
{
    printf("%s %d %f\n\n",ptr1->name,ptr1->roll,ptr1->serial);
    printf("%s %d %f",ptr2->name,ptr2->roll,ptr2->serial);

}

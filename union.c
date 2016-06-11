 #include<stdio.h>
 union un
  { int i,j;
    char c[2];
  };

  int main()
    { union un u;
      u.i=32;
      u.j=256;

       printf("%d%d%d%d",u.i,u.c[0],u.c[1],u.j);
       return 0;

    }

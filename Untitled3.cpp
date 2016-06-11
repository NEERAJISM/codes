#include <iostream>
#include <cstring>
using namespace std;

char * myFunc(char src[])
{
  for (int i = 0; i < strlen(src); i++) {
    if ((src[i] < 'a')  ||  (src[i] > 'z')) {
      cout << "Bad input!!!" << endl;
      return NULL;
    }
  }

    char * result = new char( strlen(src) + 1);
  // additional one char allocated for the end of string character '\0'
  if (result == NULL) {
    cout << "Memory allocation failure." << endl;
    return NULL;
  }

  strcpy(result, src);
  int i, j;
  int delta = 'A' - 'a';
  for(i = 0, j = 2*strlen(src); i < strlen(src); i++) {
    result[j++] = src[i] + delta;
  }
  result[j] = '\0';  // insert the final '\0'

  return result;
}


int main()
{
    char src[3] ={'a','b','c'};
    char * src2[];
    src2[] = myFunc(src);

    for(int i=0 ; i<3 ;i++)
    {
        cout<<*src2;
        src2++;
    }

}

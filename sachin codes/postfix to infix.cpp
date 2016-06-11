
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
   string data;
   struct node *next;
};

class stack
{
   struct node *top;
   
   public:
 
   stack()
   {
      top = 0;
   }

   void push(string data);
   string pop();
};

void stack::push(string data)
{
   struct node *pn;
   pn = new node();
   pn->data = data;
   pn->next = (top != 0) ? top : 0;
   top = pn;
}

string stack::pop()
{
   struct node *pn;
   if (top == 0) return '\0';
   pn = top;
   string result = pn->data; 
   top = top->next;
   delete pn;
   return result;
}



int main()
{
   stack s;
   string postfix, infix, operand1, operand2, expr, yn;
   do
   {
      cout << "Enter postfix expression" << endl;
      cin >> postfix;
      for(int i = 0; i < postfix.length(); i++)
      {
         string c = postfix.substr(i, 1);
         if (c == "+" || c == "-" || c == "*" || c == "/")
         {
            operand2 = s.pop();
            operand1 = s.pop();
            expr = "(" + operand1 + c + operand2 + ")";
            s.push(expr);
         } 
         else 
         {
            s.push(c);
         }
      }
      infix = s.pop();
      cout << "The infix expression is" << endl << infix << endl;
      cout << "Convert another y/n : ";
      cin >> yn;
      cout<< endl;
    }
    while(yn == "y" || yn == "Y");
 
    return 0;
}


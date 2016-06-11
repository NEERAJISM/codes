#include <bits/stdc++.h>
using namespace std;

int n,clk , scoreboard[10][4] ,functioal_us[5][10];
char register_rs[9];

/*
in functioal_us[0] 
    0 -> integer == l;
    1 -> mul1  == m;
    2 -> mul2 == m;
    3 -> add or substraction == a  && s;
    4 -> division == d; 

/*
    score board
    0 -> issue
    1 -> read
    2 -> execution
    3 -> writeback
*/

/*
    functional unitstatus
    0 -> name 
    1 -> busy
    2 -> operation
    3 -> f destination
    4 -> f src1
    5 -> fsrc 2
    6 -> q1
    7-> q2
    8 -> r1 
    9 ->r2 
*/

/*
    register unit status 
    0 - f0
    2 - f2
    4 - f4
    6 - f6
    8 - f8
*/


struct i1{

    char operation;
    string dest;
    string src1;
    string src2;
};

struct i1 instructions[10];


void score()
{
    clk = 1;
    int flag = 0 ,i,j,itr1;

    while(flag < 4*n)
    {
        cout<< clk <<" /**/ "<< flag <<endl;
        j=0;
        i=0;

        // 1st we check the issue
        if(scoreboard[n-1][0] == 0)
        {
            for(i; i < n;i++)
                if(scoreboard[i][j] == 0)
                    break;

            if(instructions[i].operation == 'l')
            {
                itr1 = 0;
                
                if(functioal_us[itr1][1] == 0)
                {
                                        functioal_us[itr1][9]=i;
                    functioal_us[itr1][1] = 1;
                    scoreboard[i][j] = clk; 
                    functioal_us[itr1][2] = 0;

                    if(instructions[i].dest[0] == 'f')
                    {
                            functioal_us[itr1][3]= (int) instructions[i].dest[1] -48;
                            register_rs[functioal_us[itr1][3]] = instructions[i].operation;
                    }
                    else
                        functioal_us[itr1][3]= -1;

                    if(instructions[i].src1[0] == 'f')
                    {   
                        functioal_us[itr1][4]= (int) instructions[i].src1[1] -48;
                    }
                    else
                        functioal_us[itr1][4]= -1;

                    if(instructions[i].src2[0] == 'f')
                    {   
                        functioal_us[itr1][5]= (int) instructions[i].src2[1] -48;
                    }
                    else
                        functioal_us[itr1][5]= -1;

                    flag++;
                }
            }
            else if(instructions[i].operation == 'm')
            {
                itr1 = 1;
                if(functioal_us[itr1][1] == 0)
                {
                    functioal_us[itr1][1] = 1;
                    scoreboard[i][j] = clk;
                                        functioal_us[itr1][9]=i;

                    if(instructions[i].dest[0] == 'f')
                    {
                        functioal_us[itr1][3]= (int) instructions[i].dest[1] -48;
                        register_rs[functioal_us[itr1][3]] = instructions[i].operation;
                    }
                    else
                        functioal_us[itr1][3]= -1;

                    if(instructions[i].src1[0] == 'f')
                    {   
                        functioal_us[itr1][4]= (int) instructions[i].src1[1] -48;
                        functioal_us[itr1][8]= 1;
                    }
                    else
                        functioal_us[itr1][4]= -1;

                    if(instructions[i].src2[0] == 'f')
                    {   
                        functioal_us[itr1][5]= (int) instructions[i].src2[1] -48;
                    }
                    else
                        functioal_us[itr1][5]= -1;

                    flag++;
                }
            }
            else if(instructions[i].operation == 'a' || instructions[i].operation == 's')
            {
                itr1 = 3;
                if(functioal_us[itr1][1] == 0)
                {
                    functioal_us[itr1][1] = 1;
                    scoreboard[i][j] = clk;
                                        functioal_us[itr1][9]=i;

                    if(instructions[i].dest[0] == 'f')
                    {
                        functioal_us[itr1][3]= (int) instructions[i].dest[1] -48;
                        register_rs[functioal_us[itr1][3]] = instructions[i].operation;
                    }
                    else
                        functioal_us[itr1][3]= -1;

                    if(instructions[i].src1[0] == 'f')
                    {   
                        functioal_us[itr1][4]= (int) instructions[i].src1[1] -48;
                        functioal_us[itr1][8]= 1;
                    }
                    else
                        functioal_us[itr1][4]= -1;

                    if(instructions[i].src2[0] == 'f')
                    {   
                        functioal_us[itr1][5]= (int) instructions[i].src2[1] -48;
                    }   
                    else
                        functioal_us[itr1][5]= -1;
                
                    flag++;
                }
            }
            else if(instructions[i].operation == 'd')
            {
                itr1 = 4;
                if(functioal_us[itr1][1] == 0)
                {
                    functioal_us[itr1][1] = 1;
                    scoreboard[i][j] = clk;
                                        functioal_us[itr1][9]=i;

                    if(instructions[i].dest[0] == 'f')
                    {
                        functioal_us[itr1][3]= (int) instructions[i].dest[1] -48;
                        register_rs[functioal_us[itr1][3]] = instructions[i].operation;
                    }
                    else
                        functioal_us[itr1][3]= -1;

                    if(instructions[i].src1[0] == 'f')
                    {   
                        functioal_us[itr1][4]= (int) instructions[i].src1[1] -48;
                        functioal_us[itr1][8]= 1;
                    }
                    else
                        functioal_us[itr1][4]= -1;

                    if(instructions[i].src2[0] == 'f')
                    {   
                        functioal_us[itr1][5]= (int) instructions[i].src2[1] -48;
                    }
                    else
                        functioal_us[itr1][5]= -1;
                
                    flag++;
                }
            }
        }

        /*for(int y1=0 ; y1<n ;y1++)
        {
            for(int y2 = 0 ;y2< 4;y2++)
                    cout<<scoreboard[y1][y2]<<" ";

                cout<<endl;
        }*/



        // operation read column 1
        
        for(int y1 =0;y1 < n; y1++)
        {
                       int raw=1;
            if(scoreboard[y1][1] == 0 && scoreboard[y1][0] !=0)
            {
                if(instructions[y1].operation == 'l')
                    itr1 =0;
                else if(instructions[y1].operation == 'm')
                    itr1 =1;
                else if(instructions[y1].operation == 'a'||instructions[y1].operation == 's')
                    itr1 =3;
                else if(instructions[y1].operation == 'd')
                    itr1 =4;
                                int src1= functioal_us[itr1][4];
                                int src2= functioal_us[itr1][5];
                                
                                for(int i=0;i<=4;i++)
                                {
                                      if(i!=itr1)
                                      {
                                         if(src1!=-1||src2!=-1)
                                         if((src1==functioal_us[i][3]||src2==functioal_us[i][3])&&y1>functioal_us[i][9])
                                             raw=0;
                                      }
                                }       
                if(raw && scoreboard[y1][0]!=clk)
                {    
                                 functioal_us[itr1][4]=-1;
                                 functioal_us[itr1][5]=-1;
                    scoreboard[y1][1] = clk;
                    flag++;
                                        
                }   
            }
        }
        //execution column

        for(int y1 =0;y1 < n; y1++)
        {
            if((clk -scoreboard[y1][1] == 1 && scoreboard[y1][1] !=0 && instructions[y1].operation == 'l')||(clk -scoreboard[y1][1] == 2 && scoreboard[y1][1]!=0 && instructions[y1].operation == 's') ||(clk -scoreboard[y1][1] == 2 && scoreboard[y1][1]!=0 && instructions[y1].operation == 'a') ||(clk -scoreboard[y1][1] == 10 && scoreboard[y1][1]!=0 && instructions[y1].operation == 'm') ||(clk -scoreboard[y1][1] == 20 && scoreboard[y1][1]!=0 && instructions[y1].operation == 'd'))
            {
                scoreboard[y1][2] = clk;
                flag++;
            }
        }

        //writeback cloumn

        for(int y1=0 ;y1< n ;y1++)
        {
                        int war=1; int waw=1;
                        //to check the WAR hazard
                               if(instructions[y1].operation == 'l')
                    itr1 =0;
                else if(instructions[y1].operation == 'm')
                    itr1 =1;
                else if(instructions[y1].operation == 'a'||instructions[y1].operation == 's')
                    itr1 =3;
                else if(instructions[y1].operation == 'd')
                    itr1 =4;
                         int dest_oper= functioal_us[itr1][3];  // storing destination operand;
                          for(int i=0;i<=4;i++)
                          {
                            if(i!=itr1)
                             {
                              if((functioal_us[i][4]==dest_oper||functioal_us[i][5]==dest_oper)&&y1>functioal_us[i][9])
                                   war=0;
                              if(functioal_us[i][3]==dest_oper&&y1>functioal_us[i][9])
                                   waw=0;
                              }
                          }

            if(scoreboard[y1][2]!= 0 && scoreboard[y1][2] < clk && scoreboard[y1][3] == 0&&waw&&war )
            {
                flag++;
                scoreboard[y1][3] = clk;

                    functioal_us[itr1][1] = 0;
                                        functioal_us[itr1][3] = -1;
                                        functioal_us[itr1][9]=-1;
                    register_rs[(int) instructions[y1].dest[1]-48] = '\0';

            }
        }   

        clk++;  

        // print the scoreboard

        cout<<"scoreboard\n";
        cout<<" i "<<"rd "<<"exe "<<"wb\n" ; 
        for(int y1=0 ; y1<n ;y1++)
        {
            for(int y2 = 0 ;y2< 4;y2++)
                    cout<<" "<<scoreboard[y1][y2]<<" ";
                cout<<endl;
        }
        cout<<endl;

        cout<<"functional unit status\n";
        cout<<"n "<<"B "<<"op "<<"dt "<<"s1 "<<"s2 "<<"q1 "<<"q2 "<<"r1 "<<"r2\n";
        for(int y1=0 ; y1<5 ;y1++)
        {
            for(int y2 = 0 ;y2< 10;y2++)
                    cout<<functioal_us[y1][y2]<<" ";
                
            cout<<endl;
        }
        cout<<endl;

        cout<<"register unit status\n";
        cout<<"f0 "<<"f2 "<<"f4 "<<"f6 "<<"f8 \n";
        for(int y1=0 ; y1<10 ;y1+=2)
        {
            cout<<" "<<register_rs[y1]<<" ";    
        }
        cout<<endl;
    }
}

int  main()
{
    functioal_us[0][0] = 0;
    functioal_us[1][0] = 1;
    functioal_us[2][0] = 2;
    functioal_us[3][0] = 3;
    functioal_us[4][0] = 4;
    string line;
        for(int m=0;m<5;m++)
{
    functioal_us[m][3]=-1;
    functioal_us[m][4]=-1;
    functioal_us[m][5]=-1;
}

    for(int i=0;i<=9;i++)
        {
        register_rs[i]='\0';
    }
    
    cout<<"enter the number of instructions to be executed: ";
    cin>>n;
    
    int t=n,i=0;
    
    while(i<t)
    {
        cout<< "enter the "<<i<<" instruction\n";
        cin >> instructions[i].operation >> instructions[i].dest >> instructions[i].src1 >> instructions[i].src2 ;
        
        //cout << instructions[i].operation << instructions[i].dest << instructions[i].src1 << instructions[i].src2 ;
        i++;    }

    score();
    return 0;
}       
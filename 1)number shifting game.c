#include<stdio.h>
#include<stdlib.h>

int main()
{

    int array[4][4],totalMoves=10,row=3,column=3,v=0,temp;
    char playerName[20],key,playAgain='y';
    //TAKING THE PLAYER NAME
     printf("Player name...");
     fgets(playerName,20,stdin);
     system("cls");

    //PRINTING THE RULES
    rulesForGame();
    system("cls");

    while(playAgain=='y')
    {
            //ARRANGING ARRAY VALUE WITH RANDOM PLACES
            RamdomArray(array);
            printf("\n");
            array[3][3]=16;
            while(key!='e'&&key!='E'&&totalMoves)
            {
                system("cls");
                printf("\nplayer name : %smove remaining : %d\n\n\n",playerName,totalMoves);
                   printf("---------------------\n");
                   //PRINTING UPDATED ARRAY
                   for(int i=0;i<4;i++)
                   {
                         for(int g=0;g<4;g++)
                         {
                            if(array[i][g]!=16)
                              printf("|%4d",array[i][g]);
                            else
                                printf("|    ");

                         }
                      printf("|\n");
                   }
                   printf("---------------------\n");
                  //CHECKING ARRAY IS IN OERDER OR NOT
                  if(checkArrayIsInOrdered(array)==0)
                  {
                      key=getch();
                      printf("you press %d",key);
                      //CHECKING WHICH ARROW KEY IS PRESSED
                      if(key==77)
                      {
                          //LEFT KEY PRESS
                          if(column!=3)
                          {
                              temp=array[row][column];
                              array[row][column]=array[row][column+1];
                              array[row][column+1]=temp;
                              column++;
                          }
                          totalMoves--;
                      }
                      else if(key==75)
                      {
                          //RIGHT KEY PRESS
                          if(column!=0)
                          {
                              temp=array[row][column];
                              array[row][column]=array[row][column-1];
                              array[row][column-1]=temp;
                              column--;
                          }
                          totalMoves--;
                      }
                      else if(key==72)
                      {
                          //UP KEY PRESS
                          if(row!=0)
                          {
                              temp=array[row][column];
                              array[row][column]=array[row-1][column];
                              array[row-1][column]=temp;
                              row--;
                          }
                          totalMoves--;
                      }
                      else if(key==80)
                      {
                          //DOWN KEY PRESS
                          if(row!=3)
                          {
                              temp=array[row][column];
                              array[row][column]=array[row+1][column];
                              array[row+1][column]=temp;
                              row++;
                          }
                          totalMoves--;
                      }

                  }
                  else{
                     system("cls");
                     printf("\t\t  you won the game\n");
                     printf("Want to again?\nEnter 'y' to play again\n");
                     printf("Enter any key to exit");
                     row=column=3;
                     totalMoves=10;
                     playAgain=getch();
                     break;
                  }
            }
            if(key=='e'||key=='E')
            {
                system("cls");
                printf("You exit the game\nThank you for playing...");
                break;
            }
            if(totalMoves==0)
            {
                system("cls");
                printf("\t\t  you lose the game\n");
                printf("Want to play again?\nEnter 'y' to play again\n");
                printf("Enter any key to exit");
                row=column=3;
                totalMoves=10;
                playAgain=getch();
            }
    }

    getch();
    return 1;
}

void RamdomArray(int *p)
{
    int *r,*d,j,i,f,c;
    r=malloc(sizeof(int));
    d=malloc(sizeof(int));
    i=r;
    j=d;
    for(int i=1;i<=15;i++)
        p[i-1]=i;
   for(int a=1;a<=3;a++){
       i=r;
       j=d;
       while(i&&j)
       {
          f=i%10;
          c=j%10;
          i/=10;
          j/=10;
          interChange(p,f,c);
       }
       if(a!=3)
       rightShift(p);
   }
  free(r);
  free(d);
}
//INTERCHANGING ARRAY VALUES
void interChange(int *ptr,int i,int j)
{
   int t;
   t=ptr[i];
   ptr[i]=ptr[j];
   ptr[j]=t;
}
//SHOFTING ARRAY VALUE FORM RIGHT TO LEFT
void rightShift(int *ptr)
{

   int i=5,g,f;
   while(i)
   {
      g=*(ptr+14);
      for(f=13;f>=0;f--)
      {
          ptr[f+1]=ptr[f];
      }
      ptr[f+1]=g;
      i--;
   }
}


//THE RULES FOR PLAYING THIS GAME
int checkArrayIsInOrdered(int *p)
{
    for(int i=0;i<14;i++)
    {
        if(p[i]!=p[i+1]-1)
            return 0;
    }
    return 1;
}
void rulesForGame()
{

    //HEADING OF RULES
   printf("\t\t\tMATRIX PUZZLE\n\n\t\t      RULE OF THIS GAME\n");
   printf("1.You can move only 1 step at a time by arrow key\n");

   //THE KEYS TO MOVE NUMBERS
   printf("\t\tMove Up   : by Up Arrow key\n");
   printf("\t\tMove Down : by Down Arrow key\n");
   printf("\t\tMove Left : by Left Arrow key\n");
   printf("\t\tMove Right: by Right Arrow key\n\n");

   //WHERE TO MOVE NUMBER
   printf("2.You can move number at empty position only\n");

   //SOME MORE RULES
   printf("3.For each valid move : your total number of move will decreased by 1\n");

   //WINNING SITUATION OF THE GAME
   printf("4.Winning situation : Number in a 4*4 matrix should be in order from 1 to 15\n\t\t   Winning situation:\n");

   //THE MATRIX AFTER WINNING GAME
   printf("---------------------\n");
   for(int i=1;i<=15;i++)
   {
      printf("|%4d",i);
      if(i%4==0){
        printf("|\n");
      }
   }
   printf("|    |\n---------------------");

   //TO EXIT THE GAME
   printf("\n\n5.You can exit the game at any time by pressing 'E' or 'e'\n So try to win in minimum  no of move");

   //TOTAL NUMBER OF MOVES
   printf("\n\n6.You have only 10 moves to win th game");

   //ENTERING THE KEY TO START THE GAME
   printf("\n\nEnter any key to start...  ");
   getch();
}

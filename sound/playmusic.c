#include <stdio.h>

void playmusic(int num)
{

   printf("Please choose a music number(1~3)\n");

   scanf("%d", &num);

   if(num == 1)
   {
     printf("Play music 1\n");
     system("play_num 1.wav");
   }
   else if(num == 2)
   {
     printf("Play music 2\n");
     system("play_num 2.wav");
   }
   else if(num == 3)
   {
     printf("Play music 3\n");
     system("play_num 3.wav");
   }
}

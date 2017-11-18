#include <stdio.h>

void playmusic(int num)
{

   if(num == 1)
   {
     printf("Play music 1\n");
     system("aplay 1.wav");
   }
   else if(num == 2)
   {
     printf("Play music 2\n");
     system("aplay 2.wav");
   }
   else if(num == 3)
   {
     printf("Play music 3\n");
     system("aplay 3.wav");
   }
}

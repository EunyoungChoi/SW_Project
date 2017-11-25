#include<stdio.h>
#include"playmusic.h"


int flag;
void *play(void *arg)
{
   if(flag == 1)
   {
     playmusic(1);
   }
   else if(flag == 2)
   {
     playmusic(2);
   }
   else if(flag == 3)
   {
     playmusic(3);
   }

   return NULL;
}

void music1()
{
   int result;
   flag = 1;
}
void music2()
{
   int result;
   flag = 2;
}
void music3()
{
   int result;
   flag = 3;
}

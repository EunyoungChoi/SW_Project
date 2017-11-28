#include<stdio.h>
#include"playmusic.h"
#include "bonus.h"
#include<gtk/gtk.h>

GtkWidget *bu1,*bu2,*bu3,*bu4,*bu5,*bu6,*bu7,*bu8,*output;




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

void clear()
{
    gtk_button_set_label(GTK_BUTTON(bu1),"");
    gtk_button_set_label(GTK_BUTTON(bu2),"");
    gtk_button_set_label(GTK_BUTTON(bu3),"");
    gtk_button_set_label(GTK_BUTTON(bu4),"");
    gtk_button_set_label(GTK_BUTTON(bu5),"");
    gtk_button_set_label(GTK_BUTTON(bu6),"");
    gtk_button_set_label(GTK_BUTTON(bu7),"");
    gtk_button_set_label(GTK_BUTTON(bu8),"");
}

void music1()
{
   int result;
   pthread_t mythread;
   flag = 1;
   result = pthread_create(&mythread,NULL,play,NULL);
}
void music2()
{
   int result;
   pthread_t mythread;
   result = pthread_create(&mythread,NULL,play,NULL);

   flag = 2;

}
void music3()
{
   int result;
   pthread_t mytread
   result = pthread_create(&mythread,NULL,play,NULL);

   flag = 3;
}

void buttonClick(GtkWidget *widget)
{
}




int main(int argc,char *argv[])
{
    GtkWidget* window;

    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *box3;
    GtkWidget *box4;

    gtk_init(&argc,&arg);

    gtk_init(NULL,NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
}

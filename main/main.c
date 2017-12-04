#include<stdio.h>
#include"playmusic.h"
#include "bonus.h"
#include<gtk/gtk.h>
#include<stdlib.h>
#include<pthread.h>

GtkWidget *bu1,*bu2,*bu3,*bu4,*bu5,*bu6,*bu7,*bu8,*output;
GtkWidget *bscore,*level1,*level2,*level3,*label;

char buf[100];
char buf2[100];
char namebuf[100];
char gamebuf[100];
int number = 0;
int score = 0;
int game_over = 0;
int button_push=0; // check button

int bonus = 0; //bonus
int flag = 0;  //music select flag

int end1=0;
int end2=0;
int end3=0;  //end timer


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

int button_func()
{
   if(flag==1)
   {
     end1++;
   }
   else if(flag==2)
   {
     end2++;
   }
   else if(flag==3)
   {
     end3++;
   }

   bonus++;
   clear();
   srand((unsigned)time(0));
   num = rand()%8+1;

   if(game_over == 1)
   {
        game_over = 0;
        bonus = 0;
        sprintf(buf,"GAME OVER");
        gtk_label_set_text(STK_LABEL(label1),buf);
        return 0;
   }
   if(end1==54 || end2==34 || end3==99)
   {
        game_over = 0;
        bonus = 0;
        end1 = 0;
        end2 = 0;
        end3 = 0;
        sprintf(buf,"GAME OVER");
        gtk_label_set_text(STK_LABEL(label1),buf);
        return 0;
   }
   if(num == 1)
   {
        gtk_button_set_label(GTK_BUTTON(bu1),"*");
   }
   else if(num == 2)
   {
        gtk_button_set_label(GTK_BUTTON(bu2),"*");
   }
   else if(num == 3
   {
        gtk_button_set_label(GTK_BUTTON(bu3),"*");
   }
   if(num == 4)
   {
        gtk_button_set_label(GTK_BUTTON(bu4),"*");
   }
   if(num == 5)
   {
        gtk_button_set_label(GTK_BUTTON(bu5),"*");
   }
   if(num == 6)
   {
        gtk_button_set_label(GTK_BUTTON(bu6),"*");
   }
   if(num == 7)
   {
        gtk_button_set_label(GTK_BUTTON(bu7),"*");
   }
   if(num == 8)
   {
        gtk_button_set_label(GTK_BUTTON(bu8),"*");
   }

   if(game_over != 10)
   {
         return 1;
   }
}

void music1()
{
   int pc_return;
   pthread_t mythread;
   flag = 1;
   pc_return = pthread_create(&mythread,NULL,play,NULL);

   if(pc_return != 0)
   {
     perror("pthread_creat");
     exit(1);
   }
   g_timeout_add(2000,button_func,0);
   sprintf(namebuf, "music 1");//write music 1 name
   sprintf(gamebuf, "Game Start");//announced game start
}
void music2()
{
   int pc_return;
   pthread_t mythread;
   pc_return = pthread_create(&mythread,NULL,play,NULL);

   flag = 2;

   if(pc_return != 0)
   {
     perror("pthread_creat");
     exit(1);
   }
   g_timeout_add(2000,button_func,0);
   sprintf(namebuf, "music 2");//write music 2 name
   sprintf(gamebuf, "Game Start");//announced game start
}
void music3()
{
   int pc_return;
   pthread_t mytread
   pc_return = pthread_create(&mythread,NULL,play,NULL);

   flag = 3;

   if(pc_return != 0)
   {
     perror("pthread_creat");
     exit(1);
   }
   g_timeout_add(2000,button_func,0);
   sprintf(namebuf, "music 3");//write music 3 name
   sprintf(gamebuf, "Game Start");//announced game start
}

void score_bonus()
{
   if(number == button_push)
   {
     if(bonus<10 || (bonus%10)!=0)
     {
     }
   }
}

void buttonClick(GtkWidget *widget)
{
     switch(widget)
     {
          case bu1:
                button_push = 1;
                break;
          case bu2:
                button_push = 2;
                break;
          case bu3:
                button_push = 3;
                break;
          case bu4:
                button_push = 4;
                break;
          case bu5:
                button_push = 5;
                break;
          case bu6:
                button_push = 6;
                break;
          case bu7:
                button_push = 7;
                break;
          case bu8:
                button_push = 8;
                break;
     }
     clear();


}

void setAnswer()
{
    int plus = 0;
    if(num == button_push)
    {
          if(bonus<10 || (bonus%10!=0))
          {
                number=0;
                score++;
                sprintf(buf,"Score : %d",%score);
                gtk_label_set_text(GTK_LABEL(bscore),buf);
          }
          else if((bonus>=10) && (bonus%10)==0)
          {
                plus = bonus();
                num = 0;
                score = plus+score;
                sprintf(buf,"*Bonus + %d*",plus);
                gtk_label_set_text(GTK_LABEL(bscore),buf);
          }
    }
    else if(num!=button_push)
    {
          num =0;
          stop = 1;
    }
}





int main(int argc,char *argv[])
{
    GtkWidget* window;

    GtkWidget *box_v1;
    GtkWidget *box_h2;
    GtkWidget *box_h3;
    GtkWidget *box_h4;

    gtk_init(&argc,&arg);

    gtk_init(NULL,NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window),"destory",G_CALLBACK(gtk_main_quit),NULL);

    box_v1 = gtk_vbox_new(TRUE,0);
    box_h1 = gtk_hbox_new(TRUE,0);
    box_h2 = gtk_hbox_new(TRUE,0);
    box_h3 = gtk_hbox_new(TRUE,0);


    label1 = gtk_label_new("PIANO GAME");
    gtk_widget_set_size_request(label1,350,10);

    bu1 = gtk_button_new_with_label(" ");
    gtk_widget_set_usize(GTK_WIDGET(bu1),30,100);
    bu2 = gtk_button_new_with_label(" ");
    bu3 = gtk_button_new_with_label(" ");
    bu4 = gtk_button_new_with_label(" ");
    bu5 = gtk_button_new_with_label(" ");
    bu6 = gtk_button_new_with_label(" ");
    bu7 = gtk_button_new_with_label(" ");
    bu8 = gtk_button_new_with_label(" ");

    level1 = gtk_button_new_with_label("Level 1");
    level2 = gtk_button_new_with_label("Level 2");
    level3 = gtk_button_new_with_label("Level 3");


    bscore = gtk_label_new("Score");
    output = gtk_label_new("Music");



}

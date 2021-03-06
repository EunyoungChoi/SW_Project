#include<stdio.h>
#include"playmusic.h"
#include "bonus.h"
#include<gtk/gtk.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

GtkWidget *bu1,*bu2,*bu3,*bu4,*bu5,*bu6,*bu7,*bu8,*output;
GtkWidget *bscore,*level1,*level2,*level3,*label;

char namebuf[100];
char gamebuf[100];
int number = 0;
int score = 0;
int game_over = 0;
int button_push=0; // check button

int bonus_num = 0; //bonus
int flag = 0;  //music select flag

int end1=0;
int end2=0;
int end3=0;  //end timer

gint on_timer(gpointer data);

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

   bonus_num++;
   clear();
   srand((unsigned)time(0));
   number = rand()%8+1;

   if(game_over == 1)
   {
        game_over = 0;
        bonus_num = 0;
        sprintf(namebuf,"GAME OVER");
        gtk_label_set_text(GTK_LABEL(label),namebuf);
        return 0;
   }
   if(end1==54 || end2==34 || end3==99)
   {
        game_over = 0;
        bonus_num = 0;
        end1 = 0;
        end2 = 0;
        end3 = 0;
        sprintf(namebuf,"GAME CLEAR");
        gtk_label_set_text(GTK_LABEL(label),namebuf);
        return 0;
   }
   if(number == 1)
   {
        gtk_button_set_label(GTK_BUTTON(bu1),"*");
   }
   else if(number == 2)
   {
        gtk_button_set_label(GTK_BUTTON(bu2),"*");
   }
   else if(number == 3)
   {
        gtk_button_set_label(GTK_BUTTON(bu3),"*");
   }
   else if(number == 4)
   {
        gtk_button_set_label(GTK_BUTTON(bu4),"*");
   }
   else if(number == 5)
   {
        gtk_button_set_label(GTK_BUTTON(bu5),"*");
   }
   else if(number == 6)
   {
        gtk_button_set_label(GTK_BUTTON(bu6),"*");
   }
   else if(number == 7)
   {
        gtk_button_set_label(GTK_BUTTON(bu7),"*");
   }
   else if(number == 8)
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
   sprintf(namebuf, "Smash it");//write music 1 name
   gtk_label_set_text(GTK_LABEL(output), namebuf);
   sprintf(gamebuf, "Game Start");//announced game start
   gtk_label_set_text(GTK_LABEL(label), gamebuf);

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
   sprintf(namebuf, "They don't care");//write music 2 name
   gtk_label_set_text(GTK_LABEL(output), namebuf);

   sprintf(gamebuf, "Game Start");//announced game start
   gtk_label_set_text(GTK_LABEL(label), gamebuf);

}

void music3()	
{
   int pc_return;
   pthread_t mythread;
   pc_return = pthread_create(&mythread,NULL,play,NULL);

   flag = 3;

   if(pc_return != 0)
   {
     perror("pthread_creat");
     exit(1);
   }
   g_timeout_add(2000,button_func,0);
   sprintf(namebuf, "summer");//write music 3 name
   gtk_label_set_text(GTK_LABEL(output), namebuf);


   sprintf(gamebuf, "Game Start");//announced game start
   gtk_label_set_text(GTK_LABEL(label), gamebuf);

}

void score_bonus()
{
   int plus = 0;
   if(number == button_push)
   {
     if(bonus_num<10 || bonus_num%10!=0)
     {
	number = 0;
	score++;
	sprintf(namebuf, "Score : %d",score);
	gtk_label_set_text(GTK_LABEL(bscore),namebuf);
     }
     else if(bonus_num>=10 && bonus_num%10 == 0)
     {
	plus = bonus();
	number = 0;
	score = plus + score;
	sprintf(namebuf, "BONUS + %d",plus);
	gtk_label_set_text(GTK_LABEL(bscore),namebuf);
     }
   }

   else if(number != button_push)
   {
     number = 0;
     game_over = 1;
   }
}

void buttonClick(GtkWidget *widget)
{
    if(widget == bu1){
                button_push = 1;}
    else if(widget == bu2){
                button_push = 2;}
    else if(widget == bu3){
                button_push = 3;}
    else if(widget == bu4){
                button_push = 4;}
    else if(widget == bu5){
                button_push = 5;}
    else if(widget == bu6){
                button_push = 6;}
    else if(widget == bu7){
                button_push = 7;}
    else if(widget == bu8){
                button_push = 8;}
     clear();
     score_bonus();
     

}


int main(int argc,char *argv[])
{
    GtkWidget* window;

    GtkWidget *box_v1;
    GtkWidget *box_h1;
    GtkWidget *box_h2;
    GtkWidget *box_h3;

    gtk_init(&argc,&argv);

    gtk_init(NULL,NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window),"destory",G_CALLBACK(gtk_main_quit),NULL);

    box_v1 = gtk_vbox_new(TRUE,0);
    box_h1 = gtk_hbox_new(TRUE,0);
    box_h2 = gtk_hbox_new(TRUE,0);
    box_h3 = gtk_hbox_new(TRUE,0);


    label = gtk_label_new("PIANO GAME");
    gtk_widget_set_size_request(label,400,10);

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

    g_signal_connect(G_OBJECT(bu1),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu2),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu3),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu4),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu5),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu6),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu7),"clicked",G_CALLBACK(buttonClick),NULL);
    g_signal_connect(G_OBJECT(bu8),"clicked",G_CALLBACK(buttonClick),NULL);


    g_signal_connect(G_OBJECT(level1),"clicked",G_CALLBACK(music1),NULL);
    g_signal_connect(G_OBJECT(level2),"clicked",G_CALLBACK(music2),NULL);
    g_signal_connect(G_OBJECT(level3),"clicked",G_CALLBACK(music3),NULL);

    gtk_container_add(GTK_CONTAINER(box_v1),label);

    gtk_container_add(GTK_CONTAINER(box_h1),level1);
    gtk_container_add(GTK_CONTAINER(box_h1),level2);
    gtk_container_add(GTK_CONTAINER(box_h1),level3);
    gtk_container_add(GTK_CONTAINER(box_v1),box_h1);

    gtk_container_add(GTK_CONTAINER(box_h3),bu1);
    gtk_container_add(GTK_CONTAINER(box_h3),bu2);
    gtk_container_add(GTK_CONTAINER(box_h3),bu3);
    gtk_container_add(GTK_CONTAINER(box_h3),bu4);
    gtk_container_add(GTK_CONTAINER(box_h3),bu5);
    gtk_container_add(GTK_CONTAINER(box_h3),bu6);
    gtk_container_add(GTK_CONTAINER(box_h3),bu7);
    gtk_container_add(GTK_CONTAINER(box_h3),bu8);
    gtk_container_add(GTK_CONTAINER(box_v1),box_h3);

    gtk_container_add(GTK_CONTAINER(box_h2),bscore);
    gtk_container_add(GTK_CONTAINER(box_h2),output);
    gtk_container_add(GTK_CONTAINER(box_v1),box_h2);


    gtk_container_add(GTK_CONTAINER(window),box_v1);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;


}


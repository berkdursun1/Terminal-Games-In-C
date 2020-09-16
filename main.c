#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
// constant definitions
#define MAX_TRIAL 10
#define the_top_max 1025
#define the_top_min 0

// function prototypes
void menu();
void draw_hourglass (int height);
void show_scores(int  score_human, int  score_program);
void draw_mountain_road (int length, int max_radius);
int make_a_guess(int trial,int min,int max);
void print_distance(int distance);
// main function
int main(void) {
  srand(time(NULL));
  menu();
  return 0;
}

// menu function
void menu(){
  // initialization
  int cmp_gss=0;
  int height;
  int score_human=0;
  int score_program=0;
  int min=1;
  int max=1024;
  int trial=0;
  int choise;
  int length;
  int max_radius;
  int distance=0;
  int your_gss;
  int i=0;
  // random number generation depends on time
  srand(time(NULL));
  // menu
  printf("* MENU *\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice:");
  scanf("%d",&choise);
  // if choice is four, exit, elsewhere keep asking
  while(choise!=4){
    switch(choise){
      case 1:
        cmp_gss=1+rand()%1024;
        printf("(%d) & (trial=%d)\n",cmp_gss,MAX_TRIAL);
        do{
          printf("(Trial: %d) ",trial); 
          your_gss=make_a_guess(your_gss,min,max);
          if(your_gss>cmp_gss && your_gss<the_top_max){
          max=your_gss;
          }
          else if(your_gss>the_top_max){
            printf("Error please try again");
            your_gss=make_a_guess(your_gss,min,max);
          }
          else{
          min=your_gss;
          }
          if(cmp_gss>your_gss && your_gss>the_top_min){
          distance=cmp_gss-your_gss;
          }
          
          else if(your_gss<the_top_min){
            printf("Error please try again");
            your_gss=make_a_guess(your_gss,min,max);
          }
          else{
            distance=your_gss-cmp_gss;
          }
          print_distance(distance);
          if(distance==0){
             printf("Distance : 0 Then you win the game");
             score_human++;
          }
          trial++;
  }while(trial<MAX_TRIAL && your_gss!=cmp_gss); 
  // user could not guess, program won
    if(your_gss!=cmp_gss){
      score_program++;
    }
    // print scores by calling function
    show_scores(score_human, score_program);
      trial=0;
      min=1;
      max=1024;
      break ;
      // draw hourglass
      case 2:
        draw_hourglass(height);
        break ;
      // draw mountain road
      case 3:
        draw_mountain_road ( length,  max_radius);
        break ;
      case 4:
      // exit ;
        break ; 
      default :
        printf("This is an invalid choice.Try again!");
        break;
    }
    printf("* MENU *\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice:");
    scanf("%d",&choise);
  }
}
// this function helps user to make guess better
int make_a_guess (int trial, int min, int max){
  printf("Make a guess between %d and %d:",min,max);
  scanf("%d",&trial);
  if(trial>max || trial<min){
    printf("Error");
    printf("Make a new guess between %d and %d:",min,max);
    scanf("%d",&trial);
  }
  return trial;
}
// print score function
void show_scores(int  score_human, int  score_program){  
  printf("\nScore human : %d Score program : %d\n",score_human,score_program);
}
void draw_hourglass (int height){
  int constant;
  int bosluk=0;
  printf("Height : ");
  scanf("%d",&height);
  
  // if heights is not an odd number, ask again
  while(height%2==0){
    printf("Again Height : ");
    scanf("%d",&height);
  
  }
  constant=height;
  while(height!=1){
    for(int i=0;i<bosluk;i++){
      printf(" ");
    }
    for(int i=0;i<height;i++){
      printf("*");
    }
    printf("\n");
    bosluk++;
    height=height-2;
  }
  while(height<=constant){
    for(int i=0;i<bosluk;i++){
      printf(" ");
    }
    for(int i=0;i<height;i++){
      printf("*");
    }
    printf("\n");
    bosluk--;
    height=height+2;
  }
  printf("\n");
}
void draw_mountain_road (int length, int max_radius){
  int radius ;
  int i=0;
  int k=0;
  int j;
  int bosluk;
  int tutma=0; // it keeps which stripe will program print
  // gets length and max radius from user
  printf("Length : ");
  scanf("%d",&length);
  printf("Max radius : ");
  scanf("%d",&max_radius);
  while(i<length){
  radius=rand()%(max_radius+1);
  if(i==0){
    bosluk=max_radius+1; // determining first space
  }
  // prints mountain road
    while(k<radius){
      for(j=0;j<bosluk;j++)
        printf(" ");
      if(tutma==0){
        printf("/ \n");
        bosluk--;
      }
      else{
        printf("\\ \n");
        bosluk++;
      }
      k++;
    }
    k=0;
    while(k<bosluk){
      printf(" ");
      k++;
    }
    k=0;
    printf("|");
    if(bosluk==0)
      bosluk=1;
    if(tutma==0){
      tutma=1;
      bosluk++;
    }
    else if (tutma==1)
    {
      tutma=0;
      bosluk--;
    }
    printf("\n"); 
    while(radius>0){
      for(j=0;j<bosluk;j++)
        printf(" ");
      if(tutma==0){
        printf("/ \n");
        bosluk--;
      }
      else{
        printf("\\ \n");
        bosluk++;
      }radius--;
    }
  i++;
}
}
void print_distance(int distance){
  int i=0;
  for(i=0;i<=9;i++){
    if(distance>=pow(2,i) && distance<pow(2,i+1)){
      printf("Distance = %d",i+1);
      i=10;
    }
  }
  

}

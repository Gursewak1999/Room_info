#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void notice()
{     printf("This program is made by Gursewak Singh of B.tech CSE 1st Sem, Class B1G2\n");
      printf("\n\n\t\t\t*************NOTICE*************\n");
      printf("\n\nThis program is based on test data and can be changed further as possible by simply editing *.csv files via Microsoft Excel.");
      printf("\n\nThis program is made user friendly and thus all the database files are made using excel so that they can be easily changed.");
      printf("\n\nFor Test Purpose, we have considered 4 floors with each 5 rooms.");
      printf("\nfor eg room no.101,102,....105,201,....205,....,401,...405.");

      delay(6000);
      printf("\n\n\nAll set ??? \n\t\t\t Lets move on further \n\n\n\t\tPress any key to continue");
}
char _day[4];
int period() {

    time_t current_time;
    char _dump[4];
    int hr,min,sec;
    char* c_time_string;
    current_time = time(NULL);

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    sscanf(c_time_string,"%s %s %s %d:%d:%d ",&_day,&_dump,&_dump,&hr,&min,&sec);
      if(hr<9)
      {
      clrscr();
      printf("\n\nToo Early................\n\n\t\tPlease come at Working hours.");
      delay(5000);
      exit(0);
      }
      if(hr==9 && (min>=0 && min<=55) )
      return 1;
      if((hr==9 && min>55 && min<60)|| (hr==10 && (min>=0 && min<=49)))
      return 2;
      if((hr==10 && min>=50 && min<60)||(hr==11 && min>0 && min<=44))
      return 3;
      if((hr==11 && min>=45 && min<60)||(hr==12 && min>0 && min<=39))
      return 4;
      if((hr==12 && min>=40 && min<60)||(hr==13 && min>0 && min<=34))
      return 5;
      if((hr==13 && min>=35 && min<=59)||(hr==14 && min>0 && min<=29))
      return 6;
      if((hr==14 && min>=30 && min<=59)||(hr==15 && min>0 && min<=24))
      return 7;
      if((hr==15 && min>=25 && min<=59)||(hr==16 && min>0 && min<=14))
      return 8;
      if((hr==16 && min>=15 && min<=59)||(hr==17 && min>0 && min<=5))
      return 9;
      if(hr>17)
      {  clrscr();
	 printf("Hey You just Missed the Day\n\n\nIts Too Late \n\n\n\n\n\t\t     Please Come Tomorrow to find the Rooms");
	 delay(5000);
	 exit(0);
      }
      else
      return 0;
      return 0;
}
int per = 0;

lecture()
{
	  // error code swth01
       printf("\n\nIts ");
       switch(period())
       {
	 case 1: printf("1st ");
		 per = 1;
		 break;
	 case 2: printf("2nd ");
		 per = 2;
		 break;
	 case 3: printf("3rd ");
		 per = 3;
		 break;
	 case 4: printf("4nd ");
		 per = 4;
		 break;
	 case 5: printf("Recess");
		 per = 5;
		 exit(0);
		 break;
	 case 6: printf("6th");
		 per = 6;
		 break;
	 case 7: printf("7th");
		 per = 7;
		 break;
	 case 8: printf("8th");
		 per = 8;
		 break;
	 case 9: printf("9th");
		 per = 9;
		 break;
	 case 0: printf("Not yet any Lecture going on please come in college hours.");
		 per = 0;
		 delay(5000);
		 exit(0);
		 break;
	 default : printf("\n*********************\terror code - swth01\n*********************\n");

       }
	 printf("Lecture going on.");
	 printf("\nAnd the day is %s",_day);
	 delay(1500);
    return 0;
}

 char ch,_x[22][10][10];   //here _x[room number][periods]

check_db()
{     FILE *file;

      int i=0,j=0;
       if(strcmp(_day,"Mon")==0)
	 file = fopen("mon.csv","r");
     else  if(strcmp(_day,"Tue")==0)
	 file = fopen("tue.csv","r");
     else  if(strcmp(_day,"Wed")==0)
	 file = fopen("wed.csv","r");
     else  if(strcmp(_day,"Thu")==0)
	 file = fopen("thus.csv","r");
     else  if(strcmp(_day,"Fri")==0)
	 file = fopen("fri.csv","r");
     else printf("Error Selecting Days. Please send this code(swthfl001) to developer @--guru.dhindsa9999@gmail.com");

      //add data to strings
      for(i=0;i<=20;i++)
      for(j=0;j<=9;j++)
	{  fscanf(file,"%s",_x[i][j]);
	 }

       fclose(file);
       empty(per);
      return 0;
}
int empty(int period)
{     int i,j;


	 if(period == 5)
	 {
	 clrscr();
	 printf("Its Recess Time. Please come in working hours");
	 delay(5000);
	 exit(0);
	 } else
      {
     //to check for empty rooms
	   for(i=0;i<=20;i++)
     {         j=period;
	    if((strcmp(_x[i][j],",free")==0))
	     {
	     switch(i+1)
    {
      case 1 : printf("\nRoom no. 101");
	       break;
      case 2 : printf("\nRoom no. 102");
	       break;
      case 3 : printf("\nRoom no. 103");
	       break;
      case 4 : printf("\nRoom no. 104");
	       break;
      case 5 : printf("\nRoom no. 105");
	       break;
      case 6 : printf("\nRoom no. 201");
	       break;
      case 7 : printf("\nRoom no. 202");
	       break;
      case 8 : printf("\nRoom no. 203");
	       break;
      case 9 : printf("\nRoom no. 204");
	       break;
      case 10 : printf("\nRoom no. 205");
	       break;
      case 11 : printf("\nRoom no. 301");
	       break;
      case 12 : printf("\nRoom no. 302");
	       break;
      case 13 : printf("\nRoom no. 303");
	       break;
      case 14 : printf("\nRoom no. 304");
	       break;
      case 15 : printf("\nRoom no. 305");
	       break;
      case 16 : printf("\nRoom no. 401");
	       break;
      case 17 : printf("\nRoom no. 402");
	       break;
      case 18 : printf("\nRoom no. 403");
	       break;
      case 19 : printf("\nRoom no. 404");
	       break;
      case 20 : printf("\nRoom no. 405");
	       break;
    }

	      }
       }
      }    room_info();
       return 0;
}
room_info()
{     int f,r,num;

  A :   printf("\n\n\n\t\tFor Further Information and MAP correspondance\n\t\t Please enter the room Number Below :::: \n\t\tOr press 0 to exit::  ");
     scanf("%d",&num);
     switch(num)
    {
      case 101 :
	       f=1; r=1;
	       break;
      case 102 :
	       f=1; r=2;
	       break;
      case 103 :
	       f=1; r=3;
	       break;
      case 104 :
	       f=1; r=4;
	       break;
      case 105 :
	       f=1; r=5;
	       break;
      case 201 :
	       f=2; r=1;
	       break;
      case 202 :
	       f=2; r=2;
	       break;
      case 203 :
	       f=2; r=3;
	       break;
      case 204 :
	       f=2; r=4;
	       break;
      case 205 :
	       f=2; r=5;
	       break;
      case 301 :
	       f=3; r=1;
	       break;
      case 302 :
	       f=3; r=2;
	       break;
      case 303 :
	       f=3; r=3;
	       break;
      case 304 :
		f=3; r=4;
	       break;
      case 305 :
		f=3; r=5;
	       break;
      case 401 :
		f=4; r=1;
	       break;
      case 402 :
		f=4; r=2;
	       break;
      case 403 :
		f=4; r=3;
	       break;
      case 404 :
		f=4; r=4;
	       break;
      case 405 :
		f=4; r=5;
	       break;
      case 0 : exit(0);
      default : textcolor(4);
		cprintf("\r\nPlease enter a valid input.");
		goto A;
   }
      map_select(f,r);

      return 0;
}
  int col[4][5] = {{101,102,103,104,105},{201,202,203,204,205},{301,302,303,304,305},{401,402,403,404,405}};


map_select(int f,int r)
{       if(r==1)
	{   clrscr();
	    textcolor(4);
	    cprintf("\r\n       ________________________________________");
	    cprintf("\r\n       |                                      |                  Floor :: %dth",f);
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                  %d                 |",col[f-1][4]);
	    cprintf("\r\n       ------------_______   ______------------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |      %d                  |          |",col[f-1][1]);
	    cprintf("\r\n       |          |                  %d      |",col[f-1][3]);
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       ------------                -----------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |       %d  ",col[f-1][0]);textcolor(3);cprintf("<---<--\\ ");textcolor(4);cprintf("      |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("        %d      |",col[f-1][2]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n                           ");textcolor(3);cprintf("|");
	    textcolor(3);
	    cprintf("\r\n                           |       ");
	    cprintf("\r\n                           |       ");
	    cprintf("\r\nMain Enterence--->---->----/\r\n\n");
	 }
	 else if(r==2)
	{   clrscr();
	    textcolor(4);
	    cprintf("\r\n       ________________________________________");
	    cprintf("\r\n       |                                      |		  Floor :: %dth",f);
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                  %d                 |",col[f-1][4]);
	    cprintf("\r\n       ------------_______   ______------------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |      %d   ",col[f-1][1]);textcolor(3);cprintf("<---<--\\ ");textcolor(4);cprintf("      |          |",col[f-1][1]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("        %d       |",col[f-1][3]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |      %d          ",col[f-1][0]);textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("         %d      |",col[f-1][2]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n                           ");textcolor(3);cprintf("|");
	    textcolor(3);
	    cprintf("\r\n                           |       ");
	    cprintf("\r\nMain Enterence--->---->----/\r\n\n");
	 }
	 else if(r==3)
	{   clrscr();
	    textcolor(4);
	    cprintf("\r\n       ________________________________________");
	    cprintf("\r\n       |                                      |		  Floor :: %dth",f);
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                  %d                 |",col[f-1][4]);
	    cprintf("\r\n       ------------_______   ______------------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |      %d                  |          |",col[f-1][1]);
	    cprintf("\r\n       |          |                  %d      |",col[f-1][3]);
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       ------------                ------------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |      %d                  |          |",col[f-1][4]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("/-->-->");textcolor(4);cprintf("   %d      |",col[f-1][2]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n                           ");textcolor(3);cprintf("|");
	    textcolor(3);
	    cprintf("\r\n                           |       ");
	    cprintf("\r\nMain Enterence--->---->----/\r\n\n");
	 }
	 else if(r==4)
	{   clrscr();
	    textcolor(4);
	    cprintf("\r\n       ________________________________________");
	    cprintf("\r\n       |                                      |		  Floor :: %dth",f);
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                  %d                 |",col[f-1][4]);
	    cprintf("\r\n       ------------_______   ______------------");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |          |                |          |");
	    cprintf("\r\n       |      %d                  |          |",col[f-1][1]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("/-->-->");textcolor(4);cprintf("   %d      |",col[f-1][3]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |      %d          ",col[f-1][0]);textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("         %d      |",col[f-1][2]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n                           ");textcolor(3);cprintf("|");
	    textcolor(3);
	    cprintf("\r\n                           |       ");
	    cprintf("\r\nMain Enterence--->---->----/\r\n\n");
	 }
	 else if(r==5)
	{   clrscr();
	    textcolor(4);
	    cprintf("\r\n       ________________________________________");
	    cprintf("\r\n       |                                      |		  Floor :: %dth",f);
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                                      |");
	    cprintf("\r\n       |                  %d                 |",col[f-1][4]);
	    cprintf("\r\n       ------------_______   ______------------");
	    cprintf("\r\n       |          |       ");textcolor(3);cprintf("/\\");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |      %d          ",col[f-1][1]);textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |",col[f-1][1]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("        %d       |",col[f-1][3]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |      %d          ",col[f-1][0]);textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("         %d      |",col[f-1][2]);
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       |          |        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       |          |");
	    cprintf("\r\n       ------------        ");textcolor(3);cprintf("|");textcolor(4);cprintf("       -----------");
	    cprintf("\r\n                           ");textcolor(3);cprintf("|");
	    textcolor(3);
	    cprintf("\r\n                           |       ");
	    cprintf("\r\nMain Enterence--->---->----/\r\n\n");
	 }

	    cprintf("_______________________________________________________________________________");
   return 0;
}

void initialise()
{            int i;
	 notice();
	 getch();
	 clrscr();
	 lecture();
	 printf("\n\nSearching Databses for any free lecture");

	 printf("\n\t\t\tSEARCHING");

	 for(i=1;i<=6;i++)
       {  printf(".");
	  delay(400);
       }

	  check_db();

}
void main()
{    int i;
       clrscr();
     initialise();
       getch();
}
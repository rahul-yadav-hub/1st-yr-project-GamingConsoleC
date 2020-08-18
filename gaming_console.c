#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
// for driver function
int caller();
void screen2();
void box(int,int,int,int);
void gotoxy(int x, int y);
void load2();
void screen1();
// main game function declarations
int snakegame();
int tictactoe();
int quiz();
//for snake game
bool gameover;
#define width 60
#define height 20
int x,y,fruitX,fruitY,score,taillength;
int tailX[100],tailY[100];
typedef enum{stop=0,left,right,up,down}direction;
direction dir; 
void setup();
void draw();
void input();
void logic();
void print();
void load();
//for Tic tac toe game
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char activeplayer ='X';
int time2;
int row,column;
void turn();
int checks();
void drawttt();
void tttrules();
//for quiz game
int quizscore =0;
void rules();
void round1();
// main driver function
main()    
{
	char x;
	screen1();
	system("cls");
	screen2();
	x=getch();
	system("cls");
	switch(x)
{
	case '1': snakegame();
            break;
    case '2': tictactoe();
	        break;
	case '3': quiz();
	        break;		        
	case '4':system("cls");
	printf("\t\t\t>>>>>>.....THANKS!  VISIT AGAIN......<<<<<<<");
	exit(0);	
	default:caller();	
}
}
int caller()
{  
    char x;
	system("cls");
	screen2();
	x=getch();
	system("cls");
	switch(x)
{
	case '1': snakegame();
            break;
    case '2': tictactoe();
	        break;
	case '3': quiz();
	        break;		        
	case '4':system("cls");
	printf(">>>>>>.....THANKS!  VISIT AGAIN......<<<<<<<");
	exit(0);	
	default: system("cls");
			printf("Invalid Choice");
			caller();
}
}
//fn definitions for driver part
void gotoxy(int x, int y)
{
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}
void screen2()
{
	int i;
	box(40,80,3,7); //for gaming console
    gotoxy(46,5);
    printf("WELCOME TO THE GAMING CONSOLE");
    for(i=0;i<=40;i++)     // making look like hanging
    {
    	gotoxy(i,5);
    	printf("%c",177);
	}
	for(i=80;i<=119;i++)
    {
    	gotoxy(i,5);
    	printf("%c",177);
	}
    box(5,115,10,28);  // boundary
		gotoxy(51,11);
	printf(">>>>>> GAME MENU <<<<<<");
	for(i=5;i<=115;i++)  //line below menu
	{
		gotoxy(i,12);
		printf("%c",177);
	}
	
 box(10,40,16,24); //snake
 box(45,75,16,24); //tic tac 
 box(80,110,16,24); //kbc
	
	gotoxy(45,26);
	printf("Select the game you wanna play!!!           press 4 to exit");
	gotoxy(18,14);
	printf("1. MINI SNAKE GAME                  2.  TIC-TAC-TOE                      3. QUIZ");
	gotoxy(20,18);      //SNAKE BOX
	printf("PLAY ME!!!");
	gotoxy(12,20);
	printf("->Wanna Have Some Adventure");
	gotoxy(52,18);     //TICTACTOE BOX
	printf("PLAY ME,PLZZ!!!");
	gotoxy(48,20);
	printf("->Wanna Use Your Brain");
	gotoxy(88,18);     //QUIZ BOX
	printf("HEY NO,PLAY ME!!!");
	gotoxy(83,20);
	printf("->Wanna Test Your Memory");
}
void load2(){
    int r,c,q;
    gotoxy(48,22);
    printf("loading...");
    gotoxy(42,23);
    for(r=1;r<=20;r++)
	{
	//	sleep(1);
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("$");
	}
}
void screen1()
{
	int i;
	gotoxy(45,5);
	printf("$$$...WELCOME...$$$ \n");
	for(i=43;i<66;i++)
   {
       gotoxy(i,3);
           printf("*");
       gotoxy(i,7);
           printf("*");
   }
  box(26,78,9,25);
   gotoxy(40,11);
   printf("---> PROJECT MEMBERS <---\n");
   
   gotoxy(30,13);
   printf("1.RAHUL ");
   gotoxy(30,14);
   printf("2.HRITHIK ");
   gotoxy(30,15);
   printf("3.ANKIT ");
   gotoxy(30,16);
   printf("4.PRATIK ");
   gotoxy(30,17);
   printf("5.SHIVANASHI ");
   gotoxy(30,18);
   printf("6.NISTHA ");
   gotoxy(30,19);
   printf("7.JIMMY");
   gotoxy(30,20);
   printf("8.STUTI ");
   gotoxy(39,21);
   printf("!!!PRESENTING YOU THE BEST!!!");
	load2();
	gotoxy(72,28);
	printf("DONE......Press Any Key To Continue!");
	getch();
}
void box(int h1,int h2,int v1,int v2)
{
	int i;
	for(i=h1;i<=h2;i++)      // box making horizontal line
	{
		gotoxy(i,v1);
		printf("%c",177);
		gotoxy(i,v2);
		printf("%c",177);
	}
	for(i=v1;i<=v2;i++)      // box making vertical lines
	{
		gotoxy(h1,i);
		printf("%c",177);
		printf("%c",177);
		gotoxy(h2,i);
		printf("%c",177);
		printf("%c",177);
	}
}
//fn decalartions for snake game
int snakegame()
{
	int i;
	print();
	system("cls");
	load();
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		for(i=0;i<=10000000;i++);
	} 
	printf("\n GAME ENDED\n YOUR SCORE IS %d \n Press any key to return to game menu",score);
	getch();
	x=0;y=0;fruitX=0;fruitY=0;score=0;taillength=0;
	caller();
	return 0;
}
void print()
{
   printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n-> Use w,s,a,d keys to move the snake.\n\n-> Press X key to exit the game in between \n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and   thus score by 5.\n\n ->Your game  will end if you hit the wall or eat snake's body. \n");
   printf("\n\nPress any key to play game...");
   getch();
   //if(getch()==27)
  // exit(0);
}
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    gotoxy(30,16);
    printf("Done.....Press any key to continue!!!");
    getch();
}
void setup()
{
	gameover=false;
    dir=stop;
	x=width/2;
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}
void draw()
{
	int i,j,k;
	system("cls");
	for(i=0;i<width+4;i++)             //horizontal border
		printf("%c",177);
	printf("\n");
	for(i=0;i<height;i++)             //row
	{
		for(j=0;j<width;j++)          //column
		{
			if(j==0)                  // vertical border
			{
			printf("%c",177);
			printf("%c",177);
		    }
		    if(i==y && j==x)
		    printf("@");
		    else if(i==fruitY && j==fruitX)
		    printf("F");
		    else
		    {
		    	bool flag=false;      //to check whether we printed body or not
		    	for(k=0;k<taillength;k++)                //snake body
		    	{
		    		if(tailX[k]==j && tailY[k]==i)
		    		{
		    			printf("o");
		    			flag=true;
					}
				}
				if(!flag)    //if no food eaten print blank space
				printf(" ");
			} 
			if(j==width-1)  
			{
			printf("%c",177);
			printf("%c",177);
		    }
		}
		printf("\n");         // getting into new line
	}	
	for(i=0;i<width+4;i++)    //horizontal border
	printf("%c",177);
	printf("\n"); 
	printf("SCORE=%d",score);
}
void input()
{
	if(kbhit())
	{
		switch(toupper(getch()))
		{
			case 'A': dir=left;
			          break;
			case 'D': dir=right;
			          break;
			case 'W': dir=up;
			          break;
			case 'S': dir=down;
			          break;
			case 'X':
			        gameover=true;
			          break;		  		  		  		            
		}
	}
}
void logic()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;       //to make body follow the head
	tailY[0]=y;
	for(i=1;i<taillength;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir)
	{
		case left:
			x--;
			break;
		case right:
		    x++;
			break;
		case up:
		    y--;
			break;
		case down:
		    y++;
			break;
		default:
		    break;				
	}
	if(x>width || x<0 || y>height ||y<0)
	{
    	gameover=true;
	}
	
	for(i=0;i<taillength;i++)
	if(tailX[i]==x && tailY[i]==y)
	{
     	gameover=true; 
	}
	if(x==fruitX && y==fruitY)
	{
		score+=10;
		fruitX=rand()%width;
	    fruitY=rand()%height;
	    taillength++;
	}
}
//fn decalartions for tictactoe game
int tictactoe(){
	tttrules();
	system("cls");
	load();
	int complete;
	while (!complete && time2!=9)
	{
		drawttt();
		turn();
		complete = checks(matrix);
	        if(complete==1)
	        {     
	        	drawttt();
	            printf("\n                                      Congratulations Player %c Won", matrix[row][column]);
	            printf(" \n\n                                Press any key to return to game menu");
	            getch();
               	caller();
	        }
	        time2++;
	       if (time2 == 9 && complete == 0)
	      {
	      	printf("\n                                                Oops!!! Game Drawn");
	      	printf(" \n\n                                   Press any key to return to game menu");
	      	getch();
	      	caller();
		  }
	  drawttt();
	}
}
void tttrules()
{
   printf("\tWelcome to the Tic-Tac-Toe game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n->The object of Tic-Tac-Toe is to get three in a row.You will play on a three by three board \n\n->The first player is known as X and the second is O.\n\n->Players will have to alternately place Xs and Os on the game board until either opponent has three in a row or all nine squares are filled.\n\n->X always goes first,and in the event that no one has three in a row,the game will be drawn.\n\n->Press escape key to exit in between.\n\n");
   printf("\n\nPress any key to play game...");
   getch();
   //if(getch()==27)
  // exit(0);
}
void turn(){
	char choice;
	int complete;
	if (activeplayer=='X'){
		printf("Player1[X] Turn:");
	}
	else {
		printf("Player2[O] Turn:");
	}
//	scanf("%d",&choice);
    choice=getch();
    if(choice==27)
    caller();
	switch(choice){
		case '1':row=0;column=0;break;
		case '2':row=0;column=1;break;
		case '3':row=0;column=2;break;
		case '4':row=1;column=0;break;
		case '5':row=1;column=1;break;
		case '6':row=1;column=2;break;
		case '7':row=2;column=0;break;
		case '8':row=2;column=1;break;
		case '9':row=2;column=2;break;
		default:
			printf("Invalid Choice\n");
			getch();
			break;

	}
	if (activeplayer=='X'&&matrix[row][column]!='X'&&matrix[row][column]!='O'){
		matrix[row][column]='X';
		activeplayer='O';
	}
	else if (activeplayer=='O'&&matrix[row][column]!='X'&&matrix[row][column]!='O'){
		matrix[row][column]='O';
		activeplayer='X';    
	}
	else {
		printf("Place is Booked \n");
		getch();
	}
	
 }
   





int checks(){
	if ((matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) || (matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0]))
    {
        return 1;
    }
    else
    {
        if((matrix[0][0]==matrix[0][1] && matrix[0][1]==matrix[0][2]) ||
           (matrix[1][0]==matrix[1][1] && matrix[1][1]==matrix[1][2]) ||
           (matrix[2][0]==matrix[2][1] && matrix[2][1]==matrix[2][2]))
           {
               return 1;
           }
        else  if((matrix[0][0]==matrix[1][0] && matrix[1][0]==matrix[2][0]) ||
                 (matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1]) ||
                 (matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2]))
           {
               return 1;
           }
        else
        {
            return 0;
        }
    }
}
void drawttt(){
	system("cls");
	printf("    Tic Tak Toe\n");
	printf("\tPlayer1 [X], Player2 [O]");
	printf("\n\n");
	printf("|\t\t%c\t|\t%c\t|\t%c\t|\n",matrix[0][0],matrix[0][1],matrix[0][2]);
	printf("|\t    ------------------------------------------\n");
	printf("|\t\t%c\t|\t%c\t|\t%c\t|\n",matrix[1][0],matrix[1][1],matrix[1][2]);
	printf("|\t    ------------------------------------------\n");
	printf("|\t\t%c\t|\t%c\t|\t%c\t|\n",matrix[2][0],matrix[2][1],matrix[2][2]);
}
// for fn decalarations for quiz game
int quiz()
{   
    rules();
    system("cls");
    load();
    system("cls");
    round1();
    printf(" \n\n\n\n\n              Press any key to return to game menu");
    getch();
    caller();
    return 0;
}
void rules()
{
	printf("\tWelcome to the Quiz game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n->This is MCQ based simple quiz game covering geographical questions.\n\n->You will get four options for one question.Select your choice accordingly.\n\n->One correct will give you 1 marks each.You will be graded accordingly on your score obtained.\n\n->Press escape key to exit the game in between.");
   printf("\n\nPress any key to play game...");
   getch();
}
    
void round1(){
    int c,i,count=0;
    int k[12]={7,9,3,4,8,1,5,11,10,2,0,6};
    system("cls");
    while ( count<=11)
   { 
     count++;
     system("cls");
   		if (k[count] == 0)
        { 
		printf("\t\tFirst Indian movie submitted for Oscar \n\t\tA.Madhumati\n\t\tB.Amrapali\n\t\tC.Mother India\n\t\tD.The Guide\n");
            if (toupper(getch())=='C'){
            printf("\t\tCorrect\n");
            
            getch();
             quizscore++;
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is C\n");
           
           getch();
       }
   }
   
   		if (k[count] == 1)
        { 	
		printf("\t\tThe only state in India that produces saffron is \n\t\tA.Assam\n\t\tB.Himachal Pradesh\n\t\tC.Jammu and Kashmir\n\t\tD.Meghalaya\n");
            if (toupper(getch())=='C'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is C\n");
           
           getch();
       }
   }  
   if (k[count] == 2)
        {    	
		printf("\t\tThe percentage of irrigated land in India is about \n\t\tA.45\n\t\tB.65\n\t\tC.35\n\t\tD.25\n");
            if (toupper(getch())=='C'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is C\n");
           getch();
       }
   }
if (k[count] == 3)
        {        	
		printf("\t\t The India's highest annual rainfall is reported at\n\t\tA.Namchi, Sikkim\n\t\tB.Western Ghats, Mahrashtra\n\t\tC.Mawsynram, Meghalaya\n\t\tD.Chamba, Himachal Pradesh\n");
            if (toupper(getch())=='C'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is C\n");
           getch();} }           
       if (k[count] == 4)
        {        	
		printf("\t\t What is a very cold part of Russia?\n\t\tA.Moscow\n\t\tB.Kazan\n\t\tC.Samara\n\t\tD.Siberia\n");
            if (toupper(getch())=='D'){
            printf("\t\tCorrect\n");
             getch();
             quizscore++;   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is D\n");
           getch();}}
		   
		   if (k[count] == 5)
        {
        	
		printf("\t\t The great Victoria Desert is located in\n\t\tA.Canada\n\t\tB.West Africa\n\t\tC.Australia\n\t\tD.North America\n");
            if (toupper(getch())=='C'){
            printf("\t\tCorrect\n");
             getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is C\n");
           getch();} }
           
           
           if (k[count] == 6)
        {
        	
		printf("\t\tWhat is the noisiest city in the world? \n\t\tA.Mumbai\n\t\tB.Hong Kong\n\t\tC.New York\n\t\tD.Tokyo\n");
            if (toupper(getch())=='B'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is B\n");
           getch();} }
           
                if (k[count] == 7)
        {
        	
		printf("\t\t The leading Indian state in producing paper is\n\t\tA.Bihar\n\t\tB.West Bengal \n\t\tC.Kerala\n\t\tD.Orissa\n");
            if (toupper(getch())=='B'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is B\n");
           getch();} }
           
            if (k[count] == 8)
        {
        	
		printf("\t\t What is the capital city of Australia ?\n\t\tA.Canberra\n\t\tB.Melbourne\n\t\tC.Sydney\n\t\tD.Adelaide\n");
            if (toupper(getch())=='A'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is A\n");
           getch();} }
           
               if (k[count] == 9)
        {
        	
		printf("\t\t The highest average salinity amongst the following seas is reported from ?\n\t\tA.Dead Sea\n\t\tB.Red Sea\n\t\tC.Black Sea\n\t\tD.Mediterranean Sea\n");
            if (toupper(getch())=='A'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is A\n");
           getch();} }
           
                  if (k[count] == 10)
        {
        	
		printf("\t\tThe Himalayan mountain system belongs to which of the following? \n\t\tA.Volcanic mountains\n\t\tB.Residual mountains\n\t\tC.Residual mountains\n\t\tD.Fold mountains\n");
            if (toupper(getch())=='D'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
   
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is D\n");
           getch();} }
           
           if (k[count] == 11)
        {
        	
		printf("\t\tThe island of Sri Lanka formerly known as\n\t\tA.Lanka\n\t\tB.Lakshadweep\n\t\tC.Ceylon\n\t\tD.None of the above\n");
            if (toupper(getch())=='D'){
            printf("\t\tCorrect\n");
            getch();
             quizscore++;
    
       }
       else if(getch()==27){
   	 	caller();
		} 
       else {
           printf("Wrong Answer !! Correct is D\n");
           getch();} }
}
system("cls");
printf(" \n\t\tYOUR SCORE IS %d",quizscore );
if(quizscore==12)
printf("\n\t\tEXCELLENT");
else if(quizscore>=10 && quizscore<12)
printf("\n\t\tGOOD");
else if(quizscore>=6 && quizscore<10)
printf("\n\t\tSATISFACTORY");
else
printf("\n\t\tPOOR");

 }






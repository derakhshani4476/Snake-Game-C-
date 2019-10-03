
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int x=12,y=40,a=0,f=0,m=13,w=13,n,q,s,level=1;  //a=tool mar,m=satr,w=soton
char c;
int far *SCR=(int far*)0XB8000000;
int snake[2][100];

void first1 (void)
{
	snake[1][0]=y;
	snake[0][0]=x;
	SCR[x*80+y]=116 *256 + '*';
	for (int i=0 ; i<100;i++){
	snake [0][i] = 150 ;
	snake [1][i] = 150 ;
	SCR [snake[0][i]*80+snake[1][i]] = 13 * 256 + '*' ;
	}
}

void first (void)
{
	first1();
	SCR[w*80+m] = 113 *256 + '#';

}

void food(){

	SCR[w*80+m]=112 *256;
	m = rand() %76+2;
	w = rand() %20+2;
	if(SCR[w*80+m]== 80*256)
	{
		m = rand() %76+2;
		w = rand() %20+2;
	}
	SCR[w*80+m]= 113 *256 + '#';
	if(f<7)
	{
	f++; a=a+f;
	}
	else
	{
	level=level+1 ;f=0; a=0 ;first();
	}

}
void init(){

	q=0;
	for (int z=1;z<=a;z++){
	if( snake[0][z]==snake[0][0] && snake[1][z]==snake[1][0] )
	q=1;
	}

	if(level==1)
	{
	n=12;

	}
	else if(level==2)
	{
	cout<<"level 2 "  ;
	gotoxy(35,25);
	n=10;
	}
	else if(level==3 )
	{
	cout<<"level 3 "  ;
	gotoxy(35,25);
	n=8;
	int o=6;
	for(int u=5;u<8;u++)
	SCR[u*80+o]=80*256;
	int p=48;
	for(int i=10;i<14;i++)
	SCR[i*80+p]=80*256;
	int d=6;
	for(int f=57;f<64;f++)
	SCR[d*80+f]=80*256;
	int b=19;
	for(int r=16;r<27;r++)
	SCR[b*80+r]=80*256;
	}

	else if(level==4 )
	{
	cout<<"level 4 "  ;
	gotoxy(35,25);
	n=6;
	int o=6;
	for(int u=5;u<8;u++)
	SCR[u*80+o]=80*256;
	int p=48;
	for(int i=10;i<14;i++)
	SCR[i*80+p]=80*256;
	int d=6;
	for(int f=57;f<64;f++)
	SCR[d*80+f]=80*256;
	int b=19;
	for(int r=16;r<27;r++)
	SCR[b*80+r]=80*256;


	}


}

void black1 ()
{
int U=23;
for(int O=0;O<80;O++)
SCR[U*80+O]=2*256;

int p=0;
for(int i=0;i<80;i++)
SCR[p*80+i]=2*256;
int a=0;
for(int z=0;z<25;z++)
SCR[z*80+a]=2*256;
int d=79;
for(int k=0;k<80;k++)
SCR[k*80+d]=2*256;

}

void black ()
{
int u=24;
for(int o=0;o<80;o++)
SCR[u*80+o]=2*256;
black1();
}
void white ()
{
for(int o=1;o<78;o++)
for(int u=1;u<22;u++)
SCR[u*80+o]=112*256;

	int Q=1;
	for(int W=1;W<79;W++)
	SCR[Q*80+W]=80*256;
	int A=22;
	for(int S=1;S<79;S++)
	SCR[A*80+S]=80*256;
	int E=1;
	for(int R=1;R<23;R++)
	SCR[R*80+E]=80*256;
	int D=78;
	for(int F=1;F<23;F++)
	SCR[F*80+D]=80*256;

}
int FUNCKEY (char &c)
{
	c = getch();
	if (c==0) {c=getch();return 0; }
	else return 1 ;
}

int delay (){
	long long v,g;
	for (v=0; v < (n*33000);v++)
		g=v;
		return 0;

}

void gameover(){

	 cout<<"game over";
	 q=0;
	 level=1;
	 x=12;
	 y=40;
	 a=0;
	 f=0;
	 black1();
	 first1();
	 c='a';
	 gotoxy(35,25);

}


void  move(int t,char c){


	  if(w!=x || m!=y){
	  if(t == 0){
		    delay();
		    for (int k=a;k>0;k--){
			snake[0][k]=snake[0][k-1];
			snake[1][k]=snake[1][k-1];
		    }

		    switch (c){

			   case 'H':  if (x>0)
				  x=x-1 ;
				  break;
			   case 'P':  if (x<23)
				  x=x+1;
				  break;
			   case 'M': if (y<79)
				  y=y+1 ;
				  break;

			   case 'K': if (y>0)
				  y=y-1 ;
				  break;
			}
			if( SCR[snake[0][0]*80+snake[1][0]] == 80 *256 )
			q=1;

			white();
			if( SCR[snake[0][0]*80+snake[1][0]] == 80 *256 )
			q=1;

			snake[0][0]=x;
			snake[1][0]=y;
			SCR[snake[0][0]*80+snake[1][0]]=116 *256 + '*';
			for (int r=1;r<100;r++){
			SCR [snake[0][r] * 80 + snake[1][r] ]= 116 * 256 + '*' ;
			}
			SCR [w*80+m] = 113 * 256 + '#' ;

		     }


		     }

		else food();


}



void main (void){
	black();
	white();
	first();
	gotoxy(35,25);
	char t=FUNCKEY (c);
	while ( c!=27 || t!=1)
	{
		while(!kbhit()){

				if(q==1){
				gameover();
				}

				else{
				init();
				move(t,c);
				}

		}
		t=FUNCKEY(c);
		black();
	}
}
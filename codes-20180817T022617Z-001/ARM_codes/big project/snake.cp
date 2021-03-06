#line 1 "C:/Users/pc2/Desktop/embded/codes/microCforArm/big project/snake.c"
#line 1 "c:/users/pc2/desktop/embded/codes/microcforarm/big project/header.h"
typedef unsigned char u8;
typedef unsigned int u16;
 typedef unsigned long int u32;




void Calibrate(void);
void Init_ADC(void);


void module1 ();
void Games_Module();


void draw(u8 sizeOFsnake);
void ams7();
void snake();
void after_snake();


void paint_module();
void paint_module2();
void paint();
void paint2();

void comm_module();
void comm();
#line 7 "C:/Users/pc2/Desktop/embded/codes/microCforArm/big project/snake.c"
 extern u8 size_snake;
 extern u16 x,y;
 extern u8 dofd3_flag;
 extern x_tft,y_tft;
 void draw(u8 sizeOFsnake)
 {
 TFT_Set_Pen(CL_GRAY,sizeOFsnake);
 TFT_Circle(x, y, 0);
 }

 void ams7()
 {
 TFT_Set_Pen(CL_RED,size_snake);
 TFT_Circle(x, y, 0);
 }

 void snake()
 {
 u8 i;
 u8 j;
 u8 R=0;
 u8 L=0;
 u8 U=0;
 u8 D=0;
 u8 value=0;
 u16 xRandom[3];
 u16 yRandom[3];
 u8 flag_food[3];
 u8 out1=0;
 u8 exit=0;
 TFT_Fill_Screen(CL_RED);
 TFT_Write_Text("let's play",150,120);
 Delay_ms(1000);
 TFT_Fill_Screen(CL_RED);
 TFT_Set_Pen(CL_GRAY,size_snake);
 TFT_Circle(x, y, 0);
 TFT_Set_Pen(CL_Black,7);
 TFT_Circle(xRandom, yRandom, 0);
 TFT_Set_Pen(CL_GRAY,size_snake);

 if(out1==0)
 {
 out1=1;
 for(i=0;i<3;i++)
 {
 xRandom[i]=rand()/200;
 yRandom[i]=rand()/200;
 TFT_Set_Pen(CL_Black,7);
 TFT_Circle(xRandom[i], yRandom[i], 0);
 flag_food[i]=1;
 }
 }
 while(dofd3_flag==1)
 {

 R=Button(&GPIOA_IDR,6, 100 , 0 );
 L=Button(&GPIOD_IDR,2, 100 , 0 );
 U=Button(&GPIOD_IDR,4, 100 , 0 );
 D=Button(&GPIOB_IDR,5, 100 , 0 );
 value= Button(&GPIOB_IDR,0, 100 , 1 );

 if(R==255)
 {
 while(Button(&GPIOD_IDR,2, 100 , 0 )==0&& Button(&GPIOD_IDR,4, 100 , 0 )==0 &&Button(&GPIOB_IDR,5, 100 , 0 )==0)
 {
 for(j=0;j<3;j++)
 {
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j]+i)&&(x==xRandom[j])&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 }
 }
 if( dofd3_flag==0) break;
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j]-i)&&(x==xRandom[j])&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 } if( dofd3_flag==0) break;
 }
 }
 if( dofd3_flag==0) break;
 switch(x)
 {
 case 320: ams7();
 x=0;
 draw(size_snake);
 break;
 default: ams7();
 x+=1;
 draw(size_snake);
 break;
 }
 Delay_ms(5);

 }
 }
 else if(L==255)
 {
 while(Button(&GPIOA_IDR,6, 100 , 0 )==0&& Button(&GPIOD_IDR,4, 100 , 0 )==0 &&Button(&GPIOB_IDR,5, 100 , 0 )==0)
 {
 for(j=0;j<3;j++)
 {
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j]+i)&&(x==xRandom[j])&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 }
 }
 if( dofd3_flag==0) break;
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j]-i)&&(x==xRandom[j])&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 }
 }
 }
 if( dofd3_flag==0) break;
 switch(x)
 {
 case 0: ams7();
 x=320;
 draw(size_snake);
 break;
 default: ams7();
 x-=1;
 draw(size_snake);
 break;
 }
 Delay_ms(5);

 }
 }
 else if(D==255)
 {
 while(Button(&GPIOA_IDR,6, 100 , 0 )==0&& Button(&GPIOD_IDR,4, 100 , 0 )==0 &&Button(&GPIOD_IDR,2, 100 , 0 )==0)
 {
 for(j=0;j<3;j++)
 {
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j])&&(x==xRandom[j]+i)&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 }
 if( dofd3_flag==0) break;
 }
 if( dofd3_flag==0) break;
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j])&&(x==xRandom[j]-i)&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 }
 }
 if( dofd3_flag==0) break;
 }
 if( dofd3_flag==0) break;
 switch(y)
 {
 case 320: ams7();
 y=0;
 draw(size_snake);
 break;
 default: ams7();
 y+=1;
 draw(size_snake);
 break;
 }
 Delay_ms(5);
 }
 }
 else if(U==255)
 {
 while(Button(&GPIOA_IDR,6, 100 , 0 )==0&& Button(&GPIOD_IDR,2, 100 , 0 )==0 &&Button(&GPIOB_IDR,5, 100 , 0 )==0)
 {
 for(j=0;j<3;j++)
 {
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j])&&(x==xRandom[j]+i)&&(flag_food[j]==1))
 {
 size_snake+=5;
 flag_food[j]=0;
 exit++;
 if(exit==3)
 {
 dofd3_flag=0;
 break;
 }
 } if( dofd3_flag==0) break;
 }
 if( dofd3_flag==0) break;
 for(i=0;i<10;i++)
 {
 if((y==yRandom[j])&&(x==xRandom[j]-i)&&(flag_food[j]==1)) {size_snake+=5;flag_food[j]=0;exit++; if(exit==3)
 {
 dofd3_flag=0;
 break;
 }}
 }
 }
 if( dofd3_flag==0) break;
 switch(y)
 {
 case 0: ams7();
 y=320;
 draw(size_snake);
 break;
 default: ams7();
 y-=1;
 draw(size_snake);
 break;
 }
 Delay_ms(5);

 }
 }
 }




 TFT_Fill_Screen(CL_Green);
 TFT_Write_Text("Good job ,Bro",150,120);
 size_snake=20;
 TFT_Set_Pen(CL_WHITE, 3);
 x_tft=500;
 y_tft=500;
 after_snake();
 }




void after_snake()
{
 Delay_ms(500);
 TFT_Fill_Screen(CL_Yellow);
 TFT_Write_Text("again",120,60);
 TFT_Write_Text("Back to games",120,180);
 TFT_Line(0,120,320,120);
 while(x_tft==500&&y_tft==500)
 {
 if(TP_TFT_Press_Detect())
 {
 TP_TFT_Get_Coordinates(&x_tft,&y_tft);
 }
 }
 if(y_tft<120)
 {
 dofd3_flag =1;
 snake();
 }
 else if(y_tft>120)
 Games_Module();


}

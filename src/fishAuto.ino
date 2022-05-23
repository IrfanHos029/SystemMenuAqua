#include <LiquidCrystal.h>
#include "LiquidMenu.h"
#include "Button.h"
#include <RTClib.h>

#define led 11

LiquidCrystal lcd(13,12,10,9,8,7);
RTC_DS3231 rtc;
DateTime now;

const bool pullup = true;
Button left(4,pullup);
Button right(2,pullup);
Button up(5,pullup);
Button down(6,pullup);
Button ok(3,pullup);

byte lockOk = 0;
byte lockDown = 0;
byte lockUp = 0;
byte lockright = 0;
byte lockLeft = 0;

byte menu = 1;
byte counterSub1 = 1;
byte counterPO = 1;
byte counterSub2 = 0;

void setup(){
  lcd.begin(16,2);
  rtc.begin();

}

void loop(){

   if(menu == 1){
     if(ok.check() == LOW && lockOk == 0){lockOk = 1; lcd.clear();}
     if(ok.check() != LOW && lockOk == 1){lockOk = 0; menu =2;}
     lcd.setCursor(0,0);
     lcd.print("testing menu");
     lcd.setCursor(0,1);
     lcd.print("IRFAN.A");
   }

   if(menu == 2){

     if(down.check() == LOW && lockDown == 0){lockDown=1; lcd.clear();}
     if(down.check() != LOW && lockDown == 1){lockDown=0; counterPO++;}

     if(up.check() == LOW && lockUp == 0){lockUp = 1; lcd.clear();}
     if(up.check() != LOW && lockUp == 1){lockUp = 0; counterPO--;}

     if(left.check() == LOW && lockLeft == 0){lockLeft = 1; lcd.clear();}
     if(left.check() != LOW && lockLeft == 1){lockLeft = 0; menu =1;}

     

     if(counterPO > 4){counterPO=0;}
     else if(counterPO < 1){counterPO=4;}

      switch(counterSub1){
        case 1 :
          lcd.setCursor(0,0);
          lcd.print("set pompa");
          lcd.setCursor(0,1);
          lcd.print("set lampu");
          break;

        case 2:
          lcd.setCursor(0,0);
          lcd.print("lampu 1");
          lcd.setCursor(0,1);
          lcd.print("lampu 2");
          break;
      }

      switch(counterPO){
        case 1:
          counterSub1=1;
          lcd.setCursor(14,0);
          lcd.print("<-");
          if(ok.check() == LOW && lockOk == 0){lockOk = 1; }
          if(ok.check() != LOW && lockOk == 1){lcd.clear(); lockOk = 0; menu=0; counterSub2 =1;}
          break;

        case 2:
          counterSub1=1;
          lcd.setCursor(14,1);
          lcd.print("<-");
          if(ok.check() == LOW && lockOk == 0){lockOk = 1; }
          if(ok.check() != LOW && lockOk == 1){lcd.clear(); lockOk = 0; menu=0; counterSub2 =2;}
          break;

        case 3:
          counterSub1=2;
          lcd.setCursor(14,0);
          lcd.print("<-");
          if(ok.check() == LOW && lockOk == 0){lockOk = 1;}
          if(ok.check() != LOW && lockOk == 1){ lcd.clear(); lockOk = 0; menu=0; counterSub2 =3;}
          break;

        case 4:
          counterSub1=2;
          lcd.setCursor(14,1);
          lcd.print("<-");
          if(ok.check() == LOW && lockOk == 0){lockOk = 1;}
          if(ok.check() != LOW && lockOk == 1){ lcd.clear(); lockOk = 0; menu=0; counterSub2 =4;}
          break;
      }
   }

   if(counterSub2 == 1){
      lcd.setCursor(0,0);
          lcd.print("testing");
          lcd.setCursor(0,1);
          lcd.print("1");
   }


   if(counterSub2 == 2){
      lcd.setCursor(0,0);
          lcd.print("testing");
          lcd.setCursor(0,1);
          lcd.print("2");
   }

    if(counterSub2 == 3){
      lcd.setCursor(0,0);
          lcd.print("testing");
          lcd.setCursor(0,1);
          lcd.print("3");
   }

     if(counterSub2 == 4){
       byte counterPOS4=1;

          lcd.setCursor(0,0);
          lcd.print("lampu:");
          lcd.setCursor(8,0);
          lcd.print("ON");
          lcd.setCursor(8,0);
          lcd.print("OFF");
          lcd.setCursor(15,1);
          lcd.print("<");

     if(down.check() == LOW && lockDown == 0){lockDown=1; lcd.clear();}
     if(down.check() != LOW && lockDown == 1){lockDown=0; counterPOS4++;}

     if(up.check() == LOW && lockUp == 0){lockUp = 1; lcd.clear();}
     if(up.check() != LOW && lockUp == 1){lockUp = 0; counterPOS4--;}

     if(counterPOS4 > 3){counterPOS4 = 1;}
     else if(counterPOS4 < 1){ counterPOS4 = 3;}

      switch(counterPOS4){
        case 1:
               lcd.setCursor(11,0);
               lcd.print("<-");
               break;

        case 2:
               lcd.setCursor(11,0);
               lcd.print("<-");
               break;

        case 3:
               lcd.setCursor(13,1);
               lcd.print("->");
               break;
      }

   }



}


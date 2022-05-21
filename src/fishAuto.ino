#include <LiquidCrystal.h>
#include <LiquidMenu.h>
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

char string_on[] = "ON";
char string_off[] = "OFF";
char DATETIME [] = "12:00";
char DATEALARM [] = "01:00";
float suhu = 0;
bool stateLamp = false;


LiquidLine Time(0, 0, "Time",DATETIME);
LiquidLine Sensor(0, 1, "SUHU:", suhu);
LiquidLine Alarm(9, 1, "status",DATEALARM);
LiquidScreen Output(Time, Sensor, Alarm);

LiquidLine Line1(0, 0, "setMakan", DATEALARM);
LiquidLine Line2(0, 1, "setLampu", stateLamp);
LiquidScreen mainMenu(Line1,Line2);

LiquidLine subLine1(0, 0, "ON" ,stateLamp);
LiquidLine subLine2(0, 1, "OFF",stateLamp);
LiquidScreen subMenu2(subLine1,subLine2);

LiquidMenu menu(lcd);

//LiquidSystem(menu);

int jam=0;
int menit=0;
int detik=0;

bool stateLed1 = false;
bool stateLed2 = false;
bool stateLed3 = false;


void showMenu(){
  menu.change_screen(2);
}

void ON(){
    digitalWrite(led,HIGH);
}

void OFF(){
    digitalWrite(led,LOW);
}

    void SUBMENU1(){
    menu.change_screen(3);
}

void SUBMENU2(){

}


void setup(){
  lcd.begin(16,2);
  rtc.begin();
  pinMode(led,OUTPUT);

  subLine1.attach_function(1,ON);
  subLine2.attach_function(1,OFF);
  Line1.attach_function(1,SUBMENU2);
  Line2.attach_function(1,SUBMENU1);
  menu.add_screen(Output);
  menu.add_screen(mainMenu);
   menu.add_screen(subMenu2);
  

  menu.update();
}

void loop(){
  menu.update();
  stateButton();
}

void updateClock(){
  now = rtc.now();

  jam = now.hour();
  menit = now.minute();
  detik = now.second();
}

void stateButton(){
  if(right.check()==LOW){
    menu.next_screen();
  }

  if(left.check()==LOW){
    //menu.previous_screen();
  }

  if(up.check() == LOW){
      
  }

  if(down.check()== LOW){

  }

  if(ok.check() == LOW){
      menu.switch_focus();
  }
  //menu.update();
}
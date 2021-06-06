#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

long a,b,c,x,time,timex;
int meau;

LiquidCrystal_I2C lcd(0x27,16,2); 
byte Heart[8]={
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};

byte Bell[8]={
0b00100,
0b01110,
0b01110,
0b01110,
0b11111,
0b00000,
0b00100,
0b00000
};

byte Alien[8]={
0b11111,
0b10101,
0b11111,
0b11111,
0b01110,
0b01010,
0b11011,
0b00000
};

byte Check[8]={
0b00000,
0b00001,
0b00011,
0b10110,
0b11100,
0b01000,
0b00000,
0b00000
};

byte Speaker[8]={
0b00001,
0b00011,
0b01111,
0b01111,
0b01111,
0b00011,
0b00001,
0b00000
};

byte Sound[8]={
0b00001,
0b00011,
0b00101,
0b01001,
0b01001,
0b01011,
0b11011,
0b11000
};

byte Skull[8]={
0b00000,
0b01110,
0b10101,
0b11011,
0b01110,
0b01110,
0b00000,
0b00000
};

byte Lock[8]={
0b01110,
0b10001,
0b10001,
0b11111,
0b11011,
0b11011,
0b11111,
0b00000
};
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = 
{
  {'1','4','7','C'},
  {'2','5','8','0'},
  {'3','6','9','='},
  {'+','-','*','/'}
};
byte rowPins[ROWS] = {5,4,3,2}; 
byte colPins[COLS] = {9,8,7,6}; 
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void cleanxy(int x,int y)
{
  for(int i=0;i<x;i++)
  {
    lcd.setCursor(i,y);
    lcd.print(" ");
  }
}
void clean()
{
    b=0;
    a=0;
    c=0;
    Serial.println("clean");
    x=0;
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");  
}
void compute(char key)
{
  if(key>='0'&&key<='9')
  {
    a=a*10+(key-'0');
    Serial.println(a);
    lcd.setCursor(0,0);
    lcd.print(a);
  }
  if(key=='+')
  {
    b=a;
    a=0;
    Serial.println("+");
    x=1;
    lcd.setCursor(12,0);
    lcd.print("+");
    cleanxy(11,0);
  }
  if(key=='-')
  {
    b=a;
    a=0;
    Serial.println("-");
    x=2;
    lcd.setCursor(12,0);
    lcd.print("-");
    cleanxy(11,0);
  }
  if(key=='*')
  {
    b=a;
    a=0;
    Serial.println("*");
    x=3;
    lcd.setCursor(12,0);
    lcd.print("*");
    cleanxy(11,0);
  }
  if(key=='/')
  {
    b=a;
    a=0;
    Serial.println("/");
    x=4;
    lcd.setCursor(12,0);
    lcd.print("/");
    cleanxy(11,0);
  }
  if(key=='=')
  {
    cleanxy(16,0);
    Serial.println("=");
    lcd.setCursor(0,1);
    lcd.print("=");
    if(x==1)
    {
      Serial.println(a+b);
      lcd.setCursor(1,1);
      lcd.print(a+b);
    }
    if(x==2)
    {
      Serial.println(b-a);
      lcd.setCursor(1,1);
      lcd.print(b-a);
    }
    if(x==3)
    {
      Serial.println(a*b);
      lcd.setCursor(1,1);
      lcd.print(a*b);
    }
    if(x==4)
    {
      Serial.println(b/a);
      lcd.setCursor(1,1);
      lcd.print(b/a);
    }
    a=0;
    b=0;
    x=0;
  }
  if(key=='C')
  {
      clean();
      lcd.setCursor(0,0);
      lcd.print("clean");
      delay(1000);
      clean();
  }
}
void compute2(char key)
{
  if(key>='0'&&key<='9')
  {
    a=a*10+(key-'0');
    Serial.println(a);
    lcd.setCursor(0,0);
    lcd.print(a);
  }
  if(key=='+')
  {
    b=a;
    a=0;
    Serial.println("^");
    x=1;
    lcd.setCursor(12,0);
    lcd.print("^");
    cleanxy(11,0);
  }
  if(key=='-')
  {
    b=a;
    a=0;
    Serial.println("sqrt");
    x=2;
    lcd.setCursor(0,0);
    lcd.print("stop input please");
    delay(2000);
    cleanxy(12,0);
    lcd.setCursor(12,0);
    lcd.print("sqrt");
  }
  if(key=='*')
  {
    b=a;
    a=0;
    Serial.println("sin");
    x=3;
    lcd.setCursor(0,0);
    lcd.print("stop input please");
    delay(2000);
    cleanxy(13,0);
    lcd.setCursor(13,0);
    lcd.print("sin");
  }
  if(key=='/')
  {
    b=a;
    a=0;
    Serial.println("tan");
    x=4;
    lcd.setCursor(0,0);
    lcd.print("stop input please");
    delay(2000);
    cleanxy(13,0);
    lcd.setCursor(13,0);
    lcd.print("tan");
  }
  if(key=='=')
  {
    cleanxy(16,0);
    Serial.println("=");
    lcd.setCursor(0,1);
    lcd.print("=");
    if(x==1)
    {
      Serial.println(pow(b,a));
      lcd.setCursor(1,1);
      lcd.print(pow(b,a));
    }
    if(x==2)
    {
      double sum;
      sum=sqrt(b);
      Serial.println(sum);
      lcd.setCursor(1,1);
      lcd.print(sum);
    }
    if(x==3)
    {
      Serial.println(sin(b));
      lcd.setCursor(1,1);
      lcd.print(sin(b));
    }
    if(x==4)
    {
      Serial.println(tan(b));
      lcd.setCursor(1,1);
      lcd.print(tan(b));
    }
    a=0;
    b=0;
    x=0;
  }
  if(key=='C')
  {
      clean();
      lcd.setCursor(0,0);
      lcd.print("clean");
      delay(1000);
      clean();
  }
}
void home()
{
  meau=0;
  clean();
  lcd.setCursor(0,0);
  lcd.print("menu");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("1:compute 1.0");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("2:compute 2.0");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("3:reckon by time");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("4:timing");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("5:equation 1.0");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("6:equation 2.0");
  delay(2000);
  cleanxy(16,1);
  lcd.setCursor(0,1);
  lcd.print("7:Quality factor");
  delay(2000);
  cleanxy(16,0);
  cleanxy(16,1);
  lcd.setCursor(0,0);
  lcd.print("Fighting!");
  delay(2000);
  for(int i=0;i<=7;i++)
  {
    lcd.setCursor(i*2,1);
    lcd.write(i);
    delay(1000);
  }
}
void reckon()
{
  lcd.setCursor(0,0);
  lcd.print("time:");
  delay(1000);
  if(timex==0)time++;
  lcd.setCursor(0,1);
  lcd.print(time);
}
void timing()
{
  time--;
  lcd.setCursor(0,1);
  lcd.print(time);
  delay(1000);
  cleanxy(16,1);
}
void equation1(char key)
{
  lcd.setCursor(0,0);
  if(key>='0'&&key<='9')
  {
    cleanxy(16,0);
    lcd.print("in:");
    a=a*10+(key-'0');
    Serial.println(a);
    lcd.setCursor(3,0);
    lcd.print(a);
  }
  if(key=='+')
  {
    b=a;
    a=0;
    x=1;
    cleanxy(16,0);
  }
  if(key=='-')
  {
    cleanxy(16,0);
    a=-a;
    lcd.print("in:");
    Serial.println(a);
    lcd.setCursor(3,0);
    lcd.print(a);
  }
  if(key=='=')
  {
    cleanxy(16,0);
    lcd.setCursor(0,0);
    lcd.print(b);
    lcd.setCursor(11,0);
    lcd.print("x+");
    delay(2000);
    cleanxy(16,0);
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(11,0);
    lcd.print("=0");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("x=");
    lcd.setCursor(2,1);
    if(b!=0)lcd.print((-a)/b);
    else if(b==0&&a==0)lcd.print("Any number");
    else if(b==0&&a!=0)lcd.print("unsolvable");
  }
  if(key=='C')
  {
    clean();
    lcd.setCursor(0,0);
    lcd.print("clean");
    delay(1000);
    clean();
  }
}
void equation2(char key)
{
  lcd.setCursor(0,0);
  if(key>='0'&&key<='9')
  {
    cleanxy(16,0);
    lcd.print("in:");
    a=a*10+(key-'0');
    Serial.println(a);
    lcd.setCursor(3,0);
    lcd.print(a);
  }
  if(key=='+')
  {
    if(x==0)
    {
      b=a;a=0;x=1;
    }
    else if(x==1)
    {
      c=a;a=0;x=2;
    }
    cleanxy(16,0);
  }
  if(key=='-')
  {
    cleanxy(16,0);
    a=-a;
    lcd.print("in:");
    Serial.println(a);
    lcd.setCursor(3,0);
    lcd.print(a);
  }
  if(key=='=')
  {
    cleanxy(16,0);
    lcd.setCursor(0,0);
    lcd.print(b);
    lcd.setCursor(11,0);
    lcd.print("x^2+");
    delay(2000);
    cleanxy(16,0);
    lcd.setCursor(0,0);
    lcd.print(c);
    lcd.setCursor(11,0);
    lcd.print("x+");
    delay(2000);
    cleanxy(16,0);
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(11,0);
    lcd.print("=0");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("x1=");
    lcd.setCursor(3,1);
    lcd.print((-c+sqrt(c*c-4*b*a))/2*b);
    delay(2000);
    cleanxy(16,1);
    lcd.setCursor(0,1);
    lcd.print("x2=");
    lcd.setCursor(3,1);
    lcd.print((-c-sqrt(c*c-4*b*a))/2*b);
  }
  if(key=='C')
  {
    clean();
    lcd.setCursor(0,0);
    lcd.print("clean");
    delay(1000);
    clean();
  }
}
void Quality(char key)
{
  if(key>='0'&&key<='9')
  {
    cleanxy(16,0);
    a=a*10+(key-'0');
    Serial.println(a);
    lcd.setCursor(0,0);
    lcd.print(a);
  }
  if(key=='C')
  {
    clean();
    lcd.setCursor(0,0);
    lcd.print("clean");
    delay(1000);
    clean();
  }
  if(key=='=')
  {
    lcd.setCursor(10,0);
    lcd.print("=");
    for(long i=2;i<=a;i++)
    {
      if(a%i==0)
      {
        cleanxy(16,1);
        lcd.setCursor(0,1);
        lcd.print(i);
        a=a/i;
        i--;
        if(i<a)
        {
          lcd.setCursor(15,1);
          lcd.print("*");
        }
        delay(1000);
      }
    }
    cleanxy(16,1);
    lcd.setCursor(0,1);
    lcd.print("finish");
    a=0;
  }
}
void setup()
{
  Serial.begin(9600);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  lcd.init(); //初始化LCD
  lcd.backlight(); //打开背光
  lcd.createChar(0, Heart);
  lcd.createChar(1, Bell);
  lcd.createChar(2, Alien);
  lcd.createChar(3, Check);
  lcd.createChar(4, Speaker);
  lcd.createChar(5, Sound);
  lcd.createChar(6, Skull);
  lcd.createChar(7, Lock);
  lcd.setCursor(0,0);
  lcd.print("Calculator 2.0");
  lcd.setCursor(0,1);
  lcd.print("By:Qiao and YBR");
  delay(3000);
  clean();
  home();
}
void loop()
{
    char key = keypad.getKey();
    int sV=digitalRead(12);
    if(key=='1'&&meau==0)
    {
      meau=1;
      clean();
      delay(1000);
    }
    if(key=='2'&&meau==0)
    {
      meau=2;
      clean();
      delay(1000);
    }
    if(key=='3'&&meau==0)
    {
      meau=3;
      clean();
      delay(1000);
      time=0;timex=0;
    }
    if(key=='4'&&meau==0)
    {
      meau=4;
      clean();
      delay(1000);
      time=0;
    }
    if(key=='5'&&meau==0)
    {
      meau=5;
      clean();
      delay(1000);
    }
    if(key=='6'&&meau==0)
    {
      meau=6;
      clean();
      delay(1000);
    }
    if(key=='7'&&meau==0)
    {
      meau=7;
      clean();
      delay(1000);
    }
    if(meau==1)
    {
      compute(key);
    }
    if(meau==2)
    {
      compute2(key);
    }
    if(meau==3)
    {
      reckon();
      if(key=='C')
      {
        if(timex==0)timex=1;
        else timex=0;
      }
    }
    if(meau==4)
    {
      if(key>='0'&&key<='9')
      {
        time=time*10+(key-'0');
        Serial.println(time);
        cleanxy(16,0);
        lcd.setCursor(0,0);
        lcd.print(time);
      }
      if(key=='=')
      {
        while(time>0)
        {
          timing();
          if(time==0)
          {
            lcd.setCursor(0,0);
            lcd.print("end");
          }
        }
      }
      if(key=='C')
      {
        time=0;
        clean();
      }
    }
    if(meau==5)
    {
      equation1(key);
    }
    if(meau==6)
    {
      equation2(key);
    }
    if(meau==7)
    {
      Quality(key);
    }
    if(sV==LOW)
    {
      home();
    }
}

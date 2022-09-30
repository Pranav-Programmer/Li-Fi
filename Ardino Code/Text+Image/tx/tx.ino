#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
SoftwareSerial GSerial(11,12); 
//*************************************************
int arr_count=0,i;
unsigned char arr[1027];
char cmd_arr2[100];
int rec_flag1=0;
int rec_flag2=0;
int buttonPin1=10;
int buttonPin2=3;
int buttonState = 0; 
//*************************************************
void serial_get_command()
{
  int i;
  int cmd_count=0;
  char inchar=0;
  char cmd_arr[30];
  if(Serial.available() > 0)
  {
    inchar = Serial.read();    
    if(inchar == '{')
    { 
      arr[0]=128;arr[1]=64;
      arr_count=2;
      while(inchar != '}')
      {
        if(Serial.available() > 0)
        {
          inchar = Serial.read();
          if(inchar=='x' || inchar=='X')
          {
            while(Serial.available()==0);
            cmd_arr[2]=Serial.read();
            while(Serial.available()==0);
            cmd_arr[3]=Serial.read();
            cmd_arr[0]='0';cmd_arr[1]='x';cmd_arr[4]='\0';
            uint8_t intVal;
            sscanf(cmd_arr, "%x", &intVal);
            //Serial.print("Received : ");Serial.println(intVal);
            arr[arr_count++]=intVal;
            arr[arr_count]='\0';
          }
        }        
      }
      if(inchar == '}')
      {
        Serial.print(F("Count : "));Serial.println(arr_count);
        for(i=0;i<arr_count;i++)
        {
          /*Serial.print(i);Serial.print(":");*/Serial.print(arr[i]);
        }
        lcd.clear();lcd.print(F("Received : "));lcd.print(arr_count);
        rec_flag1=1;
        //Serial.print("Cmd received : ");Serial.print(cmd_arr);Serial.print("cmd value : ");Serial.println(cmd_count);  
      }
      else
      {
        //Serial.println("<EE04>");    
      }
      // cmd_count=7 for command <xxyyyy>  
    }

    if(inchar == '<')
    {
      cmd_count=0;
      while(inchar != '>' && cmd_count<200)
      {
        if(Serial.available() > 0)
        {
          inchar = Serial.read();
          cmd_arr2[cmd_count++] = inchar;
          cmd_arr2[cmd_count] = '\0';
        }        
      }
      if(inchar == '>')
      {
        rec_flag2=1;
        cmd_arr2[cmd_count-1] = '\0';
        Serial.print(F("Text Received : "));Serial.println(cmd_arr2);
        lcd.clear();lcd.print(F("Rec. Text: "));lcd.print(cmd_count-1);
      }
      else
      {
        Serial.println(F("<EE04>"));    
      }
      // cmd_count=7 for command <xxyyyy>  
    }

    
  }
}
//*****************************************
void setup()
{
  Serial.begin(57600);
  Serial.println("Program Started");
  pinMode(buttonPin1, INPUT);digitalWrite(buttonPin1, HIGH);
  pinMode(buttonPin2, INPUT);digitalWrite(buttonPin2, HIGH);
  GSerial.begin(400);
  lcd.begin(16, 2);
  lcd.print(F("LiFiVerse"));
  delay(4000);
  lcd.clear(); 
}
//*****************************************
void loop()
{
  serial_get_command();     
  if(rec_flag1==1)
  {
    buttonState = digitalRead(buttonPin1);
    if (buttonState == LOW)
    {
      lcd.setCursor(0, 1);lcd.print(F("Sending Image..."));
      delay(1000);
      GSerial.print(F("<"));
      for(i=0;i<arr_count;i++)
      {
        GSerial.write(arr[i]);
        buttonState = digitalRead(buttonPin1);
        if (buttonState == LOW)
        {
          i=2000; 
        }
      }
      GSerial.print(F(">"));
      delay(1000);
      lcd.setCursor(0, 1);lcd.print(F("                "));
    }
  }

  if(rec_flag2==1)
  {
    buttonState = digitalRead(buttonPin2);
    if (buttonState == LOW)
    {
      lcd.setCursor(0, 1);lcd.print(F("Sending Text... "));
      delay(1000);
      GSerial.print(F("{"));
      GSerial.print(cmd_arr2);
      GSerial.print(F("}"));
      delay(1000);
      lcd.setCursor(0, 1);lcd.print(F("                "));
    }
  }
}
//*****************************************

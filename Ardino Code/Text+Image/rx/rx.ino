#include <openGLCD.h>
#include <include/openGLCD_GLCDv3.h> // GLCDv3 compatibilty mode
#include "fonts/allFonts.h" 
#include <SoftwareSerial.h>
SoftwareSerial GSerial(2,3); 

//*************************************************
unsigned char cmd_arr[1050];
char cmd_arr2[100];
int cmd_count=0;
char inchar;
//*************************************************

void DrawBitmap2(Image_t bitmap, uint8_t x, uint8_t y, uint8_t color);

void serial_get_command()
{
  char inchar=0;

  if(GSerial.available() > 0)
  {
    inchar = GSerial.read();    
    if(inchar == '<')
    {
      GLCD.ClearScreen();
      GLCD.print("Receiving...Image");
      cmd_count=0;
      while(inchar != '>' && cmd_count<1050)
      {
        if(GSerial.available() > 0)
        {
          inchar = GSerial.read();
          cmd_arr[cmd_count++] = inchar;
          cmd_arr[cmd_count] = '\0';
        }        
      }
      if(inchar == '>')
      {
        GLCD.ClearScreen();
        GLCD.print("Received...Image");
        delay(2000);
        //GLCD.print("Received : ");GLCD.print(cmd_arr);
        //Serial.print("Cmd received : ");Serial.print(cmd_arr);Serial.print("cmd value : ");Serial.println(cmd_count);  
        DrawBitmap2(cmd_arr, 0,0,BLACK);
        delay(5000);
      }
      else
      {
        Serial.println("<EE04>");    
      }
      // cmd_count=7 for command <xxyyyy>  
    }
   if(inchar == '{')
   {
      GLCD.ClearScreen();
      GLCD.print("Receiving...Text");
      cmd_count=0;
      while(inchar != '}' && cmd_count<1050)
      {
        if(GSerial.available() > 0)
        {
          inchar = GSerial.read();
          cmd_arr2[cmd_count++] = inchar;
          //Serial.print(cmd_arr2);
          cmd_arr2[cmd_count] = '\0';
        }        
      }
      if(inchar == '}')
      {
        cmd_arr2[cmd_count-1] = '\0';
        GLCD.ClearScreen();
        GLCD.print("Received...Text");
        //Serial.print("Cmd received : ");Serial.print(cmd_arr2);Serial.print("cmd value : ");Serial.println(cmd_count);  
        delay(1000);
        GLCD.ClearScreen();
        GLCD.print(cmd_arr2);
        //GLCD.print("Received : ");GLCD.print(cmd_arr);
        //Serial.print("Cmd received : ");Serial.print(cmd_arr2);Serial.print("cmd value : ");Serial.println(cmd_count);  
        delay(5000);
      }
      else
      {
        Serial.println("<EE04>");    
      }
      // cmd_count=7 for command <xxyyyy>  
    }
  } 
 }

//*************************************************
void DrawBitmap2(Image_t bitmap, uint8_t x, uint8_t y, uint8_t color)
{
uint8_t width, height;
uint8_t i, j;

  width = *bitmap++; 
  height = *bitmap++;

#ifdef BITMAP_FIX // temporary ifdef just to show what changes if a new 
        // bit rendering routine is written.
              
  /*
   * In the absence of a new/better/proper bitmap rendering routine,
   * this routine will provide a temporary fix for drawing bitmaps that are
   * are non multiples of 8 pixels in height and start on non LCD page Y addresses.
   *
   * Note: nomally a routine like this should not have knowledge of how
   *     how the lower level write routine works. But in this case it does.
   *
   *  Currently, the low level WriteData() routine ORs in the pixels when data spans
   *  a LCD memory page. So.....
   *
   * In order to ensure that the bitmap data is written to the pixels *exactly* as it
   * it defined in the bitmap data, i.e every black pixels is black and every white
   * pixel is white,...
   *
   * If height or y coordinate is not on a page boundary, clear the background first
   *  Techincally, this could be done all the time and it wouldn't hurt, it
   *  would just suck up a few more cycles.
   */
  if( (y & 7) || (height & 7))
  {
    this->FillRect(x, y, width, height, PIXEL_OFF);
  }
  for(j = 0; j < ((height+7) / 8); j++)
#else
  for(j = 0; j < height / 8; j++)
#endif
  {
  GLCD.GotoXY(x, y + (j*8) );
  for(i = 0; i < width; i++)
  {
     uint8_t displayData = *bitmap++;
       if(color == BLACK)
      GLCD.WriteData(displayData);
     else
        GLCD.WriteData(~displayData);
  }
  }
}
//*****************************************
void glcd_init()
{
  GLCD.Init();
}
//*****************************************
void welcome_page()
{
  GLCD.CursorTo(0, 2);
  GLCD.SelectFont(System5x7);
  GLCD.print("         LiFiVerse");  
  delay(3000);
  GLCD.ClearScreen();
}
//*****************************************
void setup()
{
  Serial.begin(57600);
  Serial.println("Program Started");
  GSerial.begin(400);
  glcd_init();
  welcome_page();
}
//*****************************************
void loop()
{
  serial_get_command();     
  /*if(GSerial.available() > 0)
  {
    inchar = GSerial.read();   
    GLCD.print(inchar);
  }
  */
}
//*****************************************

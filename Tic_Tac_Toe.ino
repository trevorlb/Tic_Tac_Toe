

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include "Hardware.h"
#define TFT_CS     10
#define TFT_RST    9  
#define TFT_DC     8
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
#define TFT_SCLK 13  
#define TFT_MOSI 11   
int h = tft.height();
int w = tft.width();
Hardware tic;
int d = 500;
int k = 0;
int used [3][3];
int c = 0;
boolean gameOver = false;
boolean xWin = false;
boolean oWin = false;

void setup(void) {
  Serial.begin(115200);
  tic = Hardware();
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_WHITE);
}

void loop() {
    while (!gameOver)
    {
    drawGrid();
    if (k == 0)
    placeX();
    if (k == 1)
    placeO();
    endGame();
    }
    tft.fillRect(0,0,200,200,ST7735_WHITE);
    delay(1000);
    endScreen();   
}
void drawGrid(){
  tft.drawLine(43,5,43,155,ST7735_BLACK);
  tft.drawLine(86,5,86,155,ST7735_BLACK);
  tft.drawLine(5,53,123,53,ST7735_BLACK);
  tft.drawLine(5,106,123,106,ST7735_BLACK);
}

void drawX (int x, int y){
    tft.drawLine(x-19,y-20,x+18,y+19,ST7735_RED);
    tft.drawLine(x-19,y+20,x+18,y-19,ST7735_RED);
    }

 void placeX (){
     int x1 = -1000;
     int y1;
    if (tic.getSlideVal() == 1)
        y1 = 133;
    if (tic.getSlideVal() == 2)
        y1 = 80;
    if (tic.getSlideVal() == 3)
        y1 = 27;
    if (tic.button1Pressed())
        {x1 = 22;
        if (used[0][tic.getSlideVal()-1] == 0){ 
        drawX(x1,y1);
        k += 1;
        used[0][tic.getSlideVal()-1] = 1;}
        delay(d);}
    if (tic.button2Pressed())
        {x1 = 65;
        if (used[1][tic.getSlideVal() - 1] == 0){ 
        drawX(x1,y1);
        k += 1;
        used[1][tic.getSlideVal() - 1] = 1;}
        delay(d);} 
    if (tic.button3Pressed())
        {x1 = 108;
        //c = (3*5) + tic.getSlideVal();
        if (used[2][tic.getSlideVal()-1] == 0){ 
        drawX(x1,y1);
        k += 1;
        //used[2][tic.getSlideVal() -1] = 1;
        used[2][tic.getSlideVal()-1] = 1;}
        delay(d);}
 }
    
void placeO (){
     int x1 = -1000;
     int y1;
    if (tic.getSlideVal() == 1)
        y1 = 133;
    if (tic.getSlideVal() == 2)
        y1 = 80;
    if (tic.getSlideVal() == 3)
        y1 = 27;
    if (tic.button1Pressed())
        {x1 = 22;
        if (used[0][tic.getSlideVal()-1] == 0){ 
        drawO(x1,y1);
        k -= 1;
        used[0][tic.getSlideVal()-1] = 2;}
        delay(d);}
    if (tic.button2Pressed())
        {x1 = 65;
        if (used[1][tic.getSlideVal() - 1] == 0){ 
        drawO(x1,y1);
        k -= 1;
        used[1][tic.getSlideVal() - 1] = 2;}
        delay(d);}
    if (tic.button3Pressed())
        {x1 = 108;
        if (used[2][tic.getSlideVal()-1] == 0){ 
        drawO(x1,y1);
        k -= 1;
        used[2][tic.getSlideVal()-1] = 2;}
        delay(d);}      
}   

void drawO (int x, int y){
    tft.drawCircle(x-1,y,18,ST7735_BLUE);
}
void endGame(){
    if (used[0][0] == 1 && used[0][1] == 1 && used[0][2] == 1){
        gameOver = true;
        xWin = true; 
        tft.drawLine(22,5,22,123,ST7735_RED); 
    }
    if (used[1][0] == 1 && used[1][1] == 1 && used[1][2] == 1){
        gameOver = true;
        xWin = true;  
    }
    if (used[2][0] == 1 && used[2][1] == 1 && used[2][2] == 1){
        gameOver = true; 
        xWin = true; 
    }
    if (used[0][0] == 1 && used[1][0] == 1 && used[2][0] == 1){
        gameOver = true; 
        xWin = true; 
    }
    if (used[0][1] == 1 && used[1][1] == 1 && used[2][1] == 1){
        gameOver = true; 
        xWin = true; 
    }
    if (used[0][2] == 1 && used[1][2] == 1 && used[2][2] == 1){
        gameOver = true; 
        xWin = true; 
    }
    if (used[0][0] == 1 && used[1][1] == 1 && used[2][2] == 1){
        gameOver = true; 
        xWin = true; 
    }
    if (used[0][2] == 1 && used[1][1] == 1 && used[2][0] == 1){
        gameOver = true; 
        xWin = true; 
    }
    ////////////////////////////////////////////////
    if (used[0][0] == 2 && used[0][1] == 2 && used[0][2] == 2){
        gameOver = true;
        oWin = true;  
    }
    if (used[1][0] == 2 && used[1][1] == 2 && used[1][2] == 2){
        gameOver = true;
        oWin = true;  
    }
    if (used[2][0] == 2 && used[2][1] == 2 && used[2][2] == 2){
        gameOver = true; 
        oWin = true; 
    }
    if (used[0][0] == 2 && used[1][0] == 2 && used[2][0] == 2){
        gameOver = true; 
        oWin = true; 
    }
    if (used[0][1] == 2 && used[1][1] == 2 &&  used[2][1] == 2){
        gameOver = true; 
        oWin = true; 
    }
    if (used[0][2] == 2 && used[1][2] == 2 && used[2][2] == 2){
        gameOver = true; 
        oWin = true; 
    }
    if (used[0][0] == 2 && used[1][1] == 2 && used[2][2] == 2){
        gameOver = true; 
        oWin = true; 
    }
    if (used[0][2] == 2 && used[1][1] == 2 && used[2][0] == 2){
        gameOver = true; 
        oWin = true; 
    }
    
}
    void endScreen(){
        
        if (xWin){
            for (int i = 0; i < 100; i+=5){
            tft.fillCircle(65,80,10+i,ST7735_RED);
            }
            delay(1000);
        }
        if (oWin){
            for (int i = 0; i < 100; i+=5){
            tft.fillCircle(65,80,10+i,ST7735_BLUE);}
            delay(1000);
        
        
    }
    }

 

    
    
    


    




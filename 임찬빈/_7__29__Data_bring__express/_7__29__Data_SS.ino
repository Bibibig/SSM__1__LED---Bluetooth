#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 9); //Connect HC-06 TX,RX
//RX 핀 6번 꽂읅
//Pin connected to ST_CP of 74HC595
int HoldPin_1 = 8;
int HoldPin_2 = 4;
//Pin connected to SH_CP of 74HC595
int ShiftPin_1 = 12;
int ShiftPin_2 = 7;
////Pin connected to DS of 74HC595
int DataPin_1 = 11;
int DataPin_2 = 6;
boolean buffer_flag = false;

 int l,m;

   boolean dot0[8][8];
boolean (*(arr[4]))[8];


#define numOfRegisterPins 8

boolean registers[numOfRegisterPins];

//temp array for testing


void setup(){
  l,m=0;
   
  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);
  
  pinMode(DataPin_1, OUTPUT);
  pinMode(HoldPin_1, OUTPUT);
  pinMode(ShiftPin_1, OUTPUT);
  
  pinMode(DataPin_2, OUTPUT);
  pinMode(HoldPin_2, OUTPUT);
  pinMode(ShiftPin_2, OUTPUT);

  //reset all register pins
  clearMatrix();
  writeMatrix(1);
  writeMatrix(2);

  delay(1);
}              

//set all register pins to HIGH
void clearMatrix(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
}

/* set 74HC595 and out
    index:1 - select row shift register
    index:2 - select column shift register */
void writeMatrix(int index){
  if (index == 1) {
    digitalWrite(HoldPin_1, LOW);
    for(int i = numOfRegisterPins - 1 ; i >= 0; i--){
      digitalWrite(ShiftPin_1, LOW);
      int val = registers[i];
      digitalWrite(DataPin_1, val);
      digitalWrite(ShiftPin_1, HIGH);
    }
    digitalWrite(HoldPin_1, HIGH);
  }
  else if (index == 2) {
    digitalWrite(HoldPin_2, LOW);
    for(int i = numOfRegisterPins - 1; i >= 0; i--){
      digitalWrite(ShiftPin_2, LOW);
      int val = registers[i];
      digitalWrite(DataPin_2, val);
      digitalWrite(ShiftPin_2, HIGH);
    }
    digitalWrite(HoldPin_2, HIGH);
  } else {
    //nothing
  }
}

/* Set one line register
    line: line number
    dot[8]: LED set to On/Off */
void setLineMatrix(int line, boolean dot[8]) {
    
  clearMatrix(); //prevent flicker
  writeMatrix(2);
  
  boolean col[8] = {0,0,0,0,0,0,0,0};
  col[line] = 1; // select one line
  for (int i = 0; i < 8; i++) { //set line
    registers[i] = col[i];
  }
  writeMatrix(1);
  for (int i = 0; i < 8; i++) { //set dots
    registers[i] = dot[i];
  }
  writeMatrix(2);
  delay(1); //delay for readability
}

/* set matrix
    dot[8][8]: matrix array
    delay: display time (ms) */
void setFullMatrixTime(boolean dot[8][8], int mdelay) {
  boolean col[8] = {};
  int i,j;
  unsigned long endTimer = millis() + mdelay;
  
  while(millis() < endTimer) {
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        col[j] = dot[i][j];      
      }
      setLineMatrix(i, col);    
    }
  }
}

void loop(){
  
 
                      /*  {{1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1}}; */
                        
  boolean dot1[8][8] = {{0,1,1,1,1,1,1,0},
                        {1,0,1,1,1,1,0,1},
                        {1,1,0,1,1,0,1,1},
                        {1,1,1,0,0,1,1,1},
                        {1,1,1,0,0,1,1,1},
                        {1,1,0,1,1,0,1,1},
                        {1,0,1,1,1,1,0,1},
                        {0,1,1,1,1,1,1,0},};
  
   boolean dot2[8][8] = {{1,1,0,0,0,0,1,1},
                         {1,0,1,1,1,1,0,1},
                         {0,1,1,1,1,1,1,0},
                         {0,1,1,1,1,1,1,0},
                         {0,1,1,1,1,1,1,0},
                         {0,1,1,1,1,1,1,0},
                         {1,0,1,1,1,1,0,1},
                         {1,1,0,0,0,0,1,1},};
   
  // display during 1 second
//  boolean (*arr[4])(*)[8];
  //arr[0] = dot0;
  
  if(BTSerial.available()) {
    
     char toSend= (char)BTSerial.read();
       Serial.print(toSend);
       Serial.print(dot0[0][0]);
 if(1)
 {  dot0[l][m]=(char)toSend-48;
 
    m++;
   if(m==8)
  {
    m=0;
    l++;
  } 
   if(l==8)
   {
     m=0;l=0;
   }
 }
  }
   /* dot0[l][m]=(boolean)toSend;
 
    m++;
   if(m==8)
  {
    m=0;
    l++;
  } 
   if(l==8)
   {
     m=0;l=0;
   }
   */

    
    
    
    
    
    
   /*    if(toSend == 'S') {
      
         
       }
       */
       
       
     
     
  
      
      
      
     /* Serial.println(toSend);
      if(1){
      if(toSend=='a'){
      setFullMatrixTime(dot0,1000);
      delay(2000);
      };}
      else{

      };
      */
      
      
   
  setFullMatrixTime(dot0,5);
 // setFullMatrixTime(dot1,200);
 // setFullMatrixTime(dot2,200);
}
/*
int saveArr()
{
  int dotIdx = 0;
  int i = 0;
  int j = 0;
  while(BTSerial.available()) {
    arr[dotIdx][i][j++] = (boolean)BTSerial.read();
    Serial.print(arr[dotIdx][i][j-1] + " ");
    if(j == 8) {
      i++;
      j = 0;
      Serial.println("");
    }
    if(i == 8)
    {
      break;
    }
  }
}
*/


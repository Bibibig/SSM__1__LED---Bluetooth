//#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(14,15); //Connect HC-06 TX,RX
//RX 핀 9번 꽂읅


int clock_1 = 7;  //74HC595의 클럭핀과 연결 
int clock_2 = 12;

int latch_1 = 4;    //74HC595의 래치핀과 연결 
int latch_2 = 8;

int data_1 = 6;  //74HC595의 데이터핀과 연결
int data_2 = 11;
int sum;
int k,l,j,i=0;
int buffer[6];
int flag=0;
int NUM=0;
//int received_data[10];
//boolean flag;

int count=0;

int dataval[2][8]={ 
    {0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3}};  //조금 벌린입 
int dataval_2[2][8]={ 
    {0x3,0x5f,0x1f,0xff,0x7f,0x1f,0x9f,0xff},  //다문입 
    {0x9f,0x6f,0x6f,0x9f,0xff,0x7f,0x7f,0x3}};  //조금 벌린입 
    int dataval_3[2][8]={ 
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},  //다문입 
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}};  //조금 벌린입 
    
void setup(){ 
  Serial.begin(9600);
  Serial.println("Hello!");
  //BTSerial.begin(9600);
  Serial3.begin(9600);
  pinMode(clock_1, OUTPUT); 
  pinMode(latch_1, OUTPUT); 
  pinMode(data_1, OUTPUT);
 
  pinMode(clock_2, OUTPUT); 
  pinMode(latch_2, OUTPUT); 
  pinMode(data_2, OUTPUT); 
  
} 
void loop(){ 
 // Serial.println("BBH");
   
  /*{0x99,0x66,0xff,0xff,0xc3,0xe7,0xff,0xff}, 
    {0x99,0x66,0xff,0xff,0xc3,0xdb,0xe7,0xff},   
    {0x99,0x66,0xff,0xff,0x81,0xdb,0xe7,0xff}, 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0xc3,0xff}, 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3}};  //크게 벌린입 
 */
  int scanval[8] ={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 
  
  if(Serial3.available())
  { flag=2;
    char data;
    data=Serial3.read();
    
    if(data!='a')
    {
      if(count==0)
      {
        buffer[0]=data;
        count++;
        NUM=1;
      }
      else if(count==1)
      {
        buffer[1]=data;
        count++;
        NUM=2;
      }
      else if(count==2)
      {
        buffer[2]=data;
        count=0;
        NUM=3;
      }
    }
    if(data=='a')
    {
    //  flag=true;
      count=0;
      if(NUM==1)
      {
        sum=buffer[0]-48;
      }
      if(NUM==2)
      {
        sum=(buffer[0]-48)*10 + (buffer[1]-48);
      }
      if(NUM==3)
      {
        sum=(buffer[0]-48)*100
           +(buffer[1]-48)*10
           +(buffer[2]-48);
     //      Serial.print("buffer[0]:  ");
    //       Serial.println(buffer[0]);
      //     Serial.print("buffer[1]:  ");
     //      Serial.println(buffer[1]);
     //      Serial.print("buffer[2]:  ");
     //      Serial.println(buffer[2]);
    //       Serial.print("sum:  ");
    //       Serial.println(sum);
      }
      dataval[k][l]=sum;
      char buffer[6]={0,};
      l++;
      if(l==8)
      {
        k++;
        l=0;
      }
      if(k==2)
    {
      flag=3;
      k=0;
      l=0;
      
   Serial.println("AAS");
     
    }
    }

     
  


  }

 
 if(flag==3){//값  받앚짐
   Serial.println("BAS");
    for(int i = 0; i<8; i++){ 
      digitalWrite(latch_1, LOW);    
      shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
      shiftOut(data_1,clock_1,LSBFIRST, dataval[0][i]);  
      digitalWrite(latch_1, HIGH);   
      
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval[1][i]);  
      digitalWrite(latch_2, HIGH);   
   //   delay(1); 
     }
     digitalWrite(latch_1, LOW);    
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH); 
     
      digitalWrite(latch_2, LOW);    
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH);     
 
     
  }
  
 else if(flag==2)//뎅잍 받을 롣
  {
    for(int i = 0; i<8; i++){ 
      digitalWrite(latch_1, LOW);    
      shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
      shiftOut(data_1,clock_1,LSBFIRST, dataval_2[0][i]);  
      digitalWrite(latch_1, HIGH);   
      
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval_2[1][i]);  
      digitalWrite(latch_2, HIGH);   
   //   delay(1); 
     }
     digitalWrite(latch_1, LOW);    
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH); 
     
      digitalWrite(latch_2, LOW);    
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH);     
 
  }
  else//평상
  {
     for(int i = 0; i<8; i++){ 
      digitalWrite(latch_1, LOW);    
      shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
      shiftOut(data_1,clock_1,LSBFIRST, dataval_3[0][i]);  
      digitalWrite(latch_1, HIGH);   
      
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval_3[1][i]);  
      digitalWrite(latch_2, HIGH);   
   //   delay(1); 
     }
     digitalWrite(latch_1, LOW);    
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH); 
     
      digitalWrite(latch_2, LOW);    
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH);     
 
     
 
  }
  }

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

int received_data[10];
boolean is_received;

int count=0;

int dataval[2][8]={ 
    {0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3}};  //조금 벌린입 
    
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
  { 
    int data;
    data=Serial3.read()-48;
    Serial.println("AAH");
    if(data!=5)
   {
     if(count==0)
     {
       received_data[0]=data*128;
       Serial.print("data[0]");
       Serial.println(received_data[0]);
        count++;
     }
     else if(count==1)
     {
       received_data[1]=data*64;
       Serial.print("data[1]");
       Serial.println(received_data[1]);
        count++;
     }
     else if(count==2)
     {
       received_data[2]=data*32;
       Serial.print("data[2]");
       Serial.println(received_data[2]);
        count++;
     }
     
     else if(count==3)
     {
       received_data[3]=data*16;
       Serial.print("data[3]");
       Serial.println(received_data[3]);
        count++;
     }
     
     else if(count==4)
     {
       received_data[4]=data*8;
       Serial.print("data[4]");
       Serial.println(received_data[4]);
        count++;
     }
     
     else if(count==5)
     {
       received_data[5]=data*4;
       Serial.print("data[5]");
       Serial.println(received_data[5]);
        count++;
     }
     
     else if(count==6)
     {
       received_data[6]=data*2;
       Serial.print("data[6]");
       Serial.println(received_data[6]);
        count++; 
    }
     
    
     else if(count==7)
     {
       received_data[7]=data;
       Serial.print("data[7]");
       Serial.println(received_data[7]);
       
       sum=received_data[0]+received_data[1]+received_data[2]+received_data[3]+
           received_data[4]+received_data[5]+received_data[6]+received_data[7];
       Serial.print("sum");
       Serial.println(sum);
        dataval[k][l]=sum;
       Serial.print("dataval");
         Serial.print("[");
          Serial.print(k);
            Serial.print("]");
              Serial.print("[");
               Serial.print(l);
                 Serial.print("]");
                   Serial.println(dataval[k][l]); 
        l++;
        count=0;
        if(l==8)
        {
          l=0;
          k++;
        }
        if(k==2)
        {
          k=0;
          l=0;
          
        }
           
     }
    
    // received_data+=data;
   } 
   else// if i received stop message
   {
     //received_data+=data;
     //Serial.println(received_data);
     is_received = true;
   }
   
   if(is_received)
   {
    // Serial.println(received_data);
    // BTSerial.println(received_data);
     
   /*  is_received=false;
     if(received_data =="move forward")
     {
       //is_movind_forward=true;
     }
     else if(received_data=="stop")
     {
     //  is_moving_forward=false;
     }*/
     
    // received_data="";
   
   }
   
  }

  
    for(int i = 0; i<8; i++){ 
      digitalWrite(latch_1, LOW);    
      shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
      shiftOut(data_1,clock_1,LSBFIRST, dataval[0][i]);  
      digitalWrite(latch_1, HIGH);   
      
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval[1][i]);  
      digitalWrite(latch_2, HIGH);   
      delay(1); 
     }
   
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval[1][i]);  
      digitalWrite(latch_2, HIGH);   
      delay(1);
    
      
     
     digitalWrite(latch_1, LOW);    
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH); 
     
      digitalWrite(latch_2, LOW);    
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
     digitalWrite(latch_1, HIGH); 
     delay(1);
   
 
}

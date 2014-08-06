int clock_1 = 7;  //74HC595의 클럭핀과 연결 
int clock_2 = 12;

int latch_1 = 4;    //74HC595의 래치핀과 연결 
int latch_2 = 8;

int data_1 = 6;  //74HC595의 데이터핀과 연결
int data_2 = 11;
void setup(){ 
  pinMode(clock_1, OUTPUT); 
  pinMode(latch_1, OUTPUT); 
  pinMode(data_1, OUTPUT);
 
  pinMode(clock_2, OUTPUT); 
  pinMode(latch_2, OUTPUT); 
  pinMode(data_2, OUTPUT); 
} 
void loop(){ 
  int dataval[7][8]={ 
    {0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
    {0x99,0x66,0xff,0xff,0xe7,0xe7,0xff,0xff},  //조금 벌린입 
    {0x99,0x66,0xff,0xff,0xc3,0xe7,0xff,0xff}, 
    {0x99,0x66,0xff,0xff,0xc3,0xdb,0xe7,0xff},   
    {0x99,0x66,0xff,0xff,0x81,0xdb,0xe7,0xff}, 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0xc3,0xff}, 
    {0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3}};  //크게 벌린입 
  int scanval[8] ={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 
  for(int j=0; j<7;j++){ 
    //delay(30);
    for(int i = 0; i<8; i++){ 
      digitalWrite(latch_1, LOW);    
      shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
      shiftOut(data_1,clock_1,LSBFIRST, dataval[j][i]);  
      digitalWrite(latch_1, HIGH);   
      
      digitalWrite(latch_2, LOW);    
      shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
      shiftOut(data_2,clock_2,LSBFIRST, dataval[j][i]);  
      digitalWrite(latch_2, HIGH);   
      delay(1); 
     } 
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
}

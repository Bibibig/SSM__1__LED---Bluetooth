//#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(14,15); //Connect HC-06 TX,RX
//RX 핀 9번 꽂읅
char data;

int clock_1 = 8;  //74HC595의 클럭핀과 연결 
int clock_2 = 11;
int clock_3 = 2;
int clock_4 = 5;
int clock_5 = 22;
int clock_6 = 28;
int clock_7 = 36;
int clock_8 = 42;

int latch_1 = 9;    //74HC595의 래치핀과 연결 
int latch_2 = 12;
int latch_3 = 3;
int latch_4 = 6;
int latch_5 = 24;
int latch_6 = 30;
int latch_7 = 38;
int latch_8 = 44;

int data_1 = 10;  //74HC595의 데이터핀과 연결
int data_2 = 13;
int data_3 = 4;
int data_4 = 7;
int data_5 = 26;
int data_6 = 32;
int data_7 = 40;
int data_8 = 46;

int sum;
int k,l,j,i=0;
int buffer[6];
int flag=0;
int NUM=0;
int count_temp=0;
int count = 0;

int fire_matrix_1[8][8] =  {{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }};

int fire_matrix_2[8][8] = {{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80 },
{ 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80 },
{ 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }};

int fire_matrix_3[8][8] = {{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x07 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0xE0 },
{ 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x07 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0xE0 },
{ 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }};

int fire_matrix_4[8][8] = {{ 0x00, 0x00, 0x00, 0x00, 0x09, 0x05, 0x03, 0x0F },
{ 0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x80, 0xE0 },
{ 0x03, 0x05, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x09, 0x05, 0x03, 0x0F },
{ 0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x80, 0xE0 },
{ 0x03, 0x05, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00 }};

int fire_matrix_5[8][8] = {{ 0x00, 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x1F },
{ 0x00, 0x00, 0x00, 0x10, 0x20, 0x40, 0x80, 0xF0 },
{ 0x03, 0x05, 0x09, 0x11, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x1F },
{ 0x00, 0x00, 0x00, 0x10, 0x20, 0x40, 0x80, 0xF0 },
{ 0x03, 0x05, 0x09, 0x11, 0x00, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00 }};

int fire_matrix_6[8][8] = {{ 0x00, 0x00, 0x21, 0x11, 0x09, 0x05, 0x03, 0x3F },
{ 0x00, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8 },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x21, 0x11, 0x09, 0x05, 0x03, 0x3F },
{ 0x00, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8 },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x00, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00 }};

int fire_matrix_7[8][8] = {{ 0x00, 0x41, 0x21, 0x11, 0x09, 0x05, 0x03, 0x7F },
{ 0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xFC },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x41, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00 },
{ 0x00, 0x41, 0x21, 0x11, 0x09, 0x05, 0x03, 0x7F },
{ 0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xFC },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x41, 0x00, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00 }};

int fire_matrix_8[8][8] = {{ 0x81, 0x41, 0x21, 0x11, 0x09, 0x05, 0x03, 0xFF },
{ 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xFE },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x41, 0x81, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00 },
{ 0x81, 0x41, 0x21, 0x11, 0x09, 0x05, 0x03, 0xFF },
{ 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xFE },
{ 0x03, 0x05, 0x09, 0x11, 0x21, 0x41, 0x81, 0x00 },
{ 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00 }};

int small_fire_1[8][8] = {{ 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00 },
{ 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 },
{ 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00 }};

int small_fire_2[8][8] = {{ 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00 },
{ 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0xE0 },
{ 0x00, 0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x00 },
{ 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0E },
{ 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00 },
{ 0x0E, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00 },
{ 0x00, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00 }};

int small_fire_3[8][8] = {{ 0x00, 0x54, 0x38, 0x7C, 0x38, 0x54, 0x01, 0x00 },
{ 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x00, 0x50, 0xE0 },
{ 0x01, 0x00, 0x01, 0xA8, 0x70, 0xF8, 0x70, 0xA8 },
{ 0xF0, 0xE0, 0x50, 0x00, 0x00, 0x15, 0x0E, 0x1F },
{ 0x00, 0x00, 0x05, 0x03, 0x07, 0x03, 0x05, 0x00 },
{ 0x0E, 0x15, 0x40, 0x80, 0xC0, 0x80, 0x40, 0x00 },
{ 0x2A, 0x1C, 0x3E, 0x1C, 0x2A, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x00 }};

int re_fire_1[8][8] = {{ 0x00, 0x54, 0x00, 0x44, 0x00, 0x54, 0x01, 0x00 },
{ 0x15, 0x00, 0x11, 0x00, 0x15, 0x00, 0x50, 0x00 },
{ 0x01, 0x00, 0x01, 0xA8, 0x00, 0x88, 0x00, 0xA8 },
{ 0x10, 0x00, 0x50, 0x00, 0x00, 0x15, 0x00, 0x11 },
{ 0x00, 0x00, 0x05, 0x03, 0x06, 0x03, 0x05, 0x00 },
{ 0x00, 0x15, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00 },
{ 0x2A, 0x00, 0x22, 0x00, 0x2A, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x15, 0x00, 0x11, 0x00, 0x15, 0x00 }};

int re_fire_2[8][8] = {{ 0x00, 0x54, 0x38, 0x6C, 0x38, 0x54, 0x01, 0x00 },
{ 0x15, 0x0E, 0x1B, 0x0E, 0x15, 0x00, 0x50, 0xE0 },
{ 0x01, 0x00, 0x01, 0xA8, 0x70, 0xD0, 0x70, 0xA8 },
{ 0xB0, 0xE0, 0x50, 0x00, 0x00, 0x15, 0x0E, 0x1B },
{ 0x00, 0x00, 0x05, 0x03, 0x06, 0x03, 0x05, 0x00 },
{ 0x0E, 0x15, 0x40, 0x80, 0xC0, 0x80, 0x40, 0x00 },
{ 0x2A, 0x1C, 0x36, 0x1C, 0x2A, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x15, 0x0E, 0x1B, 0x0E, 0x15, 0x00 }};

int re_fire_3[8][8] = {{ 0x00, 0x54, 0x38, 0x7C, 0x38, 0x54, 0x01, 0x00 },
{ 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x00, 0x50, 0xE0 },
{ 0x01, 0x00, 0x01, 0xA8, 0x70, 0xF8, 0x70, 0xA8 },
{ 0x70, 0xE0, 0x50, 0x00, 0x00, 0x15, 0x0E, 0x1B },
{ 0x00, 0x00, 0x05, 0x03, 0x07, 0x03, 0x05, 0x00 },
{ 0x0E, 0x15, 0x40, 0x80, 0xC0, 0x80, 0x40, 0x00 },
{ 0x2A, 0x1C, 0x36, 0x1C, 0x2A, 0x00, 0x00, 0x00 },
{ 0x00, 0x00, 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x00 }};

int dataval[8][8]={ 
	{0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
	{0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3},
	{0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
	{0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3},
	{0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
	{0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3},
	{0x99,0x66,0xff,0xff,0xc3,0xff,0xff,0xff},  //다문입 
	{0x99,0x66,0xff,0xff,0x81,0xbd,0x99,0xc3}};  //조금 벌린입*/ 

	int dataval_2[2][8] ={ {0x3,0x5f,0x1f,0xff,0x7f,0x1f,0x9f,0xff},  //다문입 
	{0x9f,0x6f,0x6f,0x9f,0xff,0x7f,0x7f,0x3}};  //조금 벌린입 
	int scanval[8] ={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 
	int dataval_3[2][8]={ 
		{0,0,0,0,0,0,0,0},  //다문입 
		{0,0,0,0,0,0,0,0}};  //조금 벌린입 

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

			pinMode(clock_3, OUTPUT); 
			pinMode(latch_3, OUTPUT); 
			pinMode(data_3, OUTPUT);

			pinMode(clock_4, OUTPUT); 
			pinMode(latch_4, OUTPUT); 
			pinMode(data_4, OUTPUT);

			pinMode(clock_5, OUTPUT); 
			pinMode(latch_5, OUTPUT); 
			pinMode(data_5, OUTPUT);

			pinMode(clock_6, OUTPUT); 
			pinMode(latch_6, OUTPUT); 
			pinMode(data_6, OUTPUT);

			pinMode(clock_7, OUTPUT); 
			pinMode(latch_7, OUTPUT); 
			pinMode(data_7, OUTPUT);  

			pinMode(clock_8, OUTPUT); 
			pinMode(latch_8, OUTPUT); 
			pinMode(data_8, OUTPUT);
		} 

		void loop(){ 


			if(Serial3.available())
			{ 
				/*if(flag !=2 ){
				for(int x=0;x<8;x++)
				{
				for(int y=0;y<8;y++)
				{
				dataval[x][y]=0;
				}

				}
				}*/    
				// Serial3.println(Serial3.read());


				flag=4;
				
				data=Serial3.read();
				count_temp++;

				if(data=='b')//Fire Matrix
				{flag=4;
				}
				if(data=='c')
				{flag=5;
				}
				if(data=='d')
				{flag=6;
				}
				Serial.print(data);
				Serial.print(" ");
				if(1)
				{
					if(data!='a'&& data!='e')
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
					else if(data=='a')
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
						}

						dataval[k][l]=sum;
						sum = 0;
						char buffer[6]={0,};

						l++;
						if(l==8)
						{
							k++;
							l=0;
						}
						if(k==8)
						{

							flag=3;
							k=0;
							l=0;
						}
					}
				}

			}
		

		if(flag==3){
			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~dataval[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST, ~dataval[1][i]);  
				digitalWrite(latch_2, HIGH); 

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~dataval[2][i]);  
				digitalWrite(latch_3, HIGH);

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST, ~dataval[3][i]);  
				digitalWrite(latch_4, HIGH);

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~dataval[4][i]);  
				digitalWrite(latch_5, HIGH);

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~dataval[5][i]);  
				digitalWrite(latch_6, HIGH);

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~dataval[6][i]);  
				digitalWrite(latch_7, HIGH);

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST, ~dataval[7][i]);  
				digitalWrite(latch_8, HIGH);  
				//delay(100);
			}
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00); 
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00); 
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00); 
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);
			digitalWrite(latch_8, HIGH); 


		}
		else if(flag==4)//Fire Matrix
		{
			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_1[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_1[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_1[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_1[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_1[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_1[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_1[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_1[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_2[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_2[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_2[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_2[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_2[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_2[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_2[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_2[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_3[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_3[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_3[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_3[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_3[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_3[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_3[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_3[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_4[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_4[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_4[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_4[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_4[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_4[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_4[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_4[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_5[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_5[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_5[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_5[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_5[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_5[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_5[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_5[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_6[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_6[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_6[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_6[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_6[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_6[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_6[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_6[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~fire_matrix_7[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~fire_matrix_7[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~fire_matrix_7[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~fire_matrix_7[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~fire_matrix_7[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~fire_matrix_7[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~fire_matrix_7[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~fire_matrix_7[7][i]);  
				digitalWrite(latch_8, HIGH);   



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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

		}
		else if(flag==5)//smallfire /d/Left
		{
			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~re_fire_1[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~re_fire_1[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~small_fire_1[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~small_fire_1[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~small_fire_1[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~small_fire_1[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~small_fire_1[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~small_fire_1[7][i]);  
				digitalWrite(latch_8, HIGH);   
				delay(2); 
			}
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			
			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~small_fire_2[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~small_fire_2[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~small_fire_2[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~small_fire_2[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~small_fire_2[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~small_fire_2[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~small_fire_2[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~small_fire_2[7][i]);  
				digitalWrite(latch_8, HIGH);   

				delay(2); 
			}
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 
			//delay(100);

			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~small_fire_3[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~small_fire_3[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~small_fire_3[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~small_fire_3[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~small_fire_3[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~small_fire_3[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~small_fire_3[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~small_fire_3[7][i]);  
				digitalWrite(latch_8, HIGH);   

				delay(2); 
			}
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 
			//delay(100);
		}
		else if(flag==6)
		{
			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~re_fire_1[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~re_fire_1[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~re_fire_1[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~re_fire_1[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~re_fire_1[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~re_fire_1[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~re_fire_1[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~re_fire_1[7][i]);  
				digitalWrite(latch_8, HIGH);   

				delay(2); 
			}
			//delay(10);
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

			//delay(500);

			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~re_fire_2[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~re_fire_2[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~re_fire_2[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~re_fire_2[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~re_fire_2[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~re_fire_2[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~re_fire_2[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~re_fire_2[7][i]);  
				digitalWrite(latch_8, HIGH);   

				delay(2); 
			}
			//delay(10);
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 
			//delay(500);

			for(int i = 0; i<8; i++){
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~re_fire_3[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST,  ~re_fire_3[1][i]);  
				digitalWrite(latch_2, HIGH);   

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~re_fire_3[2][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST,~re_fire_3[3][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~re_fire_3[4][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~re_fire_3[5][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~re_fire_3[6][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST,~re_fire_3[7][i]);  
				digitalWrite(latch_8, HIGH);   

				delay(2); 
			}
			//delay(10);
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 
			//delay(500);

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

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, dataval_2[0][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST, dataval_2[1][i]);  
				digitalWrite(latch_4, HIGH);   

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, dataval_2[0][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, dataval_2[1][i]);  
				digitalWrite(latch_6, HIGH);   

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, dataval_2[0][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST, dataval_2[1][i]);  
				digitalWrite(latch_8, HIGH);   
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

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 

		}
		else if(flag==7)//평상
		{
			for(int i = 0; i<8; i++){ 
				digitalWrite(latch_1, LOW);    
				shiftOut(data_1,clock_1,LSBFIRST, scanval[i]);  
				shiftOut(data_1,clock_1,LSBFIRST, ~dataval_3[0][i]);  
				digitalWrite(latch_1, HIGH);   

				digitalWrite(latch_2, LOW);    
				shiftOut(data_2,clock_2,LSBFIRST, scanval[i]);  
				shiftOut(data_2,clock_2,LSBFIRST, ~dataval_3[1][i]);  
				digitalWrite(latch_2, HIGH);  

				digitalWrite(latch_3, LOW);    
				shiftOut(data_3,clock_3,LSBFIRST, scanval[i]);  
				shiftOut(data_3,clock_3,LSBFIRST, ~dataval_3[0][i]);  
				digitalWrite(latch_3, HIGH);   

				digitalWrite(latch_4, LOW);    
				shiftOut(data_4,clock_4,LSBFIRST, scanval[i]);  
				shiftOut(data_4,clock_4,LSBFIRST, ~dataval_3[1][i]);  
				digitalWrite(latch_4, HIGH); 

				digitalWrite(latch_5, LOW);    
				shiftOut(data_5,clock_5,LSBFIRST, scanval[i]);  
				shiftOut(data_5,clock_5,LSBFIRST, ~dataval_3[0][i]);  
				digitalWrite(latch_5, HIGH);   

				digitalWrite(latch_6, LOW);    
				shiftOut(data_6,clock_6,LSBFIRST, scanval[i]);  
				shiftOut(data_6,clock_6,LSBFIRST, ~dataval_3[1][i]);  
				digitalWrite(latch_6, HIGH); 

				digitalWrite(latch_7, LOW);    
				shiftOut(data_7,clock_7,LSBFIRST, scanval[i]);  
				shiftOut(data_7,clock_7,LSBFIRST, ~dataval_3[0][i]);  
				digitalWrite(latch_7, HIGH);   

				digitalWrite(latch_8, LOW);    
				shiftOut(data_8,clock_8,LSBFIRST, scanval[i]);  
				shiftOut(data_8,clock_8,LSBFIRST, ~dataval_3[1][i]);  
				digitalWrite(latch_8, HIGH);  
				//   delay(1); 
			}
Serial.print(flag);
			digitalWrite(latch_1, LOW);    
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			shiftOut(data_1,clock_1,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH); 

			digitalWrite(latch_2, LOW);    
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			shiftOut(data_2,clock_2,MSBFIRST, 0x00);  
			digitalWrite(latch_1, HIGH);     

			digitalWrite(latch_3, LOW);    
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			shiftOut(data_3,clock_3,MSBFIRST, 0x00);  
			digitalWrite(latch_3, HIGH); 

			digitalWrite(latch_4, LOW);    
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			shiftOut(data_4,clock_4,MSBFIRST, 0x00);  
			digitalWrite(latch_4, HIGH); 

			digitalWrite(latch_5, LOW);    
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			shiftOut(data_5,clock_5,MSBFIRST, 0x00);  
			digitalWrite(latch_5, HIGH); 

			digitalWrite(latch_6, LOW);    
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			shiftOut(data_6,clock_6,MSBFIRST, 0x00);  
			digitalWrite(latch_6, HIGH); 

			digitalWrite(latch_7, LOW);    
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			shiftOut(data_7,clock_7,MSBFIRST, 0x00);  
			digitalWrite(latch_7, HIGH); 

			digitalWrite(latch_8, LOW);    
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			shiftOut(data_8,clock_8,MSBFIRST, 0x00);  
			digitalWrite(latch_8, HIGH); 



		}
		}

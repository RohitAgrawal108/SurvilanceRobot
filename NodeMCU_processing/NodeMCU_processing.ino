
#include <ESP8266WiFi.h>
int temp = 0;
bool just_sent;
WiFiClient client;
WiFiServer server(80);
#define A0 A0
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define SD2 9
#define SD3 10
#define RX 3
#define TX 1
unsigned long myTime;
unsigned long sentTime;


void setup() {
pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
WiFi.begin("Rohit", "123zxcvbnm");
while(WiFi.status() != WL_CONNECTED){
delay(200);
Serial.print("..");
}

Serial.begin(115200);
mySerial.begin(9600);
Serial.println();
Serial.println("NodeMCU is connected!");
Serial.println(WiFi.localIP());
server.begin();
temp = 1;
just_sent = 0;
}

void loop() {
   myTime = millis();

   
client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if(myTime )
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /f HTTP/1.1")
    {
      forward();
    }
    if(request == "GET /b HTTP/1.1")
    {
      backward();
    }
    if(request == "GET /r HTTP/1.1")
    {
      right();
    }
    if(request == "GET /l HTTP/1.1")
    {
      left();
    }
    if(request == "GET /s HTTP/1.1")
    {
      stoped();
    }
  }

delay(1500);}

void forward(){
  digitalWrite(D5,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D3,LOW);
}
void backward(){
  digitalWrite(D5,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D3,HIGH);
}
void left(){
  digitalWrite(D6,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,LOW);
}
void right(){
  digitalWrite(D6,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D4,HIGH);
}
void stoped(){
  digitalWrite(D6,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D4,LOW);
}

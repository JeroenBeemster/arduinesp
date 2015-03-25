char ssid[] = "yourNetwork";      //  your network SSID (name)
char pass[] = "secretPassword";   // your network password
int ledpin = 2;
boolean blink = true;

void setup() {
  Serial.begin(115200);
 
  wifi.begin(ssid, pass);
  wifi.server(createResponse,80); // first parameter is the function , the second parameter is the port, normally 80  
  pinMode(ledpin, OUTPUT);         

}

void loop() {
  if (blink == true) {
    digitalWrite(ledpin, LOW);
    delay(1000);
    digitalWrite(ledpin, HIGH);
    delay(1000);
  }
}

void createResponse(char response[]) {
  char myresponse[1024]; 
  strcpy(myresponse,response);
  blink = false;
  
  if(myresponse[5] == 'H') 
  {
    digitalWrite(ledpin, HIGH);
  } 
  if(myresponse[5] == 'B') 
  {
    blink = true;
  } else {
    digitalWrite(ledpin, LOW);
  }
  
  wifi.print("Click <a href=\"/H\">here</a> turn the LED on pin 2 on<br>");
  wifi.print("Click <a href=\"/L\">here</a> turn the LED on pin 2 off<br>");
  wifi.print("Click <a href=\"/B\">here</a> turn the LED on pin 2 to blink<br>");
  wifi.println("");
  wifi.send();
  
}

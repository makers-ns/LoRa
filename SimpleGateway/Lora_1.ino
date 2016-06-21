String inputString = "";  
boolean stringComplete;


//Instead using Arudino DUE Serial1
// we can use SoftwareSerial library

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(57600);
  Serial.begin(9600);

  sendcmd("sys reset");
  sendcmd("radio set mod lora");
  sendcmd("radio set freq 868100000");
  sendcmd("radio set pwr 14");
  sendcmd("radio set sf sf12");
  sendcmd("radio set afcbw 125");
  sendcmd("radio set rxbw 250");
  sendcmd("radio set fdev 5000");
  sendcmd("radio set prlen 8");
  sendcmd("radio set crc on");
  sendcmd("radio set cr 4/8");
  sendcmd("radio set wdt 0");
  sendcmd("radio set sync 12");
  sendcmd("radio set bw 250");
  sendcmd("sys get hweui");
  sendcmd("mac pause");
}

void loop() {
  // put your main code here, to run repeatedly:
  //sendcmd("mac pause");
 sendmsg("radio tx AABB"); //HEX data AA, BB
 delay(2000);
}

void sendcmd(String data){
  Serial.println(data);
  Serial1.println(data); 
  delay(200);
  Serial.println(Serial1.readStringUntil('\n'));
}

void sendmsg(String data){
  Serial.println(data);
  Serial1.println(data); 
  delay(200);
  Serial.println(Serial1.readStringUntil('\n')); // command response
  Serial.println(Serial1.readStringUntil('\n')); // transmision repsonse
}


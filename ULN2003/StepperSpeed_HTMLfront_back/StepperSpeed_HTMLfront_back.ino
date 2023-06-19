//Left
int Pin1 = 19;//IN1 is connected to 19
int Pin2 = 18;//IN2 is connected to 18  
int Pin3 = 5;//IN3 is connected to 5 
int Pin4 = 17;//IN4 is connected to 17
//Right
int Pin5 = 4;//IN1 is connected to 19
int Pin6 = 6;//IN2 is connected to 18  
int Pin7 = 7;//IN3 is connected to 5 
int Pin8 = 8;//IN4 is connected to 17

 
int pole1[] ={0,0,0,0, 0,1,1,1, 0};//pole1, 8 step values
int pole2[] ={0,0,0,1, 1,1,0,0, 0};//pole2, 8 step values
int pole3[] ={0,1,1,1, 0,0,0,0, 0};//pole3, 8 step values
int pole4[] ={1,1,0,0, 0,0,0,1, 0};//pole4, 8 step values

int pole5[] ={1,1,0,0, 0,0,0,1, 0};//pole1, 8 step values
int pole6[] ={0,1,1,1, 0,0,0,0, 0};//pole2, 8 step values
int pole7[] ={0,0,0,1, 1,1,0,0, 0};//pole3, 8 step values
int pole8[] ={0,0,0,0, 0,1,1,1, 0};//pole4, 8 step values
int poleStep = 0; 
//int poleStep = 0; 

int  dirStatus = 5;// stores direction status 3= stop (do not change)

//속도관련
//volatile int speedValue = 1;
int speedValue = 1;
String buttonTitle1[] ={"전진", "후진","회전(좌)","회전(우)"}; //ON
String buttonTitle2[] ={"전진", "후진","회전(좌)","회전(우)"}; //OFF
String argId[] ={"front", "back","rotateL","rotateR"};
String HTML;

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char *ssid = "ksb";
const char *password = "00000000";
//const char *ssid = "Your WIFI SSID";
//const char *password = "Your WIFI PASSWORD";

WebServer server(80);

void handleRoot() {
HTML ="<!DOCTYPE html>\n";
HTML += "<html>\n";
HTML += "<head>\n";
HTML += "\t<title>I2R - 28BYJ-48 Motor Control</title>\n";
HTML += "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
HTML += "\t\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">";
HTML += "\t<style>\n";
HTML += "\thtml,body{\n\twidth:100%;\n\theight:100%;\n\tmargin:0}\n";
HTML += "\t*{box-sizing:border-box}\n";
HTML += "\t.colorAll{\n\tbackground-color:#90ee90}\n";
HTML += "\t.colorBtn{\n\tbackground-color:#add8e6}\n";
HTML += "\t.angleButton,a{\n\tfont-size:30px;\n\tborder:1px solid #ccc;\n\tdisplay:table-caption;\n\tpadding:7px 10px;\n\ttext-decoration:none;\n\tcursor:pointer;\n\tpadding:5px 6px 7px 10px}\n";
HTML += "\ta{\n\tdisplay:block}\n";
HTML += "\t.btn{\n\tmargin:5px;\n\tborder:none;\n\tdisplay:inline-block;\n\tvertical-align:middle;\n\ttext-align:center;\n\twhite-space:nowrap}\n";
HTML += "\t</style>\n";
HTML += "</head>\n";
HTML += "<body>\n";
HTML += "<h1>I2R-28BYJ-48 Stepper Motor Control</h1>\n";
HTML += "<h2>전진,후진,제자리회전,좌,우,속도</h2>\n";
   if(dirStatus ==2){
    HTML +="\n\t<h2><span style=\"background-color: #FFFF00\">후진</span></h2>\n";    
   }else if(dirStatus ==1){
    HTML +="\n\t<h2><span style=\"background-color: #FFFF00\">전진</span></h2>\n";      
   }else if(dirStatus==3){
    HTML +="\n\t<h2><span style=\"background-color: #FFFF00\">제자리 회전(좌)</span></h2>\n";    
   }else if(dirStatus==4){
    HTML +="\n\t<h2><span style=\"background-color: #FFFF00\">제자리 회전(우)</span></h2>\n";    
   }else{
    HTML +="\n\t<h2><span style=\"background-color: #FFFF00\">멈춤</span></h2>\n";    
   }
   HTML += "\n\t<h2>속도: " + String(speedValue) + "</h2>\n";
   
      if(dirStatus ==1){
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton\" style=\"background-color:#f56464\"  href=\"/motor?";
        HTML += argId[0];
        HTML += "=off\">";
        HTML +=buttonTitle1[0]; //motor ON title
      }else{
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton \" style=\"background-color:#90ee90\"  href=\"/motor?";  
         HTML += argId[0];
        HTML += "=on\">";       
        HTML +=buttonTitle2[0];//motor OFF title   
      }   
     HTML +="</a>\t\n\t</div>\n\n";  
           
      if(dirStatus ==2){
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton\" style=\"background-color:#f56464\"  href=\"/motor?";
        HTML += argId[1];
        HTML += "=off\">";
        HTML +=buttonTitle1[1]; //motor ON title
      }else{
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton \" style=\"background-color:#90ee90\"  href=\"/motor?";  
         HTML += argId[1];
        HTML += "=on\">";       
        HTML +=buttonTitle2[1];//motor OFF title   
      }   
     HTML +="</a>\t\n\t</div>\n\n"; 
         
      if(dirStatus ==3){
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton\" style=\"background-color:#f56464\"  href=\"/motor?";
        HTML += argId[2];
        HTML += "=off\">";
        HTML +=buttonTitle1[2]; //motor ON title
      }else{
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton \" style=\"background-color:#90ee90\"  href=\"/motor?";  
         HTML += argId[2];
        HTML += "=on\">";       
        HTML +=buttonTitle2[2];//motor OFF title   
      }   
     HTML +="</a>\t\n\t</div>\n\n";     
   
    if(dirStatus ==4){
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton\" style=\"background-color:#f56464\"  href=\"/motor?";
        HTML += argId[3];
        HTML += "=off\">";
        HTML +=buttonTitle1[3]; //motor ON title
      }else{
        HTML +="\t<div class=\"btn\">\n\t\t<a class=\"angleButton \" style=\"background-color:#90ee90\"  href=\"/motor?";  
         HTML += argId[3];
        HTML += "=on\">";       
        HTML +=buttonTitle2[3];//motor OFF title   
      }   
     HTML +="</a>\t\n\t</div>\n\n";     

  // 슬라이더 추가
  HTML += "<input type=\"range\" id=\"speedSlider\" name=\"s\" min=\"1\" max=\"10\" value=\"1\" oninput=\"updateSliderValue(this.value)\">\n";
HTML += "<span>빠름:1</span>\n<span>느림:10</span>\n<span id=\"sliderValue\">0</span>\n"; // 슬라이더 값을 표시할 요소 추가
  // 슬라이더 값을 업데이트하는 함수 추가
// 슬라이더 값을 업데이트하는 함수 추가
// 슬라이더 값을 업데이트하는 함수 추가
HTML += "<script>\n";
HTML += "var sliderValue = document.getElementById(\"sliderValue\");\n";
HTML += "var timeoutId;\n";
HTML += "function updateSliderValue(value) {\n";
HTML += "\tsliderValue.innerHTML = value;\n";
HTML += "}\n";
HTML += "function sendSliderValue(value) {\n";
HTML += "\tclearTimeout(timeoutId);\n";
HTML += "\ttimeoutId = setTimeout(function() {\n";
HTML += "\t\tvar xhttp = new XMLHttpRequest();\n";
HTML += "\t\txhttp.open(\"GET\", \"/speed?s=\" + value, true);\n";
HTML += "\t\txhttp.send();\n";
HTML += "\t\txhttp.onreadystatechange = function() {\n";
HTML += "\t\t\tif (this.readyState === 4 && this.status === 200) {\n";
HTML += "\t\t\t\tlocation.reload();\n";
HTML += "\t\t\t}\n";
HTML += "\t\t};\n";
HTML += "\t}, 1000);\n";
HTML += "}\n";
HTML += "document.getElementById('speedSlider').addEventListener('input', function() {\n";
HTML += "\tupdateSliderValue(this.value);\n";
HTML += "});\n";
HTML += "document.getElementById('speedSlider').addEventListener('change', function() {\n";
HTML += "\tsendSliderValue(this.value);\n";
HTML += "});\n";
HTML += "</script>\n";
  HTML += "</body>\n</html>\n";
  server.send(200, "text/html", HTML);
}//handleRoot()

void handleNotFound() {
  
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  
}//end of handleNotFound()

void setup(void) {
  
 
 pinMode(Pin1, OUTPUT);//define pin for ULN2003 in1 
 pinMode(Pin2, OUTPUT);//define pin for ULN2003 in2   
 pinMode(Pin3, OUTPUT);//define pin for ULN2003 in3   
 pinMode(Pin4, OUTPUT);//define pin for ULN2003 in4   
 pinMode(Pin5, OUTPUT);//define pin for ULN2003 in1 
 pinMode(Pin6, OUTPUT);//define pin for ULN2003 in2   
 pinMode(Pin7, OUTPUT);//define pin for ULN2003 in3   
 pinMode(Pin8, OUTPUT);//define pin for ULN2003 in4  
 
  Serial.begin(115200);//initialize the serial monitor
  Serial.println("I2R_ESP32 28BYJ-48 Stepper Motor Control");

  
    
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: http://");
  Serial.println(WiFi.localIP());

//multicast DNS   //I2RESP32 28BYJ-48 Steper Motor Control
  if (MDNS.begin("I2R_ESP32")) {
    Serial.println("MDNS responder started");
    Serial.println("access via http://I2R_ESP32");
  }

  server.on("/", handleRoot);
  server.on("/motor", HTTP_GET, motorControl);     
  server.on("/speed", HTTP_GET, motorControl);      
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");

}//end of setup

void loop(void) {
  server.handleClient();
if(dirStatus ==1){ 
  // 전진
  poleStep++;
  driveStepperR(poleStep);
  driveStepperL(poleStep);
} else if (dirStatus == 2) {
  // 후진
  poleStep--;
  driveStepperR(poleStep);
  driveStepperL(poleStep);
} else if (dirStatus == 3) {
  // 회전좌 L 후 R 전
  poleStep++;
  driveStepperR(poleStep); // 01234567
  driveStepperL(7-poleStep); // 7654321
} else if (dirStatus == 4) {
  // 회전우 L 전 R 후
  poleStep--;
  driveStepperR(poleStep); // 76543210
  driveStepperL(7-poleStep); // 01234567
} else{ //정지
  driveStepperR(8);  
  driveStepperL(8); 
 }
 
 if(poleStep>7){ 
   poleStep=0;
 } 
 if(poleStep<0){ 
   poleStep=7; 
 } 

  //속도를 조절하는 부분. 작을수록 속도가 빨라짐
  delayMicroseconds(speedValue * 100);
}

void motorControl() {
  //int prestate = 1;;
 if (server.hasArg("s")) {
    speedValue = server.arg("s").toInt();
    Serial.println("speedValue: "+String(speedValue));
  }
if (server.arg(argId[0]) == "on") {
  dirStatus = 1; // CCW 전진
} else if (server.arg(argId[1]) == "on") {
  dirStatus = 2; // CW 후진
} else if (server.arg(argId[2]) == "on") {
  dirStatus = 3; // 제자리좌회전
} else if (server.arg(argId[3]) == "on") {
  dirStatus = 4; // 제자리우회전
} else {
  dirStatus = 5; // motor OFF 정지
}

  handleRoot();
}//motorControl end

 

void driveStepperR(int c)
{
     digitalWrite(Pin1, pole1[c]);  
     digitalWrite(Pin2, pole2[c]); 
     digitalWrite(Pin3, pole3[c]); 
     digitalWrite(Pin4, pole4[c]); 
}//driveStepper end here

void driveStepperL(int c)
{
     digitalWrite(Pin5, pole5[c]);  
     digitalWrite(Pin6, pole6[c]); 
     digitalWrite(Pin7, pole7[c]); 
     digitalWrite(Pin8, pole8[c]);  
}//driveStepper end here

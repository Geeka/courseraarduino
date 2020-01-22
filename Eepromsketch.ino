#include <EEPROM.h>;

int memsize = EEPROM.length();
int valsize = 255;

void setup() 
{
  Serial.begin(9600);
}
int addr,value;
String cmd;

void loop() 
{
  if(Serial.available() ){
  String buffer = "";
  buffer = Serial.readString();
  Serial.println(buffer);
    
  int cmdi = splitString(buffer);
  if (cmdi==1)
    {
    Serial.print("Data from the Address : ");
    Serial.print(addr);
    Serial.println();
    Serial.println(EEPROM.read(addr)); 
    } 
  else if(cmdi==2) {
    Serial.print("Written ");
    Serial.print(value);
    Serial.println();
    Serial.print("to the Address: ");
    Serial.print(addr);
    Serial.println();
    EEPROM.write(addr,value);
    }
   }
  
}

int splitString(String str) {
    
  String result[3]={"","",""};
  int r=0;
  
  for(int  i=0; i <3; i++){
    int index= str.indexOf(' ');
    result[i] = str.substring(0,index);
    str= str.substring(index+1);
  }
  
  cmd=result[0];
  addr=result[1].toInt();
  value = result[2].toInt();
  
  if(cmd.equals("read")) r=1;
  else if(cmd.equals("write")) r=2;
  
          
  if (!r)
  {
      Serial.println("invalid command");
      return -1;
  }
  
    
  
  if(!isNumeric( result[1]) || addr >= memsize) {
      Serial.println("invalid addresd");
      return -2;
   }
  
  
  if((!isNumeric(result[2]) || value>255) && r==2) {
        Serial.println ("invalid data to write");
        return -3;
  }
          
  return r;
}
          
bool isNumeric(String str) {
  for( int i=0;i<str.length();i++) {
    if (!isDigit(str[i])) return 0;
  }
  return 1;
}

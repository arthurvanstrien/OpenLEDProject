bool state;
const int ledRed = 8;
const int ledGreen = 7;
const int ledBlue = 6;
int colorRed;
int colorGreen;
int colorBlue;

void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  state = true;
  colorRed = 255;
  colorGreen = 255;
  colorBlue = 255;
  updateColors(colorRed, colorGreen, colorBlue);
  
  Serial.println("LED Controller Started.");
}

void loop() 
{ // run over and over

  if(Serial.available()) 
  {
    String message;
    message = Serial.readString();
    
    if(message == "switch") 
    {
      waitForSerial();
      String value = Serial.readString();
      
      if(value == "on")
      {
        updateColors(colorRed, colorGreen, colorBlue);
      }
      else
      {
        analogWrite(ledRed, 0);
        analogWrite(ledGreen, 0);
        analogWrite(ledBlue, 0);
      }
    } 
    else if(message == "color") 
    {
      recieveRGBValues();
      updateColors(colorRed, colorGreen, colorBlue);
    }
    else
    {
      Serial.println("Else");
    }
  }
}

void waitForSerial()
{
  while(Serial.available() == 0)
  {
  }
}

void updateColors(int cr, int cg, int cb)
{   
  analogWrite(ledRed, cr);
  analogWrite(ledGreen, cg);
  analogWrite(ledBlue, cb);
}

void recieveRGBValues()
{
  waitForSerial();
  String red = Serial.readString();
  waitForSerial();
  String green = Serial.readString();
  waitForSerial();
  String blue = Serial.readString();

  colorRed = red.toInt();
  colorGreen = green.toInt();
  colorBlue = blue.toInt();
}


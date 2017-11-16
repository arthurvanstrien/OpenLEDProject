bool state;
int colorRed;
int colorGreen;
int colorBlue;

int ledArray[][3] = 
{
 {8,7,6} 
};

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
        updateColors(0,0,0);
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
  for(int i = 0; i < (sizeof(ledArray) / sizeof(ledArray[0])); i++)
  {  
    analogWrite(ledArray[i][0], cr);
    analogWrite(ledArray[i][1], cg);
    analogWrite(ledArray[i][2], cb);
  }
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


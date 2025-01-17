char stringToMorseCode[] = "";

const int trig = 12;
const int echo = 13;

const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 6;

int duration = 0;
int distance = 0;
int audio8 = 5;      // output audio on pin 8

int note = 1200;      // music note/pitch


int dotLen = 100;     // length of the morse code 'dot'

int dashLen = dotLen * 3;    // length of the morse code 'dash'


void setup() {  
 
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  
  Serial.begin(9600);             

}


void loop()

{ 
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  

  if ( distance <= 7 )
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 14 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 21 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }

  char inChar = 0;          

  char inData[100] = "";        // data length of 6 characters

  String variable = "";

  String variable1 = "";

  int index1 = 0;

 

  if ( Serial.available() > 0 ) {                      // Read from Rx from atmega16

    while (Serial.available() > 0 && index1 < 100)     // read till 6th character

    {

      delay(100);

      inChar = Serial.read();      // start reading serilly and save to variable

      inData[index1] = inChar;

      index1++;

      inData[index1] = '\0';         // Add a null at the end

    }

    variable.toUpperCase();       // convert to uppercase

    for (byte  i = 0 ; i < 100 ; i++) {

      variable.concat(String(inData[i]));    // concat strings

    }

    delay(20);

  }

  String  stringToMorseCode = String(variable);                          


  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)

  {

  char tmpChar = stringToMorseCode[i];

  tmpChar = toLowerCase(tmpChar);

  GetChar(tmpChar);

  }

}


void MorseDot()

{

  tone(audio8, note, dotLen); // start playing a tone

  delay(dotLen);              // hold in this position

}


void MorseDash()

{

  tone(audio8, note, dashLen);  // start playing a tone

  delay(dashLen);               // hold in this position

}


void GetChar(char tmpChar)

{

  switch (tmpChar) {

    case 'a': 

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'b':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'c':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'd':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100); 

    break;

    case 'e':

    MorseDot();

    delay(100);

    break;

    case 'f':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'g':

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'h':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'i':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'j':

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'k':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'l':

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'm':

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'n':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'o':

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'p':

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 'q':

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'r':

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 's':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    case 't':

    MorseDash();

    delay(100);

    break;

    case 'u':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'v':

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'w':

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'x':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'y':

    MorseDash();

    delay(100);

    MorseDot();

    delay(100);

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);

    break;

    case 'z':

    MorseDash();

    delay(100);

    MorseDash();

    delay(100);   

    MorseDot();

    delay(100);

    MorseDot();

    delay(100);

    break;

    default:

       break;

  }

}
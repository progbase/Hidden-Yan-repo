#include <Ultrasonic.h>
#define enA 3
#define enB 5
#define in1 2
#define in2 4
#define in3 6
#define micro A0
#define in4 7
int valEn = -1;
int valServo = -1;
int val = -1;
int  k = 100;
float mv = 0;
int duration, distancew = 100, distancea = 100, distanced = 100;
bool en = 0;
bool servo = 0;
bool autoen = 0;
Ultrasonic ultrasonicw(13, 12);
Ultrasonic ultrasonica(11, 10);
Ultrasonic ultrasonicd(9, 8);
/*0 = EnReverse, 1 = EnOn , -1 = EnOff */
/*2 = ServoLeft, 3 = ServoRight, -1 = ServoOff */

void setup()
{
  pinMode(micro, INPUT);
  pinMode(enA, OUTPUT);
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    if ( val == 'R')
    {
      while ( 1 )
      {
        val = Serial.read();
        if ( val == 'R' )
        {
          break;
        }
        distancew = (ultrasonicw.Ranging(CM));
        distancea = (ultrasonica.Ranging(CM));
        distanced = (ultrasonicd.Ranging(CM));
        if (( distancew < 50 && distancew > 0) && ( distancea < 50 && distancea > 0 ) && ( distanced >= 50 || distanced < 1 ))
        {
          if ( autoen )
          {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(enA, 250);
            delay(700);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enB, 1000);
            delay ( 300 );
             digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            analogWrite(enA, 250);
            delay(1000);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
          }
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
        }
        else if (( distancew < 50 && distancew > 0) && ( distancea >= 50 || distancea < 1 ) && ( distanced >= 50 || distanced < 1 ))
        {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            analogWrite(enB, 1000);
            delay ( 300 );
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(enA, 250);
            delay(700);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enB, 1000);
            delay ( 400 );
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(enA, 250);
            delay ( 800 );
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
        }
        else if (( distancew < 50 && distancew > 0) && ( distancea >= 50 || distancea < 1 ) && ( distanced < 50 && distanced > 0 ))
        {
          if ( autoen )
          {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(enA, 250);
            delay(700);
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enB, 1000);
            delay ( 300 );
             digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            analogWrite(enA, 250);
            delay(1000);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
          }
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
        }
        else if (( distancew < 50 && distancew > 0) && ( distancea < 50 && distancea > 0 ) && ( distanced < 50 && distanced > 0 ))
        {
           digitalWrite(in1, LOW);
           digitalWrite(in2, LOW);
           digitalWrite(in1, HIGH);
           digitalWrite(in2, LOW);
           analogWrite(enA, 250);
           delay(700);
           digitalWrite(in1, LOW);
           digitalWrite(in2, LOW);
        }
        else
        {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          analogWrite(enA, 150);
          autoen = 1;
        }
        delay ( 100);
      }
    }
    if ( val == '0')
    {
      if ( servo == 1 )
      {
        servo = 0;
        valServo = -1;
      }
    }
    if ( val == 'o')
    {
      if ( en == 1 )
      {
        en = 0;
        valEn = -1;
      }
    }
    if (val == 'w')
    {
      valEn = 1;
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 222);
      en = 1;
    }
    if ( val == 's')
    {
      valEn = 1;
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 222);
      en = 1;
    }
    if ( val == 'a')
    {
      valServo = 1;
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 1000);
      servo = 1;
    }
    if ( val == 'd')
    {
      valServo = 1;
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 1000);
      servo = 1;
    }
    if ( val == 'm' )
    {
      while ( 1 )
      {
        val = Serial.read();
        if ( val == 'm' )
        {
          digitalWrite ( in1, LOW );
          digitalWrite ( in2, LOW );
          break;
        }
        else if ( val == 'a' )
        {
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          analogWrite(enB, 1000);
        }
        else if ( val == 'd' )
        {
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
          analogWrite(enB, 1000);
        }
        else if ( val == 's' )
        {
          digitalWrite ( in1, LOW );
          digitalWrite ( in2, LOW );
          digitalWrite ( in1, HIGH );
          digitalWrite ( in2, LOW );
          analogWrite ( enA, 222 );
          delay ( 400 );
          digitalWrite ( in1, LOW );
          digitalWrite ( in2, LOW );
        }
        else if ( val == 'o')
        {
          digitalWrite ( in1, LOW );
          digitalWrite ( in2, LOW );
        }
        else if ( val == '0' )
        {
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }
        mv = analogRead(micro);
        if ( mv < 1000 || k < 26 )
        {
          Serial.println ( mv , DEC );
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          analogWrite(enA, 222);
          if ( k>99 )
          k=0;
        }
        else
        {
          if ( k > 25 ) 
          {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            k=100;
          }
        }
        delay ( 40);
        k++;
      }
    }
  }
  if ( valEn == -1)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  if ( valServo == -1)
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}

#include <Servo.h> //defining Servos
Servo servohori; // declare horizontal rotatory servo motor
int servoh = 0; // Defining start position of shaft
int servohLimitHigh = 160;// upper limmit that is 160 degree
int servohLimitLow = 20;//lower limit that is 20 degree 

Servo servoverti; // declare vertical rotatory servo motor
int servov = 0; // Defining start position of shaft
int servovLimitHigh = 160;// upper limmit that is 160 degree
int servovLimitLow = 20;//lower limit that is 20 degree 

//Assigning LDRs
int ldrtopl = 2; //top left LDR 
int ldrtopr = 1; //top right LDR 
int ldrbotl = 3; // bottom left LDR 
int ldrbotr = 0; // bottom right LDR 

 void setup () 
 {
  servohori.attach(10);// declaring the pin connected to horizontal rotatory servo motor
  servohori.write(0);// Defining start position of shaft
  servoverti.attach(9);;// declaring the pin connected to vertical rotatory servo motor
  servoverti.write(0);// Defining start position of shaft
  delay(500);//delay if 500ms
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // calculating average
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs

//For vertical movement
  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
        servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
    {
      servov = servovLimitLow;
    }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }

  //For Horizontal Movement
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
      servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
        servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}

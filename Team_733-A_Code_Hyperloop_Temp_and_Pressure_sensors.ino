//Global Variables to be used throughtout this code.

//----------------------------------------------------------------------------------------------------------

//For Pressure Transducer

const int pressinput = A0; //The constant integer for the pressure tranduscer's analog input pin.
float pressv; //The pressure value that will be read, stored and output to the user.

//For Temperature Sensor

//const int tempinput = A1; //The constant integer for the temperature sensor's analog input pin.
//float tempsense; //The temperature value that will be read, stored and output to the user.


//----------------------------------------------------------------------------------------------------------

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600); //The baud rate is 9600.
}

void loop() {
//Pressure Transducer

  pressv = analogRead(pressinput); //This will read the analog input pin specified earlier, for the pressure transducer.
  pressv = ((pressv*5)/1024);
  //Serial.print(pressv); // To test how much analog input voltage is produced. (TESTING PURPOSES) 
  //Serial.print(" volts."); 

  pressv = (((3*pressv) - 0.475)*10e5); //Conversion from analog input voltage to pressure in the unit of "pascals".
  pressv = (pressv/10e5); //Conversion from pressure in "pascals" to pressure in "bars".
  pressv = (pressv*14.5037738); //Conversion from pressure in "bars" to pressure in "psi".  

if (pressv>=16) //This if statement will execute if the maximum pressure, 400 psi is reached. DEMO PSI for test 
{
  Serial.print("ALERT MAXIMUM PRESSURE HAS BEEN REACHED!");  //This will display a message to the client when the maximum pressure, 400 psi is reached.
  Serial.print(" ");
  Serial.print(pressv); //The pressure to be outputted in psi.
  Serial.print(" psi.");
  Serial.print('\n'); //This adds another line to the output message to make it easier for the client to keep track of the pressure readings
  Serial.print('\n');
  delay(2500); //This delays the process by 25 seconds
}

else
{
  Serial.print("The Pressure is"); //Outputing the user what the pressure is.
  Serial.print(" ");
  Serial.print(pressv); //The pressure to be outputted in psi.
  Serial.print(" psi.");
  Serial.print('\n'); //To add lines in between the output to space out and make the output look more clear.
  Serial.print('\n'); 
}
  delay(2500); //This delays the process by 25 seconds
}

//----------------------------------------------------------------------------------------------------------
  
//Temperature Sensor (To be tested on TinkerCAD) (This code can be put in the same void loop as the pressure sensor as intially planned)

//void loop() {                        
  //tempsense = analogRead(tempinput);    (The temperature sensor analog voltage will be taken from the analog pin)
  //tempsense = (tempsense/1024);         (The input will be divided by the integer value of 1024 to obtain the amount it is reading) 
  //tempsense = ((tempsense*5)-0.5);      (The amount of the reading will be multiplied by 5V and subtracted by 0.5)
  //tempsense = (tempsense*100);          (The voltage will finally be multiplied by 100 to obtain the temperature in degrees C) 

//if(tempsense>=50)                                                                                   (This if statement will execute if the maximum temperature, 50 degrees C is reached.)
//{           
  //Serial.println("ALERT MAXIMUM TEMPERATURE HAS BEEN REACHED! ");                                     (This will display a message to the client when the maximum temperature, 50 degrees C is reached.)
  //Serial.print(tempsense);                                                                            (This displays the temperture readings which exceeded the maximum temperature)
  //Serial.println(" degrees C.");
  //Serial.println(" ");                                                                                (This adds another line to the output message to make it easier for the client to keep track of the temperature readings)  
//}  

//else                                                                                                (This else statement will only operate if the maximum temperature condition is proven false)  
//{                                                                                                   
  //Serial.println("The temperature is: "); //Outputing the user what the approximate temperature is.   
  //Serial.print(tempsense);                                                                            (This displays the temperture readings)
  //Serial.println(" degrees C.");
  //Serial.println(" ");  
//}
 
  //delay(2500);                                                                                         (This delays the process by 25 seconds)
//}

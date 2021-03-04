#include <IRremote.h>
#include <IRremoteInt.h>


String device;
int RECV_PIN =  7;
int relayOut1 = 3;
int relayOut2 = 4;
int relayOut3 = 5;
int relayOut4 = 6;


IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {

  Serial.begin(9600);
  digitalWrite(relayOut1, HIGH);
  digitalWrite(relayOut2, HIGH);
  digitalWrite(relayOut3, HIGH);
  digitalWrite(relayOut4, HIGH);  
  Serial.println("Light Off   ");
Serial.println("START  ");
 

  
  irrecv.enableIRIn(); // Start the receiver
  pinMode( relayOut1, OUTPUT); 
  pinMode( relayOut2, OUTPUT);
  pinMode( relayOut3, OUTPUT);
  pinMode( relayOut4, OUTPUT);
  
}
void loop() {



////////////// bluethooth  relay selecyion///////////
  
 while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  device += c; //build the string.
  }  
  if (device.length() > 0) {
    Serial.println(device); 
  
  
  if(device == "doneon")  { // 1PLAY Button
        digitalWrite(relayOut1, LOW); // Activates the relay
        Serial.println("Light on 1  ");
        }

   
  else if(device == "doneoff") { // 1STOP Button
        digitalWrite(relayOut1, HIGH); // Deactivates the relay
        Serial.println("Light Off 1  ");
        }



  
    else if (device == "dtwoon"){ // 2PLAY Button
        digitalWrite(relayOut2, LOW); // Activates the relay
         Serial.println("Light on 2  ");
        }
  
   else if ( device == "dtwooff"){ // 2STOP Button
        digitalWrite(relayOut2, HIGH); // Deactivates the relay
         Serial.println("Light Off 2  ");
        }   
  
  
  else if (device == "dthreeon") { // 3PLAY Button
         Serial.println("Light on 3  ");
        digitalWrite(relayOut3, LOW); // Activates the relay
        }
        
 else if (device == "dthreeoff") { // 3STOP Button
        digitalWrite(relayOut3, HIGH); // Deactivates the relay
         Serial.println("Light Off 3  ");
        }   


else if (device == "dfouron") { // 4PLAY Button
         Serial.println("Light on 4  ");
        digitalWrite(relayOut4, LOW); // Activates the relay
        } 

else if (device == "dfouroff") { // 4 STOP Button
        digitalWrite(relayOut4, HIGH); // Deactivates the relay
         Serial.println("Light Off 4  ");}  

else if (device == "dallon")  { // all on STOP Button
        digitalWrite(relayOut1, LOW); // activates the relay
        digitalWrite(relayOut2, LOW);
        digitalWrite(relayOut3, LOW);
        digitalWrite(relayOut4, LOW);
          Serial.println("All Light on   ");
        // Deactivates the relay
        }   

else if (device == "dalloff") { // all of STOP Button
        digitalWrite(relayOut1, HIGH); // Deactivates the relay
        digitalWrite(relayOut2, HIGH);
        digitalWrite(relayOut3, HIGH);
        digitalWrite(relayOut4, HIGH);
        // Deactivates the relay
         Serial.println("All Light Off   ");}    


 
device="";}//Reset the variable


 


  //////////ir relay selection///////////////////////
 

        
  if (irrecv.decode(&results)) {   
    
     
    if (results.value == 16724175) { // 1PLAY Button
        digitalWrite(relayOut1, LOW); // Activates the relay
        Serial.println("Light on 1  ");
        }
    if (results.value == 16718055) { // 1STOP Button
        digitalWrite(relayOut1, HIGH); // Deactivates the relay
        Serial.println("Light Off 1  ");
        }   
  
    
    if (results.value == 16743045) { // 2PLAY Button
        digitalWrite(relayOut2, LOW); // Activates the relay
         Serial.println("Light on 2  ");
        }
    if (results.value == 16716015) { // 2STOP Button
        digitalWrite(relayOut2, HIGH); // Deactivates the relay
         Serial.println("Light Off 2  ");
        }   
         
    
    if (results.value == 16726215) { // 3PLAY Button
         Serial.println("Light on 3  ");
        digitalWrite(relayOut3, LOW); // Activates the relay
        }
    if (results.value == 16734885) { // 3STOP Button
        digitalWrite(relayOut3, HIGH); // Deactivates the relay
         Serial.println("Light Off 3  ");
        }   
        
    if (results.value == 16728765) { // 4PLAY Button
         Serial.println("Light on 4  ");
        digitalWrite(relayOut4, LOW); // Activates the relay
        }
    if (results.value == 16730805) { // 4 STOP Button
        digitalWrite(relayOut4, HIGH); // Deactivates the relay
         Serial.println("Light Off 4  ");}   


         if (results.value == 16732845) { // all on STOP Button
        digitalWrite(relayOut1, LOW); // activates the relay
        digitalWrite(relayOut2, LOW);
        digitalWrite(relayOut3, LOW);
        digitalWrite(relayOut4, LOW);
          Serial.println("All Light on   ");
        // Deactivates the relay
        }   
        

         if (results.value == 16756815) { // all of STOP Button
        digitalWrite(relayOut1, HIGH); // Deactivates the relay
        digitalWrite(relayOut2, HIGH);
        digitalWrite(relayOut3, HIGH);
        digitalWrite(relayOut4, HIGH);
        // Deactivates the relay
         Serial.println("All Light Off   ");}   
        
  irrecv.resume(); // Receive the next value
  }

  
 delay(100);
}

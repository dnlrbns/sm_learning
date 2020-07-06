// A state machine that switches between ECHO and IDLE states

enum readData {ECHO, iDLE, SLEEP};   //name all the states,
readData  machineState = iDLE;      // set start state to iDLE

// declare variables
String newByte = String(0);       // set new newbyte to Zero
String incomingByte = String (0);             // set new incomingbyte to Zero
String sleepByte = String(0);       // set sleepByte to Zero
String var_f = "f";                 // set var_f to the character f (trigger to switch state to ECHO)
String var_c = "c";                 // set var_c to the character c (trigger to switch state to IDLE)
String done = "stop";             // set 'done' to STOP  (trigger to switch state to iDLE)
String sleep = "sleep";            // set 'sleep' to SLEEP  (trigger to switch state to SLEEP)
byte ledPin = 13;                 // set LED pin



void setup() {
  Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
}
void loop() {
  echoMachine(); //calls the echo function
}


// echoMachine function checks for incoming data if the trigger is set ( character f) the state will switch from iDLE to ECHO and start echoing the data recieved


int echoMachine() {
  switch (machineState) {
    //iDLE state reads the incoming bytes but does not echo them,the state will switch to Echo when 'f' is read
    case iDLE: {

        if (Serial.available() > 0 ) {
          incomingByte = Serial.readString();             // read the incoming byte:
          Serial.print("Just read character\n");          // prints a message that byte has been recieved
          // break;
          // }
          if (incomingByte == var_f) {                      // checks to see if byte is the trigger 'f'
            Serial.print("Change to ECHO state \n");         // prints message when trigger is detected
            machineState = ECHO;                             // changes state to ECHO state
            // break;
          }
          else if (incomingByte == sleep) {                  // checks to see if byte is the trigger 'sleep'
            Serial.print("Change to SLEEP state \n");         // prints message when trigger is detected
            machineState = SLEEP;                             // changes state to SLEEP
            // break;

            //}    else {
            break;
          }

        }
      }




    // ECHO state, this case will start echoing the bytes read. The state will switch back to iDLE when "stop" is entered.
    case ECHO: {
        //Serial.print("In ECHO state \n");


        if (Serial.available() > 0 ) {
          newByte = Serial.readString();           // read the incoming byte:
          Serial.print("just read character \n");  // prints a message that byte has been recieved
          Serial.print((String)newByte);           // print byte
          Serial.print("\n");
          //break;
        }

        if (newByte == done) {                   // checks to see if byte is the trigger 'stop'
          Serial.print("Change to iDLE state \n");   // prints message when trigger is detected
          machineState = iDLE;                    // changes state to iDLE
          // break;
          // }
          // else {
          break;
        }
      }


    case SLEEP: {
        //Serial.print("In SLEEP state \n");


        if (Serial.available() > 0 ) {               // checks to see byte being recieved
          sleepByte = Serial.readString();                 // read the incoming byte stores it in sleepByte:
          digitalWrite(ledPin, HIGH) ;               // turn on LED
          // turn off various things
          //break;
        }

        if  (sleepByte == var_c) {                 // checks to see if byte is being received if byte = c  change to idle
          digitalWrite(ledPin, LOW) ;
          Serial.print("change to iDLE state \n");   // turn off LED
          machineState = iDLE;                       // changes state to iDLE
          //break;
          // }
          //else {
          break;
        }

      }


      return 0;
  }
}

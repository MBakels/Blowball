#define GIVE_INPUT     'a'  // the byte signalling that the computer wants input
#define ISSUE_COMMAND  'b'  // the byte signalling that the computer issues a command
#define SET_LED_ON     'c'  // turn led on
#define SET_LED_OFF    'd'  // turn led off
//#define PLAYER_ONE_LED 'e'  // player one led
//#define PLAYER_TWO_LED 'f'  // player two led

#define BUTTON_PLAYER_ONE_PIN 11
#define BUTTON_PLAYER_TWO_PIN 12
//#define LED_PIN_PLAYER_ONE  16
//#define LED_PIN_PLAYER_TWO 17

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PLAYER_ONE_PIN, INPUT);
    pinMode(BUTTON_PLAYER_TWO_PIN, INPUT);
    //pinMode(LED_PIN_PLAYER_ONE, OUTPUT);
    //pinMode(LED_PIN_PLAYER_TWO, OUTPUT);
}

void loop() {
    //passValuesToComputer();
    //delay(1000);
    if(Serial.available()) {
        char commandReceived = Serial.read();
    
        if (commandReceived == GIVE_INPUT) {
	        passValuesToComputer();
        } /*else if (commandReceived == ISSUE_COMMAND) {
            parseCommands();
        }*/
    }
}

void passValuesToComputer() {
    String sOutput = "";
    
    int sensorValueP1 = analogRead(A0);
    sOutput = sOutput + sensorValueP1;
    
    int sensorValueP2 = analogRead(A1);
    sOutput = sOutput + "," + sensorValueP2;

    int buttonOneState = digitalRead(BUTTON_PLAYER_ONE_PIN);
    sOutput = sOutput + "," + buttonOneState;

    int buttonTwoState = digitalRead(BUTTON_PLAYER_TWO_PIN);
    sOutput = sOutput + "," + buttonTwoState;
    
    Serial.println(sOutput);
}
/*
void parseCommands() {
    delay(1);
    if(Serial.available()) {
	    char turnLedOnOrOff = Serial.read();
        if (turnLedOnOrOff == SET_LED_ON) {
            char ledToTurnOn = Serial.read();
            if(ledToTurnOn == PLAYER_ONE_LED){
                digitalWrite(LED_PIN_PLAYER_ONE, HIGH);
            } else if(ledToTurnOn == PLAYER_TWO_LED){
                digitalWrite(LED_PIN_PLAYER_TWO, HIGH);
            }
        } else if (turnLedOnOrOff == SET_LED_OFF) {
            char ledToTurnOff = Serial.read();
            if(ledToTurnOff == PLAYER_ONE_LED){
                digitalWrite(LED_PIN_PLAYER_ONE, LOW);
            }else if(ledToTurnOff == PLAYER_TWO_LED){
                digitalWrite(LED_PIN_PLAYER_TWO, LOW);
            }
        }
    }
}
*/

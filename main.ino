// Autor: Jacek Kudlański
// www.pleaserefresh.com
// nameIO = arduinoPins
byte relay = 9;
byte pir = 3;
byte safetySwitch = 6;
byte indicator = 13;

void setup() {
  //  put your setup code here, to run once:
  //  Ropoczęcie komunikacji portu szeregowego, przypisanie właściwości poszczególnym 
    Serial.begin(9600);
  //  Output:  
    pinMode(relay, OUTPUT);
    pinMode(indicator, OUTPUT);
  //  Input:
    pinMode(pir, INPUT_PULLUP);    
    pinMode(safetySwitch, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

    openDoor();

}

void openDoor(){
  //Funkcja odpowiedzialna za otwieranie drzwi oraz kontrolę otwarcia koniecna jest kolejna pętla zamknięcia
  //Stan czujki ruchu oraz krańcówki otwarcia plus wskazanie na płytce aktywację PIR

    byte pirState = digitalRead(pir);
    byte switchState = digitalRead(safetySwitch);
    
    digitalWrite(indicator, pirState);
    
    while((pirState == 1)or(pirState == 0)){
      if ((pirState == 1) and (switchState == 1)){
        Serial.println("Door Opening");
        digitalWrite(relay, HIGH);
        delay(5);
        break;
      }
      else if ((pirState == 0) and (switchState == 1)){
        Serial.println("Door Closed");
        digitalWrite(relay, LOW);
        delay(5);
        break;
      }
      else if (switchState == 0){
        Serial.println("Opened");
        digitalWrite(relay, LOW);
        delay(5);
        break;
      }
      else {
        Serial.println("ERROR");
        delay(5);
        break;
      }
      continue;
    }
  }

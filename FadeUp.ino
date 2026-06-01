
#include <DmxSimple.h>
int pan;
#include <ArduinoJson.h>

String inputString = "";
void setup() {
  Serial.begin(9600);
  DmxSimple.usePin(4);
  DmxSimple.maxChannel(50);
  
  DmxSimple.write(10, 255); //dimmer
  DmxSimple.write(3, 255); //dimmer

}

void loop() {
while (Serial.available()) {
    char c = Serial.read();
    inputString += c;
   
    // Fin du message (ex: retour ligne)
    if (c == '\n') {

      StaticJsonDocument<200> doc;

      DeserializationError error =
        deserializeJson(doc, inputString);

      if (!error) {
        int pan  = doc["pan"];
        int tilt = doc["tilt"];
        int dimmer = doc["dimmer"];
        int effet = doc["effet"];
        
        int rouge = doc["couleur"]["rouge"];
        int vert = doc["couleur"]["vert"];
        int bleu = doc["couleur"]["bleu"];
        int blanc = doc["couleur"]["blanc"];
        int ambre = doc["couleur"]["ambre"];
        int uv = doc["couleur"]["uv"];
        
        Serial.print("Pan = ");
        Serial.println(pan);
         DmxSimple.write(1, pan);  
         
        Serial.print("Tilt = ");
        Serial.println(tilt);
        DmxSimple.write(2, tilt); 

        Serial.print("Effet = ");
        Serial.println(effet);
        DmxSimple.write(3, effet);
        
        Serial.print("Rouge = ");
        Serial.println(rouge);
        DmxSimple.write(4, rouge);
        
        Serial.print("Vert  = ");
        Serial.println(vert);
        DmxSimple.write(5, vert);
        
        Serial.print("Bleu  = ");
        Serial.println(bleu);
        DmxSimple.write(6, bleu);
        
        Serial.print("Blanc = ");
        Serial.println(blanc);
        DmxSimple.write(7, blanc);
        
        Serial.print("Ambre = ");
        Serial.println(ambre);
        DmxSimple.write(8, ambre);
        
        Serial.print("UV    = ");
        Serial.println(uv);
        DmxSimple.write(9, uv);
        
        Serial.print("Dimmer = ");
        Serial.println(dimmer);
         DmxSimple.write(10, dimmer);
      }
      else {
        Serial.println("Erreur JSON");
      }

      inputString = ""; 
    }
  }
}

//{"pan":120,"couleur":{"rouge":100,"vert":120},"dimmer":250,"effet":255}

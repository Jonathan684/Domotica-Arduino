const int rele = 6;
//const int ledPIN = 9;
String miString;
char char_a_enviar;
char char_a_recibir;
//Funciones
void encender();
void apagar();

void setup(){
  
  Serial.begin(9600);
  Serial1.begin(9600); // Cada uno con su velocidad apropiada
 // pinMode(ledPIN , OUTPUT);  //definir pin como salida
  pinMode(rele , OUTPUT);
}

void loop (){
    
    if (Serial.available()) {
        char_a_enviar = Serial.read();//Lee del serial monitor y lo pone en char_a_enviar
        Serial1.write(char_a_enviar);
        Serial.write(char_a_enviar);
    } 
    else if (Serial1.available()) {
        miString="";
        miString = Serial1.readString(); // Recibe un String
        Serial.println("->"+miString+"<-");
        //miString.remove(miString.length()-2);//Remuevo dos caracteres que serian 0/ el cual proboca que salte de linea
          if(miString.equals("hola"))
          {
            encender();
          }
          if(miString.equals("chau"))
          {
            Serial.println("no entra aca");
            apagar();
          }
    }
}

void encender(){
  Serial.write("Encender el led desde la funcion");
  //digitalWrite(ledPIN , HIGH);
  digitalWrite(rele , LOW);  
}
void apagar(){
  Serial.write("Apagar el led desde la funcion");
  //digitalWrite(ledPIN , HIGH);    // poner el Pin en LOW
  digitalWrite(rele , HIGH);
}

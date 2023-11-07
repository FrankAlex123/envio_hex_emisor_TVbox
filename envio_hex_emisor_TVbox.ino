#include <IRremote.h>

IRsend emisor_ir(13);
int botonPin = 3; // Cambia el número de pin según la conexión de tu botón

void setup() {
  Serial.begin(9600);
  pinMode(botonPin, INPUT); // Configura el pin del botón como entrada con pull-up
}

void loop() {
  if (digitalRead(botonPin) == HIGH) { // Verifica si el botón está presionado
    enviarMensaje();
    delay(50); // Espera un segundo para evitar envíos múltiples si se mantiene presionado el botón
  }
}

void enviarMensaje() {
  
  //emisor_ir.sendNEC(0x1,0x4E, 0);
  emisor_ir.sendNEC(0x1,0x01, 0);
  Serial.print("Mensaje enviado: 0x");
  //Serial.println(valorHex, HEX);
}


void enviarMensaje() {
  String mensaje = "hola mundo";
  for (int i = 0; i < mensaje.length(); i++) {
    emisor_ir.sendSony(mensaje.charAt(i), 12);
    delay(20);
  }
  Serial.println("Mensaje enviado: hola mundo");
}
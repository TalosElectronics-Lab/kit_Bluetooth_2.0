/*
 *  kit Bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
*/
#include <SoftwareSerial.h>

#define In1 2
#define In2 4
#define Pwm1 3
#define In3 6
#define In4 7
#define Pwm2 5
#define B_TX 8
#define B_RX 9
#define Echo 11
#define Trigger 10
#define Servo_pin 13

#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 12

SoftwareSerial Bluetooth(B_TX, B_RX);

//Movimientos basicos
void Motores_init();
void Motores_mv(int velocidad_izquierda, int velocidad_derecha);
char Leer_BT();

char Estado;

void setup()
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Motores_init();
  
}

void loop() 
{
    Modo_Bluetooth();
}
char Leer_BT()
{
    if (Bluetooth.available() > 0)
    {
        Estado = Bluetooth.read();
        Serial.println(Estado);
    }
    return Estado;
}

void Modo_Bluetooth()
{
    int Velocidad_Max = 255;
    int Velocidad_Med = 150;
    Estado = Leer_BT();
    if (Estado == '1')
    {
        //Arriba_Izquierda
        Motores_mv(Velocidad_Med, Velocidad_Max);
    }
    if (Estado == '2')
    {
        //Derecho
        Motores_mv(Velocidad_Max, Velocidad_Max);
    }
    if (Estado == '3')
    {
        //Arriba_Derecha
        Motores_mv(Velocidad_Max, Velocidad_Med);
    }
    if (Estado == '4')
    {
        //Girar a la izquierda
        Motores_mv(-Velocidad_Max, Velocidad_Max);
    }
    if (Estado == '5')
    {
        //Serial.println("Logo talos");
    }
    if (Estado == '6')
    {
        //Girar a la derecha
        Motores_mv(Velocidad_Max, -Velocidad_Max);
    }
    if (Estado == '7')
    {
        //Abajo Izquierda
        Motores_mv(-Velocidad_Med, -Velocidad_Max);
    }
    if (Estado == '8')
    {
        //Reversa
        Motores_mv(-Velocidad_Max, -Velocidad_Max);
    }
    if (Estado == '9')
    {
        //Abajo Derecha
        Motores_mv(-Velocidad_Max, -Velocidad_Med);
    }
    if (Estado == 'w')
    {
        Motores_mv(0,0);
    }
}

void Motores_mv(int velocidad_izquierda, int velocidad_derecha)
{
    if(velocidad_izquierda>0)
    {
        analogWrite(Pwm1, velocidad_izquierda);
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);

    }
    else
    {
        velocidad_izquierda = -1 * velocidad_izquierda;
        analogWrite(Pwm1, velocidad_izquierda);
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);
    }
    if (velocidad_derecha > 0)
    {
        analogWrite(Pwm2, velocidad_derecha);
        digitalWrite(In3, LOW);
        digitalWrite(In4, HIGH);
    }
    else
    {
        velocidad_derecha = -1 * velocidad_derecha;
        analogWrite(Pwm2, velocidad_derecha);
        digitalWrite(In3, HIGH);
        digitalWrite(In4, LOW);
    }
}

void Motores_init(){
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(Pwm1, OUTPUT);
}

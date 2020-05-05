/*
 *  kit Bluetooth 2.0
 *  Taloselectronics
 *  soporte@taloselectronics.com Rafael Lozano Rolón
*/

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


int Menu;
//Movimientos basicos
void Motores_init();
void Motores_mv(int velocidad_izquierda, int velocidad_derecha);

void setup()
{
  Serial.begin(9600);
  Motores_init();
  
}

void loop() 
{
    
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

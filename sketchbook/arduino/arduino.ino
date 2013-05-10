const int NB_OF_VALUES = 1;
int valuesIndex = 0;
int values[NB_OF_VALUES];
int buzzer =11;
int pythonista;

void setup() {
// Initialize serial port
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
}

void loop() {

    if (Serial.available()) {

       if (Serial.read() == 'H'){

           for(valuesIndex = 0; valuesIndex < NB_OF_VALUES; valuesIndex++){

             values[valuesIndex] = Serial.parseInt();

           }

           pythonista = values[0];

           Serial.println(values[0]);

           if(pythonista > 1) {

               unsigned char i;

               for(i=0;i<80;i++){//output sound of one frequency

                   digitalWrite(buzzer,HIGH);//make a sound

                   delay(1);//delay 1ms

                   digitalWrite(buzzer,LOW);//silent

                   delay(1);//delay 1ms

               }

           }else{

               digitalWrite(buzzer,LOW);

           }

         }

     }
}

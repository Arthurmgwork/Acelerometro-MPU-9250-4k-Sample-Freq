#include <Wire.h>

#define MPU9250_ADDRESS 0x68
#define SDA_PIN 21
#define SCL_PIN 22
#define ACC_FULL_SCALE_2_G 0x00
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18

volatile int interruptCounter=0;
int totalInterruptCounter=0;
int flag_serial=0;

//Interrupção
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  totalInterruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

//Acelerometro
void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data){
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.endTransmission();
  // Read Nbytes
  Wire.requestFrom(Address, Nbytes);
  uint8_t index=0;
  while (Wire.available())
  Data[index++]=Wire.read();
}


// Write a byte (Data) in device (Address) at register (Register)
void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data){
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();
}



void setup() {
  
  Wire.begin(SDA_PIN, SCL_PIN,400000);
  Wire.setClock(4000000L);
  Serial.begin(500000);

  
  // Acelerometro configuração
  // Set accelerometers low pass filter at 5Hz
  I2CwriteByte(MPU9250_ADDRESS,29,0b00001000);
  // Configure accelerometers range
  I2CwriteByte(MPU9250_ADDRESS,28,ACC_FULL_SCALE_16_G);
  // Desabilita o filtro
  I2CwriteByte(MPU9250_ADDRESS, 26, 0b00000000);
  
  
  // Interrupção
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true);
  timerAlarmEnable(timer);
}


void loop() {
  if(Serial.available()>0){
    flag_serial = serial_input_int();
  }
  
  if(interruptCounter == 1 && flag_serial != 0){
    Wire.beginTransmission(MPU9250_ADDRESS);
    Wire.write(0x3F);// starting with register 0x3F (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(MPU9250_ADDRESS,2,true);
    int16_t az=Wire.read()<<8|Wire.read();
    // Display values
    Serial.println (az,DEC);
    interruptCounter--;
  }
}

int serial_input_int(){/* declarada como "int" essa funcao pode retornar um valor do tipo int */
  /*Verifica se tem algum valor na porta serial */
  int temp = 0;
  String sti = ""; //String temporaria para ir armazenando os caracteres da porta serial
  
  while(Serial.available()>0){ //Enquanto houver caracteres na fila da porta serial, ele continua no loop
    char aqui= Serial.read(); //Le o próximo caractere na fila da porta serial
    sti += aqui; //junta os caracteres da fila da porta serial em uma string
    delay(10); //espera 10 milisegundos
  }
  
  temp = sti.toInt(); //converte a string para float
  return temp; //retorna a funcao com o valor que estiver na variavel temp
}



////////////////////////////////////////////////

// for light brightness
#define LED_pin 6

// brightness of led
//#define brightness 255 // 0-255
//#define off = 0;

// flip brightness for inverse output (5v output = OFF)
// #define duty_cycle 255
#define ON 0
#define OFF 255

void setup() {
  
  // setup buzz
  pinMode(LED_pin, OUTPUT);
  analogWrite(LED_pin, OFF);
  Serial.begin(9600);

}

void loop() {

  // master run or not
  unsigned long run = 0;
  unsigned long iterations = 50;

  // params for lighting during buzz
  unsigned long LIGHT_ON_SECONDS = 300;
  unsigned long LIGHT_OFF_SECONDS = 60;
  
  // for light timing
  unsigned long LIGHT_ON_MS = LIGHT_ON_SECONDS * 1000;
  unsigned long LIGHT_OFF_MS = LIGHT_OFF_SECONDS * 1000;
  
  // for iterations
  unsigned long loop_num = 0;
  unsigned long delay_s = 2;
  unsigned long delay_ms = delay_s * 1000;
  unsigned long light_epoch_s = 300;
  unsigned long light_epoch_ms = light_epoch_s * 1000;
  
  while(run){
      
    // do delay first
    analogWrite(LED_pin, OFF);
    Serial.print("Delay for ");
    Serial.print(delay_ms);
    Serial.print("ms.");
    delay(delay_ms);

    // do light periodically
    unsigned long light_cycle = LIGHT_ON_SECONDS + LIGHT_OFF_SECONDS;
    unsigned long light_iters = light_epoch_s / light_cycle;

    // iterate through light cycle and display
    for(int i = 0; i < light_iters; i++){
      analogWrite(LED_pin, ON);
      delay(LIGHT_ON_MS);
      analogWrite(LED_pin, OFF);
      delay(LIGHT_OFF_MS);
    }


    // increment interations
    loop_num = loop_num + 1;
    if (loop_num > iterations){
      
      analogWrite(LED_pin, OFF);
      Serial.print("Ending loop!");
      unsigned long forever = 4000000000;
      delay(forever);
    }

  }
}

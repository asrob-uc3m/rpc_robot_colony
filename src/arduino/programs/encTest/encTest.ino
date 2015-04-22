

const int outputA = 7;     
const int outputB = 6;      
int tick_A = 0;
int tick_B = 0;

int count = 0;
int tick_last = 0;

unsigned long time = 0;
unsigned long time_last = 0;

int vel;

void setup() {
  Serial.begin(9600);
  pinMode(outputA, INPUT);      
  pinMode(outputB, INPUT);     
}

void loop(){
  tick_A = digitalRead(outputA);
  /*tick_B = digitalRead(outputB);
  Serial.print("tick_A ");
  Serial.println(tick_A);
  Serial.print("tick_B ");
  Serial.println(tick_B);*/
  
  if(tick_A != tick_last) {
    count++;
    tick_last = tick_A;
    
    time = millis() - time_last;
    time_last = time;
    
    vel = 300 / time; 
  }
  
  Serial.print("counts ");
  Serial.println(count);
}

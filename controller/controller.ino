
int sp = 150;
void setup() {
  pinMode(2,OUTPUT);  // Side +ve
  pinMode(3,OUTPUT);  // Side -ve
  pinMode(4,OUTPUT);  // Front +ve
  pinMode(5,OUTPUT);  // Front -ve
  pinMode(6,OUTPUT);  // Cart +ve
  pinMode(7,OUTPUT);  // Cart -ve
  pinMode(8,OUTPUT);  // Vacuum +ve
  pinMode(9,OUTPUT);  // Vacuum -ve
  
  pinMode(A0,OUTPUT); // Side Left
  pinMode(A1,OUTPUT); // Side Right
  pinMode(A2,OUTPUT); // Front Left
  pinMode(A3,OUTPUT); // Front Right
  pinMode(A4,OUTPUT); // Cart
  pinMode(A5,OUTPUT); // Vacuum

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    char on = Serial.read();
    if(on == 's'){
      side(sp);
    }
    else if(on == 'f'){
      front(sp);
    }
    else if(on == 'c'){
      cart(sp);
    }
    else if(on == 'v'){
      vacuum(sp);
    }
    else if(on == 'i'){
      side(0);
    }
    else if(on == 'r'){
      front(0);
    }
    else if(on == 'a'){
      cart(0);
    }
    else if(on == 'u'){
      vacuum(0);
    }
    else if(on == '0'){
      front(0);
      side(0);
      vacuum(0);
      cart(0);
    }
  }
 
  delay(10);
}

void side(int value){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(A0,value);
  analogWrite(A1,value);
}

void front(int value){
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  analogWrite(A2,value);
  analogWrite(A3,value);
}

void cart(int value){
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  analogWrite(A4,value);
}

void vacuum(int value){
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  analogWrite(A5,value);
}

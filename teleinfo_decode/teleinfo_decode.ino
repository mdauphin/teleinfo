// Caractère de début de trame
#define startFrame 0x02
// Caractère de fin de trame
#define endFrame 0x03

void setup() {
  Serial.begin(9600);
  Serial1.begin(1200);
}

void loop() {
    char charIn = 0 ;
    //Wait start of trame
  while ( charIn != startFrame ) {
    charIn = Serial1.read() & 0x7F;
  }
  //wait end of trame
  for(;;) {
    if( Serial1.available()) {
      //clear 8en bits
      charIn = Serial1.read() & 0x7F ;
      if ( charIn == endFrame )
        break;
      else
        Serial.write(charIn);  
    }
  }
  Serial.println("");
}

/*
  1-Digit-7-SEGMENT-DISPLAY
      A
    F   B
      G
    E   C
      D     DP
  PIN MODE     
    2 3 4 5
    G F A B
    | | | |
    E D C DP
    6 7 8 9

   ex 3:
     A 
   .   B
     G
   .   C
     D
  
*/

const int segmentPinsCount = 8;
//                         G  F  A  B  E  D  C  DP
const int segmentPin[]  = {2, 3, 4, 5, 6, 7, 8, 9};
const int zeroPins[]    = {0, 1, 1, 1, 1, 1, 1, 0};
const int onePins[]     = {0, 0, 0, 1, 0, 0, 1, 0};
const int twoPins[]     = {1, 0, 1, 1, 1, 1, 0, 0};
const int threePins[]   = {1, 0, 1, 1, 0, 1, 1, 0};
const int fourPins[]    = {1, 1, 0, 1, 0, 0, 1, 0};
const int fivePins[]    = {1, 1, 1, 0, 0, 1, 1, 0};

const int numberPinsCount = 5;
const int numberPins[]    = {zeroPins, onePins, twoPins, threePins, fourPins, fivePins};

const int delayTime = 1000;

void setup() {
  Serial.begin(9600);
  setup7SegmentDisplay();
}

void loop() {
  countDown(numberPinsCount);
  flickerZero(numberPinsCount, 100);
} 



void countDown(int fromCount) {
  for (int i = 0; i < fromCount; i++) {
     printDisplay(numberPins[numberPinsCount - i]);
     delay(delayTime);
  }
}

void flickerZero(int count, int withDelay) {
  int i = 0;
  
  while(i < count) {
    printDisplay(zeroPins);
    delay(withDelay);
    i++;
  }
}

void printDisplay(int arr[]) {
  for (int i = 0; i < segmentPinsCount; i++) {
    digitalWrite(segmentPin[i], arr[i]); 
  }
}

void displayOff() {
  for (int i = 0; i < segmentPinsCount; i++) {
    pinMode(segmentPin[i], LOW);
  }
}

void setup7SegmentDisplay() {
  for (int i = 0; i <= segmentPinsCount; i++) {
    pinMode(segmentPin[i], INPUT);
  }  
}

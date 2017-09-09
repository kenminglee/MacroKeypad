//Clean version (no comments)
uint8_t buf[8] = {0};
#define Button_A A0
#define Button_B A1
#define Button_C A2
#define Button_D A3

bool pState_A; 
int releasedTimer_A; 
int pressTimer_A; 

bool pState_B;
int releasedTimer_B;
int pressTimer_B;

bool pState_C;
int releasedTimer_C;
int pressTimer_C;

bool pState_D;
int releasedTimer_D;
int pressTimer_D;

int pressMinTime; 
int releaseMinTime; 
 
void setup() {
  Serial.begin(9600);
  pinMode(Button_A,INPUT_PULLUP);
  pinMode(Button_B,INPUT_PULLUP);
  pinMode(Button_C,INPUT_PULLUP);
  pinMode(Button_D,INPUT_PULLUP);
  pState_A=false;
  releasedTimer_A=0;
  pressTimer_A=0;
 
  pState_B=false;
  releasedTimer_B=0;
  pressTimer_B=0;
  
  pState_C=false;
  releasedTimer_C=0;
  pressTimer_C=0;

  pState_D=false;
  releasedTimer_D=0;
  pressTimer_D=0;
  
  pressMinTime=50;
  releaseMinTime=50;
  delay(200);
}

void loop() {
  if(digitalRead(Button_A)==LOW&&digitalRead(Button_C)!=LOW){
    if(pState_A==false&&(releasedTimer_A>releaseMinTime)){
      buf[2]=29;//press z
      Serial.write(buf,8); 
      pState_A=true;
      releasedTimer_A=0;
    }
    pressTimer_A+=1;
  }

  if(digitalRead(Button_A)!=LOW){
    if(pState_A==true&&(pressTimer_A>pressMinTime)){
      releaseKey(2);
      pState_A=false;
      pressTimer_A=0;
    }
    releasedTimer_A+=1;
  }

    if(releasedTimer_A>(releaseMinTime*2)){
      releasedTimer_A=releaseMinTime+1;
    }
  
    if(pressTimer_A>(pressMinTime*2)){
      pressTimer_A=pressMinTime+1;
    }
    
  if(digitalRead(Button_B)==LOW&&digitalRead(Button_D)!=LOW){
    if(pState_B==false&&(releasedTimer_B>releaseMinTime)){
      buf[3]=27;//press x
      Serial.write(buf,8);  
      pState_B=true;
      releasedTimer_B=0;
    }
    pressTimer_B+=1;
  }

  if(digitalRead(Button_B)!=LOW){
    if(pState_B==true&&(pressTimer_B>pressMinTime)){
      releaseKey(3);
      pState_B=false;
      pressTimer_B=0;
    }
    releasedTimer_B+=1;
  }

  if(releasedTimer_B>(releaseMinTime*2)){
    releasedTimer_B=releaseMinTime+1;
  }

  if(pressTimer_B>(pressMinTime*2)){
    pressTimer_B=pressMinTime+1;
  }

  if(digitalRead(Button_C)==LOW&&digitalRead(Button_A)!=LOW){
    if(pState_C==false&&(releasedTimer_C>releaseMinTime)){
      buf[4]=6;//press c
      Serial.write(buf,8);  
      pState_C=true;
      releasedTimer_C=0;
   }
    pressTimer_C+=1;
  }

  if(digitalRead(Button_C)!=LOW){
    if(pState_C==true&&(pressTimer_C>pressMinTime)){
      releaseKey(4);
      pState_C=false;
      pressTimer_C=0;
    }
    releasedTimer_C+=1;
  }

  if(releasedTimer_C>(releaseMinTime*2)){
    releasedTimer_C=releaseMinTime+1;
  }

  if(pressTimer_C>(pressMinTime*2)){
    pressTimer_C=pressMinTime+1;
  }

  if(digitalRead(Button_D)==LOW&&digitalRead(Button_B)!=LOW){
    if(pState_D==false&&(releasedTimer_D>releaseMinTime)){
      buf[5]=25;//press v
      Serial.write(buf,8);  
      pState_D=true;
      releasedTimer_D=0;
    }
    pressTimer_D+=1;
  }

  if(digitalRead(Button_D)!=LOW){
    if(pState_D==true&&(pressTimer_D>pressMinTime)){
      releaseKey(5);
      pState_D=false;
      pressTimer_D=0;
      
    }
    releasedTimer_D+=1;
  }

  if(releasedTimer_D>(releaseMinTime*2)){
    releasedTimer_D=releaseMinTime+1;
  }

  if(pressTimer_D>(pressMinTime*2)){
    pressTimer_D=pressMinTime+1;
  }
}

void releaseKey(int i){
  buf[i]=0;
  Serial.write(buf,8);
}

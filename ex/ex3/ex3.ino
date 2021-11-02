//forward,back,left,right,stop motor sample
#include <Servo.h>//モータ用のインクルード
Servo servoL;
Servo servoR;
void setup() {
  // put your setup code here, to run once:
servoR.attach(4);//右モータのピンが4に配線されている場合のアタッチ
servoL.attach(5);//左モータのピンが5に配線されている場合のアタッチ
/*モータ回転位置初期化*/
servoR.write(90);
servoL.write(90);
Serial.begin(9600);//シリアル通信の転送速度
}

/*このプログラムではモータの回転角（速度）を与える関数を作っている*/
void set_motor(int L, int R){
  servoL.write(L);//0≦L≦180、90から離れるほど速く回転
  servoR.write(R);//0≦R≦180
}

double k = 500/480;//電池の消耗に応じて移動速度が落ちるため、
      //係数k(目標移動距離/実際に移動した距離)をかけて距離を調整する
void run_forward(double X){
  double T;
  T = k*(X+4.68)/0.1056;
  set_motor(150,56);
  delay(T);
  set_motor(88,88);
}

void turn_right(double A){
  double k = 90/95;
  double T;
  T = 0.95*(A+5.36)/0.0998;
  set_motor(150,150);
  delay(T);
  set_motor(88,88);
}

void turn_left(double A){
  double T;
  T = (A+5.36)/0.0998;
  set_motor(30,30);
  delay(T);
  set_motor(88,88);
}


void loop() {
  set_motor(88,88);
  delay(1000);

  //1回目の直進
  run_forward(440);
  delay(1000);
  turn_right(88);
  delay(1000);
  //2回目の直進
  run_forward(530);
  delay(1000);
  turn_right(88);
  delay(1000);
  //3回目の直進
  run_forward(350);
  delay(1000);
  turn_left(84);
  delay(1000);
  //4回目の直進
  run_forward(600);
  delay(1000);
  turn_left(84);
  delay(1000);
  //5回目の直進
  run_forward(340);
  delay(1000);
  turn_right(88);
  delay(1000);
  //6回目の直進
  run_forward(260);
  delay(10000);
}

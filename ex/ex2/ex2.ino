//回転角の測定
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

void loop() {

  set_motor(150,150);//右旋回
  delay(750);
  
  set_motor(88,88);//停止
  delay(5000);
  
  set_motor(150,150);//右旋回
  delay(1000);
  
  set_motor(88,88);//停止
  delay(5000);
  
  set_motor(150,150);//右旋回
  delay(1250);
  
  set_motor(88,88);//停止
  delay(5000);

  set_motor(150,30);//直進(3回の方向転換が終わったことを知らせる)
  delay(1000);
  
  set_motor(88,88);//停止
  delay(5000);
}

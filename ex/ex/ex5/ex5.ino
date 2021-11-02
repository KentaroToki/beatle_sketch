//アームsensor sample
/*アームの距離センサがある程度障害物に反応している間停止し、
それ以外のときは直進する*/
#include <Servo.h>
Servo servoR;
Servo servoL;
Servo arm;
int a; // arm sensor
void setup() {
  // put your setup code here, to run once:

servoR.attach(4);//右モータが4に配線されている場合のアタッチ
servoL.attach(5);
arm.attach(8);//8番のモータをアームのモータとする
//各モータの回転位置の初期化
servoR.write(88);
servoL.write(88);
arm.write(88);
Serial.begin(9600);//シリアル通信の転送速度
}

void set_motor(int L, int R){
  servoL.write(L);//0≦L≦180、90から離れるほど速く回転
  servoR.write(R);//0≦R≦180
}
//ex3のturn_rightとturn_leftを改良した引数によって旋回する方向を決めて回転する関数
//0≦A≦180ならば右回転,180<A≦360ならば左旋回する
void turn(double A){
  double k = 90/95;//回転角のずれを修正する係数
  double T;
  if(A<=180){
    set_motor(150,150);
  }else{
    set_motor(30,30);
    A=360-A;
  }
  T = 0.95*(A+5.36)/0.0998;
  delay(T);
  set_motor(88,88);
}

void loop(){
  a = analogRead(A5);//A5番のピンについている距離センサの値を読み取り
  Serial.println(a);//センサ値出力
  Serial.println();//シリアルモニタ上で改行
if(a>645) {//停止（前に障害物があるかの閾は645）
  set_motor(88,88);
  turn(90);//右旋回
  arm.write(90);//アームが前向きになるよう維持
}else{//それ以外のとき直進するように速度をあたえる
  set_motor(151,30);
  arm.write(90);//アームが前向きになるよう維持

}
  delay(5);
}

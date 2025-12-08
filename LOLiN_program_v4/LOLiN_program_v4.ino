// ESP8266 LOLİN
// Flash size 4M(FS:1MB OTA:~1019KB)
// MMU 32KBCHACE, ^'KB IRAM(balanced)



#include <Arduino.h>

#include <ESP8266HTTPClient.h>
//#include <FirebaseRealtime.h>
//#include <WiFiClient.h>
//#include <EEPROM.h>
//#include <DHT.h>
#include <ESP8266WiFi.h>
#include "LittleFS.h"
//#include <MQTT.h>
#include <Servo.h>
#include <DHT.h>



//#include <WebSocketsServer.h>
//#include <ESP8266WebServer.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

/* 2. Define the API Key */
String API_KEY = ""; // "AIzaSyDTMhGs_ISD4WKmJrCxw35rqv-bo34ZdYI";

/* 3. Define the RTDB URL */
String DATABASE_URL =""; // "https://esp-v4-default-rtdb.firebaseio.com"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
String YOL="";
/* 4. Define the user Email and password that alreadey registerd or added in your project */
String USER_EMAIL = ""; // "asadafag@gmail.com";
String  USER_PASSWORD = ""; // "bebedede14";
// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

//unsigned long sendDataPrevMillis = 0;

//unsigned long count = 0;

//unsigned long starttime;

/*

#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
ESP8266WebServer server(80);
void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}
*/




//#define FIREBASE_HOST "https://dafs-1-default-rtdb.firebaseio.com/"
//#define FIREBASE_AUTH "BPf4hnMz0jOlW-xyaM1qXVwNkWoAxSGUqSrL2o1idbWZtW4f2CPBfQexGORNUeIMTpy54S3KqQPwCWRpiEdAvuw"

//#define FIREBASE_REALTIME_URL "https://dafs-1-default-rtdb.firebaseio.com/"
//#define FIREBASE_REALTIME_SECRET "BPf4hnMz0jOlW-xyaM1qXVwNkWoAxSGUqSrL2o1idbWZtW4f2CPBfQexGORNUeIMTpy54S3KqQPwCWRpiEdAvuw"
//FirebaseRealtime firebaseRealtime;

/** NOTE: */
//#define FIREBASE_REALTIME_URL "https://dafs-1-default-rtdb.firebaseio.com/"
//#define FIREBASE_REALTIME_SECRET "BPf4hnMz0jOlW-xyaM1qXVwNkWoAxSGUqSrL2o1idbWZtW4f2CPBfQexGORNUeIMTpy54S3KqQPwCWRpiEdAvuw"
/* */









String errorlog;
int CHZz;
bool psco;
bool psci;
int gonderdimbekle;

int reConnectsayac=0;
unsigned long fbreConnetsayac=millis();



// YAZ-GÖNDER için
// chg=0 değişiklik yok bende
// chg=1 pinde değişiklik var gönder 1
// chg=2 pinlerde ve isimlerinde değişiklik var hem onları hem pinde değişikliği gönder sıra ile 2,1
// chg=3 benim myssidname değişti. hepsini gönder 3,2,1 diye

// OKU-GETİR için
// chg=10 direk chg=0 sıfır olacak
// chg=10 yani chg=10 ise oku pinde değişiklik var
// chg=11 pinlerde ve isimlerinde değişiklik var hem onları hem pinde değişikliği gönder sıra ile 2,1
// chg=12 benim myssidname değişti. hepsini gönder 3,2,1 diye



//#define FactoryDefault D7
//#define DHTPIN D3
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);

//int red = D0;
//int green = D1;
//int blue = D2;

//int sayac=0;



bool WiFiAP = true;  // Do yo want the ESP as AP?
WiFiServer httpserver(80);
String header;
String creator;

String esphostnameOnek = "";
String esphostname = "esp-bos";
bool high_low_invert = false;

unsigned int zamanfark;


String ssid = "Zyxel";
String pass = "12345678";

int aut = 0;
int autcode;
int logintimeout;
int logintimeoutmax=240000;
String capt;
String unme="admin";
String pwrd="1234";
int sayfayenile=0;


int Pin[10];
int pinsayisi=10;
// pin Adı|pinmode|pin baslangic degeri|pin değeri|pin degerleri|Pin label"
String pinsatir[10];
String pinname[10];
String pinmode[10];
String pinsignaltype[10];
String pinminvalue[10];
String pinval[10];
String PinState[10];
String ePinState[10];
String fbPinState[10];
String pinmaxvalue[10];
String pinlabel[10];

uint8_t DHT_TYPE[10];
int DHT_PIN[10];
bool DHT_AYAR_YAPILDI[10];

int dhtsayac = 0;

String tempstr="";
String humstr="";

Servo myservo[10];


String pinayar;
String Program;
String olay="a";


//DHT dht(DHTPIN, DHTTYPE);
//DHT DHTA(D8, DHT11);


String yazi;



File dosya;




String erlog="";
int erlogsatir=0;
String programdata;




bool webstart=false;
int fben;

String fberror="";












String mylocalip;

/////////// MQTTClient///////////////////
/*
WiFiClient mqttnet;
MQTTClient mqttclient;
String users;
String MQTTip ="192.168.2.213";
String GelenMesaj;
String GidenMesaj;
String Kullaniciadi[20];
String Kullanicisifresi[20];
int MaxUserkayidi=20;

String GonderenKullanici;
String GonderenSifresi;


void dosyaOkuMQTTip(){
  dosya.close();
  dosya = LittleFS.open("/MQTTip.txt", "r");
  if (dosya) {
    String geciciMQTTip = dosya.readStringUntil('\n');
    geciciMQTTip = geciciMQTTip.substring(0, geciciMQTTip.length() - 1);
    Serial.println(geciciMQTTip);
    MQTTip = geciciMQTTip;
    dosya.close();

}
else{};
}

String geciciMQTTuser;

void dosyaYazMQTTip(){
  dosya.close();
  LittleFS.remove("/MQTTip.txt");
  dosya = LittleFS.open("/MQTTip.txt", "w+");
    dosya.println(MQTTip);
  dosya.close();
  dosyaOkuMQTTip();
  mqttclient.disconnect();
  //ESP.reset();
}



String kullanici;
void dosyaOkuusers(){

  dosya.close();
  dosya = LittleFS.open("/users.txt", "r");
  if (dosya) {
          String geciciusers = dosya.readString();
          geciciusers = geciciusers.substring(0, geciciusers.length() - 1);
          users = geciciusers;
          Serial.println("geciciusers v ");
          Serial.println(geciciusers);
          Serial.print("users=================>");
          Serial.print(users);
          Serial.println("<");
          dosya.close();
        kullanici=users;


          for (int j=0;j<kullanici.length();j++){
              Kullaniciadi[j] = kullanici.substring(0,kullanici.indexOf("|"));
              kullanici= kullanici.substring(kullanici.indexOf("|")+1,kullanici.length());

              Kullanicisifresi[j] = kullanici.substring(0,kullanici.indexOf("\n"));
              kullanici= kullanici.substring(kullanici.indexOf("\n")+1,kullanici.length());

              if(kullanici.length()<1) break;

              Serial.println(Kullaniciadi[j]+"|"+ Kullanicisifresi[j]);

          }
      }
}


void dosyaYazusers(){
  dosya.close();
  LittleFS.remove("/users.txt");
  Serial.println(users);
  if(users.indexOf(users.substring(users.length()- 5, 5)),"%0"<0)users;
  dosya = LittleFS.open("/users.txt", "w+");
  MQTTuserYuzdeliifadesil();
  dosya.println(users);
  dosya.close();
  dosyaOkuusers();
  mqttclient.disconnect();
  //ESP.reset();
}

*/










bool pinlerdagitildi=false;

String Pinler;
String Pinlertpm;
void dosyaOkupinayar(){

  dosya.close();
    //LittleFS.remove("/pinayar.txt");
  dosya = LittleFS.open("/pinayar.txt", "r");
  if (dosya) {
          String gecicipinayar = dosya.readString();
          gecicipinayar = gecicipinayar.substring(0, gecicipinayar.length());
          pinayar = gecicipinayar;
          //Serial.println("gecicipinayar v ");
          //Serial.println(gecicipinayar);
          dosya.close();
        Pinlertpm=pinayar;
        //Serial.println(pinayar);
/*
String pinname[9];
String pinmode[9];
String pinstartvalue[9];
String pinvalue[9];
String pinvalues[9];
String pinlabel[9];
*/
erlog="";

if(Pinlertpm.length()>0){

          for (int x=0;x<Pinlertpm.length();x++){
              if(Pinlertpm.length()<1) break;
              String pinnametm=Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              int pinismiint;
              if(pinnametm.length()>1){
              pinismiint= pinnametm.substring(1,2).toInt();
              if(pinnametm.substring(0,1)=="A")pinismiint+= 9;
              } else pinismiint=pinnametm.toInt();

              //Serial.println(pinnametm);
              //Serial.println(pinismiint);
              
              x = pinismiint;

              pinsatir[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("\n"));

              //Serial.println(j);
              pinname[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              pinmode[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              pinsignaltype[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              pinminvalue[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              if(pinlerdagitildi==false){
              pinlerdagitildi=true;
                if(PinState[x]==""){
                  if(pinsignaltype[x]=="PWM"){
                    int asd=Pinlertpm.substring(0,Pinlertpm.indexOf("|")).toInt();
                    if(asd<0)PinState[x]="0";
                    if(asd>255)PinState[x]=255;
                  }
                  if(pinsignaltype[x]=="SER"){
                    int asd=Pinlertpm.substring(0,Pinlertpm.indexOf("|")).toInt();
                    if(asd<0)PinState[x]="0";
                    if(asd>180)PinState[x]=180;
                  }else PinState[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|")); 

                  ePinState[x]=PinState[x];
                }
              }
              pinval[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|")); 
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              pinmaxvalue[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("|"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("|")+1,Pinlertpm.length());

              //Serial.print("label bu");Serial.println(Pinlertpm);

            if(Pinlertpm.indexOf("\n")>-1){
              pinlabel[x] = Pinlertpm.substring(0,Pinlertpm.indexOf("\n"));
              Pinlertpm= Pinlertpm.substring(Pinlertpm.indexOf("\n")+1,Pinlertpm.length());
            }
            else
            {
              pinlabel[x] = Pinlertpm.substring(0,Pinlertpm.length());  
              Pinlertpm="";
            }

            if(Pinlertpm.length()<1) break;

          }
        }
      }


}


void dosyaYazpinayar(){
  reConnectsayac=0;
  dosya.close();
  LittleFS.remove("/pinayar.txt");
  Serial.println(pinayar);
  dosya = LittleFS.open("/pinayar.txt", "w+");
  //pinayarYuzdeliifadesil();
  dosya.print(pinayar);
  dosya.close();
  dosyaOkupinayar();
  dosyaokufbyol();
  fbpinayarlariyaz();
  fbpinstateleriyaz();
  setup2();
  //ESP.reset();

//  IPAddress lip = WiFi.localIP(); // rastgele zamanda göndermek için sayı
//  String gvs=String(lip[3]); // rastgele zamanda göndermek için sayı
//  int gv= gvs.toInt(); // rastgele zamanda göndermek için sayı
//delay(random(esphostname.length(),esphostname.length()+100)); // rastgele zamanda göndermek için sayı
//  olay="a";
//  chgstate=true;
  
  // httpgonder();
}



String butonactcol = "d1ca03";
String butonpascol = "A3A3A3";
String butonayrcol = "20d3c8";
String butonpbgcol = "ffb12a";


void butonactcoloku(){
  dosya.close();
  dosya = LittleFS.open("/butonactcol.txt", "r");
  if (dosya) {
  String butonactcol1 = dosya.readStringUntil('\n');
  butonactcol = butonactcol1.substring(0, butonactcol1.length() - 1);
  //Serial.println(butonactcol);
  dosya.close();
}else{
      butonactcol = "d1ca03";
    }
}

void butonactcolyaz(){
  dosya.close();
  LittleFS.remove("/butonactcol.txt");
  //Serial.println(butonactcol);
  dosya = LittleFS.open("/butonactcol.txt", "w+");
  dosya.println(butonactcol);
  dosya.close();
  butonactcoloku();
}

void butonpascoloku(){
  dosya.close();
  dosya = LittleFS.open("/butonpascol.txt", "r");
  if (dosya) {
  String butonpascol1 = dosya.readStringUntil('\n');
  butonpascol = butonpascol1.substring(0, butonpascol1.length() - 1);
  //Serial.println(butonpascol);
  dosya.close();
  }else{
     butonpascol = "A3A3A3";
  }
}

void butonpascolyaz(){
  dosya.close();
  LittleFS.remove("/butonpascol.txt");
  //Serial.println(butonpascol);
  dosya = LittleFS.open("/butonpascol.txt", "w+");
  dosya.println(butonpascol);
  dosya.close();
  butonpascoloku();
}

void butonayrcoloku(){
  dosya.close();
  dosya = LittleFS.open("/butonayrcol.txt", "r");
  if (dosya) {
  String butonayrcol1 = dosya.readStringUntil('\n');
  butonayrcol = butonayrcol1.substring(0, butonayrcol1.length() - 1);
  //Serial.println(butonayrcol);
  dosya.close();
  }else{
    butonayrcol = "20d3c8";
  }
}

void butonayrcolyaz(){
  dosya.close();
  LittleFS.remove("/butonayrcol.txt");
  //Serial.println(butonayrcol);
  dosya = LittleFS.open("/butonayrcol.txt", "w+");
  dosya.println(butonayrcol);
  dosya.close();
  butonayrcoloku();
}

void butonpbgcoloku(){
  dosya.close();
  dosya = LittleFS.open("/butonpbgcol.txt", "r");
  if (dosya) {
  String butonpbgcol1 = dosya.readStringUntil('\n');
  butonpbgcol = butonpbgcol1.substring(0, butonpbgcol1.length() - 1);
  //Serial.print("butonpbgcol:"); Serial.println(butonpbgcol);
  dosya.close();
  } else
  {
   butonpbgcol = "ffb12a";
  }
}

void butonpbgcolyaz(){
  dosya.close();
  LittleFS.remove("/butonpbgcol.txt");
  //Serial.println(butonpbgcol);
  dosya = LittleFS.open("/butonpbgcol.txt", "w+");
  dosya.println(butonpbgcol);
  dosya.close();
  butonpbgcoloku();
}

/*
int mqttconnectsayac;
void MQTTConnect(){

  if(mqttconnectsayac==0)
  {
    dosyaOkuusers();
    dosyaOkuMQTTip();
    const char* ipAdres = MQTTip.c_str();
    mqttclient.begin(ipAdres, mqttnet);

    String Client_IDm = esphostname;
    const char* Client_IDconstchar=Client_IDm.c_str();

    mqttclient.connect(Client_IDconstchar, "public", "public");
    mqttclient.onMessage(messageReceived);
    Serial.println("\nTry connect!");
    mqttconnectsayac=1;
  }else{
  if(mqttconnectsayac%1000 == 0)Serial.print("*");
  mqttconnectsayac+=1;
  if(mqttconnectsayac>5000)mqttconnectsayac=0;
  }


  if(mqttclient.connected()){ 
    Serial.println("\nconnected!");
    mqttclient.subscribe("/EV/KAT:1_DAiRE:1/BALKON/");
  // client.unsubscribe("/hello");
  }
}

String Gelenmsg;
String eGelenMesaj="";
String Gelentopic;
String eTopic;
String ePayload;
String publishmesaj;
int mqttmesajzamansayac;

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
if(payload.indexOf("!")==0) return;



Gelenmsg=payload; Serial.println(Gelenmsg);
Gelentopic=topic;
if(mqttmesajzamansayac==0) ePayload="";
if(Gelenmsg==ePayload && Gelentopic == eTopic) return;
  else{
    eTopic=Gelentopic;
    ePayload=Gelenmsg;
    mqttmesajzamansayac=1;
  }
  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.

Genelmesajiparcala();
UservePasskayitlimi();
}
//////////////////////////////////////////

void Genelmesajiparcala(){
userpasbulMesajAyir();
}

int normal=-1;
void userpasbulMesajAyir(){
      String Gelenmsgyedek=Gelenmsg;
    //////// username bulucu ////////////////////////////////
      if(Gelenmsg.indexOf("|*") > -1){
        GonderenKullanici = Gelenmsg.substring(0, Gelenmsg.indexOf("|*"));
        Serial.println("Kullanıcı = " + GonderenKullanici);
        Gelenmsg= Gelenmsg.substring(Gelenmsg.indexOf("|*")+2 , Gelenmsg.length()-GonderenKullanici.length()+2 );
        //Serial.println(Gelenmsg);

    //////// user alındı ve gelenmsg kesildi


    //////// password bulucu //////////////////////////////////
      if(Gelenmsg.indexOf("*|") > -1){
        GonderenSifresi = Gelenmsg.substring(0, Gelenmsg.indexOf("*|"));
        Gelenmsg = Gelenmsgyedek.substring(Gelenmsgyedek.indexOf("*|")+2,Gelenmsgyedek.length() );
        Serial.println("Kalan msg: " + Gelenmsgyedek.substring(Gelenmsgyedek.indexOf("*|")+2,Gelenmsgyedek.length() ) );
      GelenMesaj=Gelenmsgyedek.substring(Gelenmsgyedek.indexOf("*|")+2,Gelenmsgyedek.length() );
 
      
      }
    //////// password alındı ve gelenmsg kesildi
      //pasword decode edilecek
      String GelenpassSifreli = GonderenSifresi;
      String GelenpassNormal = "";
      
    // ilk 2 si trimlenecek
      GelenpassSifreli=GelenpassSifreli.substring(2,GelenpassSifreli.length()); // fazlalık at (2 at çünkü fazladan random uydurduk)
Serial.println(GelenpassSifreli);
      int sifretrim = (GelenpassSifreli.substring(0,1).toInt());
      Serial.print("sifretrim  ");
      Serial.println(sifretrim);
      GelenpassSifreli=GelenpassSifreli.substring(1,GelenpassSifreli.length()); // sifretrim sayısını at
Serial.println(GelenpassSifreli);
      GelenpassSifreli=GelenpassSifreli.substring(1,GelenpassSifreli.length()); // fazlalık at (1 at çünkü fazladan random uydurduk)

      int sifreupdown = (GelenpassSifreli.substring(0,1).toInt());
      Serial.print("sifreupdown  ");
      Serial.println(sifreupdown);
      GelenpassSifreli=GelenpassSifreli.substring(1,GelenpassSifreli.length()); // sifreupdown sayısını at
      GelenpassSifreli=GelenpassSifreli.substring(1,GelenpassSifreli.length()); //  fazlalık at (1 at çünkü fazladan random uydurduk)
Serial.println(GelenpassSifreli);
    // şifre burada DÖNGÜ İLE onu ayır döngüsü 1 al 1 at (1 at çünkü fazladan random uydurduk) fazlalık at gitsin
    // length-2 çünkü son ikisi de uydurma fazlalık 
      String Sifretrimsiz="";
      Serial.print("GelenpassSifreli length :");
      Serial.println(GelenpassSifreli.length());
      for (int z=0;z < GelenpassSifreli.length()+1000;z++)
      {
        Sifretrimsiz+=GelenpassSifreli.substring(0,1);
        GelenpassSifreli=GelenpassSifreli.substring(2,GelenpassSifreli.length()); //  fazlalık at (1 at çünkü fazladan random uydurduk)
      if (GelenpassSifreli.length()<2)break;
        Serial.println(Sifretrimsiz);

      }
        Serial.println(Sifretrimsiz);
    // şifre up down cözülecek normale dönecek (trimsiz)

      String GonderenSifresion="";
      String GonderenSifresiarka="";
    //char* Sifreupdownsuz="";

      GonderenSifresion = Sifretrimsiz.substring(0,Sifretrimsiz.length()-sifretrim);
      GonderenSifresiarka += Sifretrimsiz.substring(Sifretrimsiz.length()-sifretrim,Sifretrimsiz.length());
      GonderenSifresi=GonderenSifresiarka+GonderenSifresion;
        Serial.println("GonderenSifresi : " +GonderenSifresi);

    }
}


///// user ve pass var mı?
void UservePasskayitlimi(){
  String onek="!";

  IPAddress lip = WiFi.localIP();
  mylocalip = String(lip[0]) + '.' + String(lip[1]) + '.' + String(lip[2]) + '.' + String(lip[3]);

      for(int k=0;k<MaxUserkayidi;k++){
        Serial.println(Kullaniciadi[k]);
        if(Kullaniciadi[k]=="") 
        {

                publishmesaj="ĞÇÇ<- ["+ esphostname + "!]\n"+mylocalip;
                mqttclient.publish(Gelentopic, onek+GonderenKullanici+publishmesaj);
                publishmesaj="";
        publishmesaj="";
        return;
        }
        Serial.println(k);
        Serial.print("Gönderen kullanıcı : ");Serial.println(GonderenKullanici); 
        Serial.print("Kayıtlı kullanıcı :");Serial.println(Kullaniciadi[k]);
        Serial.print("Gönderen sifresi : ");Serial.println(GonderenSifresi); 
        Serial.print("Kayıtlı sifresi :");Serial.println(Kullanicisifresi[k]);

        if(GonderenKullanici == Kullaniciadi[k])
        {
          Serial.println("kunnalıcı adı okey");
            if(GonderenSifresi == Kullanicisifresi[k])
            {
              Serial.println("kunnalıcı şifresi okey");
              if(GelenMesaj == "yetkisor")
              {
                publishmesaj="ĞŞÇ<- [" + esphostname + "]\n" + mylocalip;
                mqttclient.publish(Gelentopic, onek+GonderenKullanici+ publishmesaj);
                publishmesaj="";
                delay(5);
                // pin bilgilerimi gönder() yazılacak
              break;
              }


              if(GelenMesaj == "P/1"){
                publishmesaj="|*P/1 On*| <- [" + esphostname + "]";
                mqttclient.publish(Gelentopic, onek+GonderenKullanici+publishmesaj);
               publishmesaj="";
               break;
               }

                //publishmesaj=programdata;
                //mqttclient.publish(Gelentopic,onek+GonderenKullanici+publishmesaj + "<- [" + esphostname + "]");


            publishmesaj="";
              break;
            } else {
                publishmesaj="ĞÇÇ<- ["+ esphostname + "!]\n" + mylocalip;
                mqttclient.publish(Gelentopic, onek+GonderenKullanici+publishmesaj);
                publishmesaj="";
            break;
            }
        }
        publishmesaj="";
      }


}

*/



///// EEPROM İŞLEMLERİ BAŞLANGICI /////////////////////////
int datavar = 0;










void esp01() {
  // MQTT OLACAK FİREBASE YOK RESET ÇEKİP DURMASIN.
  // MQTT İLE MESAJ YOLLAMAYA HAZIR.
  // 192.168.2.105
  //http://192.168.4.1/ssidset?ssid=Zyxel&pass=bebedede14
  //
  // esp role alttaki direnci sök.   bir de 10k ile 3v3 ü aşırt 3. bacağına bağla
  // bordun üstünden bakarken
  //
  //  /-10k--\
//|*   *    *    *        5v GND    role çıkışlar
  //|
  //|*   *    *    *
  //|
  //|    ESP8266
  //|
  //|     anten                     ROLE
  //|_______________                   |
  //                                   |
  //     5v>3.3v                       |
  // GPIO0 = 0      int role=0         |
  //       R1\                         |
  //          |-base-- Transistor -3v  |
  //       R2/           |_____________|
  //led
  //      R2 yi sök


 Pin[0] = 0;
 Pin[2] = 2;

}

void espLolin() {
  //Led = D4;

   Pin[0] = D0;
   Pin[1] = D1;
   Pin[2] = D2;
   Pin[3] = D3;
   Pin[4] = D4;
   Pin[5] = D5;
   Pin[6] = D6;
   Pin[7] = D7;
   Pin[8] = D8;
   Pin[9] = A0;
}


int ifcondition=0;
// epromlu versiyonda eprom cleareprom
/*
void cleareprom() {
  for (int i = 0; i < 80; ++i) {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
  Serial.println("eprom cleared");
  delay(10);

  EEPROM.write(80, 'v');
  EEPROM.write(81, '3');
  EEPROM.write(82, 0);
  for (int i = 83; i < 200; ++i) {
    EEPROM.write(i, 0);
  }
  Serial.println("Factory default... D8 unplug HIGH jumper");
  while (digitalRead(FactoryDefault) == HIGH) {
    delay(1000);
    Serial.println("3.3v ile D8 bağlantısını çıkart.");
  }
}
*/









void setup2(){
dosyaOkuprogram();
String progtmp=programdata; progtmp.toUpperCase();
if(progtmp.indexOf("PIN_INVERT;") >-1 ) high_low_invert=true; else high_low_invert=false;
//Serial.println("sorunyok");
dosyaOkupinayar();
//Serial.println("sorunyok2");
        //DHT DHTA(D7, DHT11);



for (int c=0;c<pinsayisi;c++){
      if(pinmode[c]=="OUT" & pinsignaltype[c]=="DIG"){
          if(c==0) pinMode(Pin[0], OUTPUT);
          if(c==1) pinMode(Pin[1], OUTPUT);
          if(c==2) pinMode(Pin[2], OUTPUT);
          if(c==3) pinMode(Pin[3], OUTPUT);
          if(c==4) pinMode(Pin[4], OUTPUT);
          if(c==5) pinMode(Pin[5], OUTPUT);
          if(c==6) pinMode(Pin[6], OUTPUT);
          if(c==7) pinMode(Pin[7], OUTPUT);
          if(c==8) pinMode(Pin[8], OUTPUT);
          if(c==9) pinMode(Pin[9], OUTPUT);
      }


      if(pinmode[c]=="INP" & pinsignaltype[c]=="DIG"){
          if(c==0) pinMode(Pin[0], INPUT);
          if(c==1) pinMode(Pin[1], INPUT);
          if(c==2) pinMode(Pin[2], INPUT);
          if(c==3) pinMode(Pin[3], INPUT);
          if(c==4) pinMode(Pin[4], INPUT);
          if(c==5) pinMode(Pin[5], INPUT);
          if(c==6) pinMode(Pin[6], INPUT);
          if(c==7) pinMode(Pin[7], INPUT);
          if(c==8) pinMode(Pin[8], INPUT);
          if(c==9) pinMode(Pin[9], INPUT);
      }



      if(pinmode[c]=="OUT" & pinsignaltype[c]=="PWM"){

          pinMode(Pin[c],OUTPUT);

//          pinMode(Pin[b], OUTPUT);
      }


      if(pinmode[c]=="OUT" & pinsignaltype[c]=="SER"){
          
          pinMode(Pin[c],OUTPUT);
          myservo[c].detach();
          myservo[c].attach(Pin[c]);
//        
      }


}

  // Set outputs to LOW


// servo ise /////////////////////////////////////////////////////////////////
// myservo.attach(2);
// loopa 
    //myservo.write(pos);  // tell servo to go to position in variable 'pos'
    //delay(15);           // waits 15ms for the servo to reach the position
////////////////////////////////////////////////////////////////////////////////



// DHT ise ///////////////////////////////////////////////////////////////////
//#define DHTPIN 2     // Digital pin connected to the DHT sensor

//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// DHT dht(DHTPIN, DHTTYPE);

// loopa
/*
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  */




}




String headerOld;
int headerclear = 0;


int Menu=0;





bool testWifi(void) {
  if (ssid.length() < 2) {
    return false;
  }
  int c1 = 0;
  Serial.println("Waiting>connecting Wifi");
  //display.drawBitmap(0, 0,  Lan_off_logo8x16_glcd_bmp, 16, 8, 1);
  //display.println();
  //display.println("Modeme");
  //display.println("Baglaniyor");
  //display.display();
  Serial.print(ssid + "  " + pass);
  while (c1 < 11) {
    if (WiFi.status() == WL_CONNECTED) {
      //  display.drawBitmap(0, 0,  Lan_on_logo8x16_glcd_bmp, 16, 8, 1);
      //  display.display();
      return true;
    }
    delay(1000);
    Serial.print("*");
    if(LED_BUILTIN==HIGH)digitalWrite(LED_BUILTIN, LOW); else digitalWrite(LED_BUILTIN, HIGH);

    c1++;
    serin();
  }
  Serial.println("");
  Serial.println("Connect timeout,open AP");
  return false;
}


// ip string parçalama için gereken değişkenler
/* 
String liptmp;
String giptmp;
String suptmp;

String lip[4];
String sup[4];
String gip[4];
*/
// ip adreste noktaları virgüle değiştirmek için parçalama metodu başlangıç
/*

    // local ip cfg;
    String liptm=liptmp;
    String lipadrtmp="";
    for(int lips=1;lips<5;lips++){
    lip[lips]=liptm.substring(0,liptm.indexOf("."));
        liptm=liptm.substring(liptm.indexOf(".")+1,liptm.length());
    if (lips<4) lipadrtmp += lip[lips]+",";
    if (lips==4) lipadrtmp += lip[lips];
    }
    IPAddress lipadr=IPAddress().fromString(lipadrtmp);


    String giptm=giptmp;
    String gipadrtmp="";
    for(int gips=1;gips<5;gips++){
    gip[gips]=giptm.substring(0,giptm.indexOf("."));
        giptm=giptm.substring(giptm.indexOf(".")+1,giptm.length());
    if (gips<4) gipadrtmp += gip[gips]+",";
    if (gips==4) gipadrtmp += gip[gips];
    }
    IPAddress gipadr=IPAddress().fromString(gipadrtmp);



    String suptm=suptmp;
    String supadrtmp="";
    for(int sups=1;sups<5;sups++){
    sup[sups]=suptm.substring(0,suptm.indexOf("."));
        suptm=suptm.substring(suptm.indexOf(".")+1,suptm.length());
    if (sups<4) supadrtmp += sup[sups]+",";
    if (sups==4) supadrtmp += sup[sups];
    }
    IPAddress supadr=IPAddress().fromString(supadrtmp);




Serial.println(lipadr);
Serial.println(gipadr);
Serial.println(supadr);
*/
// ip adreste noktaları virgüle değiştirmek için parçalama metodu bitişi


void connectWifi(void) {
  WiFi.mode(WIFI_AP_STA); /*1*/  //ESP8266 works in both AP mode and station mode
  //WiFi.mode(WIFI_STA); /*2*/  // ESP8266 works in station mode
  // WiFi.begin(ssid, password); // given the network

  //    Serial.print(ssid);
  //    Serial.print("connecting to ");
  //    while (WiFi.status() != WL_CONNECTED) {
  //      // not connected to the network
  //    delay(500);
  //    Serial.print(".");
  //  }
  dosyaokussidpass();
  WiFi.hostname(esphostname);
  WiFi.begin(ssid, pass);
  //Serial.println(ssid);
  //Serial.println(pass);
  //delay(1000);
  
  if (testWifi()) {
    Serial.println("Succesfully Connected!!!");
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.gatewayIP());
    WiFi.softAP(esphostname, "bebedede14");  // bağlanınca ap kalksın için // koyabiliriz.

  IPAddress lip = WiFi.localIP();
  mylocalip = String(lip[0]) + '.' + String(lip[1]) + '.' + String(lip[2]) + '.' + String(lip[3]);

    //buzzercal(2000, 3); delay(100);
    //buzzercal(3000, 2); delay(10);
  } else {

    WiFi.hostname(esphostname);
    Serial.println("Turning the HotSpot On");
    //                                wifiscan();
    //                                lookAP();// S etup HotSpot
    WiFi.softAP("Esp01-bos-v3", "12345678");
    //delay(100);
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.gatewayIP());
    //buzzercal(3000, 50); delay(100);
    //buzzercal(2500, 70); delay(100);
    //buzzercal(1500, 100); delay(10);
  }

  //firebaseRealtime.begin(FIREBASE_REALTIME_URL, FIREBASE_REALTIME_SECRET);


}



int statusCode;
String st;
void wifiscan(void) {
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else {
    st = "[ " + String(n) + " ] networks found<br>";
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      //delay(4);
    }
  }
  Serial.println("");
  //st = "<ol>";
  st += "<ol>";
  for (int i = 0; i < n; ++i) {
    // Print SSID and RSSI for each network found
    st += "<li>";
    st += WiFi.SSID(i);
    st += " (";
    st += WiFi.RSSI(i);

    st += ")";
    st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    st += "</li>";
  }
  st += "</ol><br>";

}


/*
bool dhtsensorerror;
float hic, hum, f, t;

 void dhtget(int pinno) {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  DHTA.read();
  delay(20);
  hum = DHTA.readHumidity();
  //f = dht.readTemperature(true);
  //  hum=dht.computeHeatIndex(f, hum);
  // Read temperature as Celsius (the default)
  delay(10);
  t = DHTA.readTemperature();  //
  // Read temperature as Fahrenheit (isFahrenheit = true)


  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(t)  // || isnan(f)
  ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    dhtsensorerror = true;
    return;
  } else {
    dhtsensorerror = false;
   
  }
  // Compute heat index in Fahrenheit (the default)
  //  hum = dht.computeHeatIndex(f, hum);
  // Compute heat index in Celsius (isFahreheit = false)
  hic = t;  //
  //hic = dht.computeHeatIndex(hic, hum, false)+hicfark;  // eskiden t idi

  Serial.print(("Humidity: "));
  Serial.print(hum);
  Serial.print(("%  Temperature: "));
  Serial.print(hic);
  Serial.print((" C"));
  Serial.println(".");
}
*/








// Current time
unsigned int xcurrentTime = 0;
// Previous time
// Define timeout time in milliseconds (example: 2000ms = 2s)
const int timeoutTime = 3000;

int say=0;



/*
http://192.168.2.97/programkayit?is=

EGER+%28D1.DEGER+>+35.5%29+D3.DEGER%3DHIGH%0D%0AEGER+%28D1.DEGER+<+30.0%29+D3.DEGER%3DLOW
D4%3DD1%2FD2%3BD3*D5%25aaa%3F

%20  :boşluk actionadresi icinde iken
+    :boşluk databloğu içinde iken
%7C  :|
%28  :(
>    :>
%29  :)
%3D  :=
%0D%0A: \r\n  (enter ve satır sonu) karakterleri
%2F  :/
*    :*
%25  :%
%3F  :?
%3B  :;
%26  :&
*/

// float tanımlama için
int floatDegiskenSayisi=0;
//

// işlemler için 
String floatdegiskenismi[27];
float floatdegiskenvalue[27];
int floatdegiskenismisayisi=27;
String islem;
//


void dosyaOkuprogram(){
  dosya.close();
  dosya = LittleFS.open("/program.txt", "r");
  if (dosya) {
          programdata = dosya.readString();
          programdata = programdata.substring(0, programdata.length() - 1);
          //Serial.println("gecicipinayar v ");
          //Serial.println(gecicipinayar);
          dosya.close();
  }else{
    programdata=" \n";
  }
}


void dosyaYazprogram()
{
  reConnectsayac=0;
  for(int x=0 ; x < floatdegiskenismisayisi+1 ; x++){
  floatdegiskenismi[x]="";
  floatdegiskenvalue[x]=0;
  }

for(int x=0 ; x < pinsayisi ; x++){
  pinname[x]="";
  pinmode[x]="";
  pinsignaltype[x]="";
  pinminvalue[x]="";
  PinState[x]="";
  ePinState[x]="";
  pinmaxvalue[x]="";
  pinlabel[x]="";
  }
  



Karakterduzelt();
//Serial.print("Yazilacakprogramdata:");
erlog="";

  dosya.close();
  LittleFS.remove("/program.txt");
  //Serial.println(programdata);

  dosya = LittleFS.open("/program.txt", "w+");
  dosya.print(programdata);
  dosya.close();

  setup2();
  //ESP.reset();




}







int yakinOlaninkoordinati=0;
int yazilacakkarakterno;
String yakinOlan="";

String karakter[38];
String yerinegec[38];

void Karakterduzelt(){
   karakter[0] ="%20"; //  :boşluk actionadresi icinde iken
   yerinegec[0] = " ";
 karakter[1] ="+";   //    :boşluk databloğu içinde iken
   yerinegec[1] = " ";
 karakter[2] ="%25"; //  :%
   yerinegec[2] = "%";
 karakter[3] ="%26"; //  :&
   yerinegec[3] = "&";
 karakter[4] ="%28"; //  :(
   yerinegec[4] = "(";
 karakter[5] ="%29"; //  :)
   yerinegec[5] = ")";
 karakter[6] ="%7C"; //  :|
   yerinegec[6] = "|";
 karakter[7] ="%2F"; //  :/
   yerinegec[7] = "/";
 karakter[8] ="%3B"; //  :;
   yerinegec[8] = ";";
 karakter[9] ="%3D"; //  :=
   yerinegec[9] = "=";
 karakter[10] ="%3F"; //  :?
   yerinegec[10] = "?";
 karakter[11] ="%0D%0A"; //: \r\n  (enter ve satır sonu) karakterleri
   yerinegec[11] = "\r\n";
 karakter[12] ="%3E"; //  :>
   yerinegec[12] = ">";
 karakter[13] ="%3C"; //  :<
   yerinegec[13] = "<";
 karakter[14] ="%7B"; //  :{
   yerinegec[14] = "{";
 karakter[15] ="%7D"; //  :}
   yerinegec[15] = "}";
 karakter[16] ="%5B"; //  :[
   yerinegec[16] = "[";
 karakter[17] ="%5D"; //  :]
   yerinegec[17] = "]";
 karakter[18] ="%2B"; //  :+
   yerinegec[18] = "+";
//         - * /  aynı
 karakter[19] ="%21"; //  :!
   yerinegec[19] = "!";

 

String progtmp = programdata;
String Yazilacakprogramdata;


      yakinOlaninkoordinati=10000;
  for(int y=0;y<1100;y++){
    if(progtmp.length()<1)break;
    for(int x=0;x<20;x++){
    if(progtmp.indexOf(karakter[x])>-1){
        if(yakinOlaninkoordinati > progtmp.indexOf(karakter[x])){
          yakinOlaninkoordinati = progtmp.indexOf(karakter[x]);
          yakinOlan=karakter[x];
          yazilacakkarakterno=x;
        }
      }
    }


      Yazilacakprogramdata += progtmp.substring(0,yakinOlaninkoordinati);
      progtmp = progtmp.substring(yakinOlaninkoordinati+yakinOlan.length() , progtmp.length());
      Yazilacakprogramdata += yerinegec[yazilacakkarakterno]; 


      //Serial.print("Yazilacakprogramdata:");
      //Serial.println(Yazilacakprogramdata);
      yakinOlaninkoordinati=10000;
      yakinOlan="";
  }

    //Yazilacakprogramdata.toUpperCase();
    programdata=Yazilacakprogramdata.substring(0,Yazilacakprogramdata.length()-2);

    if(programdata.indexOf(" HTTP/1.1")>-1)programdata = programdata.substring(0,programdata.indexOf(" HTTP/1.1")+1);
    


}

int sayPtakipicin = 0;

unsigned long lastMillis;



int sil=0;

void setup() {
   // initialize LED_BUILTIN as an output pin.
   // starttime=millis();
   pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  espLolin();

dosyaOkupinayar();
dosyaOkuprogram();
if(programdata.indexOf("PIN_INVERT;")>-1)
{ 
  high_low_invert=true;

  for(int i=0;i<pinsayisi+1;i++)
  {
    if(pinmode[i]=="OUT") 
    {
      pinMode(Pin[i], OUTPUT);
      digitalWrite(i, HIGH);
    }
  }
}


// dosya setup kısmı ////////////////
  if (LittleFS.begin()) {
    Serial.println();
    Serial.println("Dosya sistemi başarılı");

          if (sil==1)
            {
              LittleFS.remove("/pinayar.txt");
              delay(10);
              LittleFS.remove("/ssidpass.txt");
              delay(10);
              LittleFS.remove("/users.txt");
              delay(10);
              LittleFS.remove("/MQTTip.txt");
              delay(10);
              LittleFS.remove("/myssidname.txt");
              delay(10);
              sil=0;
            }




  } else {
    Serial.println("Dosya sistemi başarısız");
  }
  dosyaokumyssidname();
  //delay(2);
  dosyaokussidpass();
  //delay(2);
// dosya setup kısmı bitti /////  

  dosyaokufben();


 if (WiFi.status() != WL_CONNECTED) connectWifi();

//delay(10);

//Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

connectfb();




    dosyaOkupinayar();
    setup2();
    otasetup();
}




void connectfb()
{


  if(fben>0){
  dosyaokufburl();
  dosyaokufbapi();
  dosyaokufbusername();
  dosyaokufbuserpass();
  
            IPAddress lip = WiFi.localIP();
if (String(lip[0]) != "0" && fben>0 && DATABASE_URL !="" && API_KEY != "" && USER_EMAIL != "" && USER_PASSWORD != "")
{

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  
  auth.user.email = USER_EMAIL+"@gmail.com";
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */

  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

  // Or use legacy authenticate method
  // config.database_url = DATABASE_URL;
  // config.signer.tokens.legacy_token = "<database secret>";

  // To connect without auth in Test Mode, see Authentications/TestMode/TestMode.ino

  //////////////////////////////////////////////////////////////////////////////////////////////
  // Please make sure the device free Heap is not lower than 80 k for ESP32 and 10 k for ESP8266,
  // otherwise the SSL connection will fail.
  //////////////////////////////////////////////////////////////////////////////////////////////

  // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
  Firebase.reconnectNetwork(false);

  // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
  // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
  fbdo.setBSSLBufferSize(2048 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  
  // Limit the size of response payload to be collected in FirebaseData
  fbdo.setResponseSize(2048);



  // The WiFi credentials are required for Pico W
  // due to it does not have reconnect feature.

  Firebase.setDoubleDigits(2);

  config.timeout.serverResponse = 10 * 1000;


//MQTTConnect();
  //analogWrite(red, 255);
  //analogWrite(green, 240);
  //analogWrite(blue, 255);







  //analogWrite(red, 255);
  //analogWrite(green, 240);
  //analogWrite(blue, 240);



    if(fben>0)
    {
        fben+=1;
        dosyayazfben();
            if(fben<11)
            {

              Firebase.begin(&config, &auth);
              fben=1;
              dosyayazfben();
              dosyaokufbyol();
            }fbreConnetsayac=millis();
    }
}
}

}



void Programtakip(String progdata);







int dhtokusayac=0;
void loop() {

if(webstart==false){
  webstart=true;
    httpserver.begin();
    Serial.println("Web server Lunched.");
//delay(10);
}

  // put your main code here, to run repeatedly:
otaloop();

//if(gonderdimbekle>0)gonderdimbekle = gonderdimbekle - 1;
htpcl();


/* MQTT LOOP KISMI
  if(mqttmesajzamansayac>0){
    mqttmesajzamansayac+=1;
  if(mqttmesajzamansayac>20)mqttmesajzamansayac=0;
  }
  //mqttclient.onMessage(messageReceived);


  mqttclient.loop();

  if (!mqttclient.connected()) {
    MQTTConnect();
  }else{mqttconnectsayac=0;}


  // publish a message roughly every second.
  if (millis() - lastMillis > 50000) {
    lastMillis = millis();
    mqttclient.publish("/hello", "world");
  }

*/





  headerclear++;
  if (headerclear > 200) {
    headerclear = 0;
    headerOld = "";
    header="";
  }


if(!Firebase.ready() && WiFi.status()==WL_CONNECTED && fben>0){
  if(millis()-fbreConnetsayac>60000)
  {
    fbreConnetsayac=millis();
    fben=1;
    dosyayazfben();
    connectfb();
  }

//delay(1);
}
     //if(header=="") 
     zamanfark +=1;


            IPAddress lip = WiFi.localIP();
            String lipStr = String(lip[0]) + '.' + String(lip[1]) + '.' + String(lip[2]) + '.' + String(lip[3]);

if (WiFi.status()==WL_CONNECTED && String(lip[0]) != "0" && fben>0 && DATABASE_URL !="" && API_KEY != "" && USER_EMAIL != "" && USER_PASSWORD != "")
{

                  if (Firebase.ready() && (zamanfark > 4500 || zamanfark == 0))
                  {
                    zamanfark=1;

                    

                     // Serial.printf("Set string... %s\n", Firebase.RTDB.setString(&fbdo, F("/test/string"), F("Hello World!")) ? "ok" : fbdo.errorReason().c_str());



                    // For the usage of FirebaseJson, see examples/FirebaseJson/BasicUsage/Create_Edit_Parse.ino



                /*
                    FirebaseJson json;

                    if (count == 0)
                    {
                      json.set("value/round/" + String(count), F("cool!"));
                      json.set(F("value/ts/.sv"), F("timestamp"));
                      Serial.printf("Set json... %s\n", Firebase.RTDB.set(&fbdo, F("/test/json"), &json) ? "ok" : fbdo.errorReason().c_str());
                    }
                    else
                    {
                      json.add(String(count), F("smart!"));
                      Serial.printf("Update node... %s\n", Firebase.RTDB.updateNode(&fbdo, F("/test/json/value/round"), &json) ? "ok" : fbdo.errorReason().c_str());
                    }
                */

                    Serial.println();

                    // For generic set/get functions.

                    // For generic set, use Firebase.RTDB.set(&fbdo, <path>, <any variable or value>)

                    // For generic get, use Firebase.RTDB.get(&fbdo, <path>).
                    // And check its type with fbdo.dataType() or fbdo.dataTypeEnum() and
                    // cast the value from it e.g. fbdo.to<int>(), fbdo.to<std::string>().

                    // The function, fbdo.dataType() returns types String e.g. string, boolean,
                    // int, float, double, json, array, blob, file and null.

                    // The function, fbdo.dataTypeEnum() returns type enum (number) e.g. firebase_rtdb_data_type_null (1),
                    // firebase_rtdb_data_type_integer, firebase_rtdb_data_type_float, firebase_rtdb_data_type_double,
                    // firebase_rtdb_data_type_boolean, firebase_rtdb_data_type_string, firebase_rtdb_data_type_json,
                    // firebase_rtdb_data_type_array, firebase_rtdb_data_type_blob, and firebase_rtdb_data_type_file (10)

                    //count++;
                  
                  
                }





if(Firebase.ready())
{




                if (Firebase.ready() && zamanfark > 3950 && zamanfark < 4000)
                {
                  zamanfark=4001;
                  //fbsayacoku();
                  fbsayacoku();
               }
}




                if(!Firebase.ready()){
                  fberror="Firebase not ready";
                  if(fben>1 && fben<5 && WiFi.status()==!WL_CONNECTED)fberror="Firebase Ayarları hatalı. Yada internet erişimi yok. <br> Usb portundan Cihazı bilgisayara bağlayın, COM port seçin (115200 baud hızında) veri okuyun. <br> ESP resetledikten sonra Seri porttan gelen verilerle hatayı görün.";
                  
                  }
                
                //if (zamanfark > 1000  && zamanfark < 2000) htpcl();



                /**/
}

serin();


if(!Firebase.ready() && fben>0 && WiFi.status()==WL_CONNECTED){
    fbreConnetsayac+=1;
//Serial.println(fbreConnectsayac);
  if(fbreConnetsayac>20000)
  {
          fbreConnetsayac=0;
      connectfb();
  }


if(WiFi.status()!=WL_CONNECTED)
{
  reConnectsayac+=1;

  if(reConnectsayac>30000)
  {
    reConnectsayac=0;
    connectWifi();
  }
}

//delay(1);
  if(fben>4) fben=1;
}

  if(aut==1 & logintimeout>0){
    // delay 4 ve 60 saniye için 60000 / a;
    logintimeout-= 4;
  }
  if(logintimeout<=0)aut=0;

aut=1; // silinecek


updatesayac();

  if(say>880){
    if(say==881){
      digitalWrite(LED_BUILTIN, LOW);
    





    
    }  
  say+=1;
        if(say>1000){say=0;
        digitalWrite(LED_BUILTIN, HIGH);
        
        
       // int chk = DHTA.read();


// pin işlemleri rutini bitiş ////////////////////////////




         }

  }
  else
  {
    say+=1;
  }


}


//httpgonder();




/*
void fbloop() {
  // save
  DynamicJsonDocument saveDoc(1024);
  saveDoc["name"] = "Device 1";
  saveDoc["temperature"] = 30.00;
  saveDoc["location"][0] = 48.756080;
  saveDoc["location"][1] = 2.302038;
  String saveJSONData;
  serializeJson(saveDoc, saveJSONData);
  int saveResponseCode = firebaseRealtime.save("devices", "1", saveJSONData);
  Serial.println("\nSave - response code: " + String(saveResponseCode));
  saveDoc.clear();

  // update
  DynamicJsonDocument updateDoc(1024);
  updateDoc["temperature"] = 35.00;
  String updateJSONData;
  serializeJson(updateDoc, updateJSONData);
  int updateResponseCode = firebaseRealtime.save("devices", "1", updateJSONData, true);
  Serial.println("\nUpdate - response code: " + String(updateResponseCode));
  updateDoc.clear();

  // fetch
  DynamicJsonDocument fetchDoc(1024);
  int fetchResponseCode = firebaseRealtime.fetch("devices", "1", fetchDoc);
  float temp = fetchDoc["temperature"];
  String name = fetchDoc["name"];
  float lat = fetchDoc["location"][0];
  float lon = fetchDoc["location"][1];
  Serial.println("\nFetch - response code: " + String(fetchResponseCode));
  Serial.println("Name: " + name + ", Temp: " + String(temp) + ", Lat: " + String(lat) + ", Lon: " + String(lon));
  fetchDoc.clear();

  // delete
  // int deleteResponseCode = remove("devices", "1");
  // Serial.println("\nDelete response code: " + String(deleteResponseCode));

  delay(5000);
}
*/


























void dosyayazssidpass()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/ssidpass.txt");
                dosya = LittleFS.open("/ssidpass.txt", "w+");
                if (dosya) {
                  dosya.println(ssid);
                  dosya.println(pass);
                  dosya.close();
                  Serial.println("Write bitti");
                }
                dosya.close();

}









void Outpwm(String pinismi, int PWMdegerint){
              
              //Serial.println("GELDİM");
              //Serial.println(pinismi);
              if(pinismi=="")return;
              int pinismiint;
              if(pinismi.length()>1)
              pinismiint= pinismi.substring(1,2).toInt();
              else pinismiint=pinismi.toInt();
              if(pinismi.indexOf("A")>-1)pinismiint+= 9;
              //Serial.println(pinismiint);
              //Serial.println(PWMdegerint);

              analogWrite(Pin[pinismiint], PWMdegerint);
                          PinState[pinismiint]=PWMdegerint;

}











/*
String girdi;
String userstmp;
void MQTTuserYuzdeliifadesil(){
if(users.length()>0){
  userstmp=users;
  Serial.println("users ayarlanıyor:");
  Serial.println(users);
girdi="";
for (int j=1;j<userstmp.length();j++){
girdi += userstmp.substring(0,userstmp.indexOf("%7C")) + "|";
userstmp= userstmp.substring(userstmp.indexOf("%7C")+3,userstmp.length());

girdi += userstmp.substring(0,userstmp.indexOf("%0D%0A")) + "\n";
userstmp= userstmp.substring(userstmp.indexOf("%0D%0A")+6,userstmp.length());

if(userstmp.length()<1) break;
}

  girdi=girdi.substring(0,girdi.indexOf("%"));
  users=girdi;
  }
}
*/


String pingirdi;
String pinayartmp;
String artisilici;
void pinayarYuzdeliifadesil(){
  return;
if(pinayar.length()>0){pinayartmp=pinayar;
  Serial.println("pinayar ayarlanıyor:");
  Serial.println(pinayar);
    pingirdi="";
        
        for (int j=1;j<pinayartmp.length();j++){

        String pingirtmp=  pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";
        pingirtmp.toUpperCase();  // buyuk harfe çevirmek için
        pingirdi+=pingirtmp;  // pinismi

        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());

        pingirtmp=  pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";
        pingirtmp.toUpperCase();
        pingirdi+=pingirtmp;  // Pinmode |

        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());

        String pinsignaltypetmp=pinayartmp.substring(0,pinayartmp.indexOf("%7C"));  // pinsignaltype
        pingirtmp=  pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";
        pingirtmp.toUpperCase();
        pingirdi+=pingirtmp;   //signaltype|

        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());
        pingirdi += pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";  //minvalue
        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());
        pingirdi += pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";  // value PinState
        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());
        if(pinsignaltypetmp=="SER"){
          if(pinayartmp.substring(0,pinayartmp.indexOf("%7C")).toInt()>180){
            pingirdi += "180|";
          }else
          {
            pingirdi += pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";  // maxvalue
          }
        }else{
          pingirdi += pinayartmp.substring(0,pinayartmp.indexOf("%7C")) + "|";  // maxvalue
        }
        pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%7C")+3,pinayartmp.length());
        pingirdi += pinayartmp.substring(0,pinayartmp.indexOf("%0D%0A")) + "\n";
        
        if(pinayartmp.indexOf("%0D%0A")>-1)
        {
          pinayartmp= pinayartmp.substring(pinayartmp.indexOf("%0D%0A")+6,pinayartmp.length());
          if(pinayartmp.length()==0) pingirdi=pingirdi+"\n";
        }else{
          pinayartmp= pinayartmp.substring(0,pinayartmp.length());
        }
        
        if(pinayartmp.indexOf("%7C") < 0) break;
        }

      pingirdi=pingirdi.substring(0,pingirdi.indexOf("%"));
      
      artisilici = pingirdi;
      pingirdi = "";
      for(int x=0;x<1100;x++){
        if(artisilici.indexOf("+")>-1){
            pingirdi += artisilici.substring(0,artisilici.indexOf("+"));
            artisilici = artisilici.substring(artisilici.indexOf("+")+1,artisilici.length());
            if( artisilici.length()<1)break;
        }
        else
        { 
          pingirdi += artisilici;
                     break; 
        }
       
      }

Serial.print("pingirdiartisilici:  >>>  "); Serial.println(pingirdi);

/*
      String yazilacakpinayar="";
      int buldumno=-1;

    for(int y=0;y<pingirdi.length();y++){
      if(pingirdi.indexOf("+")>-1)
      {buldumno=pingirdi.indexOf("+");
      yazilacakpinayar += pingirdi.substring(0,buldumno);
      pingirdi=pingirdi.substring(buldumno+1,pingirdi.length());
    }
    else{yazilacakpinayar += pingirdi;}
    }
    */
     // pinayar=yazilacakpinayar;
     pinayar=pingirdi;
      pinayartmp="";

}
}






String gelentt;
String gidens;
String gidentt;
String sdf;
String sdf2;
int yuzdemi;
int artimi;

String Karakterduzeltfunc(String gelent){
 karakter[0] ="+";   //    :boşluk databloğu içinde iken
          yerinegec[0] = " ";
 karakter[1] ="%20"; //  :boşluk actionadresi icinde iken
          yerinegec[1] = " ";
 karakter[2] ="%25"; //  :%
          yerinegec[2] = "%";
 karakter[3] ="%26"; //  :&
          yerinegec[3] = "&";
 karakter[4] ="%28"; //  :(
          yerinegec[4] = "(";
 karakter[5] ="%29"; //  :)
          yerinegec[5] = ")";
 karakter[6] ="%7C"; //  :|
          yerinegec[6] = "|";
 karakter[7] ="%2F"; //  :/
          yerinegec[7] = "/";
 karakter[8] ="%3B"; //  :;
          yerinegec[8] = ";";
 karakter[9] ="%3D"; //  :=
          yerinegec[9] = "=";
 karakter[10] ="%3F"; //  :?
          yerinegec[10] = "?";
 karakter[11] ="%3E"; //  :>
          yerinegec[11] = ">";
 karakter[12] ="%3C"; //  :<
          yerinegec[12] = "<";
 karakter[13] ="%7B"; //  :{
          yerinegec[13] = "{";
 karakter[14] ="%7D"; //  :}
          yerinegec[14] = "}";
 karakter[15] ="%5B"; //  :[
          yerinegec[15] = "[";
 karakter[16] ="%5D"; //  :]
          yerinegec[16] = "]";
 karakter[17] ="%2B"; //  :+
          yerinegec[17] = "+";
//         - * /  aynı
 karakter[18] ="%21"; //  :!
          yerinegec[18] = "!";

  karakter[19] ="%0D%0A"; //: \r\n  (enter ve satır sonu) karakterleri
        yerinegec[19] = "\n";

  karakter[20] ="%22"; 
        yerinegec[20] = "\"";

  karakter[21] ="%3A";  
        yerinegec[21] = ":";

  karakter[22] ="%3B";  
        yerinegec[22] = "\"";

  karakter[23] ="%23";  
        yerinegec[23] = "#";

  karakter[24] ="%27";  
        yerinegec[24] = ",";

  karakter[25] ="%2C";  
        yerinegec[25] = ",";

  karakter[26] ="%C5%9E";  
        yerinegec[26] = "Ş";

  karakter[27] ="%C5%9F";  
        yerinegec[27] = "ş";

  karakter[28] ="%C3%87";  
        yerinegec[28] = "Ç";
        
  karakter[29] ="%C3%A7";  
        yerinegec[29] = "ç";

  karakter[30] ="%C3%96";  
        yerinegec[30] = "Ö";
        
  karakter[31] ="%C3%B6";  
        yerinegec[31] = "ö";

  karakter[32] ="%C3%9C";
        yerinegec[32] = "Ü";
        
  karakter[33] ="%C3%BC"; 
        yerinegec[33] = "ü";

  karakter[34] ="%C4%9E";  
        yerinegec[34] = "Ğ";
        
  karakter[35] ="%C4%9F";  
        yerinegec[35] = "ğ";

  karakter[36] ="%C4%B1";  
        yerinegec[36] = "ı";
        
  karakter[37] ="%C4%B0";  
        yerinegec[37] = "İ";



gelentt = gelent;
gidens="";
  for(int y=0;y<gelentt.length()+1;y++){
    if(gelentt.length()<1)break;
     yuzdemi=10000;
     artimi=10000;

     if(gelentt.indexOf("%")>-1){yuzdemi=gelentt.indexOf("%");}
     if(gelentt.indexOf("+")>-1){artimi=gelentt.indexOf("+");}
     if(yuzdemi<artimi)
     {
           sdf="";
           sdf2="";
          gidentt += gelentt.substring(0,yuzdemi);
          sdf = gelentt.substring(yuzdemi,yuzdemi+3);
          sdf2 = gelentt.substring(yuzdemi,yuzdemi+6);
          
          if(sdf2=="%0D0A")sdf="%0D%0A";
          if(sdf2=="%C5%9E")sdf="%C5%9E";
          if(sdf2=="%C5%9F")sdf="%C5%9F";  
          if(sdf2=="%C3%87")sdf="%C3%87";  
          if(sdf2=="%C3%A7")sdf="%C3%A7";  
          if(sdf2=="%C3%96")sdf="%C3%96";  
          if(sdf2=="%C3%B6")sdf="%C3%B6";  
          if(sdf2=="%C3%9C")sdf="%C3%9C";  
          if(sdf2=="%C3%BC")sdf="%C3%BC";  
          if(sdf2=="%C4%9E")sdf="%C4%9E";  
          if(sdf2=="%C4%9F")sdf="%C4%9F";  
          if(sdf2=="%C4%B1")sdf="%C4%B1";  
          if(sdf2=="%C4%B0")sdf="%C4%B0";  


          for (int c=1;c<37;c++)
          {
              if(karakter[c].indexOf(sdf)>-1)
              {
              gidentt += yerinegec[c];
              gelentt = gelentt.substring(yuzdemi+sdf.length(),gelentt.length());
              y=yuzdemi+sdf.length();
              break; 
              }
          }
     }

     if(artimi<yuzdemi)
          {
            gidentt += gelentt.substring(0,artimi);

              gidentt += yerinegec[0];
              gelentt = gelentt.substring(artimi+1,gelentt.length());
              y=artimi;
          }
     

     if(artimi==yuzdemi)
          {
            gidentt += gelentt;
            break;
          }
          //Serial.println(gelentt);
     }

      gelentt="";
      String sdf="";

      String gidenrn=gidentt;
      gidentt="";
      //Serial.println(gidens);
      String gidens="";
      Serial.println(gidenrn);

    for(int x=0;x<gidenrn.length()+1;x++)
    {
      if(gidenrn.indexOf("\n\n")>-1)
      {
        gidens += gidenrn.substring(0, gidenrn.indexOf("\n\n")) + "\n";
            gidenrn=gidenrn.substring(gidenrn.indexOf("\n\n")+2,gidenrn.length());
      } else 
      {
        gidens += gidenrn.substring(0, gidenrn.length());
        break;
      }
    }

      if(gidenrn.indexOf("\n\n\n")>-1)gidens = gidens.substring(0, gidenrn.indexOf("\n\n\n"));

      Serial.println(gidens);
      return gidens;
      

  }

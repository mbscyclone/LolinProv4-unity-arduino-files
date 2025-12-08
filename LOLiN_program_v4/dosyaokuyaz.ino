
void dosyaokussidpass() {


  //if (digitalRead(FactoryDefault) == HIGH) {
    // cleareprom();
  //}


  dosya = LittleFS.open("/ssidpass.txt", "r");
  if (dosya) {
    // dosya başarı ile açıldı;
    String ssidoc = dosya.readStringUntil('\n');
    ssid = ssidoc.substring(0, ssidoc.length() - 1);
    //Serial.println(ssid);

    String passoc = dosya.readStringUntil('\n');
    pass = passoc.substring(0, passoc.length() - 1);
    //Serial.println(pass);

    dosya.close();
    //Serial.println("read bitti");
  }
}

String myssidyazilimi = "";
void dosyayazmyssidname() {
                  reConnectsayac=0;
  dosya.close();
  LittleFS.remove("/myssidname.txt");
  dosya = LittleFS.open("/myssidname.txt", "w+");
  dosya.println(myssidyazilimi);
Serial.println(myssidyazilimi);
  dosya.close();
  dosyaokumyssidname();
  WiFi.hostname(esphostname);
  WiFi.softAP(esphostname, "12345678");
//  fbchzkaydial();
    fbdataguncelle();
}



void dosyaokumyssidname() {
  //   я
  int yazili = 0;
  myssidyazilimi = "";
  dosya.close();
  dosya = LittleFS.open("/myssidname.txt", "r");

  if (dosya) {
    String gecicimyssidname = dosya.readStringUntil('\n');
    gecicimyssidname = gecicimyssidname.substring(0, gecicimyssidname.length() - 1);
    Serial.println(gecicimyssidname);
    myssidyazilimi = gecicimyssidname;
    yazili = gecicimyssidname.length();
    dosya.close();
    if (yazili < 1) { myssidyazilimi = "v3"; }
         esphostname = "" + myssidyazilimi;
  }
}



void dosyaokufben()
{
                dosya.close();
                dosya = LittleFS.open("/fben.txt", "r");
                if (dosya) {
                String en = dosya.readStringUntil('\n');
                en= en.substring(0,en.length()-1);
                fben = en.toInt();
                //Serial.print("fben:");
                //Serial.println(fben);
                }
                dosya.close();
}

void dosyayazfben()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fben.txt");
                dosya = LittleFS.open("/fben.txt", "w+");
                if (dosya) {
                  dosya.println(String(fben));
                  if(fben==1)fbreConnetsayac=100000;
                }
                dosya.close();
                dosyaokufben();
}


void dosyaokufburl()
{
                dosya.close();
                dosya = LittleFS.open("/fburl.txt", "r");
                if (dosya) {
                DATABASE_URL = dosya.readStringUntil('\n');
                DATABASE_URL= DATABASE_URL.substring(0,DATABASE_URL.length()-1);
                dosya.close();
                }

}

void dosyayazfburl()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fburl.txt");
                dosya = LittleFS.open("/fburl.txt", "w+");
                if (dosya) {
                  dosya.println(DATABASE_URL);
                  dosya.close();
                  dosyaokufburl();
                }
}


void dosyaokufbapi()
{
  dosya.close();
  dosya = LittleFS.open("/fbapi.txt", "r");
  if (dosya) {
    // dosya başarı ile açıldı;
    API_KEY = dosya.readStringUntil('\n');
    API_KEY = API_KEY.substring(0,API_KEY.length()-1);
    dosya.close();
    }
}               


void dosyayazfbapi()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fbapi.txt");

                dosya = LittleFS.open("/fbapi.txt", "w+");
                if (dosya) {
                  dosya.println(API_KEY);
                dosya.close();
                }
    //Serial.print("fbapi yazılıyo");Serial.println(fbapi);

}


void dosyaokufbyol()
{
                dosya.close();
                dosya = LittleFS.open("/fbyol.txt", "r");
                if (dosya) {
                YOL = dosya.readStringUntil('\n');
                YOL= YOL.substring(0,YOL.length()-1);
                dosya.close();
                }
}

void dosyayazfbyol()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fbyol.txt");
                dosya = LittleFS.open("/fbyol.txt", "w+");
                if (dosya) {
                  dosya.println(YOL);
                  dosya.close();
                  dosyaokufbyol();
                }
}

void dosyaokufbusername()
{
                dosya.close();
                dosya = LittleFS.open("/fbusername.txt", "r");
                if (dosya) {
                USER_EMAIL = dosya.readStringUntil('\n');
                USER_EMAIL= USER_EMAIL.substring(0,USER_EMAIL.length()-1);
                dosya.close();
                }

}

void dosyayazfbusername()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fbusername.txt");
                dosya = LittleFS.open("/fbusername.txt", "w+");
                if (dosya) {
                  dosya.println(USER_EMAIL);
                  dosya.close();
                  dosyaokufburl();
                }
}


void dosyaokufbuserpass()
{
                dosya.close();
                dosya = LittleFS.open("/fbuserpass.txt", "r");
                if (dosya) {
                USER_PASSWORD = dosya.readStringUntil('\n');
                USER_PASSWORD= USER_PASSWORD.substring(0,USER_PASSWORD.length()-1);
                dosya.close();
                }

}

void dosyayazfbuserpass()
{
                  reConnectsayac=0;
                dosya.close();
                LittleFS.remove("/fbuserpass.txt");
                dosya = LittleFS.open("/fbuserpass.txt", "w+");
                if (dosya) {
                  dosya.println(USER_PASSWORD);
                  dosya.close();
                  dosyaokufburl();
                }
}
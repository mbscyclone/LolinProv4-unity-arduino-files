
void serin()
{
  if(Serial.available())
  {
        String sergel=Serial.readStringUntil('\n');
        Serial.println(sergel);



// ssid ve pass kısmı başladı ///////////////////////////////////////////////////

      if(sergel=="wifitara")
      {
        wifiscan();
      }

      if(sergel.indexOf("ssid?")==0)
      {
        Serial.println(sergel + " = " + ssid);
      }
      if(sergel.indexOf("pass?")==0)
      {
        Serial.println(sergel + " = " + pass);
      }

      if(sergel.indexOf("ssid=")==0)
      {
        ssid=sergel.substring(5,sergel.length());
      Serial.println(ssid + " ssid güncellendi.");
      }

      if(sergel.indexOf("pass=")==0)
      {
        pass=sergel.substring(5,sergel.length());
        Serial.println(pass + " pass guncellendi 'ssidpassset' ile kaydedin.");
      }

      if(sergel.indexOf("ssidpassset")==0)
      {
        dosyayazssidpass();
        Serial.println("kaydedildi. 'resetle' gerekli...");
      }

///////////////////////////////////////////////////////////// ssid pass kısmı bitti

// ismim kısmı başı ////////////////////////////////

      if(sergel.indexOf("ismim=")==0)
      {
        esphostname=sergel.substring(6,sergel.length());
        dosyayazmyssidname();
        Serial.println( "Cihaz ismi güncellendi.");
      }


/////////////////////////////////// ismim kısmı sonu



///// firebase başlangıç /////////////////////////////////////////////////////////

      if(sergel.indexOf("fburl=")==0)
      {
        DATABASE_URL = sergel.substring((6,sergel.length()));
        Serial.println( DATABASE_URL + " [FIREBASE DATABASE URL] güncellendi," + "\n Şimdi apikey i giriniz.");
      }

      if(sergel.indexOf("fbapi=")==0)
      {
        API_KEY = sergel.substring((6,sergel.length()));
        Serial.println( API_KEY + " [API_KEY] güncellendi," + "\n Şimdi yolu giriniz. (path)");
      }

      if(sergel.indexOf("fbyol=")==0)
      {
        YOL = sergel.substring((6,sergel.length()));
        Serial.println( YOL + " [YOL] güncellendi," + "\n FB user e-mail (.............@gmail.com)");
      }

      if(sergel.indexOf("fbeml=")==0)
      {
        USER_EMAIL = sergel.substring((6,sergel.length()));
        Serial.println( USER_EMAIL + " [USER_EMAIL] güncellendi," + "\n FB user şifresini giriniz. (password)");
      }

      if(sergel.indexOf("fbupw=")==0)
      {
        USER_PASSWORD = sergel.substring((6,sergel.length()));
        Serial.println( USER_PASSWORD + " [USER_PASSWORD] güncellendi," + "\n FB bilgileri güncellendi. Kayıt için fbset yazınız.");
      }


      if(sergel.indexOf("fbset")==0)
      {
        dosyayazfburl();
        dosyayazfbapi();
        dosyayazfbyol();
        dosyayazfbusername();
        dosyayazfbuserpass();
        Serial.println( "Reset için 'resetle' gerekli. \n ESP resetlenecektir.");
      }

      if(sergel.indexOf("fben=1")==0)
      {
        fben=1;
        dosyayazfben();
        Serial.println("Firebase açıldı.");
        fbreConnetsayac=20001;
      }

      if(sergel.indexOf("fben=0")==0)
      {
        fben=0;
        dosyayazfben();
        Serial.println("Firebase kapatıldı.");
      }
///////////////////////////////////////////////////////////// firebase bitti


/// yardım başı /////////////////////////////////////////////////////////

      if(sergel.indexOf("yardım")>-1)
      {
            Serial.println("wifitara - wifi taramak için");
            Serial.println("ssid=    - ssid ayarları başlatmak için.");
            Serial.println("ismim=   - Cihaza isim vermek için.");
            Serial.println("fburl=   - Firebase ayarları başlatmak için.");
            Serial.println("fben=    - Firebase açmak için. fben=1, kapatmak için fben=0");
            Serial.println("durum=   - durumları listeler");
            Serial.println("resetle  - Cihazı resetler. ");
      }
  

      if(sergel.indexOf("durum")>-1)
      {
            Serial.println("firebase Açık  : "+ String(fben));
            if(Firebase.ready())Serial.println("Firebase durumu: Bağlı" );
            if(!Firebase.ready())Serial.println("Firebase durumu: Bağlı değil" );
            Serial.println("resetle  - Cihazı resetler. ");
      }



//////////////////////////////////////////////////////////yardım bitti





      if(sergel.indexOf("resetle")==0)ESP.restart();

  }
}
[TR] ESP8266 LOLİN WEMOS için 
  * yazdığım Lolin Pro v.4 Arduino programı.
    Runtime Olarak;
         (sıra ile yapılacaklar: cihaza bağlanmak wifi ile "esplolin-bosta" şifre "12345678" web browser ile
          192.168.4.1 i açmak.)
     
      AYARLAR kısmı başı -------------------------------------------------------
      *Ayarlara girip SSID ve PASS kaydetmek
         (Ayarlara girip SSID ve PASS butonu ile ilerlemek Bağlanılacak olan WiFi vericinin SSID ve PASS'ini
         girmek ve kaydetmek cihaz bağlanacaktır Cihaza reset gerekebilir. Ağınıza bağlandıktan sonra aldığı
         ip yi not etmek kendi ağınıza bağlanıp ip girerek cihazın ayarlar menüsüne girmek)
      * Cihazın Hostname'i yani Wifi ismini girmek ve kaydetmek.
      * Cihazın pinayarlarını yapmak. kaydetmek.(Cihaz resetlenecektir)
      * Mini program yazılacaksa programı yazmak. (Cihaz resetlenecektir)
      * Firebase'ya bağlanılacaksa Firebase Açık yapmak
      * Firebase Realtime Database URL yi girmek
      * Firebase Realtime Database API_KEY'i girmek
      * Firebase Realtime Database içindeki (path) YOL girmek.
      AYARLAR kısmı sonu -------------------------------------------------------

      ARAYÜZ kısmı başı --------------------------------------------------------
      * Sayfayı tazeleme süresini belirlemek veya tazelemeyi kapatmak
      * OUTPUT, DIGITAL Pin durumlarını değiştirmek
      * OUTPUT, PWM Pin durumlarını değiştirmek
      * INPUT, DIGITAL Pin durumlarını görmek
      * INPUT, ANALOG Pin durumlarını görmek
      ARAYÜZ kısmı sonu ---------------------------------------------------------
        
    NOT: Eksik kısımlar var
       * Program kısmı yazılmadı sadece Pin_high_low_invert; komutu pinleri invert olarak çalıştırıyor.
       * SERVO motor ve DHT sensörler kısmı kod olarak henüz yazılmadı.
       * Bunlar Android apk uygulamasında da aktif değil.
         
      

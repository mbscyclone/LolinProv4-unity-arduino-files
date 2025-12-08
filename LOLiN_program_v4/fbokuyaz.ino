int fbsayac=0;
void fbsayacoku()
{
    if(WiFi.status()!=WL_CONNECTED)return;
                    String getpath="/" + YOL + "/r/"+esphostname;
                    String resul=Firebase.RTDB.getString(&fbdo, getpath) ? fbdo.to<const char *>() : fbdo.errorReason().c_str();
//Serial.println(getpath +"  ");
Serial.println("Get str. " + resul);
                          if(resul=="path not exist")
                          {
                            fbdataguncelle();
                          }
                          else
                          {
                            if(resul=="9")fbpinstatelerioku();
                            if(psco==true || psci==true) fbpinstateleriyaz();
                          }

}

void fbsayacguncelle()
{
    if(WiFi.status()!=WL_CONNECTED)return;

                            String setpath="/" + YOL + "/r/"+esphostname;
                            fbsayac+=1;
                            if(fbsayac>7)fbsayac=0;
                            String resul=Firebase.RTDB.setString(&fbdo, setpath, F("0")) ? (String)fbsayac : fbdo.errorReason().c_str();
}


void fbdataguncelle()
{
    if(WiFi.status()!=WL_CONNECTED)return;

                            String setpath="/" + YOL + "/pins/"+esphostname+"pin";
                            String resul=Firebase.RTDB.setString(&fbdo, setpath, F("0")) ? "ok" : fbdo.errorReason().c_str();

                            /*
                              // CHZ kaydını al varmı yoksa yaz
                                  fbchzkaydial();
                              ////////////////////////////////
                            */

                              // pin ayarlarını yaz
                                  fbpinayarlariyaz();
                              /////////////////////////////

                              //pinstateleri yaz
                                  fbpinstateleriyaz();
                              /////////////////////////////

                              //sayac zaman guncelle 0 yap
                                  fbsayacguncelle();
                              ////////////////////////////
}

/*
void fbchzkaydial()
{
    if(WiFi.status()!=WL_CONNECTED)return;

                  dosyaokufbyol();
              // CHZ kaydını al
                    String getpath="/" + YOL + "/CHZ";
//Serial.println(getpath);
                    String resul=Firebase.RTDB.getString(&fbdo, getpath) ? fbdo.to<const char *>() : fbdo.errorReason().c_str();
//Serial.println("Get str. " + resul);
                          if(resul=="path not exist")
                          {
                            // hiç cihaz yoksa
                            String setpath="/" + YOL + "/CHZ";
                            String dats = "," + esphostname ;
                            resul=Firebase.RTDB.setString(&fbdo, setpath, dats) ? "ok" : fbdo.errorReason().c_str();
//Serial.println("Set str. " + setpath + " " + dats + " " + resul);
                          }else
                          {
                            // cihaz var ama bizimki kayıtlı mı?
                           String resul=Firebase.RTDB.getString(&fbdo, getpath) ? fbdo.to<const char *>() : fbdo.errorReason().c_str(); 
                           
                            if(resul.indexOf(","+esphostname)<0)
                            {
                            String setpath="/" + YOL + "/CHZ";
                            String dats = ","+esphostname+resul;
                            resul=Firebase.RTDB.setString(&fbdo, setpath, dats) ? "ok" : fbdo.errorReason().c_str();
//Serial.println("Set str. " + setpath + " " + dats + " " + resul);
                            }
                          }



              // CHZ kaydedildi


}
*/




void fbpinstatelerioku()
{
    if(WiFi.status()!=WL_CONNECTED)return;
    
                    dosyaokufbyol();
                    String getpath="/" + YOL + "/pins/"+esphostname+"pin";
                          //  int str_len = getpath.length() + 1; 
                          //  char getp[str_len];
                          //  getpath.toCharArray(getp, str_len);

                    
                    String resul=Firebase.RTDB.getString(&fbdo, getpath) ? fbdo.to<const char *>() : fbdo.errorReason().c_str();
//Serial.println(getpath +"  ");
Serial.println("Get str. " + resul);
                          if(resul=="path not exist")
                          {
                            fbdataguncelle();
                          }
                          else
                          {
                            String reslt=resul;

                                for(int h=0;h<pinsayisi;h++)
                                {
                                  if(reslt==".")break;
                                  String pnm=reslt.substring(0,reslt.indexOf(":"));
                                  String pns=reslt.substring(reslt.indexOf(":")+1,reslt.indexOf(","));
                                  reslt = reslt.substring(reslt.indexOf(",")+1,reslt.length());
                                  //Serial.println(pnm+" "+pns);
                                  
                                for(int hh=0;hh<pinsayisi;hh++)
                                    {
                                      if(pnm == pinname[hh])
                                      { 
                                        if(pinmode[hh]!="INP"){
                                            
                                            if(psco==false && pns!=fbPinState[hh])
                                            {
                                              PinState[hh] =pns;
                                              ePinState[hh] = pns;
                                              fbPinState[hh] = pns;
                                            }

                                        }

                                        break;
                                      }
                                    }
                                }
                                
                                Serial.print("psco:");
                                Serial.print(psco);
                                Serial.print("  psci:");
                                Serial.println(psci);

                              if(psco==true || psci==true) fbpinstateleriyaz();
                            //String resul=Firebase.RTDB.setString(&fbdo, setpath, dats) ? "ok" : fbdo.errorReason().c_str();
                            //Serial.println("Set string... " + setpath + " " + resul);
                              fbsayacguncelle();
                          }
}



void fbpinayarlariyaz()
{
    if(WiFi.status()!=WL_CONNECTED)return;
                            
                            // pin ayarlarını yükle
                            String setpath="/" + YOL + "/pays/" + esphostname + "pay";
                            String dats="";
                                for(int h=0;h<pinsayisi;h++)
                                {
                                  if( pinsatir[h].length()>0) dats+="[" + pinsatir[h] + "]";
                                }

                            Serial.print("path: " + setpath); Serial.println("dats: " + dats);
                            String resul=Firebase.RTDB.setString(&fbdo, setpath, dats) ? "ok" : fbdo.errorReason().c_str();
//Serial.println("Set str. " + setpath + ":0>" + resul);

                            /////////////////////////////
}

void fbpinstateleriyaz()
{
    if(WiFi.status()!=WL_CONNECTED)return;

                            String setpath="/" + YOL + "/pins/" + esphostname+ "pin";
                            String dats="";
                                for(int h=0;h<pinsayisi;h++)
                                {
                                  //if(pinname[h].indexOf("|")>-1)break;
                                  //Serial.print(pinname[h] + " ");Serial.println(PinState[h]);
                                  if(PinState[h]=="")PinState[h]="0";
                                  if( pinname[h].length()>0) dats+=pinname[h] + ":" + PinState[h] + ",";
                                }
                                
                            String resul=Firebase.RTDB.setString(&fbdo, setpath, dats) ? "ok" : fbdo.errorReason().c_str();


                                    for(int hh=0;hh<pinsayisi;hh++)
                                    {
                                              ePinState[hh] = PinState[hh];
                                              fbPinState[hh] = PinState[hh];
                                    }
                            psco=false;
                            psci=false;
}



















































//          if(sayPtakipicin>100){
//            if(programdata.length()>1)Programtakip(programdata);
//            sayPtakipicin=0;
//          }
//          sayPtakipicin+=1;

/*
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
*/

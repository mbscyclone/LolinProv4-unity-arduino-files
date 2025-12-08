float t;
int h;

void updatesayac()
{


    
        for(int x=0;x<pinsayisi;x++){

        if(x==0)
        {
          /*
        Serial.print("jk :");  Serial.print(jk);
        Serial.print("          pin[0] :"); Serial.println(Pin[x]); 
        Serial.print("          pinname :"); Serial.println(pinname[x]);
        Serial.print("          Pinmode :"); Serial.println(pinmode[x]);
        Serial.print("          Pinsignal :"); Serial.println(pinsignaltype[x]);
        Serial.print("          Pinstate :"); Serial.println(PinState[x]);
        */
        }

                        if(pinmode[x]=="OUT" & pinsignaltype[x]=="DIG"){
                                    if(PinState[x]=="0.00" || PinState[x]=="0" || PinState[x] == "LOW" || PinState[x] =="OFF")  {
                                      if(high_low_invert==false)digitalWrite(Pin[x], LOW ); else  digitalWrite(Pin[x], HIGH);
                                    }

                                    if(PinState[x]=="1.00" || PinState[x]=="1" || PinState[x] == "HIGH" || PinState[x] =="ON")  
                                    {
                                      if(high_low_invert==false)digitalWrite(Pin[x], HIGH); else  digitalWrite(Pin[x], LOW);
                                    }
                        

                    
                        }


                        if(pinmode[x]=="OUT" && pinsignaltype[x]=="PWM"){
                          int PWMdegerint=PinState[x].toInt();
                          Outpwm(pinname[x], PWMdegerint);
                        }

                        if(pinmode[x]=="INP" && pinsignaltype[x]=="ANG"){
                        pinMode(Pin[x], INPUT);
                        //delay(5);
                        PinState[x] = analogRead(Pin[x]);

                        }

                        if(pinmode[x]=="INP" && pinsignaltype[x]=="DIG"){
                        pinMode(Pin[x], INPUT);
                        //delay(5);
                        PinState[x] = digitalRead(Pin[x]);

                         }




                      if(pinmode[x]=="INP" && pinsignaltype[x].indexOf("DHT")==0)
                      { dhtsayac+=1;
                         if(dhtsayac>5000){ dhtsayac=0;
                              if(pinsignaltype[x]=="DHT1") {DHT_TYPE[x]= DHT11;}
                              if(pinsignaltype[x]=="DHT2") {DHT_TYPE[x]= DHT12;}
                              if(pinsignaltype[x]=="DHT3") {DHT_TYPE[x]= DHT21;}
                              if(pinsignaltype[x]=="DHT4") {DHT_TYPE[x]= DHT22;}
                              DHT DHTA(DHT_PIN[x], DHT_TYPE[x]);
                              //DHT


                              t = DHTA.readTemperature();  // boş iken  celcius // f = DHTA.readTemperature(true); fahrenayt 
                              delay(100);
                              h = DHTA.readHumidity();
                              delay(100);

                              // Check if any reads failed and exit early (to try again).
                              if (isnan(h) || isnan(t))  // || isnan(f)
                              {
                                  erlog = "DHT sensor okunamadı";
                              } else 
                              {

                                    if(h<100)
                                    {

                                      // sıcaklık hatası düzelt
                                      float tvehata=t+pinval[x].toFloat();
                                      String ts=(String)tvehata;

                                      // nem hatası düzelt
                                      int hvehata=h+pinmaxvalue[x].toInt();
                                      String hs=(String)hvehata;

                                        // kısa veri gönder
                                      if(pinminvalue[x]=="0") ts = ts.substring(0,ts.length()-1);
                                      if(pinminvalue[x]=="0") hs = hs.substring(0,hs.length()-1);

                                      if(pinminvalue[x]=="1") ts = ts.substring(0,ts.length()-3);
                                      if(pinminvalue[x]=="1") hs = hs.substring(0,hs.length()-1);

                                        PinState[x] ="t" + ts + "h" + hs;
                                        Serial.print(("Nem: "));
                                        Serial.print(hs);
                                        Serial.print(("0%  Sıcaklık: "));
                                        Serial.print(ts);
                                        Serial.print((" C"));
                                        Serial.println(".");
                                    }
                              }
                        }

                      }




          if(ePinState[x]!=PinState[x])
          {
              //Serial.println("Farklı olan e: " + pinname[x] + " " +ePinState[x] + " >> " + PinState[x]);

            if(pinsignaltype[x]=="ANG")
            {

              int epinstate = ePinState[x].toInt();
              int pinstate  =  PinState[x].toInt();


              if(abs(epinstate-pinstate)>10){
                Serial.println("Farklı olan e: " + pinname[x] + " " +ePinState[x] + " >> " + PinState[x]);
                psci=true;
                ePinState[x] = PinState[x];
              }else
              {
                PinState[x]=fbPinState[x];
                ePinState[x] = PinState[x];
              }


            }else if (pinsignaltype[x].indexOf("DH")>-1)
                      {
                          psci=true;
                          
                          ePinState[x] = PinState[x];
                      }
            else{
                       if(pinmode[x]!="OUT")
                       {

                         ePinState[x] = PinState[x]; 
                       }
                       if(pinmode[x]=="OUT")
                       {
                         psco=true;
                         ePinState[x] = PinState[x]; 
                       }
                }

          }

        }
/*
              for(int h=0;h<pinsayisi;h++){
               if(pinmode[h]=="OUT"){


                  if(ePinState[h]!=PinState[h])
                    {
                      Serial.print(ePinState[h]);Serial.print(" <epin Pin> "); Serial.println(PinState[h]);


                         psco=true;

                         ePinState[h] = PinState[h];
                    }
                    Serial.print(pinname[h]);Serial.print(" "); Serial.println(PinState[h]);
                    
                    }


                 if(Firebase.ready())if(psco==true || psci==true)zamanfark=4950;
              }
              */

//if(chgstate==true) httpgonder();
//if(psco==true || psci==true) zamanfark=2950;
}


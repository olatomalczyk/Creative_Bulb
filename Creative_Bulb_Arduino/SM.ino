//biblioteki    
    #include <Adafruit_NeoPixel.h>
    #include <SoftwareSerial.h>
   
  //cyfrowe
    #define LED1 7
    #define LED2 6
    #define LICZBADIOD 5
    
   //analogowe
    #define DZWIEK A1
    #define FOTOREZYSTOR A0
    Adafruit_NeoPixel pixels;
    //pasek ledowy 1
    Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(LICZBADIOD, LED1, NEO_GRB + NEO_KHZ800);
    //pasek ledowy 2
    Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(LICZBADIOD, LED2, NEO_GRB + NEO_KHZ800);
   
    //KLASKACZ
    int clap = 0;
    boolean ledOn = 1;

     //BLUETOOTH
    SoftwareSerial BT(10, 11); // RX, TX
    char komenda1;
    char komenda11;
    char komenda2;
    char komenda22;
    char komenda;
    char readBT;
      ///group control
      #define POKOJ1 'q' //off
      #define POKOJ2 'w' //off
      
      ///tryby
       #define FALA1 't'
      #define RANDKA1 'y'
      #define FILM1 'u'
      #define CZYTANIE1 'i'
      #define NAUKA1 'o'
      #define OGNISKO1 'p'
      #define IMPREZA1 'a'
      
       #define FALA2 's'
      #define RANDKA2 'd'
      #define FILM2 'f'
      #define CZYTANIE2 'g'
      #define NAUKA2 'h'
      #define OGNISKO2 'j'
      #define IMPREZA2 'k'
      
      ///auto-natezenie
      #define AUTO_NATEZENIE1 'l'
      #define AUTO_NATEZENIE2 'z'
      
      ///manualne-natezenie
      #define MANUAL_NATEZENIE1 'x'
      #define MANUAL_NATEZENIE2 'c'
      int brightness1;
      char b1[3];
      int brightness2;
      char b2[3];
      int i=0;
      
      ///manualny-kolor
      #define RED1 'v'
      #define BLUE1 'b'
      #define GREEN1 'n'
      #define PURPLE1 'm'
      #define YELLOW1 ','

      #define RED2 '.'
      #define BLUE2 '/'
      #define GREEN2 '['
      #define PURPLE2 ']'
      #define YELLOW2 ';'
      
      //harmonogram
      #define HARMONOGRAM1 'e' 
      #define HARMONOGRAM2 'r' 
      #define HARMONOGRAM11 'E' //tego nie wpisywac do aplikacji
      #define HARMONOGRAM22 'R' //tego nie wpisywac do aplikacji
      unsigned long czas1;
      unsigned long czas2;
      unsigned long czasrzecz1;
      unsigned long czasrzecz2;
      int stanh1=0;
      int stanh2=0;
      unsigned long roznica1;
      unsigned long roznica2;
      char savek1;
      char savek2;
      char h1[4];
      char h2[4];
      int j=0;
      //klaskacz
      #define KLASKACZ1 '{'
      #define KLASKACZ2 '}'
    void setup()
    {
      
      //LED
      pixels1.begin();  // Inicjalizacja biblioteki do LED1
      pixels2.begin();   // Inicjalizacja biblioteki do LED2
      Serial.begin(9600); //inicjalizacja monitora szeregowego
     
      //BLUETOOTH
      Serial.println("Enter AT commands:");
      BT.begin(9600);
    }

     
    void loop()
    {    
    bluetooth();               
    struktura();

/*
Serial.println("readBT:");
    Serial.println(readBT);
Serial.println("komenda1:");
     Serial.println(komenda1);
Serial.println("komenda:");
     Serial.println(komenda);
     
Serial.println("stanh1:");
     Serial.println(stanh1);
Serial.println("czasrzecz1:");
     Serial.println(czasrzecz1);
Serial.println("czas1:");
     Serial.println(czas1);
Serial.println("h0:");
       Serial.println(h1[0]);
Serial.println("h1:");
       Serial.println(h1[1]);
Serial.println("h2:");
       Serial.println(h1[2]);
Serial.println("h3:");
       Serial.println(h1[3]);
Serial.println("roznica1:");
       Serial.println(roznica1);


/*
   //spr natezenie:
    Serial.println("readBT:");
    Serial.println(readBT);
    Serial.println("komenda:");
    Serial.println(komenda);
    Serial.println("komenda1:");
    Serial.println(komenda1);
    Serial.println("brightness1:");
    Serial.println(brightness1);
Serial.println("b0:");
       Serial.println(b1[0]);
Serial.println("b1:");
       Serial.println(b1[1]);
Serial.println("b2:");
       Serial.println(b1[2]);
    Serial.println("brightness2:");
    Serial.println(brightness2);
    
  */  
     
} //klamra od void loop()

//////////////////////////////////////////////BLUETOOTH//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
void struktura(){
  switch(komenda){
               //pokoj1
                case POKOJ1:  pokoj1(); break;
                case POKOJ2:  pokoj2(); break;
                case KLASKACZ1: klaskacz1(); break;
                case KLASKACZ2: klaskacz2(); break;}
 switch(komenda11){case HARMONOGRAM11: harmonogram1();break;}    
 switch(komenda22){case HARMONOGRAM22: harmonogram2();break;}                      
 switch(komenda1){
               //pokoj1
                case FALA1:  fala1(); break;
                case RANDKA1:  randka1(); break;
                case FILM1:  film1(); break;
                case CZYTANIE1:  czytanie1(); break;
                case NAUKA1:  nauka1(); break;
                case OGNISKO1:  ognisko1(); break;
                case IMPREZA1:  impreza1(); break;
                case AUTO_NATEZENIE1:  auto_natezenie1(); break;
                case RED1:  red1(); break;
                case BLUE1:  blue1(); break;
                case GREEN1:  green1(); break;
                case PURPLE1:  purple1(); break;
                case YELLOW1:  yellow1(); break;}
switch(komenda2){
                //pokoj2
                case FALA2:  fala2(); break;
                case RANDKA2:  randka2(); break;
                case FILM2:  film2(); break;
                case CZYTANIE2:  czytanie2(); break;
                case NAUKA2:  nauka2(); break;
                case OGNISKO2:  ognisko2(); break;
                case IMPREZA2:  impreza2(); break;
                case AUTO_NATEZENIE2:  auto_natezenie2(); break;
                case RED2:  red2(); break;
                case BLUE2:  blue2(); break;
                case GREEN2:  green2(); break;
                case PURPLE2:  purple2(); break;
                case YELLOW2:  yellow2(); break;}
}
void bluetooth(){
// wypisywanie otrzymanych z telefou wartosci w porcie szeregowym
  if (BT.available()){readBT=BT.read();
  
   if((readBT=='0'||readBT=='1'||readBT=='2'||readBT=='3'||readBT=='4'||readBT=='5'||readBT=='6'||readBT=='7'||readBT=='8'||readBT=='9')&&komenda=='x'){
   b1[i]=readBT;
   i++;
    if(i>2){ 
    i=0;
    manual_natezenie1();
           }}
   if((readBT=='0'||readBT=='1'||readBT=='2'||readBT=='3'||readBT=='4'||readBT=='5'||readBT=='6'||readBT=='7'||readBT=='8'||readBT=='9')&&komenda=='c'){
   b2[i]=readBT;
   i++;
    if(i>2){ 
    i=0;
    manual_natezenie2();
           }}
   if((readBT=='0'||readBT=='1'||readBT=='2'||readBT=='3'||readBT=='4'||readBT=='5'||readBT=='6'||readBT=='7'||readBT=='8'||readBT=='9')&&komenda=='e'){
   h1[i]=readBT;
   i++;
    if(i>3){
    komenda11='E';
           }}
   if((readBT=='0'||readBT=='1'||readBT=='2'||readBT=='3'||readBT=='4'||readBT=='5'||readBT=='6'||readBT=='7'||readBT=='8'||readBT=='9')&&komenda=='r'){
   h2[j]=readBT;
   j++;
    if(j>3){ 
    komenda22='R';
           }}          
          
          }

 if(readBT==FALA1||readBT==OGNISKO1||readBT==RANDKA1||readBT==FILM1||readBT==NAUKA1||readBT==CZYTANIE1||readBT==IMPREZA1||readBT==AUTO_NATEZENIE1||readBT==RED1||readBT==BLUE1||readBT==GREEN1||readBT==PURPLE1||readBT==YELLOW1){
 komenda1=readBT;
  if(komenda1==FALA1||komenda1==OGNISKO1||komenda1==RANDKA1||komenda1==FILM1||komenda1==NAUKA1||komenda1==CZYTANIE1||komenda1==IMPREZA1||komenda1==AUTO_NATEZENIE1){
  komenda=' ';}}
 if (readBT==FALA2||readBT==OGNISKO2||readBT==RANDKA2||readBT==FILM2||readBT==NAUKA2||readBT==CZYTANIE2||readBT==IMPREZA2||readBT==AUTO_NATEZENIE2||readBT==RED2||readBT==BLUE2||readBT==GREEN2||readBT==PURPLE2||readBT==YELLOW2){
 komenda2=readBT;
  if(readBT==FALA2||readBT==OGNISKO2||readBT==RANDKA2||readBT==FILM2||readBT==NAUKA2||readBT==CZYTANIE2||readBT==IMPREZA2||readBT==AUTO_NATEZENIE2){
  komenda=' ';}}

 if(readBT==MANUAL_NATEZENIE2||readBT==MANUAL_NATEZENIE1||readBT==HARMONOGRAM2||readBT==HARMONOGRAM1||readBT==POKOJ1||readBT==POKOJ2||readBT==KLASKACZ1||readBT==KLASKACZ2){
 komenda=readBT;
 readBT=' ';}
 if(readBT==HARMONOGRAM2){
 komenda22=readBT;
 readBT=' ';}
 if(readBT==HARMONOGRAM1){
 komenda11=readBT;
 readBT=' ';}
                        
}
                      
//////////////////////////////////////////////GROUP CONTROL//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pokoj1(){
   for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i,0,0, 0); //czytanie
        pixels1.show(); // Wysylamy dane do lancucha
      }

}

void pokoj2(){
    for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i,0,0, 0); //czytanie
        pixels2.show(); // Wysylamy dane do lancucha
      }
}
    

/////////////////////////////////////////////////FOTOREZYSTOR - NATĘŻENIE ŚWIATŁA AUTO/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void auto_natezenie1(){
  int max=850;
  int light = analogRead(FOTOREZYSTOR);    //odczytanie wartości z A0
  int procent=light*(100.0/max);
  Serial.println(light); 
  Serial.print(procent);
  Serial.print(" %");//wyświetlenie jej na monitorze
  //<500,max>
 
  if ( light>=500 )                     //gdy wartość przekroczy pewien ustalony próg, wtedy dioda na pinie 13 zaświeci się
  {
    Serial.print("  Słońce- dioda świeci słabo  ");
   
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 218, 165, 32); //czytanie
        pixels1.setBrightness(40); //40% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
     
  }
//<200,400>
  if (light > 200 && light< 490 )                     //gdy wartość przekroczy pewien ustalony próg, wtedy dioda na pinie 13 zaświeci się
  {
    Serial.print("  Słońce częsciowo za chmurką- dioda świeci średnio mocno");
     
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 255, 165, 32); //czytanie
        pixels1.setBrightness(70); //40% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
     
   }
  
  if (light <= 190 ) 
  {
    Serial.print("  Zachrzmurzenie-dioda świeci mocno");
     
     for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i,255, 250, 250); //Snow white
        pixels1.setBrightness(100); //100% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
     
  }
 
  Serial.println("");
  delay(500); //opóźnienie między kolejnymi odczytami


}  


void auto_natezenie2(){
  int max=850;
  int light = analogRead(FOTOREZYSTOR);    //odczytanie wartości z A0
  int procent=light*(100.0/max);
  Serial.println(light); 
  Serial.print(procent);
  Serial.print(" %");//wyświetlenie jej na monitorze
  //<500,max>
 
  if ( light>=500 )                     //gdy wartość przekroczy pewien ustalony próg, wtedy dioda na pinie 13 zaświeci się
  {
    Serial.print("  Słońce- dioda świeci słabo  ");
   
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 218, 165, 32); //czytanie
        pixels2.setBrightness(40); //40% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
     
  }
//<200,400>
  if (light > 200 && light< 490 )                     //gdy wartość przekroczy pewien ustalony próg, wtedy dioda na pinie 13 zaświeci się
  {
    Serial.print("  Słońce częsciowo za chmurką- dioda świeci średnio mocno");
     
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 255, 165, 32); //czytanie
        pixels2.setBrightness(70); //40% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
     
   }
  
  if (light <= 190 ) 
  {
    Serial.print("  Zachrzmurzenie-dioda świeci mocno");
     
     for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i,255, 250, 250); //Snow white
        pixels2.setBrightness(100); //100% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
     
  }
 
  Serial.println("");
  delay(500); //opóźnienie między kolejnymi odczytami


} 


//////////////////////////////////////////////////////////KLASKACZ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void klaskacz1(){
clap = analogRead(DZWIEK);

 Serial.println(clap);
//pierwsze klasniecoe
  if (clap > 451 || (clap > 360 && clap < 400 )) {
    delay(100);
   // ograniczenie ze musza być dwa klasniecia w przeciągu i_max*1[ms] 
    for (int i = 0; i < 500; i++) {
    clap = analogRead(DZWIEK);
    delay(1);
      if (clap > 448 || (clap > 360 && clap < 400 )) {
      ledOn = !ledOn;}}}
  if (ledOn == 1){
  readBT=komenda1;
  bluetooth();
  struktura();}
  else {pokoj1();}
}

void klaskacz2(){
clap = analogRead(DZWIEK);

 Serial.println(clap);
//pierwsze klasniecoe
  if (clap > 448 || (clap > 360 && clap < 400 )) {
    delay(100);
   // ograniczenie ze musza być dwa klasniecia w przeciągu i_max*1[ms] 
    for (int i = 0; i < 500; i++) {
    clap = analogRead(DZWIEK);
    delay(1);
      if (clap > 448 || (clap > 360 && clap < 400 )) {
      ledOn = !ledOn;}}}
  if (ledOn == 1){
  readBT=komenda2;
  bluetooth();
  struktura();}
  else {pokoj2();}
}

 
/////////////////////////////////////////////////TRYBY/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////pokoj1/////////////////////////////////////////

      //FALA
      void fala1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 32, 178, 170); // Dioda "i" oraz skladowe R=255 G=0 B=0
        pixels1.setPixelColor(i-1, 25, 25, 112); // Dioda "i" oraz skladowe R=255 G=0 B=0
        pixels1.setBrightness(20);
        pixels1.show(); // Wysylamy dane do lancucha
        delay(200); // Opoznienie 100ms przed zaswieceniem kolejnej diody
      }
                    }
      
      //RANDKA
      void randka1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 255, 20, 147); //Hot pink
        int j=i*5+1;
        pixels1.setBrightness(j);
        pixels1.show(); // Wysylamy dane do lancucha
        pixels1.setPixelColor(i, 255, 20, 147); //Hot pink
        pixels1.setBrightness(j+5);
        pixels1.show();
        pixels1.setPixelColor(i, 255, 20, 147); //Hot pink
        pixels1.setBrightness(j+10);
        pixels1.show();
        delay(170);
                      
      }
      }

   
     //FILM
     void film1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 240, 230, 140); 
        pixels1.setBrightness(10); //10% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }

     
      //CZYTANIE
      void czytanie1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 218, 165, 32); //Golden rod lub yellow(   255, 255, 0 )
        pixels1.setBrightness(70); //70% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
                      }      
      //NAUKA
      void nauka1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i,255, 250, 250); //Snow white
        pixels1.setBrightness(100); //100% jasności
        pixels1.show(); // Wysylamy dane do lancucha
      }
                   }
    //OGNISKO/ŚWIECA

    void ognisko1(){
  for(int i=0; i<=LICZBADIOD; i++)
  {
       pixels1.setBrightness(5);
       pixels1.show();
       pixels1.setPixelColor(i+2, 128, 0, 0); //czerwony
       pixels1.setPixelColor(i,  255, 150, 60); //bialy   
       pixels1.setPixelColor(i+1,255, 100, 0);  //zółtway
       pixels1.setPixelColor(i-1, 255, 49, 0); //pomaranczowy
       pixels1.show();
       delay(70);
  }
                      }
    
        //IMPREZA
  void impreza1(){
  //odcienie niebieskiego i rozowego    
  for(int i=0; i<=LICZBADIOD; i++)
  {
    int    j=25*i+25;

       pixels1.setBrightness(100);
       pixels1.show(); // Wysylamy dane do lancucha
       
       pixels1.setPixelColor(i-4,255-j,0,0); //F
       pixels1.setPixelColor(i-3,  255-j,0, 0); //G
       
       pixels1.setPixelColor(i-2,  0, 0, 0); // NULL

       pixels1.setPixelColor(i-1,0,  255-j,0);  //B
       pixels1.setPixelColor(i,0,  255-j,0);  //B
       pixels1.setPixelColor(i+1,0, 0,255-j); //R
       pixels1.setPixelColor(i+2,0, 0,255-j); //R
       
       pixels1.show();
      
       delay(100);

  }

                }  
/////////////////////////////////////////pokoj2////////////////////////////////////////

      //FALA
      void fala2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 32, 178, 170); // Dioda "i" oraz skladowe R=255 G=0 B=0
        pixels2.setPixelColor(i-1, 25, 25, 112); // Dioda "i" oraz skladowe R=255 G=0 B=0
        pixels2.setBrightness(20);
        pixels2.show(); // Wysylamy dane do lancucha
        delay(200); // Opoznienie 100ms przed zaswieceniem kolejnej diody
      } 
                  }

      //RANDKA
      void randka2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 255, 20, 147); //Hot pink
        int j=i*5+1;
        pixels2.setBrightness(j);
        pixels2.show(); // Wysylamy dane do lancucha
        pixels2.setPixelColor(i, 255, 20, 147); //Hot pink
        pixels2.setBrightness(j+5);
        pixels2.show();
        pixels2.setPixelColor(i, 255, 20, 147); //Hot pink
        pixels2.setBrightness(j+10);
        pixels2.show();
        delay(170);
      }
                    }

   
     //FILM
     void film2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 240, 230, 140); 
        pixels2.setBrightness(10); //10% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }

     
      //CZYTANIE
      void czytanie2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 218, 165, 32); //Golden rod lub yellow(   255, 255, 0 )
        pixels2.setBrightness(70); //70% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
                      }
      
      //NAUKA
      void nauka2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i,255, 250, 250); //Snow white
        pixels2.setBrightness(100); //100% jasności
        pixels2.show(); // Wysylamy dane do lancucha
      }
                   }
   
      //OGNISKO/ŚWIECA
       void ognisko2(){
        
       for(int i=0; i<=LICZBADIOD; i++){
      
       pixels2.setBrightness(5);
       pixels2.show();
       pixels2.setPixelColor(i+2, 128, 0, 0); //czerwony
       pixels2.setPixelColor(i,  255, 150, 60); //bialy   
       pixels2.setPixelColor(i+1,255, 100, 0);  //zółtway
       pixels2.setPixelColor(i-1, 255, 49, 0); //pomaranczowy
       pixels2.show();
       delay(70);
       }       
       
                   }

    
   //IMPREZA
   void impreza2(){
       for(int i=0; i<=LICZBADIOD; i++){
  int    j=25*i+25;

       pixels2.setBrightness(100);
       pixels2.show(); // Wysylamy dane do lancucha
       
       pixels2.setPixelColor(i-4,255-j,0,0); //F
       pixels2.setPixelColor(i-3,  255-j,0, 0); //G
       
       pixels2.setPixelColor(i-2,  0, 0, 0); // NULL
       pixels2.setPixelColor(i-1,0,  255-j,0);  //B
       pixels2.setPixelColor(i,0,  255-j,0);  //B
       pixels2.setPixelColor(i+1,0, 0,255-j); //R
       pixels2.setPixelColor(i+2,0, 0,255-j); //R
       
       pixels2.show();
      
       delay(100);}
                       }  

//////////////////////////////////////////////////////KOLOR ŚWIATŁA MANUALNIE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////pokoj1////////////////////////
//RED
     void red1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 220, 20, 60); 
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }

//BLUE
     void blue1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 0, 191, 255); 
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }
//GREEN
     void green1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 124, 252, 0); 
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }

//PURPLE
     void purple1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 139, 0, 139); 
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }
//YELLOW
     void yellow1(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels1.setPixelColor(i, 255, 255, 0); 
        pixels1.show(); // Wysylamy dane do lancucha
      }
                 }

/////////////////////////////////pokoj2////////////////////////////
//RED
     void red2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 220, 20, 60); 
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }

//BLUE
     void blue2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 0, 191, 255); 
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }
//GREEN
     void green2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 124, 252, 0); 
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }

//PURPLE
     void purple2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 139, 0, 139); 
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }
//YELLOW
     void yellow2(){
      for(int i=0; i<=LICZBADIOD; i++)
      {
        pixels2.setPixelColor(i, 255, 230,0); 
        pixels2.show(); // Wysylamy dane do lancucha
      }
                 }
////////////////////////////////////////////////////NATĘŻENIE ŚWIATŁA MANULANIE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//od 0 do 255 ( 100% natezenia)
void manual_natezenie1(){
brightness1=(b1[0]-'0')*100+(b1[1]-'0')*10+(b1[2]-'0'); //konwersja char na int
  for(int i=0; i<=LICZBADIOD; i++){
  pixels1.setBrightness(brightness1); //jasności
  pixels1.show();}
                        }

//dostaje c i po tym znaku dostaje 3 wartosci ktore zapisuje do tablicy
void manual_natezenie2(){
  brightness2=(b2[0]-'0')*100+(b2[1]-'0')*10+(b2[2]-'0'); //konwersja char na int
  for(int i=0; i<=LICZBADIOD; i++){
    pixels2.setBrightness(brightness2); //jasności
    pixels2.show();}
}
////////////////////////////////////////////////////////////HARMONOGRAM//////////////////////////////////////////////////////////////////
/////// odbierać z BT12 chary i zapisywać do tablicy  czas[] --> czas[0]-dziesiątki godzin; czas[1]-jednosci godzin; czas[2]-dziesiatki minut; czas[3]-jednosci minut 
///  czas=(czas[0] * 10 * 3600 * 1000 + czas[1]* 3600 * 1000 +czas[2] 10 * 60 * 1000 + czas[3]*60 * 1000)
// Mazela musi mi wyslac juz wyliczone czas nastawu-czas rzeczywisty bo Arduino nie posiada czasu rzeczyistego jedynie czas od rozpoczecia dzialania programu 

void harmonogram1(){
stanh1++;
// dostaje x po tym znaku dostaje 3 wartosci ktore zapisuje do tablicy
if(stanh1==1){ 
             savek1=komenda1;
             czasrzecz1=millis();}
             
czas1=(h1[0]-'0')*3600*1000+(h1[1]-'0')*1000*3600 +(h1[2]-'0')*10*60*1000+(h1[3]-'0')*6000;

roznica1=(millis()-czasrzecz1);
  
  if(roznica1>=czas1){
  readBT=savek1;
  komenda11=' ';
  stanh1=0;
  i=0;}
  
  else{
  komenda1=' ';
  pokoj1();}
}

void harmonogram2(){
stanh2++;
if(stanh2==1){ 
savek2=komenda2;
czasrzecz2=millis();}

czas2=(h2[0]-'0')*3600*1000+(h2[1]-'0')*1000*3600 +(h2[2]-'0')*10*60*1000+(h2[3]-'0')*6000;

  
roznica2=(millis()-czasrzecz2);
  
  if(roznica2>=czas2){
  readBT=savek2;
  komenda22=' ';
  stanh2=0;
  j=0;}
  else{
  komenda2=' ';
  pokoj2();}
                        }

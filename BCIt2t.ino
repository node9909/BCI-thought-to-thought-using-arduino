//This code is used to print and log data received by a brain eeg headset
//the hardware required is an eeg headset arduino mega and an ethernet shield
//to mount the SD card. signal quality,attention,meditation,delta, theta,
//low alpha,high alpha,low beta,high beta, low gamma, mid gamma. all these values are 
//logged in a file "data.txt" also these values are printed in Serial monitor.
//a thought to thought communication code with trainer is also included with this code. the trainer is 
//used for recording data for each word and then the speller finds the word 
//you think. for improving the code do add your inputs and optimize as much as possible.
//Coder- Tanmay Chakraborty //mail me at-tanmay.608@gmail.com

//function name trainer() void type
//function name spell() character type returns a character
//function name printletter() displays alphabet matrix


#include <Brain.h>
#include <SD.h>

Brain brain(Serial);
const int chipSelect = 4;
int signalquality;
String datastring,sensor,redatt,redmed,reddel, redthe,lowalp,highalp,lowbet,highbet, lowgam, midgam;

long int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2,h1,h2,i1,i2,j1,j2;   //THIS a1 highest a2 lowest
long int a3,a4,b3,b4,c3,c4,d3,d4,e3,e4,f3,f4,g3,g4,h3,h4,i3,i4,j3,j4;   //IS
long int a5,a6,b5,b6,c5,c6,d5,d6,e5,e6,f5,f6,g5,g6,h5,h6,i5,i6,j5,j6;   //A
long int a7,a8,b7,b8,c7,c8,d7,d8,e7,e8,f7,f8,g7,g8,h7,h8,i7,i8,j7,j8;   //TWO
long int a9,a0,b9,b0,c9,c0,d9,d0,e9,e0,f9,f0,g9,g0,h9,h0,i9,i0,j9,j0;   //WAY
long int aa1,aa2,ba1,ba2,ca1,ca2,da1,da2,ea1,ea2,fa1,fa2,ga1,ga2,ha1,ha2,ia1,ia2,ja1,ja2;   //THOUGHT
long int ab1,ab2,bb1,bb2,cb1,cb2,db1,db2,eb1,eb2,fb1,fb2,gb1,gb2,hb1,hb2,ib1,ib2,jb1,jb2;   //TO
long int ac1,ac2,bc1,bc2,cc1,cc2,dc1,dc2,ec1,ec2,fc1,fc2,gc1,gc2,hc1,hc2,ic1,ic2,jc1,jc2;   //THOUGHT
long int ad1,ad2,bd1,bd2,cd1,cd2,dd1,dd2,ed1,ed2,fd1,fd2,gd1,gd2,hd1,hd2,id1,id2,jd1,jd2;   //COMMUNICATION
long int ae1,ae2,be1,be2,ce1,ce2,de1,de2,ee1,ee2,fe1,fe2,ge1,ge2,he1,he2,ie1,ie2,je1,je2;   //SYSTEM


long int A[11],B[11],C[11],D[11],E[11],F[11],G[11],H[11],I[11],J[11];


void setup(void) {

 
      Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
   Serial.println("Card failed, or not present");
    // don't do anything more:
   return;
   }
}
void loop() {


   if (brain.update()) 
   {
     if (brain.readSignalQuality() > 100) //checks signal quality of the connection
     {
       Serial.println("poor signal quality");
      }
 
// all values come in unsigned long int
//they have been type casted to string for storing it in a file
//raw data is coming in unsigned long int.
else 
{
 
 Serial.println("INITIAL SENSOR VALUES");
 for(int t=0;t<2;t++)
 {
 sensor=(String)brain.readSignalQuality();  //stores signal quality
 redatt=(String)brain.readAttention();   //stores attention value
 redmed=(String)brain.readMeditation();    //stores meditaiton value
 reddel=(String)brain.readDelta();       //stores delta value
 redthe=(String)brain.readTheta();  //stores theta value
 lowalp=(String)brain.readLowAlpha();  //stores low alpha value                
 highalp=(String)brain.readHighAlpha();   //stores high alpha value
 lowbet=(String)brain.readLowBeta();   //stores low beta value
 highbet=(String)brain.readHighBeta();  //stores high beta value
 lowgam=(String)brain.readLowGamma();   //stores low gamma value
 midgam=(String)brain.readMidGamma();  //stores mid gamma value
                
                Serial.print("signal quality :");
                Serial.print(brain.readSignalQuality());
                Serial.println(" ");
                Serial.print("Attention      :");   
                Serial.print(brain.readAttention());
                Serial. println(" ");
                Serial.  print("Meditation     :");
                Serial.print(brain.readMeditation());
                Serial.println(" ");
                Serial.print("Delta      : ");
                Serial.print(brain.readDelta());
                Serial.println(" ");
                Serial.print("Theta      : ");
                Serial.print(brain.readTheta());
                Serial.println(" ");
                Serial.print("Low Alpha  : ");
                Serial.print(brain.readLowAlpha());
                Serial.println(" ");
                Serial.print("High Alpha : ");
                Serial.print(brain.readHighAlpha());
                Serial.println(" ");
                Serial.print("Low Beta   : ");
                Serial.print(brain.readLowBeta());
                Serial.println(" ");
                Serial.print("High Beta  : ");
                Serial.println(brain.readHighBeta()); 
                Serial.println(" ");
                Serial.print("Low Gamma  : ");
                Serial.print(brain.readLowGamma());
                Serial.println(" ");
                Serial.print("Mid Gamma  : ");
                Serial.print(brain.readMidGamma());
                Serial.println(" ");
 }
 
          Serial.println("THOUGHT TO THOUGHT COMMUNICATION SYSTEM");
          Serial.println("SELECT 1 FOR STARTING TRAINER... ");
          int select=0;
          if(Serial.available()>0)
          {
            select=Serial.read();
          }
          if(select==1)
          { 
            Serial.println("STARTING TRAINER... ");
            Serial.println("CONCENTRATE ON EACH WORD DISPLAYED WHILE THE CODE RECORDS DATA... ");
            trainer();
          }
          Serial.println("SELECT 2 TO TRACE OUT THE WORD");
         // Serial.println("CONCENTRATE ON THE ALPHABET YOU WANT TO FIND USING THE SPELLER.. ");
           if(Serial.available()>0)
          {
            select=Serial.read();
          }
          String s="";
          if(select==2)
          { 
            Serial.println("STARTING SPELLER... ");
                printletter();
                s=spell();
                Serial.print("selected word  : ");
                Serial.print(s);
                Serial.println(" ");
                Serial.println("SELECT 2 FOR TRACING THE NEXT WORD.. ");
                
                
          }
                
  }
}
  datastring=datastring+"signal quality: "+sensor+" ,"+"Attention: "+redatt+","+"Medition: "+redmed+","+"Delta: "+reddel+","+"Theta: "+redthe+","+"LowAlpha: "+lowalp+","+"HighAlpha"+highalp+","+"LowBeta: "+lowbet+","+"HighBeta: "+highbet+","+"LowGamma: "+lowgam+","+"MidGamma: "+midgam;
  


 
 File dataFile = SD.open("data.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(datastring);
    dataFile.close();
   //  print to the serial port too:
    Serial.println(datastring);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

void trainer()
{
  
Serial.println("THIS");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}

//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a1=highest(A);
a2=lowest(A);
b1=highest(B);
b2=lowest(B );
c1=highest(C );
c2=lowest(C );
d1=highest(D );
d2=lowest(D );
e1=highest(E );
e2=lowest(E );
f1=highest(F );
f2=lowest(F );
g1=highest(G );
g2=lowest(G );
h1=highest(H );
h2=lowest(H );
i1=highest(I );
i2=lowest(I ); 
j1=highest(J );
j2=lowest(J );

Serial.println("IS");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a3=highest(A );
a4=lowest(A );
b3=highest(B );
b4=lowest(B );
c3=highest(C );
c4=lowest(C );
d3=highest(D );
d4=lowest(D );
e3=highest(E );
e4=lowest(E );
f3=highest(F );
f4=lowest(F );
g3=highest(G );
g4=lowest(G );
h3=highest(H );
h4=lowest(H );
i3=highest(I );
i4=lowest(I ); 
j3=highest(J );
j4=lowest(J );

Serial.println("A");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}


a5=highest(A );
a6=lowest(A );
b5=highest(B );
b6=lowest(B );
c5=highest(C );
c6=lowest(C );
d5=highest(D );
d6=lowest(D );
e5=highest(E );
e6=lowest(E );
f5=highest(F );
f6=lowest(F );
g5=highest(G );
g6=lowest(G );
h5=highest(H );
h6=lowest(H );
i5=highest(I );
i6=lowest(I ); 
j5=highest(J );
j6=lowest(J );

Serial.println("TWO");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}


a7=highest(A );
a8=lowest(A );
b7=highest(B );
b8=lowest(B );
c7=highest(C );
c8=lowest(C );
d7=highest(D );
d8=lowest(D );
e7=highest(E );
e8=lowest(E );
f7=highest(F );
f8=lowest(F );
g7=highest(G );
g8=lowest(G );
h7=highest(H );
h8=lowest(H );
i7=highest(I );
i8=lowest(I ); 
j7=highest(J );
j8=lowest(J );

Serial.println("WAY");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}

//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

a9=highest(A );
a0=lowest(A );
b9=highest(B );
b0=lowest(B );
c9=highest(C );
c0=lowest(C );
d9=highest(D );
d0=lowest(D );
e9=highest(E );
e0=lowest(E );
f9=highest(F );
f0=lowest(F );
g9=highest(G );
g0=lowest(G );
h9=highest(H );
h0=lowest(H );
i9=highest(I );
i0=lowest(I ); 
j9=highest(J );
j0=lowest(J );


Serial.println("THOUGHT");
 delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
 
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

aa1=highest(A );
aa2=lowest(A );
ba1=highest(B );
ba2=lowest(B );
ca1=highest(C );
ca2=lowest(C );
da1=highest(D );
da2=lowest(D );
ea1=highest(E );
ea2=lowest(E );
fa1=highest(F );
fa2=lowest(F );
ga1=highest(G );
ga2=lowest(G );
ha1=highest(H );
ha2=lowest(H );
ia1=highest(I );
ia2=lowest(I ); 
ja1=highest(J );
ja2=lowest(J );

Serial.println("TO");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ab1=highest(A );
ab2=lowest(A );
bb1=highest(B );
bb2=lowest(B );
cb1=highest(C );
cb2=lowest(C );
db1=highest(D );
db2=lowest(D );
eb1=highest(E );
eb2=lowest(E );
fb1=highest(F );
fb2=lowest(F );
gb1=highest(G );
gb2=lowest(G );
hb1=highest(H );
hb2=lowest(H );
ib1=highest(I );
ib2=lowest(I ); 
jb1=highest(J );
jb2=lowest(J );

Serial.println("THOUGHT");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ac1=highest(A );
ac2=lowest(A );
bc1=highest(B );
bc2=lowest(B );
cc1=highest(C );
cc2=lowest(C );
dc1=highest(D );
dc2=lowest(D );
ec1=highest(E );
ec2=lowest(E );
fc1=highest(F );
fc2=lowest(F );
gc1=highest(G );
gc2=lowest(G );
hc1=highest(H );
hc2=lowest(H );
ic1=highest(I );
ic2=lowest(I ); 
jc1=highest(J );
jc2=lowest(J );

Serial.println("COMMUNICATION");
delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
  
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ad1=highest(A );
ad2=lowest(A );
bd1=highest(B );
bd2=lowest(B );
cd1=highest(C );
cd2=lowest(C );
dd1=highest(D );
dd2=lowest(D );
ed1=highest(E );
ed2=lowest(E );
fd1=highest(F );
fd2=lowest(F );
gd1=highest(G );
gd2=lowest(G );
hd1=highest(H );
hd2=lowest(H );
id1=highest(I );
id2=lowest(I ); 
jd1=highest(J );
jd2=lowest(J );

Serial.println("SYSTEM");
 delay(100);
for(int i=0;i<11;i++)
{
  A[i]=brain.readAttention();
  B[i]=brain.readMeditation();
  C[i]= brain.readDelta();
  D[i]= brain.readTheta();
  E[i]= brain.readLowAlpha();
  F[i]= brain.readHighAlpha();
  G[i]= brain.readLowBeta();
  H[i]= brain.readHighBeta();
  I[i]= brain.readLowGamma();
  J[i]= brain.readMidGamma();
 
}
//debugging print statements
//for(int i=0;i<11;i++)
//{
// Serial.print( A[i]);
// Serial.print( B[i]);
//  Serial.print(C[i]);
// Serial.print( D[i]);
//  Serial.print(E[i]);
//  Serial.print(F[i]);
//  Serial.print(G[i]);
//  Serial.print(H[i]);
// Serial.print( I[i]);
//  Serial.print(J[i]);
//  delay(100);
//}

ae1=highest(A );
ae2=lowest(A );
be1=highest(B );
be2=lowest(B );
ce1=highest(C );
ce2=lowest(C );
de1=highest(D );
de2=lowest(D );
ee1=highest(E );
ee2=lowest(E );
fe1=highest(F );
fe2=lowest(F );
ge1=highest(G );
ge2=lowest(G );
he1=highest(H );
he2=lowest(H );
ie1=highest(I );
ie2=lowest(I ); 
je1=highest(J );
je2=lowest(J );



}

long int highest(long int *m)
{
  
  int largest=m[0];                        
  for(int i=0;i<10;i++)
  {
  if(m[i]>largest)
  largest=m[i];
  }
  //Serial.print(m[i]);
  return largest;
}

long int lowest(long int *m)                                                   
{
  int smallest=m[0];       
  for(int i=0;i<10;i++)
  {
  if(m[i]<smallest)
  smallest=m[i];
  }
  //Serial.print(m[i]);
  return smallest;
}

void printletter()
{

Serial.println("[THIS]");
Serial.println("[IS]");
Serial.println("[A]");
Serial.println("[TWO]");
Serial.println("[WAY]");
Serial.println("[THOUGHT]");
Serial.println("[TO]");
Serial.println("[THOUGHT]");
Serial.println("[COMMUNICATION]");
Serial.println("[SYSTEM]");
Serial.println();
Serial.println("THINK ABOUT THE WORDS FROM THE AVOBE AVAILABLE WORDS....");
Serial.println();


}

String spell()
{ 
  delay(100);
  long int atten=brain.readAttention();
  long int medi=brain.readMeditation();
  long int delta= brain.readDelta();
  long int theta= brain.readTheta();
  long int lowalpha= brain.readLowAlpha();
  long int highalpha= brain.readHighAlpha();
  long int lowbeta= brain.readLowBeta();
  long int highbeta= brain.readHighBeta();
  long int lowgamma= brain.readLowGamma();
  long int midgamma= brain.readMidGamma();
 //debugging statements 
//  Serial.print(atten);
//  Serial.print(medi);
//  Serial.print(delta);
//  Serial.print(theta);
//  Serial.print(lowalpha);
//  Serial.print(highalpha);
//  Serial.print(lowbeta);
//  Serial.print(highbeta);
//  Serial.print(lowgamma);
//  Serial.print(midgamma);  
  if (atten<=a1 && atten>=a2 && medi<=b1 && medi<=b2 && delta<=c1 && delta>=c2 && theta<=d1 && theta>=d2 && lowalpha<=e1 && lowalpha>=e2 && highalpha<=f1 && highalpha>=f2 && lowbeta<=g1 && lowbeta>=g2 && highbeta<=h1 && highbeta>=h2 && lowgamma<=i1 && lowgamma>=i2 && midgamma<=j1 && midgamma>=j2) 
  return 'THIS';
  
   else if (atten<=a3 && atten>=a4 && medi<=b3 && medi<=b4 && delta<=c3 && delta>=c4 && theta<=d3 && theta>=d4 && lowalpha<=e3 && lowalpha>=e4 && highalpha<=f3 && highalpha>=f4 && lowbeta<=g3 && lowbeta>=g4 && highbeta<=h3 && highbeta>=h4 && lowgamma<=i3 && lowgamma>=i4 && midgamma<=j3 && midgamma>=j4) 
  return 'IS';
  
     else if (atten<=a5 && atten>=a6 && medi<=b5 && medi<=b6 && delta<=c5 && delta>=c6 && theta<=d5 && theta>=d6 && lowalpha<=e5 && lowalpha>=e6 && highalpha<=f5 && highalpha>=f6 && lowbeta<=g5 && lowbeta>=g6 && highbeta<=h5 && highbeta>=h6 && lowgamma<=i5 && lowgamma>=i6 && midgamma<=j5 && midgamma>=j6) 
  return 'A';
  
     else if (atten<=a7 && atten>=a8 && medi<=b7 && medi<=b8 && delta<=c7 && delta>=c8 && theta<=d7 && theta>=d8 && lowalpha<=e7 && lowalpha>=e8 && highalpha<=f7 && highalpha>=f8 && lowbeta<=g7 && lowbeta>=g8 && highbeta<=h7 && highbeta>=h8 && lowgamma<=i7 && lowgamma>=i8 && midgamma<=j7 && midgamma>=j8) 
  return 'TWO';
  
     else if (atten<=a9 && atten>=a0 && medi<=b9 && medi<=b0 && delta<=c9 && delta>=c0 && theta<=d9 && theta>=d0 && lowalpha<=e9 && lowalpha>=e0 && highalpha<=f9 && highalpha>=f0 && lowbeta<=g9 && lowbeta>=g0 && highbeta<=h9 && highbeta>=h0 && lowgamma<=i9 && lowgamma>=i0 && midgamma<=j9 && midgamma>=j0) 
  return 'WAY';
  
     else if (atten<=aa1 && atten>=aa2 && medi<=ba1 && medi<=ba2 && delta<=ca1 && delta>=ca2 && theta<=da1 && theta>=da2 && lowalpha<=ea1 && lowalpha>=ea2 && highalpha<=fa1 && highalpha>=fa2 && lowbeta<=ga1 && lowbeta>=ga2 && highbeta<=ha1 && highbeta>=ha2 && lowgamma<=ia1 && lowgamma>=ia2 && midgamma<=ja1 && midgamma>=ja2) 
  return 'THOUGHT';
  
     else if (atten<=ab1 && atten>=ab2 && medi<=bb1 && medi<=bb2 && delta<=cb1 && delta>=cb2 && theta<=db1 && theta>=db2 && lowalpha<=eb1 && lowalpha>=eb2 && highalpha<=fb1 && highalpha>=fb2 && lowbeta<=gb1 && lowbeta>=gb2 && highbeta<=hb1 && highbeta>=hb2 && lowgamma<=ib1 && lowgamma>=ib2 && midgamma<=jb1 && midgamma>=jb2) 
  return 'TO';
  
     else if (atten<=ac1 && atten>=ac2 && medi<=bc1 && medi<=bc2 && delta<=cc1 && delta>=cc2 && theta<=dc1 && theta>=dc2 && lowalpha<=ec1 && lowalpha>=ec2 && highalpha<=fc1 && highalpha>=fc2 && lowbeta<=gc1 && lowbeta>=gc2 && highbeta<=hc1 && highbeta>=hc2 && lowgamma<=ic1 && lowgamma>=ic2 && midgamma<=jc1 && midgamma>=jc2) 
  return 'THOUGHT';
  
     else if (atten<=ad1 && atten>=ad2 && medi<=bd1 && medi<=bd2 && delta<=cd1 && delta>=cd2 && theta<=dd1 && theta>=dd2 && lowalpha<=ed1 && lowalpha>=ed2 && highalpha<=fd1 && highalpha>=fd2 && lowbeta<=gd1 && lowbeta>=gd2 && highbeta<=hd1 && highbeta>=hd2 && lowgamma<=id1 && lowgamma>=id2 && midgamma<=jd1 && midgamma>=jd2) 
  return 'COMMUNICATION';
  
     else if (atten<=ae1 && atten>=ae2 && medi<=be1 && medi<=be2 && delta<=ce1 && delta>=ce2 && theta<=de1 && theta>=de2 && lowalpha<=ee1 && lowalpha>=ee2 && highalpha<=fe1 && highalpha>=fe2 && lowbeta<=ge1 && lowbeta>=ge2 && highbeta<=he1 && highbeta>=he2 && lowgamma<=ie1 && lowgamma>=ie2 && midgamma<=je1 && midgamma>=je2) 
  return 'SYSTEM';
  
  
}

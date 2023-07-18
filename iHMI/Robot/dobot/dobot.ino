#include "stdio.h"
#include "Protocol.h"
#include "command.h"
#include "FlexiTimer2.h"

//Set Serial TX&RX Buffer Size
#define SERIAL_TX_BUFFER_SIZE 64
#define SERIAL_RX_BUFFER_SIZE 256
static uint32_t timer = millis();
static uint32_t count = 0;

//#define JOG_STICK 
/*********************************************************************************************************
** Global parameters
*********************************************************************************************************/
EndEffectorParams gEndEffectorParams;

JOGJointParams  gJOGJointParams;
JOGCoordinateParams gJOGCoordinateParams;
JOGCommonParams gJOGCommonParams;
JOGCmd          gJOGCmd;

PTPCoordinateParams gPTPCoordinateParams;
PTPCommonParams gPTPCommonParams;
PTPCmd          gPTPCmd;

uint64_t gQueuedCmdIndex;

/*********************************************************************************************************
** Function name:       setup
** Descriptions:        Initializes Serial
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
int current1 = 10;
int current2 = 11;
int current3 = 12;
int current4 = 13;

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
      pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
   pinMode(9,INPUT);
    printf_begin();
    //Set Timer Interrupt
    FlexiTimer2::set(100,Serialread); 
    FlexiTimer2::start();

    InitRAM();
    ProtocolInit();
    
    SetJOGJointParams(&gJOGJointParams, true, &gQueuedCmdIndex);   
    SetJOGCoordinateParams(&gJOGCoordinateParams, true, &gQueuedCmdIndex);   
    SetJOGCommonParams(&gJOGCommonParams, true, &gQueuedCmdIndex);   
    printf("\r\n======Enter demo application======\r\n");  
    SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);   
}

/*********************************************************************************************************
** Function name:       Serialread
** Descriptions:        import data to rxbuffer
** Input parametersnone:
** Output parameters:   
** Returned value:      
*********************************************************************************************************/
void Serialread()
{
  while(Serial1.available()) {
        uint8_t data = Serial1.read();
        if (RingBufferIsFull(&gSerialProtocolHandler.rxRawByteQueue) == false) {
            RingBufferEnqueue(&gSerialProtocolHandler.rxRawByteQueue, &data);
        }
  }
}
/*********************************************************************************************************
** Function name:       Serial_putc
** Descriptions:        Remap Serial to Printf
** Input parametersnone:
** Output parameters:   
** Returned value:      
*********************************************************************************************************/
int Serial_putc( char c, struct __file * )
{
    Serial.write( c );
    return c;
}

/*********************************************************************************************************
** Function name:       printf_begin
** Descriptions:        Initializes Printf
** Input parameters:    
** Output parameters:
** Returned value:      
*********************************************************************************************************/
void printf_begin(void)
{
    fdevopen( &Serial_putc, 0 );
}

/*********************************************************************************************************
** Function name:       InitRAM
** Descriptions:        Initializes a global variable
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void InitRAM(void)
{
    //Set JOG Model
    gJOGJointParams.velocity[0] = 100;
    gJOGJointParams.velocity[1] = 100;
    gJOGJointParams.velocity[2] = 100;
    gJOGJointParams.velocity[3] = 100;
    gJOGJointParams.acceleration[0] = 80;
    gJOGJointParams.acceleration[1] = 80;
    gJOGJointParams.acceleration[2] = 80;
    gJOGJointParams.acceleration[3] = 80;

    gJOGCoordinateParams.velocity[0] = 100;
    gJOGCoordinateParams.velocity[1] = 100;
    gJOGCoordinateParams.velocity[2] = 100;
    gJOGCoordinateParams.velocity[3] = 100;
    gJOGCoordinateParams.acceleration[0] = 80;
    gJOGCoordinateParams.acceleration[1] = 80;
    gJOGCoordinateParams.acceleration[2] = 80;
    gJOGCoordinateParams.acceleration[3] = 80;

    gJOGCommonParams.velocityRatio = 50;
    gJOGCommonParams.accelerationRatio = 50;
   
    gJOGCmd.cmd = AP_DOWN;
    gJOGCmd.isJoint = JOINT_MODEL;

    

    //Set PTP Model
    gPTPCoordinateParams.xyzVelocity = 100;
    gPTPCoordinateParams.rVelocity = 100;
    gPTPCoordinateParams.xyzAcceleration = 80;
    gPTPCoordinateParams.rAcceleration = 80;

    gPTPCommonParams.velocityRatio = 50;
    gPTPCommonParams.accelerationRatio = 50;

    gPTPCmd.ptpMode = MOVL_XYZ;
    gPTPCmd.x = 200;
    gPTPCmd.y = -50;
    gPTPCmd.z = -35;
    gPTPCmd.r = 0;

    gQueuedCmdIndex = 0;

    
}

/*********************************************************************************************************
** Function name:       loop
** Descriptions:        Program entry
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/

void loop() 
{
    delay(5000);
    char c = Serial.read();
    int data1 = analogRead(0);
    int data2 = analogRead(1);
    int data3 = analogRead(2);
    int data4 = analogRead(3);
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;
    
    Serial.print("ch1 ");
    Serial.print(data1);
    Serial.print("     ");
    Serial.print("ch2 ");
    Serial.print(data2);
    Serial.print("     ");
    Serial.print("ch3 ");
    Serial.print(data3);
    Serial.print("     ");
    Serial.print("ch4 ");
    Serial.println(data4);
   

if (data1 < 500)
{
     s1 = 1;
   
}
else
{
   s1 = 0;
}

if (data2 < 500)
{
     s2 = -1;
}

else
{
   s2 = 0;
}

if (data3 < 500)
{
     s3 = 1;
}

else
{
   s3 = 0;
}

if (data4 < 500)
{
    s4 = -1;
   
}

else
{
   s4 = 0;
}

int xc = s1 + s2;
int yc = s3 + s4;
int d = xc*yc;

Serial.print("x  ");
    Serial.print(xc);
    Serial.print("     ");
    Serial.print("y  ");
    Serial.print(yc);
    Serial.print("     ");
    Serial.print("d  ");
    Serial.println(d);
    
if ( d = 0)
{
  if (xc = 1)
  {
  gPTPCmd.z += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
 else if (xc = -1)
  {
      gPTPCmd.z -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
  else if (yc = 1)
  {
  gPTPCmd.y += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
  else if (yc = -1)
  {
      gPTPCmd.y -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }

  
}

else if ( d = 1)
{
  if (xc = 1)
  {
  gPTPCmd.z += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
  else if (xc = -1)
  {
      gPTPCmd.z -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
}

if ( d = -1)
{
  if (xc = 1)
  {
  gPTPCmd.z += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  gPTPCmd.y -= 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);      
  }
 else if (xc = -1)
  {
      gPTPCmd.z -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
        gPTPCmd.y += 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
}

    
else if ( d = 1)
{
  if (xc = 1)
  {
  gPTPCmd.z += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  gPTPCmd.y += 25;
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);      
  }
 else if (xc = -1)
  {
      gPTPCmd.z -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
        gPTPCmd.y -= 25;
       SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  }
}
    
   
  
   

      
        
    switch(c){
        case '1':
            Serial.println(1);
            gPTPCmd.z += 25;
            SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            break;
        case '2':
            Serial.println(2);
            gPTPCmd.z -= 25;
            SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            break;
        case '3':
            Serial.println(3);
            gPTPCmd.y += 25;
            SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            break;
        case '4':
            Serial.println(4);
            gPTPCmd.y -= 25;
            SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            break;
        
        default:
            break;
      }

    ProtocolProcess();
}   

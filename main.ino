int LED = 9;                   

int FIRSTBUTTON = 2;              

int SECONDBUTTON = 3;               
 
int SETPOINT = 0;             

int SETUP = 51;            

int STATE_B1 = 0;             

int STATE_B2 = 0;          

 
void setup() 

{  

    pinMode(LED, OUTPUT);     

    pinMode(FIRSTBUTTON, INPUT);    

    pinMode(SECONDBUTTON, INPUT);   

} 

  

void loop() 

{ 

    STATE_B1 = digitalRead(FIRSTBUTTON);  


    if (STATE_B1 == 1)                

    { 

      SETPOINT = SETPOINT + SETUP;   

      while (STATE_B1 == 1)       

      { 

        STATE_B1 = digitalRead(FIRSTBUTTON); 

      } 

      if (SETPOINT >= 255) 

      { 

        SETPOINT = 255; 

      } 

    } 

    STATE_B2 = digitalRead(SECONDBUTTON); 
 
    if (STATE_B2 == 1)                

    { 

      SETPOINT = SETPOINT - SETUP;  
       
      while (STATE_B2 == 1)       

      { 

        STATE_B2 = digitalRead(SECONDBUTTON); 

      } 

      if (SETPOINT <= 0) 

      { 

        SETPOINT = 0; 

      } 

    } 
    analogWrite(LED, SETPOINT); 

} 
/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project :
Version :
Date    : 8/15/2015
Author  : Dr.EhsanSH
Company : R2T Company
Comments:


Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16a.h>
#include <delay.h>
#define CE            PORTB.3
#define CSN                  PORTB.4
#define MP1  PORTD.0
#define MP2         PORTD.1
#define MP3                PORTD.3
#define MP4                       PORTD.4
#define MP5                              PORTD.5
#define MP6                                     PORTD.6
#define MP7                                            PORTD.7
#define MP8                                                   PORTB.0
#define MN1 PORTC.0
#define MN2        PORTC.1
#define MN3               PORTC.2
#define MN4                      PORTC.3
#define MN5                             PORTC.4
#define MN6                                    PORTC.5
#define MN7                                           PORTC.6
#define MN8                                                  PORTC.7
#define Buzzer PORTB.1
#define LED           PORTB.2
 flash int clockWise = 1;
 flash int unclockWise = 0;
// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here

}

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
// Place your code here

}

// Timer2 output compare interrupt service routine
interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
// Place your code here

}

// SPI functions
#include <spi.h>

// Declare your global variables here
void setIO()
{

// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P
PORTA=0xFF;
DDRA=0x00;

// Port B initialization
// Func7=Out Func6=In Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
// State7=1 State6=P State5=1 State4=0 State3=0 State2=0 State1=0 State0=0
PORTB=0xE0;
DDRB=0xBF;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=In Func1=Out Func0=Out
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=T State1=0 State0=0
PORTD=0x00;
DDRD=0xFB;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: CTC top=OCR2
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x09;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Low level
// INT1: Off
// INT2: Off
GICR|=0x40;
MCUCR=0x00;
MCUCSR=0x00;
GIFR=0x40;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0xC0;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2000.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: High
// SPI Data Order: MSB First
SPCR=0x58;
SPSR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

}
void motorMode (char direction,char motor)
{
    if ((motor >8 )||(motor < 1)|| (direction < 0) || (direction > 1)
    {
        Buzzer = 1;
        delay_ms(1000);
        Buzzer = 0;
    }
switch(motor)
{
case 1 :
    switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
    }


break;
case 2 :
    switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
    }
break;
case 3 :
    switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;
case 4 :
      switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;
case 5 :
     switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;
case 6 :
      switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;
case 7 :
    switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;
case 8 :
      switch (direction)
    {
    case clockWise :
     MN1 = 1;
     MP  = 0;
    break;
    case unclockWise :
     MN1 = 0;
     MP  = 1;
    break;
        }
break;


}
}

void main(void)
{
setIO();
LED = 1;
Buzzer = 1;
delay_ms(200);
LED = 0;
Buzzer = 0;
delay_ms(200);
LED = 1;
Buzzer = 1;
delay_ms(200);
LED = 0;
Buzzer = 0;
delay_ms(200);
LED = 1;
Buzzer = 1;
delay_ms(200);
LED = 0;
Buzzer = 0;
delay_ms(200);
LED = 1;
Buzzer = 1;
delay_ms(200);
LED = 0;
Buzzer = 0;
delay_ms(200);
LED = 1;
Buzzer = 1;
delay_ms(200);
LED = 0;
Buzzer = 0;
// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here

      }
}


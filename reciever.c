#include<p18f4550.h>
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}
void led_config()
{
    TRISBbits.RB2 = 0;
    TRISBbits.RB3 = 0;
}
void spi_pinconfig_master()
{
    TRISCbits.RC7 = 0;  //SDO
    TRISBbits.RB1 = 1;  //SCK
    TRISAbits.RA5 = 1;  //SS   
}
void spi_init()
{
    SSPSTAT = 0X80;
    SSPCON1 = 0X25;
}
void main()
{
    led_config();
    spi_pinconfig_master();
    spi_init();
    LATBbits.LATB4 = 1;
    while(1)
    {
        char ch = SSPBUF;
        while(!SSPCON1bits.SSPOV);
        if(ch == 'A')
        {
            LATBbits.LATB3 = 1;
            delay(100);
            LATBbits.LATB3 = 0;
            delay(100);
        }
        else if(ch == 'B')
        {
            LATBbits.LATB2 = 1;
            delay(100);
            LATBbits.LATB2 = 0;
            delay(100);
        }  
    }
}


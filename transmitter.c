#include<p18f4550.h>
void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<a;j++);
}
void spi_pinconfig_master()
{
    TRISCbits.RC7 = 0;  //SDO
    TRISBbits.RB1 = 0;  //SCK
    TRISAbits.RA5 = 1;  //SS   
}
void spi_init()
{
    SSPSTAT = 0X80;
    SSPCON1 = 0X20;
}
void spi_send(char a)
{
    SSPBUF = a;
}
void main()
{
    spi_pinconfig_master();
    spi_init();
    while(1)
    {
        spi_send('A');
        delay(1000);
        spi_send('B');
        delay(1000);
    }
}

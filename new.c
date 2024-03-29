//LCD module connections
#define LCD_RS_PIN     PIN_D0
#define LCD_RW_PIN     PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4      PIN_D3
#define LCD_DATA5      PIN_D4
#define LCD_DATA6      PIN_D5
#define LCD_DATA7      PIN_D6
//End LCD module connections
 
#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock = 8000000)
#include <lcd.c>
#use fast_io(B)
 
int8 check;
unsigned int16 i, distance;
void main(){
  output_b(0);
  set_tris_b(2);                                   // Configure RB1 as input
  lcd_init();                                      // Initialize LCD module
  setup_timer_1 (T1_INTERNAL | T1_DIV_BY_2);       // Configure Timer1 module
  set_timer1(0);                                   // Reset Timer1
  lcd_putc('\f');                                  // LCD Clear
  lcd_gotoxy(4, 1);                                // Go to column 4 row 1
  lcd_putc("Distance:");
  while(TRUE){
    check = 0;
    i = 0;
    output_high(PIN_B0);
    delay_us(10);
    output_low(PIN_B0);
    set_timer1(0);                                 // Reset Timer1
    while(!input(PIN_B1) && (get_timer1() < 1000));
    if(get_timer1() > 990)
      check = 1;                                   // Timeout error
    set_timer1(0);                                 // Reset Timer1
    while(input(PIN_B1) && (i < 25000))
      i = get_timer1();                            // Store Timer1 value in i 
    if(i > 24990)                                  // Out of range error
      check = 2;
    if(check == 1){
      lcd_gotoxy(3, 2);                            // Go to column 3 row 2
      lcd_putc("  Time Out  ");
    }
    if(check == 2){
      lcd_gotoxy(3, 2);                            // Go to column 3 row 2
      lcd_putc("Out Of Range");
    }
    else{
      distance = i/58;                             // Calculate the distance
      lcd_gotoxy(3, 2);                            // Go to column 3 row 2
      lcd_putc("       cm   ");
      lcd_gotoxy(6, 2);                            // Go to column 6 row 2
      printf(lcd_putc,"%3Lu",distance);
    }
    delay_ms(100);
  }
}

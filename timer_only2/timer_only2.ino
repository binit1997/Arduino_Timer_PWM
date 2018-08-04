/*
   The Atmel® picoPower® ATmega328/P is a low-power CMOS 8-bit microcontroller based on the AVR® enhanced RISC architecture.
   Timer/Counter2 (TC2) is a general purpose, channel, 8-bit Timer/Counter module.
   The fast Pulse Width Modulation or fast PWM mode provides a high frequency PWM waveform generation option.
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  int duty= 50; //DUTY_CYCLE = Y+1/256
  cli();//stop interrupts
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20); //Clear OC2A on Compare Match, set OC2A at BOTTOM (non-inverting mode);Clear OC2B on Compare Match; fast PWM mode
  TCCR2B = _BV(WGM22) | _BV(CS21); //prescaler of 8
  OCR2A = 255; //
  OCR2B = duty; //DUTY_CYCLE = Y+1/256
}

void loop() {
  // put your main code here, to run repeatedly:

}

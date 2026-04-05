# fishfeeder
An arduino based fish feeder

This arduino based fish feeder will

- feed fish periodically based on the value of a potentiometer

*Servo Wiring*
Servo red (VCC) → external 5V supply (or separate set of AA batteries)
Servo brown (GND) → external supply GND and Arduino GND (common ground is required)
Servo yellow (signal) → stays on pin 9


*Button Wiring*
Leg	Connect to
One leg	Pin 2
Other leg	GND
No resistor needed — the code uses INPUT_PULLUP (internal pull-up resistor). The pin reads HIGH at rest and LOW when pressed.
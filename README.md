# Arduino_Self-Driving_Car
The car moves automatically after turning it on.

It reads the distance measurements from the ultrasonic sensor.

When the measurements are bigger than the stored number entered in memory it moves forward.

If the distance is equal to or smaller than the stored number it stops.

Then, the servo motor turns left, and the ultrasonic sensor measures the distance again if it's bigger than the stored number then, it turns right and then moves forward.

And if the measurement is smaller than the stored number when the servo turns left. Then, the servo motor turns right the ultrasonic measure again if it's bigger than the stored number then, it turns left and then moves forward.

And if the three sides are smaller than the stored number then it moves backward then turns left and moves forward. 

Then loop again.

Tools used: Arduino IDE, Arduino UNO, Servo Motor, Ultrasonic Sensor, Breadboard, Car Chassis Kit

from devices import Device
import RPi.GPIO as GPIO


class BasicLight(Device):
    def __init__(self, pin):
        self.pin = pin

    def on(self):
        GPIO.output(self.pin, GPIO.LOW)

    def off(self):
        GPIO.output(self.pin, GPIO.HIGH)

    def cleanup(self):
        self.off()


class RgbLight(BasicLight):
    red_value = 0
    green_value = 0
    blue_value = 0

    def __init__(self, red, green, blue):
        self.red_pin = red
        GPIO.setup(red, GPIO.OUTPUT)
        GPIO.output(red, GPIO.HIGH)
        self.red = GPIO.PWM(red, 2000)

        self.green_pin = green
        GPIO.setup(blue, GPIO.OUTPUT)
        GPIO.output(blue, GPIO.HIGH)
        self.red = GPIO.PWM(blue, 1999)

        self.blue_pin = blue
        GPIO.setup(green, GPIO.OUTPUT)
        GPIO.output(green, GPIO.HIGH)
        self.green = GPIO.PWM(red, 5000)

        red.start(100)
        green.start(100)
        blue.start(100)

    def on(self):
        GPIO.output(self.red_pin, GPIO.LOW)
        GPIO.output(self.green_pin, GPIO.LOW)
        GPIO.output(self.blue_pin, GPIO.LOW)

    def off(self):
        GPIO.output(self.red_pin, GPIO.HIGH)
        GPIO.output(self.green_pin, GPIO.HIGH)
        GPIO.output(self.blue_pin, GPIO.HIGH)

    @staticmethod
    def map(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def change_color(self, red, green, blue):
        self.red_value = self.map(red, 0, 255, 0, 100)
        self.green_value = self.map(green, 0, 255, 0, 100)
        self.blue_value = self.map(blue, 0, 255, 0, 100)

        self.red.ChangeDutyCycle(self.red_value)
        self.green.ChangeDutyCycle(self.green_value)
        self.blue.ChangeDutyCycle(self.blue_value)

    def cleanup(self):
        self.red.stop()
        self.green.stop()
        self.blue.stop()
        self.off()


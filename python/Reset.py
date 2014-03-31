import RPi.GPIO as GPIO
import time

GPIO.setup(12, GPIO.OUT)
GPIO.output(12, True)
time.sleep(0.001)
GPIO.output(12, False)
time.sleep(0.001)
GPIO.output(12, True)
GPIO.setup(12, GPIO.IN)
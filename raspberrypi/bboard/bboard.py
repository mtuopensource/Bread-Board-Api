from enum import Enum
import RPi.GPIO as GPIO


class InitModes(Enum):
    GPIO = 1
    BOARD = 2


def init_bboard(mode: InitModes):
    if mode == InitModes.GPIO:
        GPIO.setmode(GPIO.BCM)
    else:
        GPIO.setmode(GPIO.BOARD)
    pass

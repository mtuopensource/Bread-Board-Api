from . import Device
from enum import Enum


class MotorSpeed(Enum):
    Low = 0
    Medium = 1
    High = 2
    Max = 3


class MotorDirection(Enum):
    Clockwise = 0
    CounterClockwise = 1

class Motor(Device):
    speed = MotorSpeed.Low
    direction = MotorDirection.Clockwise

    def stop(self):
        raise NotImplemented()



class DcMotor(Motor):
    speed = MotorSpeed.Low
    direction = MotorDirection.Clockwise

    def __init__(self, power, data):
        pass

#!/usr/bin/env python
__author__ = 'changtao.pan'

from mDbg import *

__metaclass__ = type
class Bird:
    def __init__(self):
        self.Hungry = True
    def eat(self):
        if self.Hungry:
            NOT_Printf(True, "Ahaaa....")
            self.Hungry = False
        else:
            NOT_Printf(True, "Not Hungry, Thanks")

class SongBird(Bird):
    def __init__(self):
        super(SongBird, self).__init__()
        self.sound = 'Squawk'
    def sing(self):
        INF_Printf(True, self.sound)

if __name__ == '__main__':
    DBG_Printf(True, "Bird Class Test Program")
    bird = Bird()
    bird.eat()
    bird.eat()

    songbird = SongBird()
    songbird.eat()
    songbird.sing()
#!/usr/bin/python
# -*- coding:utf-8 -*-
import sys
__metaclass__ = type
__author__ = 'changtao.pan'


class BinarySearchTree():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.degree = 1

    def query(self, key):
        if self.key == key:
            return self
        elif self.left and self.key < key:
            return self.left.query(key)
        elif self.right and self.key > key:
            return self.right.query(key)
        else:
            return None

    def insert(self, key):
        if self.query(key):
            print 'This key is existed'
            return
        self.degree += 1
        if self.key > key:
            if self.left:
                self.left.insert(key)
            else:
                self.left = BinarySearchTree(key)
        else:
            if self.right:
                self.right.insert(key)
            else:
                self.right = BinarySearchTree(key)

    def show(self):
        print str(self.key)
        if self.left:
            print '%d left:' % self.key
            self.left.show()
        if self.right:
            print '%d right:' % self.key
            self.right.show()


def main():
    print 'sort binary tree process'
    tree = BinarySearchTree(8)
    tree.insert(3)
    tree.insert(5)
    tree.insert(10)
    tree.show()

if __name__ == '__main__':
    main()

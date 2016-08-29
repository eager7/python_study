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
        self.parent = None
        self.degree = 1

    def query(self, key):
        if self.key == key:
            return self
        elif self.left and self.key > key:
            return self.left.query(key)
        elif self.right and self.key < key:
            return self.right.query(key)
        else:
            return None

    def find_min(self):
        if self.left:
            return self.left.findMin()
        else:
            return self

    def find_max(self):
        if self.right:
            return self.right.findmax()
        else:
            return self

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
                self.left.parent = self
        else:
            if self.right:
                self.right.insert(key)
            else:
                self.right = BinarySearchTree(key)
                self.right.parent = self

    def update(self, old, new):
        node = self.query(old)
        if node is None:
            print 'This node is not existed'
            return False
        node.key = new

    def delete(self, key):
        node = self.query(key)
        if node is None:
            print 'This node is not existed'
            return self
        if not node.left and not node.right:    # node是树叶
            if node.parent.left:
                node.parent.left = None
            if node.parent.right:
                node.parent.right = None
        elif node.left and node.right:    # node有两个节点
            min_node = self.right.find_min()
            node.key = min_node.key
            self.delete(min_node.key)
        else:   # node有一个节点
            if node.left:
                node.parent.left = node.left
            else:
                node.parent.right = node.right

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
    tree.insert(4)
    tree.insert(10)
    tree.show()
    print 'delete 5'
    tree.delete(5)
    tree.show()


if __name__ == '__main__':
    main()

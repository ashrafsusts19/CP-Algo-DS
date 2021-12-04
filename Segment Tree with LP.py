#Segment tree implementation with lazy propagation

import random


class SegTree():
    def __init__(self, lst):
        self.buildTree(lst)

    def buildTree(self, lst):
        self.size = (2 ** len(bin(len(lst))[2:])) >> (2 ** (len(bin(len(lst))[2:]) - 1) == len(lst))
        self.segTree = [0] * (self.size * 2)
        for i in range(len(lst)):
            self.segTree[self.size + i] = lst[i]
        for i in range(self.size - 1, 0, -1):
            self.segTree[i] = self.segTree[i * 2] + self.segTree[i * 2 + 1]
        self.lazyTree = [0] * self.size * 2

    def query(self, ind, start, end, cs, ce):
        if self.lazyTree[ind] != 0:
            self.segTree[ind] += (ce - cs + 1) * self.lazyTree[ind]
            if cs != ce:
                self.lazyTree[ind * 2] = self.lazyTree[ind]
                self.lazyTree[ind * 2 + 1] = self.lazyTree[ind]
            self.lazyTree[ind] = 0
        if start > ce or end < cs:
            return 0
        elif start <= cs and end >= ce:
            return self.segTree[ind]
        else:
            return self.query(ind * 2, start, end, cs, (cs + ce) // 2) + self.query(ind * 2 + 1, start, end,
                                                                                    (cs+ce) // 2 + 1, ce)

    def findSum(self, start, end):
        return self.query(1, start, end, 1, self.size)

    def add(self, value, start, end = None):
        if end == None:
            self.update(start - 1, value + self.segTree[self.size + start - 1])
        else:
            self.addQuery(1, start, end, 1, self.size, value)

    def changeValue(self, value, ind):
        self.update(ind - 1, value)

    def update(self, ind, value):
        self.segTree[self.size + ind] = value
        ind = self.size + ind
        while ind > 1:
            ind //= 2
            self.segTree[ind] = self.segTree[ind * 2] + self.segTree[ind * 2 + 1]

    def addQuery(self, ind, start, end, cs, ce, value):
        if self.lazyTree[ind] != 0:
            self.segTree[ind] += (ce - cs + 1) * self.lazyTree[ind]
            if cs != ce:
                self.lazyTree[ind * 2] = self.lazyTree[ind]
                self.lazyTree[ind * 2 + 1] = self.lazyTree[ind]
            self.lazyTree[ind] = 0
        if start > ce or end < cs:
            return self.segTree[ind]
        elif start <= cs and end >= ce:
            self.segTree[ind] += (ce - cs + 1) * value
            if cs != ce:
                self.lazyTree[ind * 2] = value
                self.lazyTree[ind * 2 + 1] = value
        else:
            self.segTree[ind] = self.addQuery(ind * 2, start, end, cs, (cs + ce) // 2, value) + \
                                self.addQuery(ind * 2 + 1, start, end, (cs + ce) // 2 + 1, ce, value)
        return self.segTree[ind]




lst = [random.randint(0, 20) for _ in range(random.randint(9, 16))]

tree = SegTree(lst)
print("Type help for more info")
running = True
while running:
    print(tree.segTree[tree.size:])
    cmd = input().split()
    if cmd[0].lower() == "help":
        print("Ranged Sum: sum <start> <end>\nAdd: add <value> <index>\nRanged Add: add <value> <start> <end>")
        print("Modify Value: update <value> <index>\nPrint Tree: view segtree\nPrint Lazytree: view lazytree")
        print("New Tree: new <list of values>\nRefresh list: refresh\nExit: exit")
    if cmd[0].lower() == "sum":
        print(tree.findSum(int(cmd[1].strip()), int(cmd[2].strip())))
    if cmd[0].lower() == "add":
        if len(cmd) == 3:
            tree.add(int(cmd[1]), int(cmd[2]))
        else:
            tree.add(int(cmd[1]), int(cmd[2]), int(cmd[3]))
    if cmd[0].lower() == "update":
        tree.changeValue(int(cmd[1]), int(cmd[2]))
    if cmd[0].lower() == "view":
        if cmd[1].lower() == "segtree":
            print(tree.segTree)
        if cmd[1].lower() == "lazytree":
            print(tree.lazyTree)
    if cmd[0].lower() == "new":
        lst = list(map(int, cmd[1:]))
        tree.buildTree(lst)
    if cmd[0].lower() == "refresh":
        for i in range(1, tree.size + 1):
            tree.findSum(i, i)
    if cmd[0].lower() == "exit":
        running = False

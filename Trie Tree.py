class Trie():
    class Node():
        def __init__(self, char):
            self.char = char
            self.isword = False
            self.children = {}


    def __init__(self):
        self.root = Trie.Node("\0")

    def insertWord(self, word):
        curr = self.root
        for i in range(len(word)):
            if word[i] not in curr.children:
                curr.children[word[i]] = Trie.Node(word[i])
            curr = curr.children[word[i]]
        curr.isword = True

    def checkWord(self, word):
        curr = self.root
        for i in range(len(word)):
            if word[i] not in curr.children:
                return False
            curr = curr.children[word[i]]
        return curr.isword

    def checkPrefix(self, phrase):
        curr = self.root
        for i in range(len(phrase)):
            if phrase[i] not in curr.children:
                return False
            curr = curr.children[phrase[i]]
        return True




tree = Trie()
running = True
print("Add word: add <wordname>, Search word: find <wordname>, Exit: exit, Check prefix exists: starts <prefix>")
while running:
    word = input().strip().split()
    if word[0].lower() == "add":
        tree.insertWord(word[1])
    elif word[0].lower() == "find":
        print(tree.checkWord(word[1]))
    elif word[0].lower() == "exit":
        running = False
    elif word[0].lower() == "starts":
        print(tree.checkPrefix(word[1]))

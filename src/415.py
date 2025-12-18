class Student():

    def __init__(self, name, score):
        self.name = name
        self.score = score

    def print_score(self):
        print( '%s: %s'%(self.name, self.score))
# ____qcodep____
    def grade(self):
        if 90 <= self.score <= 100:
            return 4.0
        elif 86 <= self.score <= 89:
            return 3.7
        elif 83 <= self.score <= 85:
            return 3.3
        elif 80 <= self.score <= 82:
            return 3.0
        elif 76 <= self.score <= 79:
            return 2.7
        elif 73 <= self.score <= 75:
            return 2.3
        elif 70 <= self.score <= 72:
            return 2.0
        elif 66 <= self.score <= 69:
            return 1.7
        elif 63 <= self.score <= 65:
            return 1.3
        elif 60 <= self.score <= 62:
            return 1.0
        else:
            return 0



sc=int(input())
stu=Student("stu001",sc)
print(stu.grade())

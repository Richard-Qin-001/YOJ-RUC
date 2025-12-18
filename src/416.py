# ____qcodep____
class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
    def getCenter(self):
        return "({}, {})".format(self.x, self.y)
    def getRadius(self):
        return self.r
    def getArea(self):
        return 3.14 * self.r ** 2

(x, y, r) = map(int, input().split())
c1 = Circle(x, y, r)
print("The center of the circle is ", c1.getCenter(), " and the radius is ", c1.getRadius())
print("The area is ", c1.getArea())
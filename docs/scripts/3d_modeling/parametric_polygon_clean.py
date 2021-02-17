import math
import ezdxf
import random

# Parameters
sides = random.randrange(3, 10, 1)
radius = 40
origin = (100,100)
slot_depth = radius/2
kerf = 0.2
material_thickness = 5

class dxf_file():
    def __init__(self, __filename):
        self.filename = __filename
        self.file = None
        self.create_dxf()

    def create_dxf(self):
        self.file = ezdxf.new('R2018')
        self.file.saveas(self.filename)

    def save_dxf(self):
        self.file.saveas(self.filename)

    def add_vectors_dxf(self, vectors):
        self.model = self.file.modelspace()
        for vector in vectors:
            self.model.add_line(vector[0], vector[1])
            self.save_dxf()


def rotate_point(point, pivot, angle):
    x = ((point[0] - pivot[0]) * math.cos(angle)) - ((point[1] - pivot[1]) * math.sin(angle)) + pivot[0]
    y = ((point[0] - pivot[0]) * math.sin(angle)) + ((point[1] - pivot[1]) * math.cos(angle)) + pivot[1]
    return (x, y)


def line_intersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       raise Exception('lines do not intersect')

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return (x, y)


class workspace():
    def __init__(self, __origin=(0,0), __width=1000, __height=1000):
        self.origin = __origin
        self.width = __width
        self.height = __height
        self.objects = []

    def add_object(self, __object):
        self.objects.append(__object)
        # Should I sort this?


class polygon():
    def __init__(self, __origin, __sides, __radius, __kerf=kerf):
        self.kerf = __kerf
        self.sides = __sides
        # kerf parameter
        self.radius = __radius + self.kerf
        self.origin = __origin
        self.points = []
        self.vectors = []
        self.angle = 360/self.sides
        self.make()
        self.get_vectors()

    def make(self):
        for side in range(0, self.sides):
            __x = self.origin[0] + self.radius * math.cos(2 * math.pi * side / self.sides)
            __y = self.origin[1] + self.radius * math.sin(2 * math.pi * side / self.sides)
            self.points.append((__x, __y))

    def get_vectors(self):
        self.vectors = list(zip(self.points, self.points[1:] + self.points[:1]))

    def slot(self, __width, __depth):

        # kerf parameter
        width = __width - self.kerf
        depth = __depth - self.kerf
        # Define points of slot shape:
        __a = (self.origin[0] + self.radius - depth, self.origin[1] - (width / 2))
        __b = (self.origin[0] + self.radius - depth, self.origin[1] + (width / 2))
        __c = (self.origin[0] + self.radius, self.origin[1] + (width / 2))
        __d = (self.origin[0] + self.radius, self.origin[1] - (width / 2))

        # Set initial position rotate to initial position
        __a = rotate_point(__a, self.origin, math.radians(self.angle / 2))
        __b = rotate_point(__b, self.origin, math.radians(self.angle / 2))
        __c = rotate_point(__c, self.origin, math.radians(self.angle / 2))
        __d = rotate_point(__d, self.origin, math.radians(self.angle / 2))

        # packing slot sides
        slot_left_side_1 = (__b, __c)
        slot_right_side_1 = (__a, __d)

        # finding intersection point between slot sides and polygon face 1
        right_inter = line_intersection(self.vectors[0], slot_right_side_1)
        left_inter = line_intersection(self.vectors[0], slot_left_side_1)

        # Manually ordering the points of the slot shape
        output = [self.points[0]]
        output.append(right_inter)
        output.append(__a)
        output.append(__a)
        output.append(__b)
        output.append(__b)
        output.append(left_inter)
        # index 7

        # repeating the process radially for the number of faces.
        for side in range(1, self.sides):
            output.append(rotate_point(self.points[0], self.origin, math.radians(side * self.angle)))
            output.append(rotate_point(right_inter, self.origin, math.radians(side * self.angle)))
            output.append(rotate_point(__a, self.origin, math.radians(side *self.angle)))
            output.append(rotate_point(__a, self.origin, math.radians(side *self.angle)))
            output.append(rotate_point(__b, self.origin, math.radians(side *self.angle)))
            output.append(rotate_point(__b, self.origin, math.radians(side *self.angle)))
            output.append(rotate_point(left_inter, self.origin, math.radians(side * self.angle)))

        # creating a vector list from the points list
        self.output = list(zip(output, output[1:] + output[:1]))


# program test

# creating a random generated polygon
a = polygon(origin, sides, radius)
a.slot(material_thickness, slot_depth)

# creating a DXF document and adding slot output vectors
dxf_file_ = dxf_file("test.dxf")
a.get_vectors()
dxf_file_.add_vectors_dxf(a.output)

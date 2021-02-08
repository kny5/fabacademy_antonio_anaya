import openpyscad as ops

class shape_1():
    cube_1 = ops.Cube([10, 20, 10])
    cube_2 = ops.Cube([20, 10, 10])
    sphe_1 = ops.Sphere(9)

    operation = cube_1 + cube_2
    operation = sphe_1 - operation
    def _write(self, arg):
        self.operation.write(arg)

    def _translate(self,position):
        self.operation.translate(position)

body_1 = shape_1()

body_2 = shape_1()
body_2._translate([20,20,20])

# body_1._write("sample.scad")

difference(){
    sphere(r=9);
    union(){
        cube(size=[10, 20, 10]);
        cube(size=[20, 10, 10]);
    };
};

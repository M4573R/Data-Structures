Given three points a, b, and c, determine whether they form a counterclockwise angle. 
The function ccw takes three Point inputs a, b, and c and returns +1 if a->b->c is a counterclockwise angle, 
-1 if a->b->c is a clockwise angle, and 0 if a->b->c are collinear. 
Use the following determinant formula which gives twice the (signed) area of the triangle a->b->c. 
If the area is positive, then a->b->c is counterclockwise; if the area is negative, then a->b->c is counterclockwise; 
if the area is zero then a->b->c are collinear.

From [Geometric primitives](http://algs4.cs.princeton.edu/91primitives/)

![alt](http://algs4.cs.princeton.edu/91primitives/images/collinear.png)



and 

![alt](https://cloud.githubusercontent.com/assets/4555412/11016217/5c874912-85a4-11e5-8242-2cda0d1bb5de.png)



ccw test : 
The second version might be more efficient since fewer multiplications and additions.
Susceptible to overflow error - consider using long integers for intermediate results.
public static int ccw(Point a, Point b, Point c) {
   return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

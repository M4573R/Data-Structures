Polygons are two-dimensional shapes. They are made of straight lines, and the shape is "closed". If all angles are equal and all sides are equal, then it is regular, otherwise it is irregular.

The general formula of area of a polygon:

Area = 1/2 * Σ (From i=0 to n-1) Xi * Yi+1 - Xi+1 + Yi

It returns us the area of any polygon, given its vertices, where n is the number of vertices.


![Polygon Area](https://cloud.githubusercontent.com/assets/4555412/11033135/1ffec8cc-870b-11e5-83d9-fa175068b790.png)



Code : 

```C++
int n,x[1000],y[1000]; //keep all x and y's, n is the number of vertices
int main(){
cin>>n;
for (int i=0;i<n;i++)
{ cin>>x[i]>>y[i]; }
int polygon_area = 0; 
x[n]=x[0]; // last point is same as first
y[n]=y[0];
for (int i=0;i<n;i++)
	polygon_area += x[i+1]*y[i]-x[i]*y[i+1]; //calculate polygon's area
cout << polygon_area << endl;
}
```

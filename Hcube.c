#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<math.h>
#define WIDTH 80
#define HEIGHT 40
//#define d 70
float d = 70;
char screen[HEIGHT][WIDTH];
typedef struct{
float x;
float y;
float z;
} point3D;
typedef struct{
float x;
float y;
}point2d;
point2d planeA[4] = {{-10,10},{10,10},{10,-10},{-10,-10}};
point3D face[4] = {{-10,10,30},{10,10,30},{10,-10,30},{-10,-10,30}};
point3D cube[8]= {{-10,10,-10},{10,10,-10},{10,-10,-10},{-10,-10,-10},{-10,10,10},{10,10,10},{10,-10,10},{-10,-10,10}};
int edge[12][2]={{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{2,6},{3,7}};
void clearScreen(){
for (int row = 0; row < HEIGHT; row++){
for (int col = 0; col < WIDTH; col++){
screen[row][col] = ' ';
}
}
}

void drawPixel(int x, int y, char ch){
if (x >= 0 && x < WIDTH &&
y >= 0 && y < HEIGHT){
screen[y][x] = ch;
}
}
void render(){
printf("\x1b[H");
for (int row = 0; row < HEIGHT; row++){
for (int col = 0; col < WIDTH; col++) {
putchar(screen[row][col]);
}
putchar('\n');
}
}
void drowline(float x1,float y1,float x2,float y2){
float dx = fabsf(x2-x1);
float dy = fabsf(y2-y1);
int sx = (x1<x2)?1:-1;
int sy = (y1<y2)?1:-1;
int err = dx-dy;
int e2;
while(1){
drawPixel((int)x1,(int)y1,'.');
if(x1==x2 && y1==y2) break;
e2 = 2*err;
if(e2>-dy){
err -= dy;
x1 +=sx;
}
if(e2<dx){
err +=dx;
y1+= sy;
}
}
}
point2d rotate(point2d p,float angle){
point2d result;
result.x = round(p.x*(cos(angle))-p.y*sin(angle));
result.y = round(p.x*(sin(angle))+p.y*cos(angle));
return result;
}
point2d project(point3D p){
point2d sp;
if(p.z<1){
p.z = 1;
}
sp.x = (p.x*d)/p.z;
sp.y = (p.y*d)/p.z;
return sp;
}

point3D rotatex(point3D p,float angle){
point3D result;
result.x = p.x;
result.y = p.y*cos(angle)-p.z*sin(angle);
result.z = p.y*sin(angle)+p.z*cos(angle);
return result;
}
point3D rotatey(point3D p,float angle){
point3D result;
result.x = p.x*cos(angle) + p.z*sin(angle);
result.y = p.y;
result.z = -p.x*sin(angle)+p.z*cos(angle);
return result;
}
point3D rotatez(point3D p,float angle){
point3D result;
result.x = p.x*cos(angle)-p.y*sin(angle);
result.y = p.x*sin(angle) + p.y*cos(angle);
result.z = p.z;
return result;
}
int main()
{
int midx = WIDTH/2;
int midy = HEIGHT/2;
printf("\x1b[2J");
double angle = 0;
while (1){
angle += 0.02;
clearScreen();
//drawPixel(WIDTH / 2, HEIGHT / 2, 'O');

// drow square in 2d plane 
//point2d rot[4];
//for(int i=0;i<4;i++){
//rot[i] = rotate(planeA[i],angle);
//}
//for(int i=0;i<4;i++){
//drowline((int)round(rot[i].x+midx),(int)round(midy-rot[i].y),(int)round(rot[(i+1)%4].x+midx),(int)round(midy-rot[(i+1)%4].y));
//}
// /////////////////////////////////////////////
// 3D point projection
//point3D p = {10,5,22};
//point3D q = {30,15,200};
//point2d ra = project(p);
//point2d rb = project(q);
//drawPixel(midx+ra.x,midy-ra.y,'O');
//drawPixel(midx+rb.x,midy-rb.y,'X');
// /////////////////////////////////////////

// 3d square
int camdis = 80; 
point3D rotated3D[8];
point2d projected[8];
for(int i=0;i<8;i++){
point3D p = cube[i];
p = rotatex(p,angle);
p = rotatey(p,angle);
p = rotatez(p,angle);
p.z +=camdis;
rotated3D[i] = p;
projected[i]= project(p);
}
for(int i=0;i<12;i++){
int a = edge[i][0];
int b = edge[i][1];
drowline((int)round(midx+projected[a].x),(int)round(midy-projected[a].y),(int)round(midx+projected[b].x),(int)round(midy-projected[b].y));
}
render();
usleep(16000);
}

return 0;
}

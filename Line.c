#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
int point = 5;
int pointx = 3;
int pointy = 3;
int org = 12;
char mat[25][25];
for(int t=0;t<25;t++){
for(int y=0;y<25;y++){
mat[t][y] = ' ';
}
}
printf("\x1b[2J");
while(1){
for(double o=0;o<=2*M_PI;o+=0.524){
for(int px=0;px<3;px++){
int x = px+3;
int locx =round(x*(cos(o)) +x*(sin(o)));
int locy =round(-x*(sin(o)) + x*(cos(o)));
if(org+locx>=0 && org+locx<25 && org+locy>=0 && org+locy<25){
mat[(org)+ locx][(org)+locy]= 'O';
}
}
for(int width =1;width<25;width++){
for(int height = 1;height<25;height++){
printf("%c ",mat[width][height]);
}
printf("\n");
}
for(int px=0;px<25;px++){
for(int py=0;py<25;py++){
mat[px][py]=' ';
}
}
printf("\x1b[H");
usleep(16000);
}
}
return 0;
}

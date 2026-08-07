#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
int radius = 2;
int orgx = 6;
int orgy = 6;
int centerx = 12;
int centery = 12;
char mat[24][24];
for(int t=0;t<24;t++){
for(int y=0;y<24;y++){
mat[t][y] = ' ';
}
}
mat[12][12] = 'o';

printf("\x1b[2J");
while(1){
for(double ang = 0;ang<=2*M_PI;ang+=0.524){
int rx = 6;
orgx = round(rx*(cos(ang)));
orgy = round(rx*(sin(ang)));
for(double o=0;o<=2*M_PI;o+=0.524){
///for(int px=0;px<3;px++){
int x = radius;
int locx =round(x*(cos(o)));
int locy =round(x*(sin(o)));
if(centerx + orgx+locx>=0 && centerx +orgx+locx<24 &&centery+ orgy+locy>=0 &&centery+ orgy+locy<24){
mat[centerx+orgx+ locx][centery+ orgy+locy]= '*';
}
//}
for(int width =0;width<24;width++){
for(int height = 0;height<24;height++){
printf("%c ",mat[width][height]);
}
printf("\n");
}
//for(int px=0;px<24;px++){
//for(int py=0;py<24;py++){
//mat[px][py]=' ';
//}
//}
printf("\x1b[H");
usleep(16000);
}
for(int row=0;row<24;row++){
for(int col=0;col<24;col++){
mat[row][col] = ' ';
}
}
mat[12][12] = 'o';
}
}
return 0;
}

#include<GL/gl.h>        
#include<GL/glu.h>       
#include<GL/glut.h>        
#include<stdlib.h>
#include<stdio.h>
void draw(){
    
glClear(GL_COLOR_BUFFER_BIT);


gluOrtho2D(-100,100,-100,100); 
glFlush();
}

void mouse(int button, int state, int x, int y){
glClear(GL_COLOR_BUFFER_BIT);
//if(button==GLUT_LEFT_BUTTON){
glClearColor(1,0,0,0);
glFlush();
//}

}

void keyboard(unsigned char key,int x,int y){
if(key=='q'){
printf("%d %d",x,y);
exit(0);
}
}



int main(int argc, char **argv){
glutInit(&argc, argv); 
        
glutInitWindowSize(500,500);        
glutCreateWindow("single viewport spans the left-bottom interface window quarter");        
glutDisplayFunc(draw); 
glutMouseFunc(mouse);       
glutKeyboardFunc(keyboard);        
glutMainLoop();
return 0;
}

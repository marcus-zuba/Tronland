#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "global.h"
#include "vector.h"
#include "glm.h"
#include "load.h"
#include "music.h"

void setupProjection();

void reshape(int w, int h) {
    glViewport (0, 0, w, h);
    setupProjection();
}

void setupProjection() {
    float aspectRatio = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(orthoperspective==1){
        gluPerspective(45, aspectRatio, 1, 1000);
    }else{
        glOrtho(-100, 100, -100, 100, 0, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void initialize(){
    
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHTING);
    glDisable(GL_FOG);

    lightingswitch = 1;
    fogswitch = 0;
    pauseSwitch = 0;

    orthoperspective=0;

    red = green = blue = 1;
    lighttimer=0;


    tronland = glmReadOBJ("../graphics/obj/Tronland.obj");
    ferriswheelBase = glmReadOBJ("../graphics/obj/ferriswheelbase.obj");
    wheel = glmReadOBJ("../graphics/obj/wheel.obj");
    towerFall = glmReadOBJ("../graphics/obj/towerfLL.obj");
    towerFallCabins = glmReadOBJ("../graphics/obj/towerfallcabins.obj");
    carouselStructure = glmReadOBJ("../graphics/obj/carousel.obj");
    carouselMoto1 = glmReadOBJ("../graphics/obj/motorcycle1.obj");
    carouselMoto2 = glmReadOBJ("../graphics/obj/motorcycle2.obj");
    globeOfDeath = glmReadOBJ("../graphics/obj/globeofdeath.obj");
    globeOfDeathMoto = glmReadOBJ("../graphics/obj/globeofdeathMotorcycle.obj");

    idMenu = loadTexture("../graphics/StartScreen/startscreen.png");
    idStart = loadTexture("../graphics/StartScreen/iniciarButton.png");
    idSelectedStart = loadTexture("../graphics/StartScreen/iniciarButtonP.png");
    idExit = loadTexture("../graphics/StartScreen/sairButton.png");
    idSelectedExit = loadTexture("../graphics/StartScreen/sairButtonP.png");
    idPause = loadTexture("../graphics/StartScreen/sairButtonP.png");

    menuMusic = load_music("../music/Menumusic.ogg");
    playingMusic = load_music("../music/Gamemusic.ogg");
    choise = load_music("../music/select.ogg");

    ytowerfallcabins=0;
    falling=0;
    goingup=0;
    waitingup=0;      //tower fall variables
    waitingdown=1;
    towerfalltimer=0;

    xCursor= 0;
    yCursor= 2; //a câmera começa olhando para o ponto 0
    zCursor= 0;

    camera.x=0;
    camera.y=1;
    camera.z=0;

    phi=90, teta=0;
    xMouse=0, yMouse=0;

    degreeFW=0;
    degreeCarousel=0;
    degreeGlobeOfDeath=0;
    yCMoto1=-0.5;
    yCMoto2=0.5;
    carouselTimer=0;

    currentCamera=TWO;
    currentTopCamera=0;
    currentScreen=MENU;
    currentButton=START;

    play_music(menuMusic,1,-1);

    printf("\n\nWELCOME TO TRONLAND!!!\n\n");
    
    printf("Comands in menu:\n");
    printf("[w] [s] -> switch between buttons\n");
    printf("[enter] -> select\n");
    printf("[esc] -> exit the game\n\n");

    printf("Comands in game:\n");
    printf("[1] [2] [3] -> switch between cameras\n");
    printf("[w] [a] [s] [d] -> walk in world and change camera position\n");
    printf("[q] [e] ->  control height of camera 1\n");
    printf("[mouse] -> control view of camera 1\n");
    printf("[l] -> turn on/off lightining\n");
    printf("[n] -> turn on/off fog\n");
    printf("[p] -> pause rides movement\n");
    printf("[esc] -> exit the game\n\n");

}
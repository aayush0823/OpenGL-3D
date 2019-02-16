#include "main.h"
#include "timer.h"
#include "ball.h"
#include "enemy.h"
#include "background.h"
#include "dashboard.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;
glm::vec3 eye,target,up;
/**************************
* Customizable functions *
**************************/
long long int frame = 0;
int check=0;
int view_change = 0;
int accelerator = 0;
int shoot = 0;
int enemy_shoot = 0;
double fuel_level = 5.0;
int score =0;
int damage = 50;
double prevx, prevy;
double cam_x,cam_y;
Dashboard board[3];
Dashboard speedometer;
Dashboard compass;
vector<Dashboard> pointers;
vector<Enemy> land;
vector<Enemy> fuel;
vector<Enemy> cannon;
vector<Enemy> arrow;
vector<Enemy> flag;
vector<Enemy> volcano;
vector<Enemy> bomb;
vector<Enemy> bomb_enemy;
vector<Enemy> missile;
vector<Enemy> boat;
vector<Enemy> ring;
vector<Enemy> parachute;

Ball player;
Bg background;

int width  = 1600;
int height = 1600;
int view=2;

void detect_collision();

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

void draw() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram (programID);

    eye = glm::vec3(0,0,5);
    target = glm::vec3(0,0,0);
    up = glm::vec3(0,1,0);
    Matrices.view = glm::lookAt( eye, target, up );
    glm::mat4 VP2 = Matrices.projection2 * Matrices.view;
    board[0].draw(VP2,-3.7,-2.5,0,0.8*fuel_level,COLOR_BROWN,0);
    board[1].draw(VP2,-3.7,-2.8,0,0.8*player.position.y,COLOR_RED,0);
    board[2].draw(VP2,-3.7,-3.1,0,0.12*damage,COLOR_YELLOW,0);
    speedometer.draw(VP2,3,3,0,player.speed,COLOR_YELLOW,1);
    compass.draw(VP2,-3,3,0,player.speed,COLOR_YELLOW,2);
    pointers[0].draw(VP2,-3,3,0,player.rotationy,COLOR_ORANGE,3);
    pointers[1].draw(VP2,(cannon[0].position.x - player.position.x)/100-3,(cannon[0].position.z - player.position.z)/100 +3,0,player.speed,COLOR_BLACK,4);
    for(int i=0;i<volcano.size();i++)
    {
    	if((mod((volcano[i].position.x - player.position.x)/100)*mod((volcano[i].position.x - player.position.x)/100) + mod((volcano[i].position.z - player.position.z)/100)*mod((volcano[i].position.z - player.position.z)/100)) < 1)
    		pointers[i+2].draw(VP2,(volcano[i].position.x - player.position.x)/100-3,(volcano[i].position.z - player.position.z)/100 + 3,0,player.speed,COLOR_RED,4);
    }
    for(int i=0;i<fuel.size();i++)
    {
    	if((mod((fuel[i].position.x - player.position.x)/100)*mod((fuel[i].position.x - player.position.x)/100) + mod((fuel[i].position.z - player.position.z)/100)*mod((fuel[i].position.z - player.position.z)/100)) < 1)
    		pointers[i+2+volcano.size()].draw(VP2,(fuel[i].position.x - player.position.x)/100-3,(fuel[i].position.z - player.position.z)/100 + 3,0,player.speed,COLOR_GREEN,4);
    }
    if(view==0)//top
    {
   		eye = glm::vec3( player.position.x , player.position.y + 30, player.position.z + 1);
    	target = glm::vec3(player.position.x , player.position.y , player.position.z);
   		up = glm::vec3(0, 1, 0);
	}
	else if(view==1)//tower
	{
		eye = glm::vec3( player.position.x - 10 , player.position.y + 15, player.position.z - 10);
    	target = glm::vec3(player.position.x , player.position.y , player.position.z);
   		up = glm::vec3(0, 1, 0);
	}
	else if(view==2)//front
	{
		eye = glm::vec3( player.position.x + 1*sin(player.rotationy * M_PI / 180.0f), player.position.y, player.position.z + 1*cos(player.rotationy * M_PI / 180.0f));
    	target = glm::vec3(player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 10*cos(player.rotationy * M_PI / 180.0f));
   		up = glm::vec3(0, 1, 0);
	}
	else if(view==3)//follow
	{
		eye = glm::vec3( player.position.x - 3*sin(player.rotationy * M_PI / 180.0f), player.position.y + 0.5, player.position.z - 3*cos(player.rotationy * M_PI / 180.0f));
    	target = glm::vec3(player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 10*cos(player.rotationy * M_PI / 180.0f));
   		up = glm::vec3(0, 1, 0);
	}
	else if(view==4)
	{
		double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        cam_y -= + (ypos - prevy) * 90 / height;
        cam_x += + (xpos - prevx) * 90 / width;
        prevy = ypos;
        prevx = xpos;
        target = glm::vec3(player.position.x, player.position.y, player.position.z);

        float eye_y = player.position.y + (20-10*screen_zoom)*cos(cam_y*M_PI/180.0f);
        if(eye_y<0.1)eye_y=0.1;
        eye = glm::vec3(player.position.x + (20-10*screen_zoom)*cos(cam_x*M_PI/180.0f)*sin(cam_y*M_PI/180.0f),eye_y,player.position.z + (20-10*screen_zoom)*sin(cam_x*M_PI/180.0f)*sin(cam_y*M_PI/180.0f));
        up = glm::vec3(0,1,0);
	}
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    background.draw(VP);
    for(int i=0;i<land.size();i++)
    	land[i].draw(VP);
    for(int i=0;i<fuel.size();i++)
    	fuel[i].draw(VP);
    if(cannon.size()>0)
	    cannon[0].draw(VP);
    if(arrow.size()>0)
	    arrow[0].draw(VP);
    for(int i=0;i<volcano.size();i++)
    	volcano[i].draw(VP);
    for(int i=0;i<bomb.size();i++)
    	bomb[i].draw(VP);
    for(int i=0;i<ring.size();i++)
    	ring[i].draw(VP);
    for(int i=0;i<bomb_enemy.size();i++)
    	bomb_enemy[i].draw(VP);
    for(int i=0;i<missile.size();i++)
    	missile[i].draw(VP);
    for(int i=0;i<boat.size();i++)
    	boat[i].draw(VP);
    for(int i=0;i<parachute.size();i++)
    	parachute[i].draw(VP);
    player.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int front  = glfwGetKey(window, GLFW_KEY_UP);
    int right  = glfwGetKey(window, GLFW_KEY_RIGHT);
    int back  = glfwGetKey(window, GLFW_KEY_DOWN);
    int acc  = glfwGetKey(window, GLFW_KEY_SPACE);
    int bo  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    int mis  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int v = glfwGetKey(window, GLFW_KEY_V);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int z = glfwGetKey(window, GLFW_KEY_Z);
    int x = glfwGetKey(window, GLFW_KEY_X);
    
    if(acc)
    {
    	accelerator++;
    	player.speed = 0.2 + 0.002*accelerator;
    	if(player.speed > 0.57) player.speed = 0.57;
    }
    else
    {
    	accelerator=0;
    	player.speed = 0.2;
    }
    if(a)player.rotate(1);
    if(d)player.rotate(2);
    if(z)player.rotate(3);
    if(x)player.rotate(4);
    
    if(mis && shoot  == 0)
    {
    	missile.push_back(Enemy(player.position.x, player.position.y, player.position.z,COLOR_BLACK, 5));
    	shoot = 1;
    	missile[missile.size()-1].rotationx = player.rotationx;
    	missile[missile.size()-1].rotationy = player.rotationy;
    	missile[missile.size()-1].rotationz = player.rotationz;
    }
    if(bo && shoot  == 0)
    {
    	bomb.push_back(Enemy(player.position.x + 0.7*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 0.7*cos(player.rotationy * M_PI / 180.0f),COLOR_BLACK, 4));
    	shoot = 1;
    }
    if (v && view_change  == 0 ) {
    	view++;
    	view%=5;
        view_change = 1;
    }
    if(left)
    {
    	player.tick(2);
    }
    if(right)
    {
    	player.tick(1);
    }
    if(front)
    {
    	player.tick(3);
    }
    if(back)
    {
    	player.tick(4);
    }
    if(w)
    {
    	player.tick(5);
    }
    if(s)
    {
    	for(int i=0;i<land.size();i++)
    	if(mod(land[i].position.x-player.position.x)<=1.2 && mod(land[i].position.y-player.position.y)<=0.15 && mod(land[i].position.z-player.position.z)<=1.2)
    	{
    		player.tick(5);
    	}	
    	player.tick(6);
    }
}

void tick_elements() {
    camera_rotation_angle += 1;
    for(int i=0;i<bomb.size();i++)
    	bomb[i].missile();
    for(int i=0;i<bomb.size();i++)
    	if(bomb[i].position.y < 0)
         	bomb.erase(bomb.begin()+i);

    if(enemy_shoot == 0)
    {
    	enemy_shoot = 1;
    	bomb_enemy.push_back(Enemy(cannon[0].position.x, cannon[0].position.y, cannon[0].position.z,COLOR_ORANGE, 4));
    	bomb_enemy[bomb_enemy.size()-1].playerx = player.position.x + rand()%3/2;
    	bomb_enemy[bomb_enemy.size()-1].playery = player.position.y + rand()%3/2;
    	bomb_enemy[bomb_enemy.size()-1].playerz = player.position.z + rand()%3/2;
    	bomb_enemy[bomb_enemy.size()-1].time = frame;
    }

    for(int i=0;i<bomb_enemy.size();i++)
    	bomb_enemy[i].enemybomb();

    for(int i=0;i<parachute.size();i++)
    	parachute[i].parachute();

    for(int i=0;i<bomb_enemy.size();i++)
    	if(bomb_enemy[i].time - frame > 1200)
         	bomb_enemy.erase(bomb_enemy.begin()+i);

    for(int i=0;i<missile.size();i++)
    	missile[i].boom(missile[i].rotationx, missile[i].rotationy);
    
    for(int i=0;i<missile.size();i++)
    	if(missile[i].position.y < 0)
         	missile.erase(missile.begin()+i);
}

void dead(){
	if(player.position.y < 0)
    	printf("SORRY! SUBMERGED UNDERWATER\n");
    else if(fuel_level < 0 )
    	printf("SORRY! FUEL EXHAUSTED\n");
    else if(damage <= 0)
    	printf("SORRY! EXCESSIVE DAMAGE CAUSED BY ENEMIES\n");
    else
    	printf("SORRY! PLAYER DIED DUE TO CLOSE PROXIMITY OF VOLCANO\n");
	printf(" ___   _   __  _______    ___ _   _________\n");
    printf("/  _| /_\\ |  \\/  | __|   / _ \\ \\ / / __| _ \\\n");
    printf("| ( |/ _ \\| |\\/| | _|    | () \\ V /| _||   /\n");
    printf("\\___/_/ \\_\\_|  |_|___|   \\___/ \\_/ |___|_|_\\\n");
    printf("BETTER LUCK NEXT TIME\n");
    printf("YOUR FINAL SCORE = %d\n YOU REQUIRED TO CLEAR %d MORE CHECK-POINTS\n",score,5-check);
	quit(window);
}

void initGL(GLFWwindow *window, int width, int height) {
    player       = Ball(0,1,0, COLOR_SILVER);
    background   = Bg(0,0,0,COLOR_BLUE);
    for(int i=0;i<30;i++)
    for(int k=0;k<30;k++)
    	if(rand()%2==0)
    	{
    		land.push_back(Enemy(i*10,0.1,k*10 + 3,COLOR_GREEN,1));
    		if(rand()%30 == 0)
    		{
    			cannon.push_back(Enemy(i*10,0.3,k*10+3,COLOR_BLACK,7));
    			arrow.push_back(Enemy(i*10,2,k*10+3,COLOR_RED,8));
    		}
    		else if(rand()%3 == 0)
    			fuel.push_back(Enemy(i*10,1,k*10 + 3,COLOR_BROWN,2));
    		else if(rand()%10 == 1)
    			volcano.push_back(Enemy(i*10,0.1,k*10 + 3,COLOR_BLACK,3));
		}
		else
		{
    		boat.push_back(Enemy(i*10,0.3,k*10 + 3,COLOR_BLACK,6));
    		if(rand()%30 == 0)
			    parachute.push_back(Enemy(i*10,4.3,k*10 + 3, COLOR_BROWN,10));
		}

	for(int i=1;i<cannon.size();i++)
	{
		if((abs(player.position.x - cannon[i].position.x) + abs(player.position.z - cannon[i].position.z)) < (abs(player.position.x - cannon[0].position.x) + abs(player.position.z - cannon[0].position.z)))
		{
			Enemy a,b;
			a=cannon[i];
			cannon[i]=cannon[0];
			cannon[0]=a;
			b=arrow[i];
			arrow[i]=arrow[0];
			arrow[0]=b;
		}			
	}
	board[0] = Dashboard(-3.7,-2.5,0,COLOR_BROWN,0);
    board[1] = Dashboard(-3.7,-2.8,0,COLOR_RED,0);
    board[2] = Dashboard(-3.7,-3.1,0,COLOR_YELLOW,0);
    speedometer = Dashboard(3,3,0,COLOR_YELLOW,1);
    compass = Dashboard(-3,3,0,COLOR_YELLOW,2);
    pointers.push_back(Dashboard(-3,3,0,COLOR_ORANGE,3));
    pointers.push_back(Dashboard((cannon[0].position.x - player.position.x)/100-3,(cannon[0].position.z - player.position.z)/100 +3,0,COLOR_BLACK,4));
    for(int i=0;i<volcano.size();i++)
    	pointers.push_back(Dashboard((volcano[i].position.x - player.position.x)/100-3,(volcano[i].position.z - player.position.z)/100 + 3,0,COLOR_RED,4));
    for(int i=0;i<fuel.size();i++)
    	pointers.push_back(Dashboard((fuel[i].position.x - player.position.x)/100-3,(fuel[i].position.z - player.position.z)/100 + 3,0,COLOR_GREEN,4));
 
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
    reshapeWindow (window, width, height);
    glClearColor (COLOR_LIGHTBLUE.r / 256.0, COLOR_LIGHTBLUE.g / 256.0, COLOR_LIGHTBLUE.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);
    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);
}
char display[100];

int main(int argc, char **argv) {
    srand(time(0));
    
    window = initGLFW(width, height);
    initGL (window, width, height);
    while (!glfwWindowShouldClose(window)) {
        if (t60.processTick()) {
            // 60 fps
            draw();
            glfwSwapBuffers(window);
            tick_elements();
            tick_input(window);

            if(frame%60 == 0 )view_change = 0;
            if(frame%20 == 0 )shoot = 0;
            if(frame%60 == 0 )enemy_shoot = 0;
            if(frame%6 == 0 )score++;

            if( (frame-60)%960 == 0 )
            	ring.push_back(Enemy(player.position.x + 1 +rand()%3,player.position.y,player.position.z + 1 + rand()%3 ,COLOR_BLACK,9));
			if( (frame-720)%960 == 0 )
            	ring.clear();	            
            
            frame++;
            fuel_level-=0.001;
            fuel_level=min(5.0,fuel_level);
            detect_collision();
            sprintf(display,"WELCOME  TO THE PIRATE-WORLD           YOUR SCORE : %d\n",score);
 		   glfwSetWindowTitle(window,display);
 		   if(check == 5)
 		   {
 		   		printf("CONGRATS! YOU CLEARED ALL 5 CHECK-POINTS\n");
			    printf("YOUR FINAL SCORE = %d\n",score);
 			   	quit(window);
 		   }
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    quit(window);
}

void detect_collision() {
	//fuel
	for(int i=0;i<fuel.size();i++)
    if(mod(fuel[i].position.x-player.position.x)<=0.3 && mod(fuel[i].position.y-player.position.y)<=0.3 && mod(fuel[i].position.z-player.position.z)<=0.3)
    {
    	fuel_level = 5.0f;
    	fuel.erase(fuel.begin()+i);
    }
    //volcano
    for(int i=0;i<volcano.size();i++)
    if(mod(volcano[i].position.x-player.position.x)<=1.2 && mod(volcano[i].position.y-player.position.y)<=2 && mod(volcano[i].position.z-player.position.z)<=1.2)
    	dead();

    //fuel-exhaust or underwater
    if(player.position.y < 0 || fuel_level < 0 || damage <= 0)
    	dead();
    
    //boat-missile
    for(int i=0;i<boat.size();i++)
    	for(int j=0;j<missile.size();j++)
    		if(mod(boat[i].position.x-missile[j].position.x)<=0.4 && mod(boat[i].position.y-missile[j].position.y)<=0.4 && mod(boat[i].position.z-missile[j].position.z)<=0.4)
    		{
    			boat.erase(boat.begin()+i);
    			missile.erase(missile.begin()+j);
    			score+=30;
    		}

    //cannon-missile
    	for(int j=0;j<missile.size();j++)
		    if( mod(cannon[0].position.x-missile[j].position.x) <= 0.4 && mod(cannon[0].position.y-missile[j].position.y)<=0.4 && mod(cannon[0].position.z-missile[j].position.z- 0.3)<=0.7)
		    {
		    	cannon.erase(cannon.begin());
		    	arrow.erase(arrow.begin());
		    	missile.erase(missile.begin()+j);
		  		for(int i=1;i<cannon.size();i++)
				{	
					if((abs(player.position.x - cannon[i].position.x) + abs(player.position.z - cannon[i].position.z)) < (abs(player.position.x - cannon[0].position.x) + abs(player.position.z - cannon[0].position.z)))
					{
						Enemy a,b;
						a=cannon[i];
						cannon[i]=cannon[0];
						cannon[0]=a;
						b=arrow[i];
						arrow[i]=arrow[0];
						arrow[0]=b;
					}			
				}
    			score+=100;
    			check++;
		    }

	//missile - land	   
    for(int i=0;i<land.size();i++)
    	for(int j=0;j<missile.size();j++)
    		if(mod(land[i].position.x-missile[j].position.x)<=1.2 && mod(land[i].position.y-missile[j].position.y)<=0.15 && mod(land[i].position.z-missile[j].position.z)<=1.2)
    		{
	    		missile.erase(missile.begin()+j);
	    		land[i]=Enemy(land[i].position.x,land[i].position.y,land[i].position.z,COLOR_RED,1);
    		}

    //boat-bomb
    for(int i=0;i<boat.size();i++)
    	for(int j=0;j<bomb.size();j++)
    		if(mod(boat[i].position.x-bomb[j].position.x)<=0.4 && mod(boat[i].position.y-bomb[j].position.y)<=0.4 && mod(boat[i].position.z-bomb[j].position.z)<=0.4)
    		{
    			boat.erase(boat.begin()+i);
    			bomb.erase(bomb.begin()+j);
    			score+=30;
    		}
    //land-bomb
    for(int i=0;i<land.size();i++)
    	for(int j=0;j<bomb.size();j++)
	    	if(mod(land[i].position.x-bomb[j].position.x)<=1.2 && mod(land[i].position.y-bomb[j].position.y)<=0.15 && mod(land[i].position.z-bomb[j].position.z)<=1.2)
    		{
		    	bomb.erase(bomb.begin()+j);
		    	land[i]=Enemy(land[i].position.x,land[i].position.y,land[i].position.z,COLOR_RED,1);
    		}

    //cannon-bomb
    for(int i=0;i<cannon.size();i++)
    	for(int j=0;j<bomb.size();j++)
		    if( mod(cannon[i].position.x-bomb[j].position.x) <= 0.3 && mod(cannon[i].position.y-bomb[j].position.y)<=0.4 && mod(cannon[i].position.z-bomb[j].position.z)<=0.3)
		    	{
		    		cannon.erase(cannon.begin()+i);
		    		arrow.erase(arrow.begin()+i);
		    		bomb.erase(bomb.begin()+j);
    		    	for(int i=1;i<cannon.size();i++)
					{
						if(mod(player.position.x - cannon[i].position.x) + mod(player.position.z - cannon[i].position.z) < mod(player.position.x - cannon[0].position.x) + mod(player.position.z - cannon[0].position.z))
						{
							Enemy a;
							a=cannon[i];
							cannon[i]=cannon[0];
							cannon[0]=a;
							a=arrow[i];
							arrow[i]=arrow[0];
							arrow[0]=a;
						}			
					}
    				score+=100;
    				check++;
		    	}

	//enemybomb-player
	for(int i=0;i<bomb_enemy.size();i++)
	    if( mod(bomb_enemy[i].position.x-player.position.x) <= 0.3 && mod(bomb_enemy[i].position.y-player.position.y)<=0.3 && mod(bomb_enemy[i].position.z-player.position.z)<=1)
		    {
		    	bomb_enemy.erase(bomb_enemy.begin()+i);
		    	damage--;
		    }

	//smoke-ring
	for(int i=0;i<ring.size();i++)
	    if( mod(ring[i].position.x-player.position.x) <= 0.2 && mod(ring[i].position.y-player.position.y)<=0.1 && mod(ring[i].position.z-player.position.z)<=0.3)
		    {
		    	score+=60;
		    	ring.erase(ring.begin()+i);
		    }

	//parachute-missile
    for(int i=0;i<parachute.size();i++)
    	for(int j=0;j<missile.size();j++)
		    if( mod(parachute[i].position.x-missile[j].position.x) <= 0.4 && mod(parachute[i].position.y-2-missile[j].position.y)<=0.4 && mod(parachute[i].position.z-missile[j].position.z)<=0.4)
		    {
		    	parachute.erase(parachute.begin()+i);
		    	missile.erase(missile.begin()+j);
    			score+=50;
		    }
	//parachute-bomb
    for(int i=0;i<parachute.size();i++)
    	for(int j=0;j<bomb.size();j++)
		    if( mod(parachute[i].position.x-bomb[j].position.x) <= 0.3 && mod(parachute[i].position.y-2-bomb[j].position.y)<=0.4 && mod(parachute[i].position.z-bomb[j].position.z)<=0.3)
		    	{
		    		parachute.erase(parachute.begin()+i);
		    		bomb.erase(bomb.begin()+j);
    				score+=50;
		    	}
}

void reset_screen() {
    float view    = screen_center_y + 4 ;
    float bottom = screen_center_y - 4 ;
    float left   = screen_center_x - 4 ;
    float right  = screen_center_x + 4 ;
    Matrices.projection2 = glm::ortho(left, right, bottom, view, 0.1f, 500.0f);
     view    = screen_center_y + 4 / screen_zoom;
     bottom = screen_center_y - 4 / screen_zoom;
     left   = screen_center_x - 4 / screen_zoom;
     right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(glm::radians(45.0f),3.0f/4.0f,0.1f,100.0f);
}
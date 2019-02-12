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
int view_change = 0;
int shoot = 0;
double fuel_level = 5.0;
Dashboard board[2][5];
vector<Enemy> land;
vector<Enemy> fuel;
vector<Enemy> volcano;
vector<Enemy> bomb;
vector<Enemy> missile;
Ball player;
Bg background;
void detect_collision();

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);
int view=0;

void draw() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram (programID);

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
	else//follow
	{
		eye = glm::vec3( player.position.x - 3*sin(player.rotationy * M_PI / 180.0f), player.position.y + 0.5, player.position.z - 3*cos(player.rotationy * M_PI / 180.0f));
    	target = glm::vec3(player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 10*cos(player.rotationy * M_PI / 180.0f));
   		up = glm::vec3(0, 1, 0);
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
    for(int i=0;i<volcano.size();i++)
    	volcano[i].draw(VP);
    for(int i=0;i<bomb.size();i++)
    	bomb[i].draw(VP);
    for(int i=0;i<missile.size();i++)
    	missile[i].draw(VP);
    player.draw(VP);
    if(view==0)//top
    {
    	board[0][0].draw(VP,player.position.x + 5, player.position.y , player.position.z + 7,0.8*fuel_level,0,COLOR_BROWN);
    	board[1][0].draw(VP,player.position.x + 5, player.position.y , player.position.z + 6,0.4*player.position.y,0,COLOR_RED);
	}
	else if(view==1)//tower
	{
    	board[0][1].draw(VP,player.position.x + 15, player.position.y , player.position.z + 6,0.6*fuel_level,1,COLOR_BROWN);
    	board[1][1].draw(VP,player.position.x + 13.5, player.position.y , player.position.z + 5,0.3*player.position.y,1,COLOR_RED);
	}
	else if(view==2)//front
	{
		board[0][2].draw(VP,player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y + 3, player.position.z + 10*cos(player.rotationy * M_PI / 180.0f),0.6*fuel_level,2,COLOR_BROWN);   
		board[1][2].draw(VP,player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y + 2.5, player.position.z + 10*cos(player.rotationy * M_PI / 180.0f),0.3*player.position.y,2,COLOR_RED);   
	}
	else if(view==3)//follow
	{
		board[0][3].draw(VP,player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y + 4.5, player.position.z + 10*cos(player.rotationy * M_PI / 180.0f),0.6*fuel_level,3,COLOR_BROWN);   
		board[1][3].draw(VP,player.position.x + 10*sin(player.rotationy * M_PI / 180.0f), player.position.y + 4, player.position.z + 10*cos(player.rotationy * M_PI / 180.0f),0.3*player.position.y,3,COLOR_RED);   
	}
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int front  = glfwGetKey(window, GLFW_KEY_UP);
    int right  = glfwGetKey(window, GLFW_KEY_RIGHT);
    int back  = glfwGetKey(window, GLFW_KEY_DOWN);
    int bo  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    int mis  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int v = glfwGetKey(window, GLFW_KEY_V);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int z = glfwGetKey(window, GLFW_KEY_Z);
    int x = glfwGetKey(window, GLFW_KEY_X);
    
    if(a)
    	player.rotate(1);
    if(d)
    	player.rotate(2);
    if(z)
    	player.rotate(3);
    if(x)
    	player.rotate(4);
    
    if(mis && shoot  == 0)
    {
    	missile.push_back(Enemy(player.position.x, player.position.y, player.position.z,COLOR_BLACK, 5));
    	shoot = 1;
    }
    if(bo && shoot  == 0)
    {
    	bomb.push_back(Enemy(player.position.x + 0.7*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 0.7*cos(player.rotationy * M_PI / 180.0f),COLOR_BLACK, 4));
    	shoot = 1;
    }
    if (v && view_change  == 0 ) {
    	view++;
    	view%=4;
        view_change = 1;
    }
    if(left)
    {
    	player.tick(2);
    	board[0][2].tick(2);
    	board[0][3].tick(2);
    	board[1][2].tick(2);
    	board[1][3].tick(2);
    }
    if(right)
    {
    	player.tick(1);
    	board[0][2].tick(1);
    	board[0][3].tick(1);
    	board[1][2].tick(1);
    	board[1][3].tick(1);
    }
    if(front)
    {
    	player.tick(3);
    	board[0][2].tick(3);
    	board[0][3].tick(3);
    	board[1][2].tick(3);
    	board[1][3].tick(3);
    }
    if(back)
    {
    	board[0][2].tick(4);
    	board[0][3].tick(4);
    	board[1][2].tick(4);
    	board[1][3].tick(4);
    	player.tick(4);
    }
    if(w)
    {
    	board[0][2].tick(5);
    	board[0][3].tick(5);
    	board[1][2].tick(5);
    	board[1][3].tick(5);
    	player.tick(5);
    }
    if(s)
    {
    	for(int i=0;i<land.size();i++)
    	if(abs(land[i].position.x-player.position.x)<=1.2 && abs(land[i].position.y-player.position.y)<=0.15 && abs(land[i].position.z-player.position.z)<=1.2)
    	{
    		board[0][2].tick(5);
    		board[0][3].tick(5);
    		board[1][2].tick(5);
	    	board[1][3].tick(5);
    		player.tick(5);
    	}	
    	board[0][2].tick(6);
    	board[0][3].tick(6);
    	board[1][2].tick(6);
    	board[1][3].tick(6);
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

    for(int i=0;i<missile.size();i++)
    	missile[i].boom(player.rotationx, player.rotationy);
    for(int i=0;i<missile.size();i++)
    	if(missile[i].position.y < 0)
         	missile.erase(missile.begin()+i);
}
void dead(){
	quit(window);
}
/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    player       = Ball(0,1,0, COLOR_SILVER);
    background   = Bg(0,0,0,COLOR_BLUE);
    for(int i=0;i<10;i++)
    for(int k=0;k<10;k++)
    if(rand()%2==0)
    {
    	land.push_back(Enemy(i*10,0.1,k*10 + 3,COLOR_GREEN,1));
    	if(rand()%3 == 0)
    	fuel.push_back(Enemy(i*10,1,k*10 + 3,COLOR_BROWN,2));
    	else if(rand()%6 == 1)
    	volcano.push_back(Enemy(i*10,0.1,k*10 + 3,COLOR_BLACK,3));
	}
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_LIGHTBLUE.r / 256.0, COLOR_LIGHTBLUE.g / 256.0, COLOR_LIGHTBLUE.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1000;
    int height = 800;
    long long int frame = 0;
    window = initGLFW(width, height);
    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            if(frame%60 == 0 )
            	view_change = 0;
            if(frame%20 == 0 )
            	shoot = 0;
            frame++;
            fuel_level-=0.001;
            fuel_level=min(5.0,fuel_level);
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
        detect_collision();
    }

    quit(window);
}

void detect_collision() {
	for(int i=0;i<fuel.size();i++)
    if(abs(fuel[i].position.x-player.position.x)<=0.3 && abs(fuel[i].position.y-player.position.y)<=0.3 && abs(fuel[i].position.z-player.position.z)<=0.3)
    {
    	fuel_level++;
    	fuel.erase(fuel.begin()+i);
    }
    for(int i=0;i<volcano.size();i++)
    if(abs(volcano[i].position.x-player.position.x)<=1.2 && abs(volcano[i].position.y-player.position.y)<=2 && abs(volcano[i].position.z-player.position.z)<=1.2)
    {
    	dead();
    }
    if(player.position.y < 0 || fuel_level < 0)
    	dead();
}

void reset_screen() {
    float view    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    // Matrices.projection = glm::ortho(left, right, bottom, view, 0.1f, 500.0f);
    Matrices.projection = glm::perspective(glm::radians(45.0f),3.0f/4.0f,0.1f,100.0f);
}
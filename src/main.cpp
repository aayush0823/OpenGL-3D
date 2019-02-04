#include "main.h"
#include "timer.h"
#include "ball.h"
#include "enemy.h"
#include "background.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;
glm::vec3 eye,target,up;
/**************************
* Customizable functions *
**************************/
int change = 0;
int score = 0;
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

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
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
		eye = glm::vec3( player.position.x -3*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z - 3*cos(player.rotationy * M_PI / 180.0f));
    	target = glm::vec3(player.position.x , player.position.y , player.position.z);
   		up = glm::vec3(0, 1, 0);
	}
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
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
    
    if(a)player.rotate(1);
    if(d)player.rotate(2);
    
    if(mis && change  == 0)
    {
    	missile.push_back(Enemy(player.position.x, player.position.y, player.position.z,COLOR_BLACK, 5));
    	change = 1;
    }
    if(bo && change  == 0)
    {
    	bomb.push_back(Enemy(player.position.x + 0.7*sin(player.rotationy * M_PI / 180.0f), player.position.y , player.position.z + 0.7*cos(player.rotationy * M_PI / 180.0f),COLOR_BLACK, 4));
    	change = 1;
    }
    if (v && change  == 0 ) {
    	view++;
    	view%=4;
        change = 1;
    }
    if(left)
    	player.tick(2);
    if(right)
    	player.tick(1);
    if(front)
    	player.tick(3);
    if(back)
    	player.tick(4);
    if(w)
    	player.tick(5);
    if(s)
    {
    	for(int i=0;i<land.size();i++)
    	if(abs(land[i].position.x-player.position.x)<=1.2 && abs(land[i].position.y-player.position.y)<=0.15 && abs(land[i].position.z-player.position.z)<=1.2)
    	{
    		player.tick(5);
    	}	
    	player.tick(6);
    }
}

void tick_elements() {
    camera_rotation_angle += 1;
    for(int i=0;i<bomb.size();i++)
    	bomb[i].boom(player.rotationy);
    for(int i=0;i<bomb.size();i++)
    	if(bomb[i].position.y < 0)
         	bomb.erase(bomb.begin()+i);

    for(int i=0;i<missile.size();i++)
    	missile[i].missile();
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
    	fuel.push_back(Enemy(i*10,0.1,k*10 + 3,COLOR_BROWN,2));
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
            if(frame%20 == 0 )
            	change = 0;
            frame++;
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
    	score+=10;
    	fuel.erase(fuel.begin()+i);
    }
    for(int i=0;i<volcano.size();i++)
    if(abs(volcano[i].position.x-player.position.x)<=1.5 && abs(volcano[i].position.y-player.position.y)<=2 && abs(volcano[i].position.z-player.position.z)<=1.5)
    {
    	dead();
    }
    if(player.position.y < 0)
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
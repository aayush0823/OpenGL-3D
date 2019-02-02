#include "main.h"
#include "timer.h"
#include "ball.h"
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
Ball player;
Bg background;
bool detect_collision(Ball a, Ball b);

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);
int top=0;

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    if(top==0)
    {
   		eye = glm::vec3( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    	target = glm::vec3(0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
   		up = glm::vec3(0, 1, 0);
	}
	else
	{

		eye = glm::vec3( -2, -0.4, -2);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    	target = glm::vec3(-2, -0.4, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
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
    player.draw(VP);
    background.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int front  = glfwGetKey(window, GLFW_KEY_UP);
    int right  = glfwGetKey(window, GLFW_KEY_RIGHT);
    int back  = glfwGetKey(window, GLFW_KEY_DOWN);
    int up  = glfwGetKey(window, GLFW_KEY_SPACE);
    int c = glfwGetKey(window, GLFW_KEY_C);
    if (c && change  == 0 ) {
    	top = 1- top;
        change = 1;
    }
    if(left)
    {
    	player.tick(2);
    }
    else if(right)
    {
    	player.tick(1);
    }
    else if(front)
    {
    	player.tick(3);
    }
    else if(back)
    {
    	player.tick(4);
    }
    else if(up)
    {
    	player.tick(5);
    }
    // else
    	// player.tick(4);
}

void tick_elements() {
    camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    player       = Ball(-2,-1,0, COLOR_SILVER);
    background   = Bg(0,0,0,COLOR_BLUE);
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
    int width  = 600;
    int height = 600;
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
            if(frame%30 == 0 )
            	change = 0;
            frame++;
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(Ball a, Ball b) {
    if(abs(a.position.x-b.position.x)<=0.36)
        return true;
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
    Matrices.projection = glm::perspective(glm::radians(45.0f),3.0f/4.0f,0.1f,100.0f);
}
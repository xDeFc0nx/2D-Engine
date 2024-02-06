#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct {
  GLFWwindow *window;
} Application;

int app_init(Application *app);
void app_run(Application *app);
void app_cleanup(Application *app);

#endif // APPLICATION_H

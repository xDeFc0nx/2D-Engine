
#include "application.h"
#include "logger.h"
#include <stdio.h>

KAPI int app_init(Application *app) {
  glewExperimental = TRUE; // Needed for core profile

  if (!glfwInit()) {
    KERROR("Failed to initialize GLFW\n");
    return FALSE;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  app->window = glfwCreateWindow(1024, 768, "OpenGL Window", NULL, NULL);

  if (!app->window) {
    KERROR("Failed to open GLFW window. If you have an Intel GPU, they are not "
           "3.3 compatible. Try the 2.1 version of the tutorials.\n");
    glfwTerminate();
    return FALSE;
  }

  glfwMakeContextCurrent(app->window);

  if (glewInit() != GLEW_OK) {
    KERROR("Failed to initialize GLEW\n");
    glfwDestroyWindow(app->window);
    glfwTerminate();
    return FALSE;
  }

  glfwSetInputMode(app->window, GLFW_STICKY_KEYS, GL_TRUE);

  return TRUE;
}

KAPI void app_run(Application *app) {
  while (!glfwWindowShouldClose(app->window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Your rendering code goes here

    glfwSwapBuffers(app->window);
    glfwPollEvents();
  }
}

KAPI void app_cleanup(Application *app) {
  glfwDestroyWindow(app->window);
  glfwTerminate();
}

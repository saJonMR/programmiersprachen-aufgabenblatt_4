# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  rect.cpp
  circle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})


# Build clock
 add_executable(clock
  window.cpp
  glew.c
  clock.cpp
  vec2.cpp
  mat2.cpp
  rect.cpp
  circle.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})


# Build tests
add_executable(tests
  glew.c
  vec2.cpp
  mat2.cpp
  tests.cpp
  rect.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe 2 und 3
add_executable(aufgabe_2_und_3
  aufgabe_2_und_3.cpp
  )
target_link_libraries(aufgabe_2_und_3
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe 5
add_executable(aufgabe_5
  glew.c
  vec2.cpp
  mat2.cpp
  aufgabe_5.cpp
  rect.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(aufgabe_5
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe 8
add_executable(aufgabe_8
  aufgabe_8.cpp
  )
target_link_libraries(aufgabe_8
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe 10
add_executable(aufgabe_10
  aufgabe_10.cpp
  )
target_link_libraries(aufgabe_10
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe 11
add_executable(aufgabe_11
  aufgabe_11.cpp
  )
target_link_libraries(aufgabe_11
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
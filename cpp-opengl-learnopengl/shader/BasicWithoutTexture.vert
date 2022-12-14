#version 330
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec3 aNormal;
out vec3 outCol;
out vec3 outNormal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 vp;

void main() {
  outCol    = aCol;
  outNormal = mat3(transpose(inverse(model))) * aNormal;
  fragPos   = vec3(model * vec4(aPos, 1.0));

  gl_Position = vp * vec4(fragPos, 1.0);
}
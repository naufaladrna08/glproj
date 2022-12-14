#version 330
out vec4 FragCol;
in vec3 outCol;

void main() {
  FragCol = vec4(outCol, 1.0);
}
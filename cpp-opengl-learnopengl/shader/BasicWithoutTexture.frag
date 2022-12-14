#version 330
out vec4 FragCol;
in vec3 outCol;
in vec3 outNormal;
in vec3 fragPos;

uniform vec3 lightColor;
uniform vec3 eyePosition;

struct Material {
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float shininess;
};

struct Light {
  vec3 position;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

uniform Material material;
uniform Light light;

void main() {
  vec3 ambient = light.ambient * material.ambient;

  vec3 normal = normalize(outNormal);
  vec3 lightDir = normalize(light.position - fragPos);
  float diff = max(dot(normal, lightDir), 0.0);

  vec3 diffuse = light.diffuse * (diff * material.diffuse);
  vec3 viewDir = normalize(eyePosition - fragPos);
  vec3 reflectDir = reflect(-lightDir, normal);  
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

  vec3 specular = light.specular * (material.specular * spec);  

  vec3 result = (ambient + diffuse + specular) * outCol;
  FragCol = vec4(result, 1.0);
}
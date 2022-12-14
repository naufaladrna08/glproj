#version 330
out vec4 FragCol;
in vec3 outCol;
in vec2 texCoords;
in vec3 outNormal;
in vec3 fragPos;

// struct Material {
//   vec3 ambient;
//   vec3 diffuse;
//   vec3 specular;
//   float shininess;
// };

// uniform sampler2D outex;

struct Material {
  sampler2D diffuse;
  sampler2D specular;
  float shininess;
};

struct Light {
  vec3 position;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;

  float constant;
  float linear;
  float quadratic;
};

uniform Material material;
uniform Light light;
uniform vec3 eyePosition;

void main() {
  vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords)).rgb;

  // Diffuse
  vec3 normal = normalize(outNormal);
  vec3 lightDir = normalize(light.position - fragPos);
  float diff = max(dot(normal, lightDir), 0.0);
  vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords)).rgb;  

  // Specular
  vec3 viewDir = normalize(eyePosition - fragPos);
  vec3 reflectDir = reflect(-lightDir, normal);  
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
  vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords)).rgb;

  float distance = length(light.position - fragPos);
  float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

  ambient  *= attenuation;
  diffuse  *= attenuation;
  specular *= attenuation;

  FragCol = vec4(ambient + diffuse + specular, 1.0);
}
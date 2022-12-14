#include <Shader.hpp>

/*!
 * @brief Load and compile shader program
 *
 * Load file from path and store it on m_vertexShader, m_fragmentShader. 
 * If the boolean compile is set to true, this will compile all shader and
 * make the shader program, otherwise you must call CreateProgram();. 
 */
Shader::Shader(std::string vertexPath, std::string fragmentPath, bool compile, bool text) {
  if (text == false) {
    std::ifstream file;
    std::string line;
    std::stringstream ss0, ss1;

    /* Reading vertex shader source from path */
    file.open(vertexPath);

    if (file.is_open()) {
      while (getline(file, line)) {
        ss0 << line << std::endl;
      }
    } else {
      std::cout << "File: " << vertexPath << " is not found." << std::endl;
    }
    
    file.clear();
    file.close();

    /* Reading fragment shader source from path */
    file.open(fragmentPath);

    if (file.is_open()) {
      while (getline(file, line)) {
        ss1 << line << std::endl;
      }
    } else {
      std::cout << "File: " << fragmentPath << " is not found." << std::endl;
    }
    
    file.clear();
    file.close();

    m_vertexShaderSource = ss0.str();
    m_fragmentShaderSource = ss1.str();
  } else {
    m_vertexShaderSource = vertexPath;
    m_fragmentShaderSource = fragmentPath;
  }
  
  if (compile) {
    CreateProgram();
    m_compileOnConstructor = true;
  }
}

Shader::~Shader() {

}

/* We can compile shader program through contructor or call this function. */
void Shader::CreateProgram() {
  int success;
  char infoLog[512];

  if (m_compileOnConstructor) {
    std::cout << "Shader program is already compiled. Skipping..." << std::endl;
    return;
  }

  const char* vertex_source_c = m_vertexShaderSource.c_str();
  const char* fragment_source_c = m_fragmentShaderSource.c_str();

  m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(m_vertexShader, 1, &vertex_source_c, NULL);
  glCompileShader(m_vertexShader);
  
  /* Compile info */
  glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(m_vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED : " << infoLog << std::endl;
  }

  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(m_fragmentShader, 1, &fragment_source_c, NULL);
  glCompileShader(m_fragmentShader);

  glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(m_fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED : " << infoLog << std::endl;
  }

  m_ShaderProgram = glCreateProgram();
  glAttachShader(m_ShaderProgram, m_vertexShader);
  glAttachShader(m_ShaderProgram, m_fragmentShader);
  glLinkProgram(m_ShaderProgram);

  glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
  
  if (!success) {
    glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINK_STATUS : " << infoLog << std::endl;
  }

  glDeleteShader(m_vertexShader);
  glDeleteShader(m_fragmentShader);
}

/* Since OpenGL is a state machine, theoretically we can use
 * any shader from anywhere in the program. */
void Shader::UseProgram() {
  glUseProgram(m_ShaderProgram);
}

unsigned int Shader::GetProgram() {
  return m_ShaderProgram;
}

void Shader::UniformInt(std::string uniform, const int value) {
  GLint uniform_loc = glGetUniformLocation(m_ShaderProgram, uniform.c_str());
  glUseProgram(m_ShaderProgram);
  glUniform1i(uniform_loc, value);
}

void Shader::Uniform1f(std::string uniform, const float value) {
  GLint uniform_loc = glGetUniformLocation(m_ShaderProgram, uniform.c_str());
  glUseProgram(m_ShaderProgram);
  glUniform1f(uniform_loc, value);
}

void Shader::Uniform4f(std::string uniform, const float* value) {
  GLint uniform_loc = glGetUniformLocation(m_ShaderProgram, uniform.c_str());
  glUseProgram(m_ShaderProgram);
  glUniform4fv(uniform_loc, 1, value);
}

void Shader::UniformMat4(std::string uniform, const glm::mat4 mat) {
  GLint uniform_loc = glGetUniformLocation(m_ShaderProgram, uniform.c_str());
  glUseProgram(m_ShaderProgram);
  glUniformMatrix4fv(uniform_loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::UniformVec3(std::string uniform, const glm::vec3 vec) {
  GLint uniform_loc = glGetUniformLocation(m_ShaderProgram, uniform.c_str());
  glUseProgram(m_ShaderProgram);
  glUniform3fv(uniform_loc, 1, glm::value_ptr(vec));
}

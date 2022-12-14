#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
  public: 
    /*!
     * @brief Load and compile shader program
     *
     * Load file from path and store it on m_vertexShader, m_fragmentShader. 
     * If the boolean compile is set to true, this will compile all shader and
     * make the shader program, otherwise you must call CreateProgram();. 
     */
    Shader(std::string vertexPath, std::string fragmentPath, bool compile = false, bool text = false);
    ~Shader();

    /* We can compile shader program through contructor or call this function. */
    void CreateProgram();

    /* Since OpenGL is a state machine, theoretically we can use
     * any shader from anywhere in the program. */
    void UseProgram();
    unsigned int GetProgram();

    void Uniform1f(std::string uniform, const float value);
    void UniformInt(std::string uniform, const int value);
    void Uniform4f(std::string uniform, const float* value);
    void UniformMat4(std::string uniform, const glm::mat4 mat);
    void UniformVec3(std::string uniform, const glm::vec3 vec);

  private:
    unsigned int m_vertexShader, m_fragmentShader, m_ShaderProgram;
    std::string m_vertexShaderSource, m_fragmentShaderSource;
    bool m_compileOnConstructor = false;
};

#endif
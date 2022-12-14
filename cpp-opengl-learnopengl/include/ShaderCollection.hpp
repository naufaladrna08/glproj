#ifndef SHADER_COLLECTION_H
#define SHADER_COLLECTION_H
#include <string>

class ShaderCollection {
  public:
    static std::string GetShader(const std::string& type, const std::string& title);
};

#endif
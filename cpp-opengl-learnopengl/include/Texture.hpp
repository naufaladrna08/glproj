#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/gl.h>
#include <stb_image.h>
#include <iostream>
#include <string>


class Texture {
  public:
    Texture(std::string source);
    ~Texture();

    void Bind();
    void Unbind();
    void ActivateTexture(int slot);

    inline GLuint GetID() { return m_id; }

  private:
    unsigned int m_id;
};

typedef struct {
  Texture* texture = nullptr;
  int slot;
} TextureSpec;

#endif 
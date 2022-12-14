#include <Texture.hpp>

Texture::Texture(std::string source) {
  glGenTextures(1, &m_id);
  glBindTexture(GL_TEXTURE_2D, m_id);

  /* Set texture parameter */
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  /* Load texture */
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true); 
  unsigned char* data = stbi_load(source.c_str(), &width, &height, &nrChannels, 0);

  /* Generate texture using previously loaded data */
  if (data) {
    if (source.substr(source.find_last_of(".") + 1) == "jpg") {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    } else {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Unable to load texture. Skipping" << std::endl;
  }

  stbi_image_free(data);

  glBindTexture(GL_TEXTURE_2D, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Texture::~Texture() {

}

void Texture::Bind() {
  glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::Unbind() {
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::ActivateTexture(int slot) {
  glActiveTexture(slot);
  glBindTexture(GL_TEXTURE_2D, m_id);
}